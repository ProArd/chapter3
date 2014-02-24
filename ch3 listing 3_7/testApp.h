//Example 7-3.0. testapp.h : Expand on the idea
#include "ofMain.h"
#include "ofEvents.h"
class testApp : public ofBaseApp {
  public:
    void setup();
    void update();
    void draw();
    void arduinoSetup(const int & version);//Arduino equivalent setup function
    void arduinoLoop();// Arduino equivalent loop function
    bool pin13; // pin13 data container
    bool pin8; // pin8 data container
    float analogPin0; // pin8 data container
    bool isArduinoSet;// flag to know when Arduino is conected and configured
    ofArduino arduino; // the Arduino object
}; // end class testApp : public ofBaseApp

