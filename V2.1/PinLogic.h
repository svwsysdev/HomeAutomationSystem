void pinSetup() {
    int pin = 0;
    int spin = digitalRead(pin);
    int butval = 0;

    delay(1500);
    Serial.begin(9600);

    for (int pin = 22; pin < 43; pin++) {
        pinMode(pin, OUTPUT);
        digitalRead(pin);
        digitalWrite(pin, HIGH);
    }
}