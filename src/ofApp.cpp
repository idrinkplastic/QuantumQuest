#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
        gameStarted = false;

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
