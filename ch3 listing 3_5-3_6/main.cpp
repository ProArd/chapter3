//Example 7-1.1. main.cpp

#include "ofMain.h"           // include files
#include "testApp.h"          // declarations for the testapp class
#include "ofAppGlutWindow.h"  // for using open gl and creating windows

int main(){
  ofAppGlutWindow window; // sets up an opengl window object
    ofSetupOpenGL(&window, 200,100, OF_WINDOW);//sets window size in pixels
	ofRunApp( new testApp());//create testapp object & enter program loop
} //end int main()
