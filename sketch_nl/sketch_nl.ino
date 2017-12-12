



int currentDialPosition;
int lastDialPosition;

typedef void (*DisplayFunction)();
DisplayFunction displayFuncs[9] = {&Display1, &Display2, &Display3, &Display4, &Display5, &Display6, &Display1, &Display7, &Display8};
DisplayFunction selectedDisplayFunc = NULL;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  InitRing();
  Brightness(30);
  InitButtons();
}

void loop() {

  if (PositionChanged())
  {
    currentDialPosition = ReadDialSetting();
    Serial.print("Value changed: ");
    Serial.println(currentDialPosition);

    if (KnobUp())
    {
      // go through the modes
      selectedDisplayFunc = displayFuncs[currentDialPosition];
      selectedDisplayFunc();
    } else {
      SetAllPix(255, 255, 255);
      char mask[16];
      for (int i = 0; i < 16; i++)
      {
        if (currentDialPosition * 2 > i)
        {
          mask[i] = '1';
        } else {
          mask[i] = '0';
        }
      }
      PixMask(mask);
    }
    Show();
    ButtonStatus();

    // schedule a delay, then the current pattern


  }
  if (RedPressed())
  {
    if (selectedDisplayFunc != NULL) selectedDisplayFunc();
  }
}


