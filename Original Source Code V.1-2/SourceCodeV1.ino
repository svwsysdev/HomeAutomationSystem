
#include <SPI.h>
#include <Ethernet2.h>
#include <PubSubClient.h>
#include <Bounce2.h>

// Set led variables to Arduino digital pins
int light22 = 22;
int light23 = 23;
int light24 = 24;
int light25 = 25;
int light26 = 26;
int light27 = 27;
int light28 = 28;
int light29 = 29;
int light30 = 30;
int light31 = 31;
int light32 = 32;
int light33 = 33;
int light34 = 34;
int light35 = 35;
int light36 = 36;
int light37 = 37;
int light38 = 38;
int light39 = 39;
int light40 = 40;
int light41 = 41;
int light42 = 42;
int light43 = 43;
int light44 = 44;
int light45 = 45;
int light46 = 46;                             // pin 4 used by ethernet shield
int light47 = 47;


// Set button variables to Arduino digital pins
                         // pins 11,12,13 used by ethernetshield

// Set variables to act as virtual switches
// Set variable values initially to LOW (and not HIGH)
int light22Value = digitalRead(22);           
int light23Value = digitalRead(23);
int light24Value = digitalRead(24);            
int light25Value = digitalRead(25);
int light26Value = digitalRead(26);
int light27Value = digitalRead(27);
int light28Value = digitalRead(28);            
int light29Value = digitalRead(29);
int light30Value = digitalRead(30);
int light31Value = digitalRead(31);
int light32Value = digitalRead(32);            
int light33Value = digitalRead(33);
int light34Value = digitalRead(34);
int light35Value = digitalRead(35);
int light36Value = digitalRead(36);            
int light37Value = digitalRead(37);
int light38Value = digitalRead(38);
int light39Value = digitalRead(39);
int light40Value = digitalRead(40);            
int light41Value = digitalRead(41);
int light42Value = digitalRead(42);
int light43Value = digitalRead(43);
int light44Value = digitalRead(44);            
int light45Value = digitalRead(45);
int light46Value = digitalRead(46);
int light47Value = digitalRead(47);

//---------------------------------------------------------------------------

// Arduino MAC address is on a sticker on your Ethernet shield
// must be unique for every node in same network
// To make a new unique address change last letter

byte mac[]    = { 0x90, 0xA2, 0xDA, 0x11, 0x26, 0xFB };  


IPAddress ip(192,168,88,);


byte server[] = { 192, 168, 88, 2};



