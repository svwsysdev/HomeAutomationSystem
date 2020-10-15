
#include <Bounce2.h>
#include <PubSubClient.h>
#include <SPI.h>
#include <Ethernet2.h>
#include "Connection.h"
#include "PinLogic.h"



void setup() {
connector();
pinSetup();
}

void loop(){
checkConnect();
}