
#include <Bounce2.h>
#include <PubSubClient.h>
#include <SPI.h>
#include <Ethernet2.h>
#include "Connection.h"
#include "PinLogic.h"
#include "log.h"

void setup() {
	//Call connector function located in Connection.h
	connector();
	//Call pinSetup function located in PinLogic.h
	pinSetup();
}

void loop(){
	//Call reconnect function located in Connection.h
	reconnect();
}