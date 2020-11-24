#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

//THIS IS THE METHOD WHICH POSTS THE COLLECTED DATA CURRENT WATT AND TOTAL Wh USED TO KEEPY
void postDataToKeepy(double watt,double wh){
   String wattString;
  String whString;

  HTTPClient http;
  http.begin(serverName);

  // Specify content-type header
  http.addHeader("Content-Type", "application/json");  //("Content-Type", "application/x-www-form-urlencoded");
  // Data to send with HTTP POST
  wattString = String(watt, 2);
  whString = String(wh, 2);
  
  String httpRequestData = "{ \"iot2tangle\": [ { \"sensor\": \"ACS712\", \"data\": [ { \"Watt\": \"" + wattString + "\" },{ \"wh\": \"" + whString + "\" },{ \"PriceIOTAperWh\": \"" + iotaPerWhPrice + "\" } ] } ], \"device\": \"TTGO\", \"timestamp\": 1558511111 }";

  // Send HTTP POST request
  int httpResponseCode = http.POST(httpRequestData);

  

 //-------------If you need to see the response code unmark the next 2 lines of code---------
 
  //Serial.print("HTTP Response code: ");                                                  //
  //Serial.println(httpResponseCode);                                                      //

//------------------------------------------------------------------------------------------


  http.end();   // HAPPY END ;)
}
