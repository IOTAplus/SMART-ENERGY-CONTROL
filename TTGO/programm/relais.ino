
//THIS FILE IS TO PHYSICALLY SWITCH ON OR OFF THE RELLAY

void RelaisON(){
  digitalWrite(relayPin, HIGH);
    Serial.println("switched on");

}
void RelaisOFF() {
  digitalWrite(relayPin, LOW);
      Serial.println("switched off");
}
