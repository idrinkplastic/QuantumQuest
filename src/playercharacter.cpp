#include "playercharacter.h"
#include "gamestate.h"


PlayerCharacter::PlayerCharacter() {
    // Initialize player's width and height
    width = 50;
    height = 50;
    gravity = 1;
    jumpForce = 12.0;
    isJumping = false;
    verticalVelocity = 0.0;
    friction = 0.7;
}

void PlayerCharacter::setup(float x, float y, gameState& state) {
    // Set the initial position of the player
    this->x = x;
    this->y = y;
    this->gameStateRef = &state;
}

void PlayerCharacter::update() {


    //updating gravity
    verticalVelocity += gravity;
    y += verticalVelocity;


    //updating horizontal velocity with friction to slow down
    if (horizontalVelocity != 0){
        if (horizontalVelocity > 0){
            horizontalVelocity -= friction;
        } else {
            horizontalVelocity += friction;
        }
    }

    x += horizontalVelocity;

    //restraining character within screen
    if (x < 0){
        x = 0; //left
    } else if (x + width > ofGetWidth()){
        x = ofGetWidth() - width; // right
    }

    if (y < 0){
        y = 0; //top
    } else if (y + height > ofGetHeight()) {
        y = ofGetHeight() - height; //bottom
        verticalVelocity = 0; //stops falling when hitting rock BOTTOM
        isJumping = false;
    }


    //collision
    if (gameStateRef){
        for (const auto& platform : gameStateRef->platforms){
            if (x < platform.x + platform.width &&
                    x + width > platform.x &&
                    y < platform.y + platform.height &&
                    y + height > platform.y){
                    y = platform.y - height;
                    verticalVelocity = 0;
                    isJumping = false;
            }
        }
    }
}

void PlayerCharacter::draw() {
    // Draw the player character as a simple square
    ofSetColor(255, 0, 0); // Set color to red
    ofDrawRectangle(x, y, width, height); // Draw a red square representing the player character
}

void PlayerCharacter::jump(){
    if (!isJumping){
        verticalVelocity = -jumpForce;
        isJumping = true;
    }
}

void PlayerCharacter::move(Direction dir){

    const float acceleration = 10; // acceleration


// change in vel / change in tim

    switch (dir) {
            case UP:
                verticalVelocity -= acceleration;
                break;
            case LEFT:
                horizontalVelocity -= acceleration;
                break;
            case RIGHT:
                horizontalVelocity += acceleration;
                break;
            case UP_LEFT:
                verticalVelocity -= acceleration;
                horizontalVelocity -= acceleration;
                break;
            case UP_RIGHT:
                verticalVelocity -= acceleration;
                horizontalVelocity += acceleration;
                break;
            default:
                break;
        }

    // Apply friction to slow down when no keys are pressed
        if (dir != UP && dir != LEFT && dir != RIGHT && dir != UP_LEFT && dir != UP_RIGHT) {
            if (verticalVelocity > 0) {
                verticalVelocity -= friction;
            } else if (verticalVelocity < 0) {
                verticalVelocity += friction;
            }

            if (horizontalVelocity > 0) {
                horizontalVelocity -= friction;
            } else if (horizontalVelocity < 0) {
                horizontalVelocity += friction;
            }
}
}




//COLLISION








