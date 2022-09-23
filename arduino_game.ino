//------------------------- Includes -------------------------//
//LCD Screen Libraries
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
//C++ Map Library
//#include <ArxContainer.h>
//Header Files for the C++ project classes
#include "OutputDisplay.h"
#include "InputHandler.h"
#include "NStory.h"


//----------------- Setup -----------------------------------//
void setup () {
  //set bitrate 
  Serial.begin(9600);
  //Call SETUP() Functions 
  //Initialize screen object 
  OutPutDisplay.SETUP();
  //InputHandler.SETUP(); 
}

//-------------- Main ---------------------------------//
void loop() {
  //declare and intialize variables
  bool bootgame = true;
  char * restart[] = {"** RESTARTING! ***"};

  do {
  
     //call story function from OutClass to begin story 
     bootgame = OutPutDisplay.story();

     if (bootgame) {
       int j = 0;
       //call output Function from OutClass to display restart message
       OutPutDisplay.singleDisplay(restart, j);
     }

     } while (bootgame);

    exit(0);
}
