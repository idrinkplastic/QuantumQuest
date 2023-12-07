#include "gamestate.h"
#include "ofApp.h"
#include <vector>
#include "ofxGui.h"

//CORE
gameState::gameState() {
    scrollingSpeed = 5;
    backgroundImage.load("gamescrollbackground.jpg");
    backgroundX = 0;

    platforms = std::vector<Platform>();

    showOptionsPanel = false;

}

void gameState::setup(ofApp* app) {
    cout << "Game state setup called" << endl;
    this->app = app;
    generateInitialPlatforms();
    populatePlatforms();
    tutorialScreen.load("tutorialscreen.png");


    float middleX = ofGetWidth() * 0.5;

    float platformY = platforms[0].y;
    float abovePlatformY = platformY - 120;

    player.setup(middleX, abovePlatformY, *this);

    leftBoundary = ofGetWidth() * 0.3;
    rightBoundary = ofGetWidth() * 0.7;

    //options

    optionsPanel.setup("Options");
    optionsPanel.setPosition(960, 590);

    soundVolumeSlider.setup("Sound Volume", 0.0, 0.0, 1.0);
    optionsPanel.add(&soundVolumeSlider);
    gameMusic.setVolume(soundVolumeSlider);

    screenWidthSlider.setup("Screen Width", ofGetWidth(), 800, 1920);
    optionsPanel.add(&screenWidthSlider);

    screenHeightSlider.setup("Screen Height", ofGetHeight(), 600, 1080);
    optionsPanel.add(&screenHeightSlider);

    exitButton.setup("Exit");
    exitButton.addListener(this, &gameState::exitButtonPressed);
    optionsPanel.add(&exitButton);

}

void gameState::update() {
    player.update();

    cameraX = player.getX() - ofGetWidth() / 2;
    cameraY = player.getY() - ofGetHeight() / 2;

    // Adjust the boundaries to allow the character to move freely
    if (getPlayerX() > rightBoundary - ofGetWidth() * 0.3) {
        float newPlatformX = rightBoundary + 200; // Place the new platform 200 units to the right
        float newPlatformY = ofRandom(50, ofGetHeight() - 100); // Random Y position between 50 and height-100
        float newPlatformWidth = 150; // constant width
        float newPlatformHeight = 20; // constant height

        platforms.push_back(Platform(newPlatformX, newPlatformY, newPlatformWidth, newPlatformHeight));

        rightBoundary = newPlatformX + newPlatformWidth; // Update the right boundary
    } else if (getPlayerX() < leftBoundary) {
        float newPlatformX = leftBoundary - 200;
        float newPlatformY = ofRandom(50, ofGetHeight() - 100);
        float newPlatformWidth = 150;
        float newPlatformHeight = 20;

        platforms.push_back(Platform(newPlatformX, newPlatformY, newPlatformWidth, newPlatformHeight));

        leftBoundary = newPlatformX; // Update the left boundary
    }

    if (ofGetKeyPressed(OF_KEY_F1)) {
            showOptionsPanel = !showOptionsPanel;
        }

    gameMusic.setVolume(soundVolumeSlider);

    if (screenWidthSlider != ofGetWidth() || screenHeightSlider != ofGetHeight()) {
            ofSetWindowShape(screenWidthSlider, screenHeightSlider);
        }

}

void gameState::draw() {
    ofPushMatrix();
    ofTranslate(-cameraX, -cameraY);

    cout << "Drawing Background" << endl;

    int numBackgrounds = ceil((float) ofGetWidth() / backgroundImage.getWidth()) + 1;
    ofSetColor(255); // Set color back to default (white)
    for (int i = 0; i < numBackgrounds; ++i) {
        float xPos = i * backgroundImage.getWidth();
        backgroundImage.draw(xPos, 0, backgroundImage.getWidth(), ofGetHeight());
    }

    // Draw tutorial screen image to the left of the background
        float tutorialWidth = tutorialScreen.getWidth();
        tutorialScreen.draw(-tutorialWidth, 0, tutorialWidth, ofGetHeight());

        cout << "Drawing Platforms" << endl;
    ofSetColor(0);

    if (platforms.empty()) {
        cout << "No platforms to draw" << endl;
    } else {
        cout << "Number of platforms: " << platforms.size() << endl;
        for (const auto& platform : platforms){
            cout << "Platform X: " << platform.x << ", Y: " << platform.y
                 << " Width: " << platform.width << ", Height: " << platform.height << endl;
            ofDrawRectangle(platform.x, platform.y, platform.width, platform.height);
        }
    }

    if (showOptionsPanel) {
        ofPushMatrix();
        ofTranslate(cameraX, cameraY);

            float panelX = player.getX() - ofGetWidth() * 0.25; // Adjust X position relative to the player
            float panelY = player.getY() - ofGetHeight() * 0.25; // Adjust Y position relative to the player

            // Ensure the panel remains within the screen boundaries
            panelX = ofClamp(panelX, 0, ofGetWidth() - optionsPanel.getWidth());
            panelY = ofClamp(panelY, 0, ofGetHeight() - optionsPanel.getHeight());

            optionsPanel.setPosition(panelX, panelY);
            optionsPanel.draw();

            ofPopMatrix();

        }


    player.draw();

    ofPopMatrix();
}


//Platforms
Platform::Platform(float x, float y, float width, float height){
    this -> x = x;
    this -> y = y;
    this -> width = width;
    this -> height = height;
}

void gameState::generateInitialPlatforms() {
    cout << "Generating initial platform" << endl;

    // Clear existing platforms
    platforms.clear();

    float platformHeightPercentage = 0.7; // Approximately 30% from the bottom
    float platformY = ofGetHeight() * platformHeightPercentage;
    float platformWidth = ofGetWidth() * 0.6; // 20% away from each side (10% on each side)

    cout << "Generated initial platform: X=" << (ofGetWidth() * 0.2) << ", Y=" << platformY << ", Width=" << platformWidth << ", Height=20" << endl;


    ofSetColor(0);
    platforms.push_back(Platform(ofGetWidth() * 0.2, platformY, platformWidth, 20)); // Create a black platform
}

void gameState::populatePlatforms() {
    cout << "Populating platforms" << endl;

}


void gameState::createPlatformToRight() {
    // Generate new platforms to the right based on player's position
    float newPlatformX = rightBoundary + 200; // Place the new platform 200 units to the right
    float newPlatformY = ofRandom(50, ofGetHeight() - 100); // Random Y position between 50 and height-100
    float newPlatformWidth = 150;
    float newPlatformHeight = 20;

    platforms.push_back(Platform(newPlatformX, newPlatformY, newPlatformWidth, newPlatformHeight));
}

void gameState::createPlatformToLeft() {
    // Generate new platforms to the left based on player's position
    float newPlatformX = leftBoundary - 200; // Place the new platform 200 units to the left
    float newPlatformY = ofRandom(50, ofGetHeight() - 100); // Random Y position between 50 and height-100
    float newPlatformWidth = 150; //constants
    float newPlatformHeight = 20;

    platforms.push_back(Platform(newPlatformX, newPlatformY, newPlatformWidth, newPlatformHeight));
}

void gameState::exitButtonPressed(){
    ofExit();
}


//Options menu rework
//

//Create a main game state menu when in
//create the tutorial room when player transitions left
//create a level picker && randomised calculations within
//






