#include <Arduino.h>

#define LED_PIN 22
#define TIMER_TO_BLINK 1000
unsigned long int timerToBlink = 0;

void blinkLed(void);

void setup() 
{
   pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
   blinkLed();
}

void blinkLed(void)
{
   static bool ledState = false;

   if((millis() - timerToBlink) > TIMER_TO_BLINK)
   {
      timerToBlink = millis();
      digitalWrite(LED_PIN, ledState);
      ledState = !ledState;
   }
}

