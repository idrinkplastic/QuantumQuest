#ifndef GAMESTATE_H
#define GAMESTATE_H
#include "ofMain.h"
#include "ofxGui.h"
#include "playercharacter.h"


class ofApp;
class menuState;

class Platform{
public:
    float x, y; //position
    float width, height; //size

    //construct to init
    Platform(float x, float y, float width, float height);
};



class gameState {
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

private:
    ofImage backgroundImage;
    ofSoundPlayer gameMusic;
    void endButtonPressed();

    float scrollingSpeed;
    float backgroundX;

    ofApp* app;


    void generateInitialPlatforms(); //generate initial platforms
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


};





#endif // GAMESTATE_H
