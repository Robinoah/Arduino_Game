//------------------------- Includes -------------------------//
//header files
#include "OutputDisplay.h"
#include "InputHandler.h"
#include "NStory.h"
#include "Arduino.h"
//LCD Screen Libraries
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>


// Declare LCD object for software SPI
// Adafruit_PCD8544(CLK,DIN,D/C,CE,RST);
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

//constructor
OutClass::OutClass(){
  }

void OutClass::SETUP(){

  //Initialize Display, set contrast, clear buffer  
  display.begin();
  display.setContrast(50);
  display.clearDisplay();

  // Display Team Logo
  display.setTextSize(0.5);
  display.setTextColor(BLACK);
  display.setCursor(0,16);
  display.println("Blue Team     Prototype #3.1");
  display.display();
  delay(1500);
  display.clearDisplay();
  
}

bool OutClass::story() {
  bool continuegame = true;
  
  do{ 

     
    continuegame = NStory.myStory();
    
    } while (continuegame);

  continuegame = true;

  return (continuegame);
}


void OutClass::arrowBlink(int moveBtnCount){
    //Moving, Blinking, Selection Arrow
    if (moveBtnCount == 1) {
      display.setCursor(0,24);
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.write(16);
      display.display();
      display.setCursor(0,12);
      display.setTextSize(1);
      display.setTextColor(BLACK);
      display.write(16);
      display.display();
    } 
    else if (moveBtnCount == 2){
      display.setCursor(0,12);
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.write(16);
      display.display();
      display.setCursor(0,24);
      display.setTextSize(1);
      display.setTextColor(BLACK);
      display.write(16);
      display.display();
    }
}

void OutClass::displayStory(const char * paths [11],const char * c1[10], const char * c2[10], int i){
    display.clearDisplay();
    //Start Screen
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0,0);
    display.println(paths[i]);
    display.display();
    //option One
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(8,12);
    display.println(c1[i]);
    display.display();
    //option Two
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(8,24);
    display.println(c2[i]);
    display.display();
  
  }
