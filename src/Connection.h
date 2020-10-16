#include "log.h"
//Client mac address specified.
byte mac[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
// Setup network address for Client & Server.
IPAddress ip(192, 168, 0, 0);
IPAddress server(192, 168, 0, 0);
//Declare Ethernet & MQTT client libraries.
EthernetClient ethClient;
PubSubClient mqttClient(ethClient);
//Function callback handles incoming & outgoing messages.
//Function callback is explained in more detail in the ReadMe for more information.
void callback(char* topic, byte* payload, unsigned int length) {
    String content = "";
    char character;
    for (int num = 0; num < length; num++) {
        character = payload[num];
        content.concat(character);
    }
    logger("callback_MQTT_topic", "Topic:" + String(topic));
    logger("callback_MQTT_payload", "Payload:" + content);
    int pinval = content.toInt();
    logger("callback_set_pinval", "Pin Value:" + pinval);
    String pinvalstr;
    if (pinval > 21 && pinval < 43) {
        int swt = digitalRead(pinval);
        logger("callback_set_pinstate", "Pin State:" + swt);
        swt = swt > 0 ? LOW : HIGH;
        pinvalstr = swt == LOW ? content + "0" : content + "1";
        int str_len = pinvalstr.length() + 1;
        char char_array[str_len];
        pinvalstr.toCharArray(char_array, str_len);
        if (mqttClient.connect("anorakClient")) {
            mqttClient.publish("Homeret", char_array);
        }
        digitalWrite(pinval, swt);
        logger("callback_final_check", "Pin Value:" + String(pinval) + "Pin State:" + swt);
    }
}
//Function connector sets up the connection to the server.
void connector() {
    mqttClient.setServer(server, 1883);
    mqttClient.setCallback(callback);
    Ethernet.begin(mac, ip);
}
//Function reconnect will check state of connection and reatempt if disconnected.
void reconnect() {
    // Loop until connected
    while (!mqttClient.connected()) {
        logger("reconnect", "Attempting MQTT connection.");
        // Attempt to reconnect.
        if (mqttClient.connect("anorakClient")) {
            logger("reconnect_success", "Connected!");
            // Once connected, publish a Message.
            mqttClient.publish("Home2", "connected");
            // Subscribe to specific topic.
            mqttClient.subscribe("Home2");
        }
        else {
            logger("reconnect_fail", "State:" + String(mqttClient.state()) + ", Reattempting connection in 5 seconds.");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
    mqttClient.loop();
}

