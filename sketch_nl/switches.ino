#define REDBUTTON 7
#define TAPBUTTON 8


int redButton = HIGH;
int tapButton = HIGH;

void InitButtons(){

  pinMode(REDBUTTON, INPUT_PULLUP);
  pinMode(TAPBUTTON, INPUT_PULLUP);
}


void RedPressed()
{
  return (digitalRead(REDBUTTON) == LOW);
}

void KnobUp()
{
  return (digitalRead(TAPBUTTON) == LOW);
}

void ButtonStatus()
{
  Serial.print("Red button:");
  Serial.println(digitalRead(REDBUTTON));
  Serial.print("Knob Position:");
  Serial.println(digitalRead(TAPBUTTON)); 
}


