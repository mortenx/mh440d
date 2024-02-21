/*----------------------------------------------------------
    mh440 CH4 sensor  Span calibration SAMPLE
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
long avg_sum = 0L;
const long waitingSeconds = waitingMinutes * 60L;
void loop()
{
  if (++cnt % 60 == 0)
  {
    int ppm = mh440.getCH4PPM();
    avg_sum += (long)ppm;
    Serial.print(cnt / 60);
    Serial.println("min.");
    Serial.print("CH4: ");
    Serial.print(ppm);
    Serial.println("ppm now.");
  }
  else
  {
    Serial.print(".");
  }
  delay(1000);

  if (cnt > waitingSeconds)
  {
    long avg = avg_sum / waitingMinutes;
    if (avg < 1000)
    {
      Serial.print("CH4 Avg. :");
      Serial.println(avg);
      Serial.println("Can't Span point calibration because CH4 average is lower than 1000ppm");
      cnt = 0;
      avg_sum = 0L;
      return;
    }

    Serial.println("");
    mh440.calibrateSpan(avg);
    Serial.println("span calibration now .");

    for (int i = 0; i < 10; i++)
    {
      Serial.print("CH4: ");
      Serial.print(mh440.getCH4PPM());
      Serial.println("ppm now.");
      delay(10000);
    }
    cnt = 0;
    avg_sum = 0L;
  }
}
