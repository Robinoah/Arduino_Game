//------------------------- Includes -------------------------//
//header files
#include "OutputDisplay.h"
#include "InputHandler.h"
#include "NStory.h"
#include "Arduino.h"

//LCD Screen Libraries
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

  //global variables
  const int btnSelect = 11;
  const int btnMove = 10;
  boolean buttonMove; 
  boolean buttonSelect;

InClass::InClass(){

}

void InClass::SETUP(){

}
 

//exception check function to be called when handling user input 
static int InClass::validateInput () {
  
  int moveBtnCount = 1;
  int selectBtnCount = 0;

  OutPutDisplay.arrowBlink(moveBtnCount);
  //loop allows for user input to be read (returns input)
  while (selectBtnCount < 1) {
    buttonMove = digitalRead(btnMove);
    buttonSelect = digitalRead(btnSelect);
    delay(100);
    if (buttonMove == HIGH){
      moveBtnCount = moveBtnCount + 1;
      Serial.println(moveBtnCount);
      //changes position of selection arrow
      OutPutDisplay.arrowBlink(moveBtnCount);
    }
    if(buttonSelect == HIGH) {
      if(moveBtnCount == 0){
        selectBtnCount = 2;
        Serial.println(selectBtnCount);
        return selectBtnCount;
      }
      else{
        selectBtnCount = 1;
        Serial.println(selectBtnCount);
        return selectBtnCount;
      }
    }
    
    if (moveBtnCount == 2) {
        moveBtnCount = 0;
    }
  } 
  
  return selectBtnCount;
}
