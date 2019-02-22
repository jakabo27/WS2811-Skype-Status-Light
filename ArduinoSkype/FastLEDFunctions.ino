/*FUNCTIONS SUPPORTED - all use globalSpeed
 * BouncingColoredBalls()
 * RainbowCycle()
 * Fire()
 * ColorWipe()
 * SnowSparkle()
 * TheaterChaseRainbow()
 * RGBLoop()
 * HalloweenEyes()
 * FadeInOut()
 * CylonBounce()
 *
 */

void FillColor()
{
  animate = true;
  while (animate) {
    fill_solid(leds, NUM_LEDS, CRGB(_r, _g, _b));
    FastLED.show();
    FastLED.delay(1000 / FRAMES_PER_SECOND);
    CheckInput();
  }
}

void AmericanFlag()
{
	int firstStep = 20;
	int stepSize = (NUM_LEDS - firstStep) / 20; //split into 13 ish stripes
	while (animate)
	{
		setAll(0, 0, 0);
		for (int i = 0; i < firstStep; i++)
			setPixel(i, 0, 0, 255); //set the first 20ish to blue
		for (int i = firstStep; i < (firstStep + 1 * stepSize); i++)
			setPixel(i, 255, 0, 0); //red group
		for (int i = (firstStep + 1 * stepSize); i < (firstStep + 2 * stepSize); i++)
			setPixel(i, 235, 235, 235);  //white group
		for (int i = (firstStep + 2 * stepSize); i < (firstStep + 3 * stepSize); i++)
			setPixel(i, 255, 0, 0);      //red group
		for (int i = (firstStep + 3 * stepSize); i < (firstStep + 4 * stepSize); i++)
			setPixel(i, 235, 235, 235);  //white group
		for (int i = (firstStep + 4 * stepSize); i < (firstStep + 5 * stepSize); i++)
			setPixel(i, 255, 0, 0);      //red group
		for (int i = (firstStep + 5 * stepSize); i < (firstStep + 6 * stepSize); i++)
			setPixel(i, 235, 235, 235);  //white group
		for (int i = (firstStep + 6 * stepSize); i < (firstStep + 7 * stepSize); i++)
			setPixel(i, 255, 0, 0);      //red group
		for (int i = (firstStep + 7 * stepSize); i < (firstStep + 8 * stepSize); i++)
			setPixel(i, 235, 235, 235);  //white group
		for (int i = (firstStep + 8 * stepSize); i < (firstStep + 9 * stepSize); i++)
			setPixel(i, 255, 0, 0);      //red group
		for (int i = (firstStep + 9 * stepSize); i < (firstStep + 10 * stepSize); i++)
			setPixel(i, 235, 235, 235);  //white group
		for (int i = (firstStep + 10 * stepSize); i < (firstStep + 11 * stepSize); i++)
			setPixel(i, 255, 0, 0);      //red group
		for (int i = (firstStep + 11 * stepSize); i < (firstStep + 12 * stepSize); i++)
			setPixel(i, 235, 235, 235);  //white group
		for (int i = (firstStep + 12 * stepSize); i < (firstStep + 13 * stepSize); i++)
			setPixel(i, 255, 0, 0);      //red group
		for (int i = (firstStep + 13 * stepSize); i < (firstStep + 14 * stepSize); i++)
			setPixel(i, 235, 235, 235);  //white group
		for (int i = (firstStep + 14 * stepSize); i < (firstStep + 15 * stepSize); i++)
			setPixel(i, 255, 0, 0);      //red group
		for (int i = (firstStep + 15 * stepSize); i < (firstStep + 16 * stepSize); i++)
			setPixel(i, 235, 235, 235);  //white group
		for (int i = (firstStep + 16 * stepSize); i < (firstStep + 17 * stepSize); i++)
			setPixel(i, 255, 0, 0);      //red group
		for (int i = (firstStep + 17 * stepSize); i < (firstStep + 18 * stepSize); i++)
			setPixel(i, 235, 235, 235);  //white group
		for (int i = (firstStep + 18 * stepSize); i < (firstStep + 19 * stepSize); i++)
			setPixel(i, 255, 0, 0);      //red group
		for (int i = (firstStep + 19 * stepSize); i < (NUM_LEDS); i++)
			setPixel(i, 235, 235, 235);  //white group
		showStrip(); FastLED.delay(1000 / FRAMES_PER_SECOND); //delay(globalDelayTime);
		CheckInput(); if (!animate) break;
		Rest();
	}
}

