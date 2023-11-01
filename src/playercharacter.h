#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#pragma once

#include "ofMain.h"

class PlayerCharacter {

public:
        //Construct
    PlayerCharacter();
        //Destruct
    ~PlayerCharacter();
        //Func to setup character (char)
    void setup();
        //Func to update logic of char
    void update();
        //Func to draw char
    void draw();
        //Func to set location of char
    void setPosition(const ofVec2f& position );
        //Func to get location of char
    ofVec2f getPosition() const;
        //Func to set char speed
    void setSpeed(float speed);
        //Func to get char speed
    float getSpeed() const;
        //Func to set char health
    void setHealth(int health);
        //Func to get char health
    int getHealth() const;
        //Func to decrease char health
    void decreaseHealth(int amount);


private:
    ofVec2f position; //char position
    float speed; //char speed
    int health; //char health ; set to 100 to begin

};

#endif // PLAYERCHARACTER_H
