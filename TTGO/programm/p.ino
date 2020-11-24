#include <HTTPClient.h>
#include <WiFi.h>
#include <Arduino.h>
#include <ArduinoJson.h>
#include <time.h>
//THIS FILE CONTAINS THE MAIN PROGRAMM. TO GET AN COMPLETE OVERVIEW OV WHATS HAPPENING, THIS 
//FILE HERE IS THE RIGHT PLACE TO DO IT. 
//THESE ARE ALL VARIABLES WHICH ARE USED BY THE MAIN PROGRAMM 

//---------------------------------------------//
// CHOOSE THE RIGHT PIN FOR THE RELAIS IF YOU  //
// CONNECTED ONE. IF NOT YOU WOULD STILL SEE   //
// THE ENERGY CONSUMPTION SO ON THE MOBILE APP //
//                                             //               
            int relayPin = 21;                 //
//                                             //
//---------------------------------------------//

double wh;
double whOld;

double watt;
int messageID;
String channelID;

String httpRelaisi;
bool ON;
bool RelaisONStatus;
int balance;

// THIS SET UP THE RAILPIN AND THE WIFI CREDNTIAL TO GET CONNECTED TO THE INTERNET
void setup() {

  Serial.begin(115200);
  pinMode(relayPin, OUTPUT);
  //RelaisON();
  // HTTP REQUEST SETTINGS
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}
// THE LOOP WHICH STARTS ALL METHODS
void loop() {
  
  MeasureAndPost();
  delay(5000);
  Serial.print("Balance: ");
  Serial.println(balance);
  GetAndSwich();
}
//THIS COMBINES THE RETURN OUTPUT W AND Wh AND POST IT TO KEEPY
void MeasureAndPost()
{
  watt = MeasureCurrent(volt, watt);
  wh = WhMethode(iotaPerWhPrice, watt, wh);
  postDataToKeepy(watt, wh);
}
// THIS METHOD RECEIVES FROM A HTTP REQUEST THE INFOS, CONVERT IT,
// MAKES THE DECISION WHETER TO SWICH ON OR OFF THE RELLAY WITH ALL THE INFORMATIONS
// AND ACTUALLY CALLS THE RELAY-ON OR -OFF METHOD. 
void GetAndSwich()
{
  httpRelaisi = httpGETRequest(serverNameReceiving);

  for (int i = 20; i > 0 ; i--)
  {
    ON = jsonToStringMobile(httpRelaisi, i, ON);
    // THIS LINE SHOWS HOW THE OUTPUT IS ADDED TO THE OLD BALANCE
    balance = balance + jsonToStringRaspbi(httpRelaisi, i);
  }
//HERE YOU SEE HOW THE CREDIT/BALANCE OF THE DEVICE IS CHARGED FOR ENERGY USED.
  if(RelaisONStatus == true)
  {
  balance -= (wh-whOld) * atoi(iotaPerWhPrice);
  whOld=wh;
  }
  //SWITCH ON IF THE ORDER OF THE PHONE FOR THIS DEVICE IS ON AND THE BALANCE IS BIGGER OR EVEN TO 0
  if (ON == true && balance >= 0)
  {
    RelaisONStatus = true;
    RelaisON();
  }
  else
 {
  RelaisOFF();     
  RelaisONStatus = false;
}
}
