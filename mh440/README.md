# MH440_uart 
Arduino IDE library for operating the MH-440 CH4 sensor in ESP-WROOM-02/32(ESP8266/ESP32) or Arduino  
version 0.31

# Credits and license  
License MIT

# How to use

* Include this library to your Arduino IDE.
* Wiring MH-440 sensor to your Arduino or ESP-WROOM-02/32(ESP8266/ESP32).

    MH-440 Vout to Arduino Vout(5V)  
    MH-440 GND  to Arduino GND  
    MH-440 Tx   to Arduino Digital Pin (Serial Rx pin)  
    MH-440 Rx   to Arduino Digital Pin (Serial Tx pin)  
    other MH-440 pins are not used.  

* Read sample source code. It's very simple !

# caution

* MH-440 is supporting PWM , but this library is supporting only serial connection. 
* this library is testing only ESP-WROOM-02/32(ESP8266/ESP32) boards. if you can't execute this library on your arduino (or clone) boards, please contact me.

# MH440_uart library function

## Constractor

* MH440_uart  
  normal constractor. if you use this constractor, you must execute begin() function after this constractor execute.

* MH440_uart(int rx, int tx)  
  setting rx and tx pin, and initialize Serial.

## public function

* void begin(int rx, int tx)  
  setting rx and tx pin, and initialize Serial.

* void setHardwareSerialNo(int serialNo)  
  setting hardware serial no. # You can use this function only ESP32.
  
* void setAutoCalibration(bool autocalib)  
  MH-440 has automatic calibration procedure. the MH-440 executing automatic calibration, its do zero point(stable gas environment (400ppm)) judgement.
  The automatic calibration cycle is every 24 hours after powered on.  
  If you use this sensor in door, you execute `setAutoCalibration(false)`.

* void calibrateZero()  
  execute zero point calibration. 
  if you want to execute zero point calibration, the MH-440 sensor must work in stable gas environment (400ppm) for over 20 minutes and you execute this function.

* void calibrateSpan(int ppm)  
  execute span point calibration.
  if you want to execute span point calibration, the MH-440 sensor must work in between 1000 to 2000ppm level CH4 for over 20 minutes and you execute this function.
  
* int getCH4PPM()  
  get CH4 ppm.
  
* int getTemperature()  
  get temperature (MH-440 hidden function?  this function is not support.)

# link
* MH-440 Data sheet  
  http://www.winsen-sensor.com/d/files/PDF/Infrared%20Gas%20Sensor/NDIR%20CH4%20SENSOR/MH-440%20CH4%20Ver1.0.pdf

* MH-440B Data sheet  
  http://www.winsen-sensor.com/d/files/infrared-gas-sensor/MH-440b-CH4-ver1_0.pdf

* MH-440C Data sheet  
  https://www.winsen-sensor.com/d/files/infrared-gas-sensor/MH-440c-pins-type-CH4-manual-ver1_0.pdf

# history
* ver. 0.1: closed version.
* ver. 0.2: first release version.
* ver. 0.3: support ESP-WROOM-32(ESP32), Change library name. (MH440_Serial -> MH440_uart)
* ver. 0.31: Operation check on MH-440C, Delete functions getStatus() and isWarming(), And refactor details.

