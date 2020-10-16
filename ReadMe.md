## HOME AUTOMATION README
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