void AmericaLoop() {
	setAll(0, 0, 0);
	showStrip();
	delay(globalDelayTime);
	while (animate) {
		for (int j = 0; j < 3; j++) {

			for (int k = 0; k < 256; k += 4) {
				switch (j) {
				case 0:
					for (int i = 0; i < NUM_LEDS / 3; i++)               setPixel(i, 0, 0, k); //blue
					for (int i = NUM_LEDS / 3; i < NUM_LEDS * 2 / 3; i++)  setPixel(i, k, 0, 0); //red
					for (int i = NUM_LEDS * 2 / 3; i < NUM_LEDS; i++)    setPixel(i, k, k, k); //white
					break;
				case 1:
					for (int i = 0; i < NUM_LEDS / 3; i++)               setPixel(i, k, k, k); //white
					for (int i = NUM_LEDS / 3; i < NUM_LEDS * 2 / 3; i++)  setPixel(i, 0, 0, k); //blue
					for (int i = NUM_LEDS * 2 / 3; i < NUM_LEDS; i++)    setPixel(i, k, 0, 0); //red
					break;
				case 2:
					for (int i = 0; i < NUM_LEDS / 3; i++)               setPixel(i, k, 0, 0); //red
					for (int i = NUM_LEDS / 3; i < NUM_LEDS * 2 / 3; i++)  setPixel(i, k, k, k); //white
					for (int i = NUM_LEDS * 2 / 3; i < NUM_LEDS; i++)    setPixel(i, 0, 0, k); //blue
					break;
				}
				showStrip();
				//if(k%25 == 0) {delay(globalDelayTime); CheckInput();if(!animate) { break;}}      
				delay(map(globalSpeed, 0, 50, 1, 20));
				CheckInput(); if (!animate) { break; }
			}
			if (!animate) { break; }
			// Fade OUT
			for (int k = 255; k >= 0; k -= 4) {
				switch (j) {
				case 0:
					for (int i = 0; i < NUM_LEDS / 3; i++)               setPixel(i, 0, 0, k); //blue
					for (int i = NUM_LEDS / 3; i < NUM_LEDS * 2 / 3; i++)  setPixel(i, k, 0, 0); //red
					for (int i = NUM_LEDS * 2 / 3; i < NUM_LEDS; i++)    setPixel(i, k, k, k); //white
					break;
				case 1:
					for (int i = 0; i < NUM_LEDS / 3; i++)               setPixel(i, k, k, k); //white
					for (int i = NUM_LEDS / 3; i < NUM_LEDS * 2 / 3; i++)  setPixel(i, 0, 0, k); //blue
					for (int i = NUM_LEDS * 2 / 3; i < NUM_LEDS; i++)    setPixel(i, k, 0, 0); //red
					break;
				case 2:
					for (int i = 0; i < NUM_LEDS / 3; i++)               setPixel(i, k, 0, 0); //red
					for (int i = NUM_LEDS / 3; i < NUM_LEDS * 2 / 3; i++)  setPixel(i, k, k, k); //white
					for (int i = NUM_LEDS * 2 / 3; i < NUM_LEDS; i++)    setPixel(i, 0, 0, k); //blue
					break;
				}
				showStrip();
				CheckInput(); if (!animate) { break; }
				delay(map(globalSpeed, 0, 50, 1, 20));
			}
			if (!animate) { break; }
		}
		if (!animate) { break; }
	}
}

void AmericaOneColorLoop()
{
  setAll(0, 0, 0);
  showStrip();
  delay(globalDelayTime);
  while (animate) {
    for (int j = 0; j < 3; j++) {

      for (int k = 0; k < 256; k += 4) {
        switch (j) {
        case 0:
          fill_solid(leds, NUM_LEDS, CRGB(0,0,k)); //blue
          break;
        case 1:
          fill_solid(leds, NUM_LEDS, CRGB(k,0,0)); //red
          break;
        case 2:
          fill_solid(leds, NUM_LEDS, CRGB(k,k,k)); //white
          break;
        }
        showStrip();  
        delay(map(globalSpeed, 0, 50, 1, 200));
        CheckInput(); if (!animate) { break; }
      }
      if (!animate) { break; }
      // Fade OUT
      for (int k = 255; k >= 0; k -= 4) {
        switch (j) {
        case 0:
          fill_solid(leds, NUM_LEDS, CRGB(0,0,k)); //blue
          break;
        case 1:
          fill_solid(leds, NUM_LEDS, CRGB(k,0,0)); //red
          break;
        case 2:
          fill_solid(leds, NUM_LEDS, CRGB(k,k,k)); //white
          break;
        }
        showStrip();
        CheckInput(); if (!animate) { break; }
        delay(map(globalSpeed, 0, 50, 1, 200));
      }
      if (!animate) { break; }
    }
    if (!animate) { break; }
  }
}

