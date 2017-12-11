#include "Adafruit_NeoPixel.h"

#define PIN 6


// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);


void Init()
{
  strip.begin();
}

void Brightness(int val)
{
  strip.setBrightness(val);

}

void Show()
{
  strip.show();
}


void SetPix( uint16_t position, int r, int g, int b)
{
  strip.setPixelColor(position, strip.Color(r,g,b));
}

void SetAllPix(int r, int g, int b)
{
  for(uint16_t i=0; i<strip.numPixels(); i++)
  {
    SetPix(i, r,g,b);
  }
}

void PixMask(char* mask)
{
  for (int i = 0; i < strlen(mask); i++){
    if (mask[i] == '0') SetPix(i,0,0,0);
  }
}

void SetPixMask(int setting, char* mask)
{
  for (int i=0; i<strlen(mask); i++)
  {
    if (i < setting * 2){
        mask[i] = '1';
    }else{
         mask[i] = '1';
    }
  }
}
