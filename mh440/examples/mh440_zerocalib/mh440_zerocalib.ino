/*----------------------------------------------------------
    mh440 CH4 sensor  Zero calibration SAMPLE
  ----------------------------------------------------------*/

#include <mh440_uart.h>

const int rx_pin = 16; //Serial rx pin no
const int tx_pin = 17; //Serial tx pin no

const int waitingMinutes = 30; //waiting 30 minutes

mh440_uart mh440;

/*----------------------------------------------------------
    mh440 CH4 sensor  setup
  ----------------------------------------------------------*/
void setup()
{
  Serial.begin(9600);
  mh440.begin(rx_pin, tx_pin);
  mh440.setAutoCalibration(false);
  Serial.println("mh440 is warming up now.");
  delay(20 * 1000); //
  Serial.println();
}

/*----------------------------------------------------------
    mh440 CH4 sensor  loop
  ----------------------------------------------------------*/
long cnt = 0;
const long waitingSeconds = waitingMinutes * 60L;
void loop()
{
  if (++cnt % 60 == 0)
  {
    Serial.print(cnt / 60);
    Serial.println("min.");
    Serial.print("CH4: ");
    Serial.print(mh440.getCH4PPM());
    Serial.println("ppm now.");
  }
  else
  {
    Serial.print(".");
  }
  delay(1000);

  if (cnt > waitingSeconds)
  {
    Serial.println("");
    mh440.calibrateZero();
    Serial.println("1st zero calibration now .");

    delay(60000);
    mh440.calibrateZero(); // Just in case
    Serial.println("2nd zero calibration now .");

    for (int i = 0; i < 10; i++)
    {
      Serial.print("CH4: ");
      Serial.print(mh440.getCH4PPM());
      Serial.println("ppm now.");
      delay(10000);
    }
    cnt = 0;
    return;
  }
}
