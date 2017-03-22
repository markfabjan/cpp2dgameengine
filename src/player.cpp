#include "graphics.h"
#include "player.h"

namespace player_constants{
    const float WALK_SPEED = 0.2f;
}

Player::Player(){}

Player::Player(Graphics &graphics, float x, float y) :
    AnimatedSprite(graphics, "assets/player.png",0,0,25,43,x,y,100)
{
    graphics.loadImage("assets/player.png");
    this->setupAnimations();
    this->playAnimation("idle180");
    this->_facing = WEST;
}

void Player::setupAnimations(){
    this->addAnimation(1, 0, 86, "idle0", 25, 43, Vector2(0,0));   //idle left
    this->addAnimation(1, 1, 86, "idle180", 25, 43, Vector2(0,0));   //idle left
    this->addAnimation(4, 0, 0, "run0", 25, 43, Vector2(0,0));      //run right
    this->addAnimation(4, 0, 43, "run180", 25, 43, Vector2(0,0));   //run left
}

void Player::animationDone(std::string currentAnimation){}

void Player::moveLeft(){
    this->_dx = -player_constants::WALK_SPEED;
    this->playAnimation("run180");
    this->_facing = WEST;
}

void Player::moveRight(){
    this->_dx = +player_constants::WALK_SPEED;
    this->playAnimation("run0");
    this->_facing = EAST;
}

void Player::stopMoving(){
    this->_dx = 0.0f;
    this->_dy = 0.0f;
    if (this->_facing == WEST){
        this->playAnimation("idle180");
    }else{
        this->playAnimation("idle0");
    }
}

void Player::update(float elapsedTime){
    //move by dx
    this->_x += this->_dx * elapsedTime;
    this->_y += this->_dy * elapsedTime;
    AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics &graphics){
    AnimatedSprite::draw(graphics, this->_x, this->_y);
}














