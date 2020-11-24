#include <ArduinoJson.h>
const size_t capacity = 20*JSON_ARRAY_SIZE(1) + 20*JSON_ARRAY_SIZE(2) + JSON_ARRAY_SIZE(20) + 40*JSON_OBJECT_SIZE(1) + 20*JSON_OBJECT_SIZE(2) + 40*JSON_OBJECT_SIZE(3) + 1930;
DynamicJsonDocument doc(capacity);

//--------------------------------------   //
// THE SENSOR NAME.CHANGE THE NAME IF YOU  //
// CONNECT VARIOUS TTGO SIMULTANIUSLY      //
//                                         //    
     String sensor = "TTGO-Relais";        //
//                                         //
//-----------------------------------------//


//THIS METHOD IS USED TO CONVERT THE JSON DATA AND TO GET IT'S CONTENT
bool jsonToStringMobile(String httpRelais, int i, bool lastStatus) {

deserializeJson(doc, httpRelais);

JsonObject root_1 = doc[i];
int root_1_id = root_1["id"]; // 1254

JsonObject root_1_message = root_1["message"];

const char* root_1_message_iot2tangle_0_sensor = root_1_message["iot2tangle"][0]["sensor"]; // "TTGO-Relais"

const char* root_1_message_iot2tangle_0_data_0_Relais = root_1_message["iot2tangle"][0]["data"][0]["Relais"]; // "OFF"

const char* root_1_message_device = root_1_message["device"]; // "Mobile"
const char* root_1_message_timestamp = root_1_message["timestamp"]; // "1558511111"

// FROM HERE THIS PART IS MADE TO GIVE THE TTGO/ESP32 THE INFOS TO REACT TO THE CONVERTED JSON INFORMATIONS

//JUST A PRINTOUT THAT THE RECEIVED MESSAGE HAS THE SENSOR CALLED - MOBILE
if(String(root_1_message_device) == "Mobile"){
  Serial.print("message_device: ");
  Serial.println(root_1_message_device);
}
// IF THE DEVICENAME OF THE JSON IS NOT MOBILE IT GIVES OUT THE LAST STAUS ON OR OFF
  if ( String(root_1_message_device) != "Mobile" ) {
    return lastStatus;
  }
// IF THE MESSAGE IS ON AND IF THE SENSOR IS THE SAME LIKE THIS ONE HERE THAN IT GIVES OUT TRUE
  if (String(root_1_message_iot2tangle_0_data_0_Relais) == "ON" && String(root_1_message_iot2tangle_0_sensor) == sensor )
  {
    Serial.println("Device Status: Relais ON  ");
    return true;
  }
  // IF THE MESSAGE IS ON AND IF THE SENSOR IS THE SAME LIKE THIS ONE HERE THAN IT GIVES OUT FALSE
  if (String(root_1_message_iot2tangle_0_data_0_Relais) == "OFF" && String(root_1_message_iot2tangle_0_sensor) == sensor)
  {
    Serial.println("Device Status: Relais OFF ");
    return false;
  }
}
