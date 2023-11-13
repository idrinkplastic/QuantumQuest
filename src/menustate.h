#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "ofMain.h"
#include "ofxGui.h"

class ofApp;

class menuState {
public:
    menuState();
    void setup(ofApp* app);
    void update();
    void draw();

    int playerScore;


    void volumeSliderChanged(int &value);
    void volumeTogglePressed(bool &value);
    bool gameStarted;
private:
    ofImage menuImage;
    //menu music
    ofSoundPlayer menuMusic;
    ofxIntSlider volumeSlider;
    ofxToggle volumetoggle;

    //gui
    ofxPanel gui;
    ofxButton startButton;
    ofxButton endButton;
    ofxLabel scoreLabel;



    void startButtonPressed();
    void endButtonPressed();

    ofApp* app;


};

#endif // MENUSTATE_H
