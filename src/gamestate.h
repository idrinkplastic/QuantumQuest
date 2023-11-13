#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "ofMain.h"
#include "ofxGui.h"

class ofApp;
class menuState;

class gameState {
public:
    gameState();
    void setup(ofApp* app);
    void update();
    void draw();
    bool gameStarted;
private:
    ofImage scrollingBackground;
    ofSoundPlayer gameMusic;
    void endButtonPressed();

    float scrollingSpeed;
    float backgroundX;

    ofApp* app;

};


#endif // GAMESTATE_H
