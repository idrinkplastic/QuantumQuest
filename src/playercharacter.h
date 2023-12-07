#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H
#pragma once
#include "ofMain.h"



class gameState;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    UP_RIGHT,
    UP_LEFT
};

class PlayerCharacter {
public:
    PlayerCharacter(); // Constructor
    void setup(float x, float y, gameState& state); // Setup function to initialize the player's position
    void update(); // Update function for character behavior
    void draw(); // Draw function to render the character
    void jump();
    void move (Direction dir);

    float getX() const { return x; }
    float getY() const { return y; }


    //movement



private:
    float x, y; // Position of the player character
    float width, height; // Width and height of the player character
    float gravity;
    float jumpForce;
    bool isJumping;
    float verticalVelocity;
    float horizontalVelocity;
    float friction;

    gameState* gameStateRef; //ref to gamestate


};


#endif // PLAYERCHARACTER_H
