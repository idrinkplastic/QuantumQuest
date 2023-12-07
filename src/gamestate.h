#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "ofMain.h"
#include "ofxGui.h"
#include "playercharacter.h"


class ofApp;
class menuState;

class Platform{
public:
    float x, y;
    float width, height;

    //construct to init
    Platform(float x, float y, float width, float height);
};



class gameState {
    ofImage backgroundImage;
    ofImage tutorialScreen;

    ofxPanel optionsPanel;
    ofxSlider<float> soundVolumeSlider;
    ofxSlider<int> screenWidthSlider;
    ofxSlider<int> screenHeightSlider;
    ofxButton exitButton;




public:
    gameState();
    void setup(ofApp* app);
    void update();
    void draw();
    bool gameStarted;
    std::vector<Platform> platforms; //vector to hold platforms
    PlayerCharacter player;
    void drawGame();
    void drawBackground();
    void exitButtonPressed();

private:

    ofSoundPlayer gameMusic;
    void endButtonPressed();

    float scrollingSpeed;
    float backgroundX;

    ofApp* app;


    void generateInitialPlatforms();
    void drawPlatforms();
    void populatePlatforms();

    float leftBoundary;
    float rightBoundary;

    void createPlatformToRight();
    void createPlatformToLeft();

    void updateBoundaries();

    float getPlayerX() const { return player.getX(); }
    float getPlayerY() const { return player.getY(); }

    float cameraX;
    float cameraY;

    bool showOptionsPanel;

};





#endif // GAMESTATE_H
