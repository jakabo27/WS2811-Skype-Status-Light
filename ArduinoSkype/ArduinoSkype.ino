#include <FastLED.h>
#define NUM_LEDS  26  
#define PIN 11    


#define FRAMES_PER_SECOND 40
#define THREESTRIP false

CRGB leds[NUM_LEDS];

/*
 *Hackster tutorial:  https://www.hackster.io/matheus-fenner/skype-status-light-c2df6c 
 * Bridge EXE:  https://github.com/f3nner/Skype-Status-Light-Bridge-EXE
 * My bridge exe:  https://github.com/jakabo27/WS2811-Skype-Status-Light
 */

//Various custom setup
String receivedString = "Starting";
String commandString = "";
int command, prevCommand;
byte functionNum = 44;
byte prevFunctionNum = 0;
byte _r, _g, _b;  //global rgb values
byte CustomFunction = 0;

 //GLOBAL VARIABLES
volatile boolean animate = true;
volatile long animationTimeout, restTimeout;
int timeToRun = 20; //milliseconds until checking input
byte globalBright = 220; //0 to 255
byte globalSpeed = 20;   //0 to 50 (managed by Receiver code)
byte globalSpeedMax = 50;  //upper limit of global speed
byte globalDelayTime = NUM_LEDS * 30 / 1000 + 1; //it takes 30uS per LED
unsigned long loopStart = millis();


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
  animate = true;
  
  if (commandString == "CustomFunction")
  {
    switch (CustomFunction)
    {
      //Unique functions
      case 33:  ColorWipe();                    break;
      case 34:  CylonBounce();                  break;
      case 37:  TheaterChaseRainbow();          break;
      case 38:  HalloweenEyes();                break;
      case 39:  BouncingColoredBalls();         break;
      case 40:  SnowSparkle();                  break;
      case 41:  RGBLoop();                      break;
      case 42:  Fire();                         break;
      case 44:  RainbowCycle();                 break;
      case 45:  AmericanFlag();                 break;
      case 47:  AmericaLoop();                  break;
      case 48:  AmericaOneColorLoop();          break;
    }
  }
  else if (commandString == "RunFillColor")
    FillColor();
  
  CheckInput();
 
 }

void CheckInput()
{
   if (Serial.available()) {
    receivedString = Serial.readStringUntil('\n');

    animate = false;
    byte c1, c2, c3, c4, c5, c6, c7, c8;  //comma positions
    String orig, part1, part2, part3, part4, part5, part6, part7, part8, theRest; //temp variables for the parts

    orig = receivedString;  //the original received commang, orig is shorter to type
    c1 = orig.indexOf(','); //find location of first comma
    part1 = orig.substring(0, c1); //just the first part, like "Brightness" or "RGB"
    theRest = orig.substring(c1 + 1, orig.length()); //take off the first part
    //Brightness
    if (part1 == "Brightness")
    {
      animate = true; //so that it doesn't restart the animation
      //map it for 1-255
      if(isDigit(theRest.charAt(0)))
      {
        //receive 0-100
        globalBright = byte(theRest.toInt());
        globalBright = map(globalBright,0,100,1,255);
        FastLED.setBrightness(globalBright);  FastLED.show();
      }
     
      
    }
    //Speed
    else if (part1 == "Speed")
    {
      globalSpeed = globalSpeedMax - byte(theRest.toInt());
      animate = true;  //so that it doesn't restart the animation
    }
    //Single color "RGB,255,255,255,ModeNum"
    else if (part1 == "RGB")
    {
      //This mess splits up "RGB,123,0,255,#" into usable numbers.  Accept it.  
      c2 = theRest.indexOf(','); //find location of first comma
      part2 = theRest.substring(0, c2); //split the string from the beginning to the comma
      theRest = theRest.substring(c2 + 1, theRest.length());//index c2+1 otherwise comma in spot 0      
      c3 = theRest.indexOf(',');
      part3 = theRest.substring(0, c3); //g
      theRest = theRest.substring(c3 + 1, theRest.length());
      c4 = theRest.indexOf(',');
      part4 = theRest;

      _r = byte(part2.toInt());//convert "255" into 255 as a byte
      _g = byte(part3.toInt());
      _b = byte(part4.toInt());
      
      // constrain the values to 0 - 255
      _r = constrain(_r, 0, 255);
      _g = constrain(_g, 0, 255);
      _b = constrain(_b, 0, 255);

//      fill_solid(leds, NUM_LEDS, CRGB(red, green, blue));
//      FastLED.show();
//      delay(100);
      //run mode single color with this color
      commandString = "RunFillColor";

    }
    //Custom Function
    else if (part1 == "CustomFunction")
    {
      CustomFunction = byte(theRest.toInt());
      commandString = "CustomFunction";
    }
    else {
      CustomFunction = 0;
      animate = true;
    }
    
  }
  delay(5);
}

void Rest()
{
  while (animate)
  {
    CheckInput();
  }
}

void Rest(int restTime)
{
  loopStart = millis(); //yeah we actually need this here
  while (animate)
  {
    animationTimeout = millis() - loopStart;
    restTimeout = millis() - loopStart;
    CheckInput();
    if (restTimeout > restTime)
      break;
  }
}

//Clear any data in the seraial buffer
void ClearBuffer()
{
  while (Serial.available() > 0) { Serial.read(); }
}
