
//#include "Adafruit_NeoPixel.h"

#define DIAL A0

// globals
int dialValue = 0;
int lastSetting = 0;
int currentSetting = 0;

#define POT_SETTINGS 9
int potVoltages[POT_SETTINGS] = { 1019,957,812,623,465,315,144,26,0};

#define DEAD_ZONE 3

/*======================================================================
Function to determine whether the current position of the 
potentiometer has changed since last time it was read
======================================================================*/
bool PositionChanged()
{
  return (GetPotPosition() != lastSetting);
}

/*======================================================================
Function to dreturn the dial setting
======================================================================*/
int ReadDialSetting()
{
  lastSetting = GetPotPosition();
  return lastSetting;
}

/*======================================================================
 Funtion to identify which of the settings the
 potentiometer is closest to, with a dead zone to stop the 
 setting flapping
======================================================================*/
int GetPotPosition()
{
  int setting = 0;
  int currentValue = analogRead(DIAL);
  
  for (int i=0; i<POT_SETTINGS; i++)
  {
    if (currentValue >= potVoltages[i])
    {
      // if this is a change of setting, put in a dead zone
      // so it doesn't flutter
      setting = i;
      if (i == lastSetting +1)
      {
        // if setting is going up, the new reading must 
        // be beyond the boundary of the one it used to be
        // so it must be enough smalled than the last
        // boundary
        if (potVoltages[i -1 ] - currentValue <= DEAD_ZONE) setting = lastSetting;
      }else if (i == lastSetting -1){
        // if the setting is going down, the value
        // is greater than a new boundary, but it must 
        // be greater by enough
        if (currentValue -potVoltages[i]  <= DEAD_ZONE) setting = lastSetting;
      }
      break;
    }
  }

  return setting;
}


