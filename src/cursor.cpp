#include "graphics.h"
#include "cursor.h"


Cursor::Cursor(){}

Cursor::Cursor(Graphics &graphics, int x, int y){
    //graphics.loadImage("assets/cursor.png");
    this->_x = x;
    this->_y = y;
    this->_cursor = Sprite(graphics, "assets/cursor.png", 0, 0, 32, 32, this->_x, this->_y);
}

void Cursor::update(){
    //move by dx
    SDL_GetMouseState(&this->_x,&this->_y);
}

void Cursor::draw(Graphics &graphics){
    _cursor.draw(graphics, this->_x-(16*globals::SPRITE_SCALE), this->_y-(16*globals::SPRITE_SCALE));
}














