byte mac[] = { 0x90, 0xA2, 0xDA, 0x11, 0x26, 0xFB };
IPAddress ip(192, 168, 88, 3);
IPAddress server(192, 168, 88, 2);

EthernetClient ethClient;
PubSubClient mqttClient(ethClient);

void callback(char* topic, byte* payload, unsigned int length) {

    String content = "";
    char character;

    for (int num = 0; num < length; num++) {
        character = payload[num];
        content.concat(character);
    }
    Serial.println(topic);
    Serial.println(content);
    int pinval = content.toInt();
    String pinvalstr;
    if (pinval > 21 && pinval < 43) {
        int swt = digitalRead(pinval);

        swt = swt > 0 ? LOW : HIGH;
        pinvalstr = swt == LOW ? content + "0" : content + "1";

        Serial.print("Test to see string value: " + pinvalstr);
        int str_len = pinvalstr.length() + 1;
        char char_array[str_len];
        pinvalstr.toCharArray(char_array, str_len);

        if (mqttClient.connect("anorakClient")) {
            mqttClient.publish("Homeret", char_array);
        }
        digitalWrite(pinval, swt);
        Serial.println();
    }
    Serial.println();
    Serial.println("pinval: " + String(pinval));
    Serial.println();
}

void connector() {
    mqttClient.setServer(server, 1883);
    mqttClient.setCallback(callback);
    Ethernet.begin(mac, ip);
}

void reconnect() {
    // Loop until connected
    while (!mqttClient.connected()) {
        Serial.print("Attempting MQTT connection...");
        // Attempt to connect
        if (mqttClient.connect("anorakClient")) {
            Serial.println("connected");
            // Once connected, publish a Message.
            mqttClient.publish("Home2", "connected");
            // Subscribe to specific Topic
            mqttClient.subscribe("Home2");
        }
        else {
            Serial.print("Failed to connect: ");
            Serial.print(mqttClient.state());
            Serial.println(" Will retry in 5 seconds.");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }
}




void checkConnect() {
    if (!mqttClient.connected()) {
        reconnect();
    }
    mqttClient.loop();
}