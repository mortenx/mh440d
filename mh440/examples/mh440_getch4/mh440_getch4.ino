/*----------------------------------------------------------
    MH-440 CH4 sensor  SAMPLE
  ----------------------------------------------------------*/

#include <mh440_uart.h>

const int rx_pin = 16; //Serial rx pin no
const int tx_pin = 17; //Serial tx pin no

mh440_uart mh440;

/*----------------------------------------------------------
    MH-440 CH4 sensor  setup
  ----------------------------------------------------------*/
void setup()
{
  Serial.begin(9600);
  mh440.begin(rx_pin, tx_pin);
  mh440.setAutoCalibration(false);

  Serial.println("MH-440 is warming up now.");
  delay(10 * 1000); //
}

/*----------------------------------------------------------
    MH-440 CH4 sensor  loop
  ----------------------------------------------------------*/
void loop()
{
  int CH4ppm = mh440.getCH4PPM();
  int temp = mh440.getTemperature();

  Serial.print("CH4: ");
  Serial.println(CH4ppm);
  Serial.print("temp: ");
  Serial.println(temp);

  delay(5000);
}
