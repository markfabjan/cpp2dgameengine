#ifndef GLOBALS_H
#define GLOBALS_H

#include <math.h>

namespace globals{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const float SPRITE_SCALE = 2.0f;
    const float PI = 3.14159265358979323846;
}

enum Direction {
    EAST,
    NE,
    NORTH,
    NW,
    WEST,
    SW,
    SOUTH,
    SE
};

struct Vector2 {
    int x, y;
    Vector2():
        x(0), y(0)
    {}
    Vector2(int x, int y):
        x(x), y(y)
    {}
    Vector2 zero(){
        return Vector2(0,0);
    }
    float dot(Vector2 a, Vector2 b){
        return a.x*b.x + a.y*b.y;
    }
    float dot(Vector2 b){
        return x*b.x + y*b.y;
    }
    float angleDegrees(Vector2 b){
        float a = (acos(dot(b)/(length()*b.length())))*(180/globals::PI);
        if(y>0){
            return 360-a;
        }
        return a;
    }
    float angleRads(Vector2 b){
        float a = (acos(dot(b)/(length()*b.length())));
        if(y>0){
            return 2*globals::PI-a;
        }
        return a;
    }
    float length(){
        return sqrt((x*x)+(y*y));
    }
    Vector2 add(Vector2 b){
        return Vector2(x+b.x,y+b.y);
    }
    Vector2 mul(Vector2 b){
        return Vector2(x*b.x,y*b.y);
    }
    Vector2 mul(float b){
        return Vector2(x*b,y*b);
    }
    Vector2 unit(){
        return Vector2(x/length(),y/length());
    }
};

#endif
