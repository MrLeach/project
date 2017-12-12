#define REDBUTTON 7
#define TAPBUTTON 8


int redButton = HIGH;
int tapButton = HIGH;
int lastRedButton = HIGH;
int lastTapButton=HIGH;

void InitButtons(){

  pinMode(REDBUTTON, INPUT_PULLUP);
  pinMode(TAPBUTTON, INPUT_PULLUP);
}


bool ButtonsChanged()
{
  if (digitalRead(REDBUTTON) != lastRedButton)
  {
    return true;
  }
  if (digitalRead(TAPBUTTON) != lastTapButton)
  {
    return true;
  }
  return false;
}


bool RedPressed()
{
  return ((lastRedButton = digitalRead(REDBUTTON)) == LOW);
}

bool KnobUp()
{
  return ((lastTapButton = digitalRead(TAPBUTTON)) == LOW);
}

void ButtonStatus()
{
  Serial.print("Red button:");
  Serial.println(digitalRead(REDBUTTON));
  Serial.print("Knob Position:");
  Serial.println(digitalRead(TAPBUTTON)); 
}


