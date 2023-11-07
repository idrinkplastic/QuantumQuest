#include "ofApp.h"
#include "menustate.h"

// this kicks off the running of my app
// can be OF_WINDOW or OF_FULLSCREEN
// pass in width and height too:
//========================================================================
int main( ){
    ofSetupOpenGL(1024,768,OF_FULLSCREEN);			// <-------- setup the GL context
    ofApp app;
    menuState menu(&app); //Instance of menu state

    menu.setup(&app);//call the setup
    ofRunApp(&app); //run ofapp instance
    return 0;
}
