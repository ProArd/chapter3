//Example 7-2.1. testapp.cpp
#include "testApp.h"
void testApp::setup() {
  arduino.connect("/dev/ttyUSB0");//remeber! change this to the proper port
  ofAddListener(arduino.EInitialized, this, &testApp::arduinoSetup);
  /*the ofAddListener waits for the Arduino to preform a handshake telling the program that it is ready to be configured and set up. This will call arduinoSetup*/
  isArduinoSet = false;// this flag is set false until the Arduino is setup
}// end void testApp::setup()
void testApp::update() {
  testApp::arduinoLoop();// preform the arduino style code
}// end void testApp::update()
void testApp::draw() {// objects are drawn to the screen in order called
  if (isArduinoSet){ // do not run  this code untill arduino is operating
    ofFill();
    if(pin8 == ARD_HIGH)
      ofSetColor(0,0,255);// if button on pin8 pressed bright the circle
    else
      ofSetColor(0,0,127);// blue is dim if button is released
    ofCircle(50,50,50); //draw circle at (x,y,radius) in pixles for button
    if(pin13 == ARD_HIGH)
      ofSetColor(0,255,0); //when LED is on draw full green
    else
      ofSetColor(0,127,0);// green is dimed when LED is off
    ofCircle(150,50, 50); //draw circle at (x,y,radius) in pixles for LED
    ofSetColor(255,0,0);//set color for anolog potetiomer
                                //draw rectangle with corners at(x1,y1,x2,y2)
    ofRect(0, 45 ,(analogPin0*200) , 10); //rectangle is dynamic on the X-axis
             // anologPin0 is a percentage multiplyed by window width
  } // end if (isArduinoSet)
}//end void testApp::draw()
void testApp::mousePressed(int x, int y, int button) {
    if(ledcomand == true) // if LED is ON
      ledcomand = false ;   // flag the LED to turn OFF
    else //the LED is OFF
      ledcomand = true;// flag the LED to turn ON
}//end testApp::mousePressed
void testApp::arduinoSetup(const int & version) {
  ofRemoveListener(arduino.EInitialized, this, &testApp::arduinoSetup);
  // there is no need to contune to listen for the Arduino clear memory.
  arduino.sendAnalogPinReporting(0, ARD_ANALOG);// turn on anolog pin0
  arduino.sendDigitalPinMode(8, ARD_INPUT);// set digital pin8 as input
  arduino.sendDigitalPinMode(13, ARD_OUTPUT);// set digital pin13 as output
  isArduinoSet = true;// inform the rest of the program that arduino is ready
}//end void testApp::arduinoSetup(
void testApp::arduinoLoop() {
    if (isArduinoSet){ // do not run  this code untill arduino is operating
    pin8 = arduino.getDigital(8);//digial read pin8
    pin13 = arduino.getDigital(13);//digtal read pin13 verifing state
    analogPin0 = arduino.getAnalog(0)/1023.0; // anolog read A0
    arduino.sendDigital(13, ledcomand);//digital write new state
    }// end if (isArduinoSet)
    arduino.update();// get any changes that the Arduino might have
}// end void testApp::arduinoLoop()
