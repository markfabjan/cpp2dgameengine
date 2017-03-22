#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

#include <string>

class Graphics;

class Sprite{
public:
    Sprite();
    Sprite(Graphics &graphics, const std::string &filePath,
        int sourceX, int sourceY,
        int width, int height,
        float posX, float posY);
    virtual ~Sprite();
    virtual void update();
    void draw(Graphics &graphics, int x, int y);
    float _x, _y;
protected:
    SDL_Rect _sourceRect;
    SDL_Texture* _spriteSheet;
private:

};

#endif