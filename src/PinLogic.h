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
        //Log final pin values to the log file.
        logger("pin_setup", "Pin: " + String(pin));
    }
}