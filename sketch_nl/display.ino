

bool Delay(int delayMs)
{
  // do a delay, but check for things being pressed/turned and exit if they are
  long startTime = millis();
  long endTime = startTime + delayMs;

  while (millis() <= endTime)
  {
    delay(100);
    if (PositionChanged()) return false;
    if (ButtonsChanged()) return false;
  }
  return true;
}

void Flash(int r, int g, int b)
{
  while (true) {
    SetAllPix(r, g, b);
    Show();
    if (!Delay(1000)) return;
    SetAllPix(0, 0, 0);
    Show();
    if (!Delay(1000)) return;
  }
}
void Display1() {
  Flash(255, 0, 0);
}
void Display2() {
  Flash(255, 0, 0);
}
void Display3() {
  Flash(0, 255, 0);
}
void Display4() {
  Flash(0, 0, 255);
}
void Display5() {
  Flash(255, 255, 0);
}
void Display6() {
  Flash(255, 0, 255);
}
void Display7() {
  Flash(0, 255, 255);
}
void Display8() {
  Flash(255, 255, 255);
}
/*
  void Display1()
  {
  // circle round the board lighting up pixels
  // then change colour and continue

  while (true)
  {
    int r = random(0, 255);
    int g = random(0, 255);
    int b = random(0, 255);
    SetAllPix(r, g, b);
    char mask[16];
    for (int i = 0; i < 16; i++)
    {
      for (int c = 0; c < 16; c++)
      {
        if (c <= i)
        {
          mask[c] = '1';
        } else {
          mask[c] = '0';
        }
      }
    }
    PixMask(mask);
    Show();
    if (!Delay(1000)) break;

  }


  }
*/