void callback(char* topic, byte* payload, unsigned int length) {
 
  String content="";
  char character;
  for (int num=0;num<length;num++) {
      character = payload[num];
      content.concat(character);
  }   
  Serial.println(topic);
  Serial.println(content); 
  
 
  if (content == "22on") {
    light22Value = HIGH;
  }
  else if (content == "22off") {
    light22Value = LOW;
  }
  
  if (content == "23on") {
    light23Value = HIGH;
  }
  else if (content == "23off") {
    light23Value = LOW;
  }

  
  if (content == "24on") {
  light24Value = HIGH;
  }
  else if (content == "24off") {
  light24Value = LOW;
  }
  
  if (content == "25on") {
    light25Value = HIGH;
  }
  else if (content == "25off") {
    light25Value = LOW;
  }

  // 4 lights  
  if (content == "26on") {
    light26Value = HIGH;
  }
  else if (content == "26off") {
    light26Value = LOW;
  }
  
  if (content == "27on") {
    light27Value = HIGH;
  }
  else if (content == "27off") {
    light27Value = LOW;
  }

  
  if (content == "28on") {
    light28Value = HIGH;
  }
  else if (content == "28off") {
    light28Value = LOW;
  }

  if (content == "29on") {
    light29Value = HIGH;
  }
  else if (content == "29off") {
    light29Value = LOW;
  }
  
  if (content == "30on") {
    light30Value = HIGH;
  }
  else if (content == "30off") {
    light30Value = LOW;
  }

  // 4 lights  
  if (content == "31on") {
    light31Value = HIGH;
  }
  else if (content == "31off") {
    light31Value = LOW;
  }
  
  if (content == "32on") {
    light32Value = HIGH;
  }
  else if (content == "32off") {
    light32Value = LOW;
  }

  
  if (content == "33on") {
    light33Value = HIGH;
  }
  else if (content == "33off") {
    light33Value = LOW;
  }
  
  if (content == "34on") {
    light34Value = HIGH;
  }
  else if (content == "34off") {
    light34Value = LOW;
  }

  // 4 lights  
  if (content == "35on") {
    light35Value = HIGH;
  }
  else if (content == "35off") {
    light35Value = LOW;
  }
  
  if (content == "36on") {
    light36Value = HIGH;
  }
  else if (content == "36off") {
    light36Value = LOW;
  }

  
  if (content == "37on") {
    light37Value = HIGH;
  }
  else if (content == "37off") {
    light37Value = LOW;
  }
  
  if (content == "38on") {
    light38Value = HIGH;
  }
  else if (content == "38off") {
    light38Value = LOW;
  }

  // 4 lights  
  if (content == "39on") {
    light39Value = HIGH;
  }
  else if (content == "39off") {
    light39Value = LOW;
  }
  
  if (content == "40on") {
    light40Value = HIGH;
  }
  else if (content == "40off") {
    light40Value = LOW;
  }

  
  if (content == "41on") {
    light41Value = HIGH;
  }
  else if (content == "41off") {
    light41Value = LOW;
  }
  
  if (content == "42on") {
    light42Value = HIGH;
  }
  else if (content == "42off") {
    light42Value = LOW;
  }

  // 4 lights  
  if (content == "43on") {
    light43Value = HIGH;
  }
  else if (content == "43off") {
    light43Value = LOW;
  }
  
  if (content == "44on") {
    light44Value = HIGH;
  }
  else if (content == "44off") {
    light44Value = LOW;
  }

  
  if (content == "45on") {
    light45Value = HIGH;
  }
  else if (content == "45off") {
    light45Value = LOW;
  }
  
  if (content == "46on") {
    light46Value = HIGH;
  }
  else if (content == "46off") {
    light46Value = LOW;
  }

  if (content == "47on") {
    light47Value = HIGH;
  }
  else if (content == "47off") {
    light47Value = LOW;
  }
  

  
    
  // Set digital pin states according to virtual switch settings
    
digitalWrite(light22,light22Value);
digitalWrite(light23,light23Value);
digitalWrite(light24,light24Value);
digitalWrite(light25,light25Value);
digitalWrite(light26,light26Value);
digitalWrite(light27,light27Value);
digitalWrite(light28,light28Value);
digitalWrite(light29,light29Value);
digitalWrite(light30,light30Value);
digitalWrite(light31,light31Value);
digitalWrite(light32,light32Value);
digitalWrite(light33,light33Value);
digitalWrite(light34,light34Value);
digitalWrite(light35,light35Value);
digitalWrite(light36,light36Value);
digitalWrite(light37,light37Value);
digitalWrite(light38,light38Value);
digitalWrite(light39,light39Value);
digitalWrite(light40,light40Value);
digitalWrite(light41,light41Value);
digitalWrite(light42,light42Value);
digitalWrite(light43,light43Value);
digitalWrite(light44,light44Value);
digitalWrite(light45,light45Value);
digitalWrite(light46,light46Value);
digitalWrite(light47,light47Value);
  

}

// Initiate instances -----------------------------------

EthernetClient ethClient;
PubSubClient client(server, 1883, callback, ethClient);

// Initiate a bouncer instance for each button
Bounce bouncer1 = Bounce();
Bounce bouncer2 = Bounce();
Bounce bouncer3 = Bounce();
Bounce bouncer4 = Bounce();
Bounce bouncer5 = Bounce();
Bounce bouncer6 = Bounce();
Bounce bouncer7 = Bounce();
Bounce bouncer8 = Bounce();
Bounce bouncer9 = Bounce();
Bounce bouncer10 = Bounce();
Bounce bouncer11 = Bounce();
Bounce bouncer12 = Bounce();
Bounce bouncer13 = Bounce();
Bounce bouncer14 = Bounce();
Bounce bouncer15 = Bounce();
Bounce bouncer16 = Bounce();
Bounce bouncer17 = Bounce();
Bounce bouncer18 = Bounce();
Bounce bouncer19 = Bounce();
Bounce bouncer20 = Bounce();
Bounce bouncer21 = Bounce();
Bounce bouncer22 = Bounce();
Bounce bouncer23 = Bounce();
Bounce bouncer24 = Bounce();
Bounce bouncer25 = Bounce();
Bounce bouncer26 = Bounce();

