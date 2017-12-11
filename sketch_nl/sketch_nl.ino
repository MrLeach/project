#include <Adafruit_NeoPixel.h>

int currentDialPosition;
int lastDialPosition;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (PositionChanged())
  {
    currentDialPosition = ReadDialSetting();
    Serial.print("Value changed: ");
    Serial.println(currentDialPosition);
  }
  

}
