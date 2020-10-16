//Function logger allows serial debug info to be printed. 
void logger(String cat, String msgg) {
	Serial.println("[" + cat + "] " + msgg);
}