void FadeInOut() {
	Serial.print("   GlobalSpeed = "); Serial.println(globalSpeed);
	while (animate) {
		float r, g, b;
		for (int k = 0; k < 256; k = k + 4) {
			r = (k / 256.0)*_r;
			g = (k / 256.0)*_g;
			b = (k / 256.0)*_b;
			setAll(r, g, b);
			showStrip();
			CheckInput(); if (!animate) { break; }
			delayMicroseconds(map(globalSpeed, 0, 50, 300, 20000));
		}

		for (int k = 255; k >= 0; k = k - 4) {
			r = (k / 256.0)*_r;
			g = (k / 256.0)*_g;
			b = (k / 256.0)*_b;
			setAll(r, g, b);
			showStrip();
			CheckInput(); if (!animate) { break; }
			delayMicroseconds(map(globalSpeed, 0, 50, 300, 20000));
		}
	}
}

void CylonBounce() {
	byte SpeedDelay, red, green, blue, EyeSize, ReturnDelay;

	while (animate) {
		//different values for every loop through
		red = random(255);
		green = random(255);
		blue = random(255);
		ReturnDelay = random(30, 60);
		EyeSize = random(2, NUM_LEDS/4);

		for (int i = 0; i < NUM_LEDS - EyeSize - 2; i++) {
			setAll(0, 0, 0);
			setPixel(i, red / 10, green / 10, blue / 10);
			for (int j = 1; j <= EyeSize; j++) {
				setPixel(i + j, red, green, blue);
			}
			setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);
			showStrip();

			//delayMicroseconds(map(globalSpeed, 0, 50, 500, 25000));
     delay(map(globalSpeed,0,50,1,200));
			CheckInput(); if (!animate) { break; }
		}
		if (!animate) { break; }

		Rest(ReturnDelay);

		for (int i = NUM_LEDS - EyeSize - 2; i > 0; i--) {
			setAll(0, 0, 0);
			setPixel(i, red / 10, green / 10, blue / 10);
			for (int j = 1; j <= EyeSize; j++) {
				setPixel(i + j, red, green, blue);
			}
			setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);
			showStrip();

			//delayMicroseconds(map(globalSpeed, 0, 50, 500, 25000));
      delay(map(globalSpeed,0,50,1,200));
			CheckInput(); if (!animate) { break; }
		}
		if (!animate) { break; }
		CheckInput();
		if (!animate) { break; }
		Rest(ReturnDelay);

	}
}

void BouncingColoredBalls() {
	float Gravity = -9.81;
	int StartHeight = 1;
	const int BallCount = 3;
	float Height[BallCount];
	float ImpactVelocityStart = sqrt(-2 * Gravity * StartHeight);
	float ImpactVelocity[BallCount];
	float TimeSinceLastBounce[BallCount];
	int   Position[BallCount];
	long  ClockTimeSinceLastBounce[BallCount];
	float Dampening[BallCount];

	while (animate) {
		long endTime2 = millis() + 10000;
		byte colors[][3] = { { random(150,255),random(0,150),random(0,30)},{random(150,255),random(150,255),random(150,255)},{random(50,200),random(0,50),random(175,255)} };

		for (int i = 0; i < BallCount; i++) {
			ClockTimeSinceLastBounce[i] = millis();
			Height[i] = StartHeight;
			Position[i] = 0;
			ImpactVelocity[i] = ImpactVelocityStart;
			TimeSinceLastBounce[i] = 0;
			Dampening[i] = 0.90 - float(i) / pow(BallCount, 2);
		}

		while (millis() < endTime2) {
			for (int i = 0; i < BallCount; i++) {
				TimeSinceLastBounce[i] = millis() - ClockTimeSinceLastBounce[i];
				Height[i] = 0.5 * Gravity * pow(TimeSinceLastBounce[i] / 1000, 2.0) + ImpactVelocity[i] * TimeSinceLastBounce[i] / 1000;

				if (Height[i] < 0) {
					Height[i] = 0;
					ImpactVelocity[i] = Dampening[i] * ImpactVelocity[i];
					ClockTimeSinceLastBounce[i] = millis();

					if (ImpactVelocity[i] < 0.01) {
						ImpactVelocity[i] = ImpactVelocityStart;
					}
				}
				Position[i] = round(Height[i] * (NUM_LEDS - 1) / StartHeight);
				CheckInput(); if (!animate) { break; }
				delay(4);
			}
			if (!animate) { break; }
			for (int i = 0; i < BallCount; i++) {
				setPixel(Position[i], colors[i][0], colors[i][1], colors[i][2]);
			}
			CheckInput(); if (!animate) { break; }
			showStrip();
			setAll(0, 0, 0);
		}
		if (!animate) { break; }
		CheckInput();
	}
}

