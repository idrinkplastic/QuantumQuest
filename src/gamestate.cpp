#include "gamestate.h"
#include "ofApp.h"

gameState::gameState(){
    //var
    ofImage backgroundImage;
    scrollingSpeed = 5;
    backgroundImage.load("gamescrollbackground.jpg");
    backgroundX = 0;
}

void gameState::setup(ofApp* app){

}

void gameState::update(){
 cout << "Game State Update" << endl;
}

void gameState::draw(){
    cout << "Game State is active!" << endl;
    ofImage backgroundImage;
    backgroundImage.load("gamescrollbackground.jpg");
    backgroundImage.draw(0, 0, ofGetWidth(), ofGetHeight());
}
