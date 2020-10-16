## HOME AUTOMATION README
---
### How To:
---
**For:** Arduino Atmega2560

**Flashing to Arduino:** 

---

### Home.ino
##### Void Setup:
The void setup is where all the setup functions are done.

1. The connector function also handles the messages recieved and sent.
2. The connector function will be explained in more detail below. 
```c++
void setup() {
//Call connector function located in Connection.h
connector();
//Call pinSetup function located in PinLogic.h
pinSetup();
}
``` 
##### Void Loop:
The void loop is used to check connection status and reconnect function.
```c++
void loop(){
//Call checkConnect function located in Connection.h
checkConnect();
}
``` 
### PinLogic.h
##### Void pinSetup:
Inside pinSetup the variables are declared and pins for the arduino are setup.

```c++
void pinSetup() {
    //Variables set to instantiate pin values 
    int pin = 0;
    //Delay set to allow the previous function in Home.ino to finish.
    delay(1500);
    //Open serial listner on 9600 baud rate.
    Serial.begin(9600);
    //For loop declared to loop through the pin values to be set.
    for (int pin = 22; pin < 43; pin++) {
        //Set the pin values to output.
        pinMode(pin, OUTPUT);
        //Check state of each pin initially.
        digitalRead(pin);
        //Set each pin to preffered state. 
        digitalWrite(pin, HIGH);
    }
}
``` 
### Connection.h
##### Globals:


```c++
#include "log.h"
//Client mac address specified.
byte mac[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
// Setup network address for Client & Server.
IPAddress ip(192, 168, 0, 0);
IPAddress server(192, 168, 0, 0);
//Declare Ethernet & MQTT client libraries.
EthernetClient ethClient;
PubSubClient mqttClient(ethClient);
```
##### Void callback:

Detailed comments.
```c++
//Function callback handles incoming & outgoing messages.
void callback(char* topic, byte* payload, unsigned int length) {
  //Declaring variables for use.
  String content = "";
  char character;
  //For loop is used to read the payload in bytes.
  for (int num = 0; num < length; num++) {
    //The payload is converted into char variable.
    character = payload[num];
    //Here the variable character is converted from char to String.
    content.concat(character);
  }
  //Debug messages are logged to serial.
  logger("callback_MQTT_topic", "Topic:" + String(topic));
  logger("callback_MQTT_payload", "Payload:" + content);
  //The content variable is convert to an integer.
  int pinval = content.toInt();
  //Debug messages are logged to serial.
  logger("callback_set_pinval", "Pin Value:" + pinval);
  //Declare new string variable use.
  String pinvalstr;
  //Condition to cancel out pins that are not set.
  if (pinval > 21 && pinval < 43) {
    //Read state of pins.
    int swt = digitalRead(pinval);
    //Debug messages are logged to serial.
    logger("callback_set_pinstate", "Pin State:" + swt);
    //Condition checked and switch state set.
    swt = swt > 0 ? LOW : HIGH;
    //Condition sets pinvalstr to a unique message to return on or off value.
    pinvalstr = swt == LOW ? content + "0" : content + "1" ;
    //Integer declared to count pinvalstr length.
    int str_len = pinvalstr.length() + 1;
    //Declaring char array.
    char char_array[str_len];
    //Convert pinvalstr into char array.
    pinvalstr.toCharArray(char_array, str_len);
    //Condition to check if it is connected to server.
    if (mqttClient.connect("anorakClient")) {
      //Send message to MQTT server.
      mqttClient.publish("Homeret", char_array);
    }
    //Set the pin number to the specific state determined above.
    digitalWrite(pinval, swt);
    //Debug messages are logged to serial.
    logger("callback_final_check", "Pin Value:" + String(pinval) + "Pin State:" + swt);
  }
}
```
##### Void connector:
```c++
//Function connector sets up the connection to the server.
void connector() {
    //Server address and port specified.
    mqttClient.setServer(server, 1883);
    //Call library function to use callback.
    mqttClient.setCallback(callback);
    //Start ethernet client connection to connect to server. 
    Ethernet.begin(mac, ip);
}
```
##### Void reconnect:
```c++
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
``` 