//.........................................................






//-------------------------------------------------------

void setup()
{


  // setup led, button, bouncer 1 -----------------------
  pinMode(light22, OUTPUT);
  bouncer1 .interval(5);

  // setup led, button, bouncer 2 -----------------------
  pinMode(light23, OUTPUT);
  bouncer2 .interval(5);

  // setup led, button, bouncer 3 -----------------------
  pinMode(light24, OUTPUT);
  bouncer3 .interval(5);

  // setup led, button, bouncer 4 -----------------------
  pinMode(light25, OUTPUT);
  bouncer4 .interval(5);

  // setup led, button, bouncer 1 -----------------------
  pinMode(light26, OUTPUT);
  bouncer5 .interval(5);

  // setup led, button, bouncer 2 -----------------------
  pinMode(light27, OUTPUT);
  bouncer6 .interval(5);

  // setup led, button, bouncer 3 -----------------------
  pinMode(light28, OUTPUT);
  bouncer7 .interval(5);

  // setup led, button, bouncer 4 -----------------------
  pinMode(light29, OUTPUT);
  bouncer8 .interval(5);

  // setup led, button, bouncer 1 -----------------------
  pinMode(light30, OUTPUT);
  bouncer9 .interval(5);

  // setup led, button, bouncer 2 -----------------------
  pinMode(light31, OUTPUT);
  bouncer10 .interval(5);

  // setup led, button, bouncer 3 -----------------------
  pinMode(light32, OUTPUT);
  bouncer11 .interval(5);

  // setup led, button, bouncer 4 -----------------------
  pinMode(light33, OUTPUT);
  bouncer12 .interval(5);

  // setup led, button, bouncer 1 -----------------------
  pinMode(light34, OUTPUT);
  bouncer13 .interval(5);

  // setup led, button, bouncer 2 -----------------------
  pinMode(light35, OUTPUT);
  bouncer14 .interval(5);

  // setup led, button, bouncer 3 -----------------------
  pinMode(light36, OUTPUT);
  bouncer15 .interval(5);

  // setup led, button, bouncer 4 -----------------------
  pinMode(light37, OUTPUT);
  bouncer16 .interval(5);

  // setup led, button, bouncer 1 -----------------------
  pinMode(light38, OUTPUT);
  bouncer17 .interval(5);

  // setup led, button, bouncer 2 -----------------------
  pinMode(light39, OUTPUT);
  bouncer18 .interval(5);

  // setup led, button, bouncer 3 -----------------------
  pinMode(light40, OUTPUT);
  bouncer19 .interval(5);

  // setup led, button, bouncer 4 -----------------------
  pinMode(light41, OUTPUT);
  bouncer20 .interval(5);

  // setup led, button, bouncer 1 -----------------------
  pinMode(light42, OUTPUT);
  bouncer21 .interval(5);

  // setup led, button, bouncer 2 -----------------------
  pinMode(light43, OUTPUT);
  bouncer22 .interval(5);

  // setup led, button, bouncer 3 -----------------------
  pinMode(light44, OUTPUT);
  bouncer23 .interval(5);

  // setup led, button, bouncer 4 -----------------------
  pinMode(light45, OUTPUT);
  bouncer24 .interval(5);

    // setup led, button, bouncer 3 -----------------------
  pinMode(light46, OUTPUT);
  bouncer25 .interval(5);

  // setup led, button, bouncer 4 -----------------------
  pinMode(light47, OUTPUT);
  bouncer26 .interval(5);

  // setup serial and ethernet communications -------------------------------

  // Setup serial connection
  Serial.begin(9600);

  // Setup ethernet connection to MQTT broker
  Ethernet.begin(mac);
  if (client.connect("AnorakClient1")) {                // change as desired - clientname must be unique for MQTT broker
    client.publish("Home","Connected - AnorakClient1");
    Serial.println("connected");
    client.subscribe("Home");  // subscribe to topic "led"
    } else {
    Serial.println("Disconnected");
  }
}
//______________________________________________________________________________
void reconnect()
{
    Serial.begin(9600);

  // Setup ethernet connection to MQTT broker
  Ethernet.begin(mac);
  while (!client.connected()) { 
    Serial.println("connecting");// change as desired - clientname must be unique for MQTT broker
    if (client.connect("AnorakClient1")){
    client.publish("Home","Connected - AnorakClient1");
    Serial.println("connected");
    client.subscribe("Home");  // subscribe to topic "led"
     }else {
    Serial.println("Disconnected");
    delay(5000);
  }
}
}
//----------------------------------------------

