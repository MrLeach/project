



int currentDialPosition;
int lastDialPosition;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Init();
  Brightness(30);
  
}

void loop() {
  
  if (PositionChanged())
  {
    currentDialPosition = ReadDialSetting();
    Serial.print("Value changed: ");
    Serial.println(currentDialPosition);
    SetAllPix(currentDialPosition * 31 ,0, 255 - (currentDialPosition * 31) /2);
    Show();
  }
}
