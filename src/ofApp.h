#pragma once

#include "ofMain.h"
#include "ofxGui.h" //Includes GUI library

class ofApp : public ofBaseApp{

    //gui
    ofxButton startButton;
    ofxToggle soundToggle;
    ofxSlider<int> volumeSlider;
    ofxLabel scoreLabel;

    int playerScore;

    void startButtonPressed();
    void soundToggleChanged(bool &value);

    bool gameStarted;
    bool isSoundOn;

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