void RainbowCycle() {
	while (animate) {
		loopStart = millis();
		byte *c;
		uint16_t i, j;

		for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
			for (i = 0; i < NUM_LEDS; i++) {
				c = Wheel(((i * 256 / NUM_LEDS) + j) & 255);
				setPixel(i, *c, *(c + 1), *(c + 2));
			}
			showStrip();
			if (millis() - loopStart > timeToRun)
			{
				delay(globalDelayTime);
				CheckInput();
				loopStart = millis();
			}
			if (!animate) { break; }

			delay(globalSpeed*2);
		}
	}
}
byte * Wheel(byte WheelPos) {
	static byte c[3];

	if (WheelPos < 85) {
		c[0] = WheelPos * 3;
		c[1] = 255 - WheelPos * 3;
		c[2] = 0;
	}
	else if (WheelPos < 170) {
		WheelPos -= 85;
		c[0] = 255 - WheelPos * 3;
		c[1] = 0;
		c[2] = WheelPos * 3;
	}
	else {
		WheelPos -= 170;
		c[0] = 0;
		c[1] = WheelPos * 3;
		c[2] = 255 - WheelPos * 3;
	}

	return c;
}


void Fire() {
	int Cooling = random(40, 70);
	int Sparking = random(100, 140);
	int SpeedDelay = random(3, 7);
	randomSeed(analogRead(0));

	while (animate) {
		static byte heat[NUM_LEDS];
		int cooldown;
		// Step 1.  Cool down every cell a little
		for (int i = 0; i < NUM_LEDS; i++) {
			cooldown = random(0, ((Cooling * 10) / NUM_LEDS) + 2);
			if (cooldown > heat[i]) {
				heat[i] = 0;
			}
			else {
				heat[i] = heat[i] - cooldown;
			}
		}

		// Step 2.  Heat from each cell drifts 'up' and diffuses a little
		for (int k = NUM_LEDS - 1; k >= 2; k--) {
			heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
		}

		// Step 3.  Randomly ignite new 'sparks' near the bottom
		if (random(255) < Sparking) {
			int y = random(7);
			heat[y] = heat[y] + random(160, 255);
			//heat[y] = random(160,255);
		}

		// Step 4.  Convert heat to LED colors
		for (int j = 0; j < NUM_LEDS; j++) {
			SetPixelHeatColor(j, heat[j]);
		}

		showStrip();
		delay(map(globalSpeed, 0, 50, 3, 50));
		CheckInput();
	}
}

void SetPixelHeatColor(int Pixel, byte temperature) {
	// Scale 'heat' down from 0-255 to 0-191
	byte t192 = round((temperature / 255.0) * 191);

	// calculate ramp up from
	byte heatramp = t192 & 0x3F; // 0..63
	heatramp <<= 2; // scale up to 0..252

	// figure out which third of the spectrum we're in:
	if (t192 > 0x80) {                     // hottest
		setPixel(Pixel, 255, 255, heatramp);
	}
	else if (t192 > 0x40) {             // middle
		setPixel(Pixel, 255, heatramp, 0);
	}
	else {                               // coolest
		setPixel(Pixel, heatramp, 0, 0);
	}
}

void ColorWipe() {
	byte red, green, blue, thisIndex;
	randomSeed(analogRead(0));
	while (animate) {
		//red = random(255);
		//green = random(255);
		//blue = random(255);
		thisIndex = random(255);
		for (uint16_t i = 0; i < NUM_LEDS; i++) {
			//setPixel(i, red, green, blue);
			leds[i] = ColorFromPalette(RainbowColors_p, thisIndex, 255, NOBLEND);
			showStrip();
			//delayMicroseconds(map(globalSpeed, 0, 50, 300, 30000));
      delay(map(globalSpeed,0,50,1,200));
			CheckInput(); if (!animate) { break; }
		}
		if (!animate) { break; }
	}
}


void SnowSparkle() {
	byte red = 12;
	byte green = 12;
	byte blue = 20;
	int SpeedDelay, SparkleDelay;

	while (animate) {
		SpeedDelay = random(50, 1500);
		SparkleDelay = random(30, 70);
		setAll(red, green, blue);
		int Pixel = random(NUM_LEDS);
		setPixel(Pixel, 0xff, 0xff, 0xff);
		showStrip();
		CheckInput(); if (!animate) { break; }
		Rest(SparkleDelay);
		setPixel(Pixel, red, green, blue);
		showStrip();
		CheckInput(); if (!animate) { break; }
		Rest(SpeedDelay);
		CheckInput(); if (!animate) { break; }
	}
}


