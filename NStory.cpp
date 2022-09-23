//------------------------- Includes -------------------------//
//header files
#include "OutputDisplay.h"
#include "InputHandler.h"
#include "NStory.h"
#include "Arduino.h"
//LCD Screen Libraries
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
//C++ Map Library
//#include <ArxContainer.h>

//constructor
NClass::NClass(){ 
  }

   //global variables
  //arrays for story
  const char * paths[] = {"Field","Tree","Forest","Mushroom","Nest","Zipline","Cave","Sharp","Light","Dragon!","death"};
  const char *c1[] = {"Run","Branch","Canopy","Pick","Caw!","Jump","Feel","Calm","Leave","Fight!"};
  const char *c2[] = {"Look", "Knot", "Floor","Taste","Egg","Ride","Torch","Panic!","Further","Fight!"};
  const char  *deaths[] =  {"Rabid Squirrel!","It's Poisonous!","Bird Attack!","Ouch...","Spear Trap!","Unarmed.. Death!"};
  //const char *startAdventure[] = {"Sleep","Wake","You Did it the Dragon is dead!"};
  
  //arrays used to control progression of story
  const char * choices[] = {"Look", "Run", "Knot", "Branch", "Caw!", "Egg", "Floor", "Canopy", "Taste", "Pick", "Jump", "Ride", "Torch", "Feel", "Further", "Leave", "Panic!", "Calm", "Fight!"};
  const char * misc[] = {"Acquired      Mushroom!", "Acquired      Sword!", "You Did it the Dragon is dead!"};
  int keys[] = {1, 2, 11, 4, 0, 11, 3, 5, 11, 2, 11, 6, 8, 7, 9, 0, 11, 6, 11}; 
  //declare variables
  bool continuegame = false;
  bool death = false;
  bool mushroom = false;
  bool sword = false;
  int i = 0;
  int choice = 0;
  

void NClass::SETUP(){
 
}


// main story function
bool NClass::myStory() {
  //initialize variables 
  continuegame = false;
  death = false;
  mushroom = false;
  sword = false;
  i = 0; 
  choice = 0;
  
  //loop through story as long as !death to allow for continuous play
  do {
    //display current choices
    OutPutDisplay.displayStory(paths, c1, c2, i);
    //returns user selection from InClass 
    choice = InputHandler.validateInput();

    //Reads users choice (1 or 2) and determines next path
    //Through comparison of choices array between 
    switch (choice) {
      case 1:
        for (int j = 0; j<19; j++){
          if (c1[i] == choices[j]){
              i = j;
              //Check if selection activates a boolean statement or ends story  
              deathCheck();
              boolCheck();
              i = keys[j]; 
            break;
          }
        }
        Serial.print(i);
        break;
      case 2:
        for (int j = 0; j<19; j++){
          if (c2[i] == choices[j]){
            i = j;
            deathCheck();
            boolCheck();
            i = keys[j];
            break;
          }
        }
        Serial.print(i);   
        break;
    }
    

  } while (!death);
  
    
  return (continuegame);
}

  //Checks if user selection leads to end of story 
void NClass::deathCheck(){ 
  int j = 0;
  
    //cheacks death statements using comparision 
    if (choices[i] == "Knot"){
      j = 0;
      OutPutDisplay.singleDisplay(deaths, j);
      death = true;
    }
    if (choices[i] == "Egg"){
      j = 2;
      OutPutDisplay.singleDisplay(deaths, j);
      death = true;  
    }
    if (choices[i] == "Taste"){
      j = 1;
      OutPutDisplay.singleDisplay(deaths, j);
      death = true;    
    }
    if (choices[i] == "Jump"){
      j = 3;
      OutPutDisplay.singleDisplay(deaths, j);
      death = true; 
    }
    if (choices[i] == "Panic!"){
      j = 4;
      OutPutDisplay.singleDisplay(deaths, j);
      death = true; 
    }
  return;
  }

//Checks if user selection leads to a boolean statement
void NClass::boolCheck(){
  int j = 0;

    //boolean statements using comparison 
    if (choices[i] == "Pick"){
      mushroom = true;
      j = 0;
      OutPutDisplay.singleDisplay(misc, j);
      
    }
    if (choices[i] == "Caw!"){
      if (!mushroom){
        j = 2;
        OutPutDisplay.singleDisplay(deaths, j);
        death = true; //death
      }
      if (mushroom) {
        sword = true;
        j = 1;
        OutPutDisplay.singleDisplay(misc, j);
      }
    }
    if (choices[i] == "Fight!"){
      if (!sword){
        j = 5;
        OutPutDisplay.singleDisplay(deaths, j);
        death = true; //death (end current progression)
      }
      if (sword) {
        continuegame = false;
        j = 2;
        OutPutDisplay.singleDisplay(misc, j);
      }
    }
  
  return;
 }


   //old functions/variables (not implemented) 
  //arx::map<String, int> mp {{"Look", 1}, {"Run", 2}, {"Knot", 11}, {"Branch", 4}, {"Caw!", 0}, {"Egg", 11}, {"Floor", 3}, {"Canopy", 5}, 
                            //{"Taste", 11}, {"Pick", 2}, {"Jump", 11}, {"Ride", 6}, {"Torch", 8}, {"Feel", 7}, {"Further", 9}, {"Leave", 0}, 
                            //{"Panic", 11}, {"Calm", 6}, {"Fight!", 11}};
