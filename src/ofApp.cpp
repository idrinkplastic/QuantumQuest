#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
        gameStarted = false;
        gameState = MENU;
    //TitleScreen
        menuImage.load("titlescreen.png");


    //Menu music
        menuMusic.load("MenuMusic.mp3");
        menuMusic.setVolume(0.5);
        menuMusic.play();

        volumeSlider.addListener(this, &ofApp::volumeSliderChanged);
        volumetoggle.addListener(this, &ofApp::volumeTogglePressed);
    //Gui
        gui.setup();

        gui.add(volumeSlider.setup("Volume Slider", 50, 0, 100));

        gui.add(volumetoggle.setup("Volume Toggle", false));

        gui.add(startButton.setup("Begin."));

        gui.add(scoreLabel.setup("Player Score", "0"));


    //guiend
        endButton.setup("End Game");
        endButton.addListener(this, &ofApp::endButtonPressed);
        endButton.setVisible(false);


}
//--------------------------------------------------------------
void ofApp::startButtonPressed() {
    // Handle the Start Game button click
    gameState = GAME; // Change the game state to GAME

}

//--------------------------------------------------------------
void ofApp::volumeSliderChanged(int &value) {
    float volume = ofMap(value, 0, 100, 0.0, 1.0); // Map slider value to a volume range
    menuMusic.setVolume(volume); // Set the volume of the menu music
}
//--------------------------------------------------------------
void ofApp::volumeTogglePressed(bool &value) {
    if (value) {
        // Turn the sound on
        menuMusic.setVolume(1.0);
    } else {
        // Mute the sound
        menuMusic.setVolume(0.0);
    }
}
//--------------------------------------------------------------
void ofApp::update(){
    scoreLabel.getParameter().cast<string>()= "Player Score: " + ofToString(playerScore);

}
//--------------------------------------------------------------

void ofApp::draw(){

    ofBackground(0);
    int windowWidth = ofGetWidth();
    int windowHeight = ofGetHeight();
    menuImage.draw(0,0, windowWidth, windowHeight);

     //drawing gui
    gui.draw();

    if (gameState == MENU){
        menuImage.draw(0,0,windowWidth, windowHeight);
        gui.draw();
    } else if (gameState == GAME){

    }

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
//--------------------------------------------------------------

//Game State Menu:
//Create Menu
//Create StartButton
//Create Volume Sliders and Button
//Create Options Button
//Create different game state files
//Create Exit button
//Animated intro into game (not prio)
//Gif Menu (not prio)


//Game State Game:
//Try out the states after completing that to a different scene just coloured for now
//Scrolling background for a level (not prio)
//Start creating obstacles
//Start creating player
//Create classes for each game state
