#include <FastLED.h>
#define NUM_LEDS  26  
#define PIN 11    //Also important.  Needs to be a PWM pin.
CRGB leds[NUM_LEDS];
int globalBright = 220;

/*
 *Hackster tutorial:  https://www.hackster.io/matheus-fenner/skype-status-light-c2df6c 
 * Bridge EXE:  https://github.com/f3nner/Skype-Status-Light-Bridge-EXE
 */

void setup() {
  // initialize serial:
  Serial.begin(9600);

  FastLED.addLeds<WS2812, PIN, BRG>(leds, NUM_LEDS);
  FastLED.setCorrection(TypicalLEDStrip);
  //FastLED.setMaxPowerInVoltsAndMilliamps(5,maxMilliamps);
  FastLED.setBrightness(globalBright);

}

void loop() {

  delay(10);
  
  // if there's any serial available, read it:
  while (Serial.available() > 0) {

    // look for the next valid integer in the incoming serial stream:
    int red = Serial.parseInt();
    // do it again:
    int green = Serial.parseInt();
    // do it again:
    int blue = Serial.parseInt();

    // look for the newline. That's the end of your
    // sentence:
    if (Serial.read() == '\n') {
      // constrain the values to 0 - 255
      red = constrain(red, 0, 255);
      green = constrain(green, 0, 255);
      blue = constrain(blue, 0, 255);

      fill_solid(leds, NUM_LEDS, CRGB(red, green, blue));
      FastLED.show();
      delay(100);
      
      // print the three numbers in one string
      Serial.print(red); Serial.print(", ");
      Serial.print(green);Serial.print(", ");
      Serial.println(blue);
    }
  }
}
