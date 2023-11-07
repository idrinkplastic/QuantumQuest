#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "ofMain.h"
#include "ofxGui.h"


#pragma once

class ofApp;

class menuState {

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

public:
    menuState(ofApp* app);
    int playerScore;

    void setup(ofApp* app);
    void update(ofApp* app);
    void draw(ofApp* app);

    void volumeSliderChanged(int &value);
    void volumeTogglePressed(bool &value);

    bool gameStarted;
};

#endif // MENUSTATE_H
