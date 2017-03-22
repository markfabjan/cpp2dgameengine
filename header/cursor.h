#ifndef CURSOR_H
#define CURSOR_H

#include "sprite.h"
#include "globals.h"

class Graphics;

class Cursor{
public:
    Cursor();
    Cursor(Graphics &graphics, int x, int y);
    void draw(Graphics &graphics);
    void update();
    Sprite _cursor;
    int _x;
    int _y;
private:
};

#endif // PLAYER_H
