



int currentDialPosition;
int lastDialPosition;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Init();
  Brightness(30);

  InitButtons();

  
}

void loop() {
  
  if (PositionChanged())
  {
    currentDialPosition = ReadDialSetting();
    Serial.print("Value changed: ");
    Serial.println(currentDialPosition);

    if (KnobUp)
    {
    
      SetAllPix(currentDialPosition * 31 ,0, 255 - (currentDialPosition * 31) /2);
    char mask[16];
    for (int i=0; i<16; i++)
    {
      if (currentDialPosition * 2 > i)
      {
        mask[i] = '1';
      }else{
        mask[i] = '0';
      }
    }
    PixMask(mask);
    Show();
    ButtonStatus();
  }
}
