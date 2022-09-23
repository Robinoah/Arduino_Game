//------------------------- Includes -------------------------//
//LCD Screen Libraries
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
//C++ Map Library
#include <ArxContainer.h>
//Header Files for the C++ project classes
#include "OutputDisplay.h"
#include "InputHandler.h"
#include "NStory.h"


//----------------- Setup -----------------------------------//
void setup () {
  
  Serial.begin(9600);
  //Call SETUP() Functions 
  OutPutDisplay.SETUP();
  //InputHandler.SETUP(); *poopoopeepee*
}

//-------------- Main ---------------------------------//
void loop() {
  //declare boolean control
  bool bootgame = true;
  char restart[] = "** RESTARTING! ***";

  do {
    
     bootgame = OutPutDisplay.story();

     if (bootgame) {
       //cout << "\n** RESTARTING! ***\n";
     }

     } while (bootgame);

    exit(0);
}
