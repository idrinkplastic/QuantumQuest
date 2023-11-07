#include "menustate.h"
#include "ofApp.h"


void menuState::setup(ofApp* app) {
    this -> app = app;
    gameStarted = false;
    //TitleScreen
    app->gameState = ofApp::MENU;
    menuImage.load("titlescreen.png"); //menu image

    //Menu Music
    menuMusic.load("MenuMusic.mp3");
    menuMusic.setVolume(0.5);
    menuMusic.play();

    volumeSlider.addListener(this, &::menuState::volumeSliderChanged);
    volumetoggle.addListener(this, &::menuState::volumeTogglePressed);

    //GUI MENU
    gui.setup();

    gui.add(volumeSlider.setup("Volume Slider", 50, 0, 100));

    gui.add(volumetoggle.setup("Volume Toggle", false));

    gui.add(startButton.setup("Begin."));

    gui.add(scoreLabel.setup("Player Score", "0"));


}

void menuState::draw(ofApp* app){
    ofBackground(0);
    int windowWidth = ofGetWidth();
    int windowHeight = ofGetHeight();
    menuImage.draw(0,0, windowWidth, windowHeight);

}


void menuState::volumeTogglePressed(bool &value) {
    if (value) {
        // Turn the sound on
        menuMusic.setVolume(1.0);
    } else {
        // Mute the sound
        menuMusic.setVolume(0.0);
    }
}

void menuState::volumeSliderChanged(int &value) {
    float volume = ofMap(value, 0, 100, 0.0, 1.0); // Map slider value to a volume range
    menuMusic.setVolume(volume); // Set the volume of the menu music
}