void loop()
{
  if (!client.connected()){
    reconnect();
  }
// Listen for button interactions and take actions ----------------------------------------  
// Note: Button actions do send MQTT message AND do set led(x)Value to HIGH or LOW

  if (bouncer1.update()) {
    if (bouncer1.read() == LOW) {
      if (light22Value == HIGH) {
        light22Value = LOW;
        client.publish("Lights","22on");                
      } else {
        light22Value = HIGH;
        client.publish("Lights","22off");
      }
    }
  }  

//-----------------------------------------------
  
  if (bouncer2.update()) {
    if (bouncer2.read() == LOW) {
      if (light22Value == HIGH) {
        light23Value = LOW;
        client.publish("Lights","23on");                
      } else {
        light23Value = HIGH;
        client.publish("Lights","23off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer3.update()) {
    if (bouncer3.read() == LOW) {
      if (light24Value == HIGH) {
        light24Value = LOW;
        client.publish("Lights","24on");                
      } else {
        light24Value = HIGH;
        client.publish("Lights","24off");
      }
    }
  }  

//-----------------------------------------------
  
   if (bouncer4.update()) {
    if (bouncer4.read() == LOW) {
      if (light25Value == HIGH) {
        light25Value = LOW;
        client.publish("Lights","25on");                
      } else {
        light25Value = HIGH;
        client.publish("Lights","25off");
      }
    }
  }  

//----------------------------------------------- 

  if (bouncer5.update()) {
    if (bouncer5.read() == LOW) {
      if (light26Value == HIGH) {
        light26Value = LOW;
        client.publish("Lights","26on");                
      } else {
        light26Value = HIGH;
        client.publish("Lights","26off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer6.update()) {
    if (bouncer6.read() == LOW) {
      if (light27Value == HIGH) {
        light27Value = LOW;
        client.publish("Lights","27on");                
      } else {
        light27Value = HIGH;
        client.publish("Lights","27off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer7.update()) {
    if (bouncer7.read() == LOW) {
      if (light28Value == HIGH) {
        light28Value = LOW;
        client.publish("Lights","28on");                
      } else {
        light28Value = HIGH;
        client.publish("Lights","28off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer8.update()) {
    if (bouncer8.read() == LOW) {
      if (light29Value == HIGH) {
        light29Value = LOW;
        client.publish("Lights","29on");                
      } else {
        light29Value = HIGH;
        client.publish("Lights","29off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer9.update()) {
    if (bouncer9.read() == LOW) {
      if (light30Value == HIGH) {
        light30Value = LOW;
        client.publish("Lights","30on");                
      } else {
        light30Value = HIGH;
        client.publish("Lights","30off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer10.update()) {
    if (bouncer10.read() == LOW) {
      if (light31Value == HIGH) {
        light31Value = LOW;
        client.publish("Lights","31on");                
      } else {
        light31Value = HIGH;
        client.publish("Lights","31off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer11.update()) {
    if (bouncer11.read() == LOW) {
      if (light32Value == HIGH) {
        light32Value = LOW;
        client.publish("Lights","32on");                
      } else {
        light32Value = HIGH;
        client.publish("Lights","32off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer12.update()) {
    if (bouncer12.read() == LOW) {
      if (light33Value == HIGH) {
        light33Value = LOW;
        client.publish("Lights","33on");                
      } else {
        light33Value = HIGH;
        client.publish("Lights","33off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer13.update()) {
    if (bouncer13.read() == LOW) {
      if (light34Value == HIGH) {
        light34Value = LOW;
        client.publish("Lights","34on");                
      } else {
        light34Value = HIGH;
        client.publish("Lights","34off");
      }
    }
  }  

  
  //-----------------------------------------------

  if (bouncer14.update()) {
    if (bouncer14.read() == LOW) {
      if (light35Value == HIGH) {
        light35Value = LOW;
        client.publish("Lights","35on");                
      } else {
        light35Value = HIGH;
        client.publish("Lights","35off");
      }
    }
  }
  

//-----------------------------------------------

  if (bouncer15.update()) {
    if (bouncer15.read() == LOW) {
      if (light36Value == HIGH) {
        light36Value = LOW;
        client.publish("Lights","36on");                
      } else {
        light36Value = HIGH;
        client.publish("Lights","36off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer16.update()) {
    if (bouncer16.read() == LOW) {
      if (light37Value == HIGH) {
        light37Value = LOW;
        client.publish("Lights","37on");                
      } else {
        light37Value = HIGH;
        client.publish("Lights","37off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer17.update()) {
    if (bouncer17.read() == LOW) {
      if (light38Value == HIGH) {
        light38Value = LOW;
        client.publish("Lights","38on");                
      } else {
        light38Value = HIGH;
        client.publish("Lights","38off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer18.update()) {
    if (bouncer18.read() == LOW) {
      if (light39Value == HIGH) {
        light39Value = LOW;
        client.publish("Lights","39on");                
      } else {
        light39Value = HIGH;
        client.publish("Lights","39off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer19.update()) {
    if (bouncer19.read() == LOW) {
      if (light40Value == HIGH) {
        light40Value = LOW;
        client.publish("Lights","40on");                
      } else {
        light40Value = HIGH;
        client.publish("Lights","40off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer20.update()) {
    if (bouncer20.read() == LOW) {
      if (light41Value == HIGH) {
        light41Value = LOW;
        client.publish("Lights","41on");                
      } else {
        light41Value = HIGH;
        client.publish("Lights","41off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer21.update()) {
    if (bouncer21.read() == LOW) {
      if (light42Value == HIGH) {
        light42Value = LOW;
        client.publish("Lights","42on");                
      } else {
        light42Value = HIGH;
        client.publish("Lights","42off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer22.update()) {
    if (bouncer22.read() == LOW) {
      if (light43Value == HIGH) {
        light43Value = LOW;
        client.publish("Lights","43on");                
      } else {
        light43Value = HIGH;
        client.publish("Lights","43off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer23.update()) {
    if (bouncer23.read() == LOW) {
      if (light44Value == HIGH) {
        light44Value = LOW;
        client.publish("Lights","44on");                
      } else {
        light44Value = HIGH;
        client.publish("Lights","44off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer24.update()) {
    if (bouncer24.read() == LOW) {
      if (light45Value == HIGH) {
        light45Value = LOW;
        client.publish("Lights","45on");                
      } else {
        light45Value = HIGH;
        client.publish("Lights","45off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer25.update()) {
    if (bouncer25.read() == LOW) {
      if (light46Value == HIGH) {
        light46Value = LOW;
        client.publish("Lights","46on");                
      } else {
        light46Value = HIGH;
        client.publish("Lights","46off");
      }
    }
  }  

//-----------------------------------------------

  if (bouncer26.update()) {
    if (bouncer26.read() == LOW) {
      if (light47Value == HIGH) {
        light47Value = LOW;
        client.publish("Lights","47on");                
      } else {
        light47Value = HIGH;
        client.publish("Lights","47off");
      }
    }
    
    
    
    
  }  

//-----------------------------------------------




  client.loop();
  

}

