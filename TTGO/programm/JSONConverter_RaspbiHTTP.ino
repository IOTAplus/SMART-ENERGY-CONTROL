#include <ArduinoJson.h>

// THIS ALWAYS HAS THE LATEST BALANCE TO COMPARE IT WITH THE NEW ONE TO CALCULATE HOW MUCH WAS ADDED.
int balanceOld;

//THIS METHOD CONVERTS THE RECEIVED JSON FROM KEEPY WHICH CAMES ORIGINALLY FROM THE RASPBERY PI WALLET
//OR FROM ANY PLACE YOU DECIDE RUN THE PYTHON WALLET SCRIPT(IT RUNS ALSO ON ANY OTHER MACHINE WHICH RUNS PYTHON).
//TO GET THE INFO BALANCE OUT OF IT AND RETURNS THE NEW BALANCE FOR THE DEVICE.
//IF YOU HAVE VARIOUS DEVICES CONNECTED WITH DIFFERENT NAMES ALL DEVICES CONNECTED 
//TO THE SAME GATEWAY YOU STILL WILL SEE THIS MESSAGE ON ALL DEVICES AND RECEIVE THE NEW BALANCE.
//ON ALL OF THEM. AS YOU KNOW HOW MANY DEVICES YOU CONNECET YOU COULD JUST INCREASE THE PRICE 1X PER EACH DEVICE
//JUST TO MENTION, THIS WOULD CAUSE AS SIDE EFFECT THAT ON THE PHONE THE Wh PRICE WILL LOOK X TIMES HIGHER.
//WITH A BIT MORE INFORMATIONFLOW THIS COULD BE FIXED EASY

int jsonToStringRaspbi(String httpRelais, int i) {

const size_t capacity = 20*JSON_ARRAY_SIZE(1) + 20*JSON_ARRAY_SIZE(2) + JSON_ARRAY_SIZE(20) + 40*JSON_OBJECT_SIZE(1) + 20*JSON_OBJECT_SIZE(2) + 40*JSON_OBJECT_SIZE(3) + 1930;
DynamicJsonDocument doc(capacity);

deserializeJson(doc, httpRelais);

JsonObject root_3 = doc[i];
int root_3_id = root_3["id"]; // 968

JsonObject root_3_message = root_3["message"];
const char* root_3_message_device = root_3_message["device"]; // "Raspi-HTTP"
const char* root_3_message_timestamp = root_3_message["timestamp"]; // "1601653408"

const char* root_3_message_iot2tangle_0_data_0_Address_ = root_3_message["iot2tangle"][0]["data"][0]["Address "]; // "IIKBMKIMV9XNBAJRIZOSBQPEDXYDKPCWTCLTDTRGASEJISX9JRGVAWHLBALOBPYFHTAUI9DLFSOOZVLDBKQRJHUFKC"

const char* root_3_message_iot2tangle_0_data_1_Balance = root_3_message["iot2tangle"][0]["data"][1]["Balance"]; // "1"

const char* root_3_message_iot2tangle_0_sensor = root_3_message["iot2tangle"][0]["sensor"]; // "Wallet"

//THIS METHOD CHECKS IF THE DIFFERENCE OF THE OLD VARIABLE IS BIGGER THAN 0 AND IF SO IT 
//PRINTS OUT NEW CREDIT RECEIVED AND RETURNS AN INT HOW MANY CREDITS ARE NOW AVAIABLE ON THIS DEVICE
  if (String(root_3_message_device) == "Raspi-HTTP" && atoi(root_3_message_iot2tangle_0_data_1_Balance)>balanceOld)
  {
    int newCredits = atoi(root_3_message_iot2tangle_0_data_1_Balance) - balanceOld;

    Serial.print("message device: ");
    Serial.println(root_3_message_device);
    Serial.print("New Credits: ");
    Serial.println(newCredits);
    
    balanceOld = atoi(root_3_message_iot2tangle_0_data_1_Balance);
    return newCredits;
  }
//THIS METHOD CHECKES IF THE DEVICE IS RASPI-HTTP AND IF NOT IT RETURNS 0 NEW BALANCE/CREDITS CHARGED.
  else if (root_3_message_device != "Raspi-HTTP")
  {
    return 0;
  }

}
