#include <ArduinoJson.h>

//THIS METHOD CAN CONVERT THE RECEIVED JSON WHICH CAMES ORIGINALLY FROM THIS DEVICE ITSELF.
//THIS METHOD IS NOT IN USE BUT CAN BE INCLUDED EASILY IN THE MAIN PROGRAM FILE P OR WHEREVER YOU NEED IT
void jsonToStringESP(String httpRelais) {

  const size_t capacity = JSON_ARRAY_SIZE(1) + JSON_ARRAY_SIZE(2) + 2*JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(2) + 2*JSON_OBJECT_SIZE(3) + 220;
DynamicJsonDocument doc(capacity);

const char* json = "{\"id\":13221,\"message\":{\"iot2tangle\":[{\"sensor\":\"ACS712\",\"data\":[{\"Watt\":\"0.10\"},{\"wh\":\"0.00\"}]}],\"device\":\"TTGO\",\"timestamp\":1558511111},\"channelId\":\"6b11585537ae2050a6e730e470930f1ea2699bc8051c1ac45545d322b7f299e50000000000000000:e0ae6e1c90178b6bf3b752b9\"}";

deserializeJson(doc, httpRelais);

int id = doc["id"]; // 13221

JsonObject message = doc["message"];
const char* message_iot2tangle_0_sensor = message["iot2tangle"][0]["sensor"]; // "ACS712"
const char* message_iot2tangle_0_data_0_Watt = message["iot2tangle"][0]["data"][0]["Watt"]; // "0.10"
const char* message_iot2tangle_0_data_1_wh = message["iot2tangle"][0]["data"][1]["wh"]; // "0.00"
const char* message_device = message["device"]; // "TTGO"
long message_timestamp = message["timestamp"]; // 1558511111
const char* channelId = doc["channelId"]; // "6b11585537ae2050a6e730e470930f1ea2699bc8051c1ac45545d322b7f299e50000000000000000:e0ae6e1c90178b6bf3b752b9"


  Serial.print("Device from ESP:  ");
  Serial.println(message_device);
    Serial.print("Message added with ID: ");
  Serial.println(id);

}
