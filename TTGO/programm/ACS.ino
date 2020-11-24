
//--------------------------------------------------------------------------------------------------------
//CHOOSE THE PIN YOU FINALLY CONNECTED. THE EXAMPLE IS ON A TTGO PIN=36 BUT IF YOU USE A ESP32 CHANGE IT TO THE ONE USED.
   int pin = 36;

// PLEASE MEASURE THE CURRENT WITH A DIFFEREN DEVICE AND COMPARE IT WITH THE OUTPUT Current: x mAmpere.
// CHOOSE THE RIGHT CALIBRATIONFACTOR TO GET THE RIGHT CURRENT AND POWER OUTPUT.
   double calibrationFactor = 1;

//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------



int offset = 20; // set the correction offset value; IF NECESSARY
 
 //DON'T CHANGE THIS. THIS IS TO SAVE ALWAYS THE LAST TIME WHEN THE PROGRAM PASSED.
  //TO COMPARE IT WITH THE NEW TIME AND TO FINALLY GET THE TIME PASSED -
  //TO CALCULATE THE ENERGY IN WATTHOURS WHERE USED.
  unsigned long timeOld = millis();

  
//THIS METHOD DOEST MEASURE THE AC CURRENT. YOU HAVE TO CALIBRATE IT!
double MeasureCurrent(double volt, double watt) {

  float AcsValue = 0.0, Samples = 0.0, AvgAcs = 0.0, AcsValueF = 0.0;

  for (int x = 0; x < 150; x++) { //Get 150 samples
    AcsValue = analogRead(pin);     //Read current sensor values
    Samples = Samples + AcsValue;  //Add samples together
    delay (3); // let ADC settle before next sample 3ms
  }
  AvgAcs = Samples / 150.0; //Taking Average of Samples

  //((AvgAcs * (5.0 / 1024.0)) is converitng the read voltage in 0-5 volts
  //2.5 is offset(I assumed that arduino is working on 5v so the viout at no current comes
  //out to be 2.5 which is out offset. If your arduino is working on different voltage than
  //you must change the offset according to the input voltage)
  //0.185v(185mV) is rise in output voltage when 1A current flows at input
  AcsValueF = (2.5 - (AvgAcs * (5.0 / 1024.0)) ) / (-0.185);

  // Robojax.com voltage sensor
  //int amperePinOUtput = analogRead(36);// read the input and correct
  double ampere = calibrationFactor * map(AcsValueF, 0, 1023, 0, 2500) + offset; // map 0-1023 to 0-2500 and add correction offset

  watt = ((volt * ampere) / 1000);

  Serial.print("Current: ");
  Serial.print(ampere);//print the current
  Serial.println(" mAmpere   " );

  Serial.print("Power Consumption = ");
  Serial.print(watt);
  Serial.println(" W ");

  return watt;

}

//THIS METHOD TAKE THE W AND MULTIPLYS IT WITH THE TIME PASSED TO GET WATTHOURS [Wh].
//AS INMPORTANT INPUT IT GETS THE WH ALREADY USED AND IT ADS THE NEW NUMBER TO IT.
//THE DOUBLE OUTPUT IS ALWAYS THE TOTAL USED Wh OF THE DEVICE.
double WhMethode(const char* iotaPerWhPrice, double watt, double wh) {

  unsigned long timeNew = millis();

  int seconds = (int(timeNew) - int(timeOld)) / 1000;
  timeOld = timeNew;
  wh += (seconds * watt / 3600);

  Serial.print("Total Energy consumed: ");
  Serial.print(wh);
  Serial.println(" Wh    ");

  Serial.print("Current costs per hour ");
  Serial.print((watt * atoi(iotaPerWhPrice) * 3.6) / 1000);
  Serial.println(" kIOTA   ");
  return wh;
}
