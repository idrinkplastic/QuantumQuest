#include "gamestate.h"
#include "ofApp.h"
#include <vector>


//CORE
gameState::gameState() {
    scrollingSpeed = 5;
    backgroundImage.load("gamescrollbackground.jpg");
    backgroundX = 0;

    platforms = std::vector<Platform>();

}

void gameState::setup(ofApp* app) {
    cout << "Game state setup called" << endl;
    this->app = app;
    generateInitialPlatforms(); // Generate initial platforms when the game state is set up
    populatePlatforms();

    float middleX = ofGetWidth() * 0.5;

    float platformY = platforms[0].y;
    float abovePlatformY = platformY - 120;

    player.setup(middleX, abovePlatformY, *this);

    leftBoundary = ofGetWidth() * 0.3;
    rightBoundary = ofGetWidth() * 0.7;

}

void gameState::update(){
    player.update();

    // Check player's position to generate platforms
        if (getPlayerX() > rightBoundary) {
            createPlatformToRight();
            rightBoundary += 300; // Adjust the distance for next platform generation
        } else if (getPlayerX() < leftBoundary) {
            createPlatformToLeft();
            leftBoundary -= 300; // Adjust the distance for next platform generation
        }

        cameraX = player.getX() - ofGetWidth() / 2;
        cameraY = player.getY() - ofGetHeight() / 2;



}

void gameState::draw() {
    ofPushMatrix();
    ofTranslate(-cameraX, -cameraY);

    cout << "Drawing Background" << endl;

    int numBackgrounds = ceil((float) ofGetWidth() / backgroundImage.getWidth()) + 1;

    // Draw multiple background images for continuous scrolling
    ofSetColor(255); // Set color back to default (white)
    for (int i = 0; i < numBackgrounds; ++i) {
        float xPos = i * backgroundImage.getWidth();
        backgroundImage.draw(xPos, 0, backgroundImage.getWidth(), ofGetHeight());
    }

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
    float newPlatformWidth = 150; // Set a constant width for the platform
    float newPlatformHeight = 20; // Set a constant height for the platform

    platforms.push_back(Platform(newPlatformX, newPlatformY, newPlatformWidth, newPlatformHeight));
}

void gameState::createPlatformToLeft() {
    // Generate new platforms to the left based on player's position
    float newPlatformX = leftBoundary - 200; // Place the new platform 200 units to the left
    float newPlatformY = ofRandom(50, ofGetHeight() - 100); // Random Y position between 50 and height-100
    float newPlatformWidth = 150; // Set a constant width for the platform
    float newPlatformHeight = 20; // Set a constant height for the platform

    platforms.push_back(Platform(newPlatformX, newPlatformY, newPlatformWidth, newPlatformHeight));
}











