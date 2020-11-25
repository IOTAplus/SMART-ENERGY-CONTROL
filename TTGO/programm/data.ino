#include <Arduino.h>


//----------------------------------------------------------------------------------//
// HERE YOU HAVE TO SET YOUR WIFI PNAME AND PASSWORD                                 //
               const char* ssid = "Mo_2.4GH";                                        //                                //
               const char* password = "Morales0910";                                 //                                
//                                                                                   //
// HERE YOU CAN CHANGE THE VOLTAGE YOU ARE USING TO CALCULATE THE POWER WATT [W]     //
               double volt = 120;                                                    //
//                                                                                   //  
//                                                                                   //
// CHANGE HERE THE PRICE YOU WANT PER Wh IN IOTA                                     //
// IF IT IS AT 0 IT'S FOR FREE TO USE THE DEVICE AND YOU WILL BE ABLE TO USE IT      //
// JUST LIKE A SMART RELLAIS WITH WHERE YOU SEE THE CONSUMPTION OR YOU PUT AN AMOUNT // 
// HIGHER THAN 0 FOR EXAMPLE 1000 IOTA PER Wh BUT THAN YOU CAN JUST SWITCH ON THE    //
// RELLAIS IF YOU HAVE  ENOUGH IOTA ON THE GATEWAY PYTHON WALLET                     //
// put here 1000 for 1000 IOTA/Wh price. Icalculated it with energy price            //
//  0.2USD / 1 kWh and the IOTA price 0.2 USD/MIOTA                                  //
//                                                                                   //
              const char* iotaPerWhPrice = "0";                                      //
//                                                                                   //
// CHOOSE HERE YOUR URL ON WHERE KEEPY IS RUNNING. DON'T FORGET THE PORT.            //
              String URL = "http://192.168.1.200:3002/messages";                     //
//                                                                                   //
//                                                                                   //
//-----------------------------------------------------------------------------------//


//YOUR DOMAIN / URL READABLE FOR THE PROGRAMM. DONT CHANGE FROM HERE 
String serverName = URL;
//THIS COMBINES YOUR URL WHITH THE ENDING ?LIMIT=20
String serverNameReceiving = URL +"?limit=20";


unsigned long timerDelay = 20000;
unsigned long lastTime = 0;
