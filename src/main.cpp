#include "ofApp.h"
#include "menustate.h"

// this kicks off the running of my app
// can be OF_WINDOW or OF_FULLSCREEN
// pass in width and height too:
//========================================================================
int main() {
    ofSetupOpenGL(1920, 1080, OF_WINDOW);
    ofRunApp(new ofApp());
}
