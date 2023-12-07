#include "menustate.h"
#include "ofApp.h"

menuState::menuState(){

}

void menuState::setup(ofApp* app){
    this->app = app;
    gameStarted = false;

    //TitleScreen
    app->gameState = ofApp::MENU;
    this->menuImage.load("titlescreen.png"); //menu image

    //Menu Music
    if (menuMusic.load("MenuMusic.mp3")){
    menuMusic.setVolume(0.5);
    menuMusic.play();
    menuMusic.setLoop(true);
    }else{
        cout << "Error loading music file!" << endl;

    }


    volumeSlider.addListener(this, &menuState::volumeSliderChanged);
    volumetoggle.addListener(this, &menuState::volumeTogglePressed);

    // GUI MENU
    gui.setup();

    gui.add(volumeSlider.setup("Volume Slider", 50, 0, 100));

    gui.add(volumetoggle.setup("Volume Toggle", false));

    gui.add(startButton.setup("Begin."));

    gui.add(scoreLabel.setup("Player Score", "0"));


    startButton.addListener(this, &menuState::startButtonPressed);

}




void menuState::update(){


}


void menuState::draw(){

    ofBackground(0);
    int windowWidth = ofGetWidth();
    int windowHeight = ofGetHeight();
    menuImage.draw(0,0, windowWidth, windowHeight);
    gui.draw();

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

void menuState::startButtonPressed(){
    gameStarted = true;


}
