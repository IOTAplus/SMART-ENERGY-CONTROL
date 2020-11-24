#include <Arduino.h>
#include <HTTPClient.h>

//THIS METHOD JUST MAKES THE HTTP REQUEST TO THE URL YOU CHOSE
String httpGETRequest(String serverNameReceiving) {
  HTTPClient http;

  // Your IP address with path or Domain name with URL path
  http.begin(serverNameReceiving);

  // Send HTTP POST request
  int httpResponseCode = http.GET();

  String payload = "{}";

  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}
