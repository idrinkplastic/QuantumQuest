#pragma once

#include "ofMain.h"
#include "ofxGui.h" 

class ofApp : public ofBaseApp{

    //gui


    ofxPanel gui;

    ofxIntSlider volumeSlider;
    ofxToggle volumetoggle;
    ofxButton startButton;
    ofxLabel scoreLabel;

    ofImage menuImage;

    int playerScore;

    void startButtonPressed();
    void soundToggleChanged(bool &value);

    bool gameStarted;
    bool isSoundOn;


    //menu music
    ofSoundPlayer menuMusic;
    void volumeSliderChanged(int &value);
    void volumeTogglePressed(bool &value);

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);



};
