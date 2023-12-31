#pragma once

#include "menustate.h"
#include "gamestate.h"
#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {

    bool wPressed;
    bool aPressed;
    bool dPressed;



public:
    // game states
    enum GameState {
        MENU,
        GAME,
    } gameState;

    ofApp() : wPressed(false), aPressed(false), dPressed(false) {}

    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);




private:
    menuState menu;
    class gameState game;
};
