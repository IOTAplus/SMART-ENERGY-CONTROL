# SMART ENERGY CONTROL
![Title-pic](https://github.com/IOTAplus/SMART-ENERGY-CONTROL/blob/main/Images/unknown.png)
## Introduction
(PLEASE CHECK THE <a href="https://github.com/IOTAplus/SMART-ENERGY-CONTROLL/wiki/">WIKI</a> FOR MORE INFORMATIONS)

[Watch the project intro here.](https://www.powtoon.com/embed/eKk2WBgknBg)

### IOTA SMART HOME   -> ON AND OFF
This is a solution how to remotely measure, save and read the energy consumption data of any AC device(with small changes also DC devices) all over IOTA. 

Setup this example project and monitor some data like Watt or the consumed energy directly on the Android or Windows app.
You can connect as many TTGO or other devices (just sending data with the correct JSON format) the Smart Home app will automatically recognize 
and show them. You dont just receive the energy data you can controll each device monitored seperate over the phone to switch "ON" and "OFF" a rellais and so the the energy circuit.
Connect to this circuit an device like a lamp and it will switch on and off with just tapping a button in your app.

There is more. 

### THE BUISNESS MODEL -> RECEIVE IOTAs PER WATT HOURS CONSUMED

This model could be used by energy grid companies or even small hotels to count and charge the energy which was really used.
This small and affordable device can be used aswell for locating of power wasting machines.
This way to use this POC directly opens a huge amount of user cases.

If you want to charge the power used from someone you can change the price in the code of the TTGO to more than 0 IOTA per Wh.
The TTGO counts now the balance down to 0. So there is an additional tool needed the  <a href="https://github.com/IOTAplus/SMART-ENERGY-CONTROL/tree/main/PythonWallet">Python Wallet!</a>
It is a programm which contains a very small IOTA Wallet. It checks the balance and the last save address where people can send IOTA to and post it to keepy and from there to the IOTA tangle.
Install it on any device which can run python. 
If you have running the iot2tangle Gateway, Keepy, the Python wallet and at least one TTGO with a relay and a ACS712 you can check the Smart Home app.
Add the same Keepy URL you are sending to with the other devices(TTGO and Pyhton Wallet). Now you can watch all data and controll the devices connected.   


## Software requirements
* [Streams-http-gateway](https://github.com/iot2tangle/Streams-http-gateway) 
* [Keepy](https://github.com/iot2tangle/Keepy)
* [Python Wallet](https://github.com/IOTAplus/SMART-ENERGY-CONTROL/tree/main/PythonWallet)
* [Uncompiled Unity Smart Home app](https://www.dropbox.com/home/Unity)
  * [Compiled Unity Smart Home app for Android](https://github.com/IOTAplus/SMART-ENERGY-CONTROL/tree/main/SmartHomeApp/android)
  * [Compiled Unity Smart Home app for Windows](https://github.com/IOTAplus/SMART-ENERGY-CONTROL/tree/main/SmartHomeApp/windows)



## Bill of materials

| Components	| Link   | Q.ty  |Price (tipically)
| ------------- |:-------------:| -----:|-----------------:
| TTGO          | [TTGO](https://www.banggood.com/TTGO-T-Display-ESP32-CP2104-WiFi-bluetooth-Module-1_14-Inch-LCD-Development-Board-LILYGO-for-Arduino-products-that-work-with-official-Arduino-boards-p-1522925.html?utm_source=googleshopping&utm_medium=cpc_organic&gmcCountry=CH&utm_content=minha&utm_campaign=minha-ch-en-pc&currency=CHF&createTmp=1&utm_source=googleshopping&utm_medium=cpc_bgs&utm_content=xibei&utm_campaign=xibei-ssc-ch-warehouse-all-0922&cur_warehouse=UK) |     1 | 10$
| ACS712        | [ACS712](https://www.galaxus.ch/en/s1/product/acs712-sensor-electronics-modules-8193978?gclsrc=ds&gclsrc=ds) | 1      |10$
| Relay        | [Relais](https://www.galaxus.ch/en/s1/product/acs712-sensor-electronics-modules-8193978?gclsrc=ds&gclsrc=ds)      |     1 | 4$
| LED Lamp | [LED](https://www.reichelt.com/ch/de/led-5-mm-bedrahtet-rot-5-mcd-60--led-5mm-2ma-rt-p21627.html?PROVID=2808&gclid=CjwKCAiAnvj9BRA4EiwAuUMDf4LytdpEjwGv7ao9chOvG5fp72vGqP20uMangznA93wCwf4ZlMNdYRoC0FcQAvD_BwE)|1|0.1$
|USB-C for the TTGO | [USB-Cable](https://www.microspot.ch/de/mobiltelefon-tablet-wearables/mobiltelefon/mobiltelefon-tablet-kabel-adapter--c413000/intertronic-usb-c-kabel-usb-3-0-usb-typ-c-1-m--p0001860850?gclsrc=ds&gclsrc=ds)| 1|2-15$|
|Power Adapter|[Power Bank]()|1|20$|
|Some Cable|[Cable](https://www.digikey.ch/product-detail/de/mikroelektronika/MIKROE-513/1471-1232-ND/4495596?utm_adgroup=Jumper%20Wire&utm_source=google&utm_medium=cpc&utm_campaign=Shopping_Product_Prototyping%2C%20Fabrication%20Products&utm_term=&productid=4495596)|1|3$|

## Sources
* [Top lines in the Smart Home App](https://pngtree.com/freebackground/abstract-pink-blue-waves-isolated-on-white_1151999.html)

* [Icon made by Freepik from www.flaticon.com](https://www.flaticon.com/)
