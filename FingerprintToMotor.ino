#define CUSTOM_SETTINGS
#define INCLUDE_FINGERPRINT_SCANNER_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>
#include <Servo.h> 

/* A name for the LED on pin 13. */
int pin = 3;
Servo motor;
void setup()
{
  /* Start communication. */
  OneSheeld.begin();
  /* Set the LED pin as output. */
  motor.attach(pin);
  motor.write(180);
}

void loop()
{
  if(FingerprintScanner.isNewFingerScanned() && FingerprintScanner.isVerified())
  {
    motor.write(90);
    delay(3000);
    motor.write(180);
  } 
}