void TheaterChaseRainbow() {
	int SpeedDelay;
	byte tripleOffset = 0;
	byte *c;

	if (NUM_LEDS % 3 == 0) tripleOffset = 0;
	else if (NUM_LEDS % 3 == 1) tripleOffset = 1;
	else if (NUM_LEDS % 3 == 2) tripleOffset = 2;

	while (animate) {
		for (int j = 256; j > 0; j = j - 3) {     // cycle all 256 colors in the wheel
			for (int q = 0; q < 3; q++) {
				for (int i = 0; i < NUM_LEDS - tripleOffset; i = i + 3) {
					c = Wheel((i + j) % 255);
					setPixel(i + q, *c, *(c + 1), *(c + 2));    //turn every third pixel on
				}
				showStrip();

				Rest(map(globalSpeed, 0, 50, 25, 250));
				CheckInput(); if (!animate) { break; }

				for (int i = 0; i < NUM_LEDS - tripleOffset; i = i + 3) {
					setPixel(i + q, 0, 0, 0);        //turn every third pixel off
				}
			}
			if (!animate) { break; }
		}
		if (!animate) { break; }
	}
}

void RGBLoop() {
	while (animate) {
		for (int j = 0; j < 3; j++) {
			// Fade IN
			for (int k = 0; k < 256; k += 4) {
				switch (j) {
				case 0: setAll(k, 0, 0); break;
				case 1: setAll(0, k, 0); break;
				case 2: setAll(0, 0, k); break;
				}
				showStrip();
				CheckInput(); if (!animate) { break; }
				delayMicroseconds(map(globalSpeed, 0, 50, 400, 15000));
			}
			if (!animate) { break; }
			// Fade OUT
			for (int k = 255; k >= 0; k -= 4) {
				switch (j) {
				case 0: setAll(k, 0, 0); break;
				case 1: setAll(0, k, 0); break;
				case 2: setAll(0, 0, k); break;
				}
				showStrip();
				CheckInput(); if (!animate) { break; }
				delayMicroseconds(map(globalSpeed, 0, 50, 400, 15000));
			}
			if (!animate) { break; }
		}
		if (!animate) { break; }
		CheckInput(); if (!animate) { break; }
	}
}
void HalloweenEyes() {
	byte red, green, blue;
	int i, StartPoint, Start2ndEye, EyeWidth, EyeSpace, Steps, FadeDelay, EndPause;
	boolean Fade = true;
	Steps = 24;
	setAll(0, 0, 0);

	while (animate) {
		randomSeed(analogRead(0));
		red = random(255);
		green = random(255);
		blue = random(255);
		EyeWidth = random(5);
		EyeSpace = random(4, 15);
		FadeDelay = map(globalSpeed, 0, 50, 7, 30);
		EndPause = map(globalSpeed, 0, 50, 30, 1000);

		StartPoint = random(0, NUM_LEDS - (2 * EyeWidth) - EyeSpace);
		Start2ndEye = StartPoint + EyeWidth + EyeSpace;

		for (i = 0; i < EyeWidth; i++) {
			setPixel(StartPoint + i, red, green, blue);
			setPixel(Start2ndEye + i, red, green, blue);
		}

		showStrip();
		CheckInput(); if (!animate) { break; }

		if (Fade == true) {
			float r, g, b;

			for (int j = Steps; j >= 0; j--) {
				r = j * (red / Steps);
				g = j * (green / Steps);
				b = j * (blue / Steps);

				for (i = 0; i < EyeWidth; i++) {
					setPixel(StartPoint + i, r, g, b);
					setPixel(Start2ndEye + i, r, g, b);
				}

				showStrip();
				Rest(FadeDelay);
				CheckInput(); if (!animate) { break; }
			}
		}

		setAll(0, 0, 0); // Set all black
		Rest(EndPause);
		CheckInput(); if (!animate) { break; }

	}
}

void showStrip() {
	FastLED.show();
}
void setPixel(int Pixel, byte red, byte green, byte blue) {
	// FastLED
	leds[Pixel].r = red;
	leds[Pixel].g = green;
	leds[Pixel].b = blue;
}
void setAll(byte red, byte green, byte blue) {
	for (int i = 0; i < NUM_LEDS; i++) {
		setPixel(i, red, green, blue);
	}
}
