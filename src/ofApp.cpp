#include "ofApp.h"
#include "menustate.h"
#include "gamestate.h"

//--------------------------------------------------------------
void ofApp::setup(){
    menu.setup(this);
    gameState = MENU;
}

//--------------------------------------------------------------
void ofApp::update() {
    switch (gameState) {
        case MENU:
            menu.update();
            if (menu.gameStarted) {
                gameState = GAME; // Transition to the GAME state
                game.setup(this); // Initialize the game state
            }
            break;
    case GAME:
        game.update();
                break;
    }
}
//--------------------------------------------------------------

void ofApp::draw(){
    switch(gameState){
    case MENU:
        menu.draw();
        break;
    case GAME:
        game.draw();
        break;
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (gameState == GAME){
        switch (key) {
            case 'w':
                wPressed = true;

                if (aPressed) {
                    game.player.move(UP_LEFT);
                    wPressed = false;
                } else if (dPressed) {
                    game.player.move(UP_RIGHT);
                    wPressed = false;
                } else {
                    game.player.move(UP);
                }
                break;
            case 'a':
                aPressed = true;

                if (wPressed) {
                    game.player.move(UP_LEFT);
                    aPressed = false;
                } else {
                    game.player.move(LEFT);
                }
                break;
            case 'd':
                dPressed = true;

                if (wPressed) {
                    game.player.move(UP_RIGHT);
                    dPressed = false;
                } else {
                    game.player.move(RIGHT);
                }
                break;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if (gameState == GAME){
        switch (key){
        case 'w':
            wPressed = false;
            break;
        case 'a':
            aPressed = false;
            break;
        case 'd':
            dPressed = false;
            break;
        }
    }

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

