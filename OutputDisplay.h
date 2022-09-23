
#ifndef OUTPUTDISPLAY_H
#define OUTPUTDISPLAY_H



class OutClass 
{
  public: 
    OutClass();
    void SETUP();
    bool story();
    void arrowBlink(int moveBtnCount);
    void displayStory(const char * paths [11], const char * c1[10], const char * c2[10], int i);
    void singleDisplay(const char * relevantmsg[], int j);
    
};

extern OutClass OutPutDisplay;

#endif
