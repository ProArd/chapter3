//Example 7-1.2.  testapp.h
#include "ofMain.h"
class testApp : public ofBaseApp{
  public:
    void setup(); //For setting initial peramiters.
    void update();//the loop
    void draw();// runs after update,this updates & creates the window objects
    void mousePressed(int x, int y, int button);// on event function
    bool SendSerialMessage;// signals that data needs to be sent
    char ledcomand;         // hold what state the LED is in.
    char Returned;          // hold returend char from Arduino
    ofSerial   serial;      // this is the object to handle serial
};// end class testApp : public ofBaseApp
