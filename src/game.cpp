#include <SDL2/SDL.h>
#include "graphics.h"
#include "game.h"
#include "input.h"
#include <iostream>
#include "globals.h"

//holds all information for main game loop

namespace {
    const int FPS = 30;
    const int MAX_FRAME_TIME = 5 * 1000/FPS;
}

Game::Game(){
    SDL_Init(SDL_INIT_EVERYTHING);
    //hide mouse cursor
    SDL_ShowCursor(false);
    this->gameLoop();
}

Game::~Game(){

}

void Game::gameLoop(){
    Graphics graphics;
    Input input;
    SDL_Event event;

    //this->_player = Sprite(graphics,"assets/environment/0_default_floor.png",0,0,50,25,100,100);

    this->_player = Player(graphics, 100, 100);
    this->_cursor = Cursor(graphics, 100, 100);
    //this->_cursor = Sprite(graphics, "assets/target.png", 0, 0, 32, 32, input._mouseX, input._mouseY);


    int LAST_UPDATE_TIME = SDL_GetTicks();
    while(true){
        input.beginNewFrame();
        if(SDL_PollEvent(&event)){

            if(event.type == SDL_KEYDOWN){
                if(event.key.repeat == 0){
                    input.keyDownEvent(event);
                }
            }
            else if(event.type == SDL_KEYUP){
                input.keyUpEvent(event);
            }
            else if(event.type == SDL_QUIT){
                return;
            }
        }
        if(input.wasKeyPressed(SDL_SCANCODE_ESCAPE)){
            return;
        }
        //player input
        //TODO: make player class more complex (it will need more thatn one animated sprite (at least 2 for now.))
        //or maybe just rename it to playertorso and playerlegs (then you can just check for difference in angle and adjust speed accordingly)
        else if(input.isKeyHeld(SDL_SCANCODE_D)){
            _player.moveRight();
        }
        else if(input.isKeyHeld(SDL_SCANCODE_A)){
            _player.moveLeft();
        }
        if(!input.isKeyHeld(SDL_SCANCODE_A) && !input.isKeyHeld(SDL_SCANCODE_D)){
            _player.stopMoving();
        }

        //printing player and mouse position
        //std::cout << std::endl << "_player._x:" << _player._x << ";_player._y:" << _player._y << ";mousex" << input._mouseX << ";mousey" << input._mouseY << std::endl;
        //printing mouse location relative to player location
        //std::cout << std::endl << "relative mousex" << (input._mouseX - _player._x) << "; relative mousey" << (input._mouseY - _player._y) << std::endl;
        //printing vector angle between player's EAST and mouse
        std::cout << std::endl <<
            "angle (player's EAST, mouse pos): " <<
            Vector2((input._mouseX-_player._x),(input._mouseY-_player._y)).angleDegrees(Vector2(1,0)) <<
            "; radians = " <<
            Vector2((input._mouseX-_player._x),(input._mouseY-_player._y)).angleRads(Vector2(1,0));

        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
        LAST_UPDATE_TIME = CURRENT_TIME_MS;

        this->draw(graphics);
    }

}

void Game::draw(Graphics &graphics){
    graphics.clear();
    this->_player.draw(graphics);
    //this->_cursor.draw(graphics, input._mouseX - 16, input._mouseY - 16);//because it's 32x32 and I'm aiming for center
    this->_cursor.draw(graphics);
    //draw line between player pivot and cursor pivot
    SDL_SetRenderDrawColor(graphics.getRenderer(), 255, 255, 0, 255);
    SDL_RenderDrawLine(graphics.getRenderer(), this->_player._x, this->_player._y, this->_cursor._x, this->_cursor._y);
    SDL_SetRenderDrawColor(graphics.getRenderer(), 0, 0, 0, 255);
    graphics.flip();
}

void Game::update(float elapsedTime){
    this->_player.update(elapsedTime);
    this->_cursor.update();
    //TODO: make a cursor class later
    //this->_cursor._x = input._mouseX;
    //this->_cursor._y = input._mouseY;
}
