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
#include <ArxContainer.h>

//constructor
NClass::NClass(){ 
  }

void NClass::SETUP(){
 
}


// main story function
bool NClass::myStory() {


  //arrays/hashmap for story
  const char * paths[] = {"Field","Tree","Forest","Mushroom","Nest","Zipline","Cave","Sharp","Light","Dragon!","death"};
  const char *c1[] = {"Run","Branch","Canopy","Pick","Caw!","Jump","Feel","Calm","Leave","Fight!"};
  const char *c2[] = {"Look", "Knot", "Floor","Taste","Egg","Ride","Torch","Panic!","Further","Fight!"};
  const char  *deaths[] =  {"Rabid Squirrel Attack!","It's Poisonous!","Bird Attack!","Ouch...","Spear Trap!","Should've Brought a Sword"};
  const char *startAdventure[] = {"Sleep","Wake","You Did it the Dragon is dead!"};
  
  //arrays used to control progression of story
  const char * choices[] = {"Look", "Run", "Knot", "Branch", "Caw!", "Egg", "Floor", "Canopy", "Taste", "Pick", "Jump", "Ride", "Torch", "Feel", "Further", "Leave", "Panic", "Calm", "Fight!"}; 
  int keys[] = {1, 2, 11, 4, 0, 11, 3, 5, 11, 2, 11, 6, 8, 7, 9, 0, 11, 6, 11};
  
  //declare variables
  bool continuegame = false;
  bool death = false;
  bool mushroom = false;
  bool sword = false;
  unsigned int i = 0;
  int choice = 0;
  
  do {
    //display current choices
    OutPutDisplay.displayStory(paths, c1, c2, i);
    choice = InputHandler.validateInput();

    switch (choice) {
      case 1:
        for (int j = 0; j<19; j++){
          if (c1[i] == choices[j]){
            i = keys[j];
            break;
          }
        }
        Serial.print(i);
        break;
      case 2:
        for (int j = 0; j<19; j++){
          if (c2[i] == choices[j]){
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


    //old functions/variables
  //arx::map<String, int> mp {{"Look", 1}, {"Run", 2}, {"Knot", 11}, {"Branch", 4}, {"Caw!", 0}, {"Egg", 11}, {"Floor", 3}, {"Canopy", 5}, 
                            //{"Taste", 11}, {"Pick", 2}, {"Jump", 11}, {"Ride", 6}, {"Torch", 8}, {"Feel", 7}, {"Further", 9}, {"Leave", 0}, 
                            //{"Panic", 11}, {"Calm", 6}, {"Fight!", 11}};
