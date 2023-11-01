#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
        gameStarted = false;



    //Gui
        //SettingUpGuiElem
        startButton.setup("Start Game", 562, 650);
        soundToggle.setup("Sound On/Off", true, 500, 600);
        volumeSlider.setup("Volume", 20, 200, 200, 100, 400);

        // Label init parameter for score
        ofParameter<string> scoreParam;
        scoreParam.set("Score", "0");
        scoreLabel.setup(scoreParam, 100, 100);

        //Event Listeners for Gui
        startButton.addListener(this, &ofApp::startButtonPressed);
        soundToggle.addListener(this, &ofApp::soundToggleChanged);

}
void ofApp::startButtonPressed() {
    // Handle the Start Game button click
    gameStarted = true;
}
void ofApp::soundToggleChanged(bool &value) {
    // Handle the Sound On/Off toggle state change
    isSoundOn = value;
}
//--------------------------------------------------------------
void ofApp::update(){
    scoreLabel.getParameter().cast<string>() = "Score: " + ofToString(playerScore);

}
//--------------------------------------------------------------

void ofApp::draw(){
     //drawing gui
        startButton.draw();
        soundToggle.draw();
        volumeSlider.draw();
        scoreLabel.draw();

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
