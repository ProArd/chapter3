//Example 7-1.3. testapp.cpp
#include "testApp.h"
void testApp::setup(){
  ofSetVerticalSync(true);    // helps to smoothe out object drawing
  ofBackground(255,255,255);  // set background color to an RGB value
  serial.setup("/dev/ttyUSB0", 9600); // change "COM4" to match where the Arduino is
  ledcomand = 's';            // set inital state of the LED
  serial.writeByte(ledcomand);// tell Arduino of the inital state
  SendSerialMessage = false; // nothing to send yet
} //end void testApp::setup()
void testApp::update(){
  if (SendSerialMessage) // is there serial information that needs to be sent
   serial.writeByte(ledcomand); // tell the arduino to change LED state
  if (serial.available())       // check to see if there is incoming data
    Returned = serial.readByte(); // save the incoming data
  SendSerialMessage = false; // reset the need to send data to the arduino
}//end testApp::update
void testApp::draw(){    // defines placement and draws objects in the window
  ofFill();                   // fills geometry with a solid color
    if (Returned == 'h')  // is the button on the arduino being pressed
      ofSetColor(0,0,255);    // set the first circle color to full blue
    else                      // the button is not pressd or state not known
      ofSetColor(0,0,127);    // set the first circle color to 1/2 blue
  ofCircle(50,50, 50);      // draw the first circle at last set color
    if (ledcomand == 'a')  // should the LED be on
      ofSetColor(0,255,0); // set color to full green for the second circle
    else                   // LED should be off or not known
      ofSetColor(0,127,0); // set color to 1/2 green for the second circle
   ofCircle(150,50, 50);   // draw the second circle at last set color
} //end void testApp::draw()
void testApp::mousePressed(int x, int y, int button){
  SendSerialMessage = true; //inform update function ther is data to send
  if(ledcomand == 'a') // if the LED is ON
    ledcomand = 's';   // change LED to be OFF
  else                 // if the LED is OFF
    ledcomand = 'a';   // change LED to be ON
}//end testApp::mousePressed
