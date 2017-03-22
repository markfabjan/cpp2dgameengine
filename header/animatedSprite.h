#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include <map>
#include <string>
#include <vector>

#include "sprite.h"
#include "globals.h"

class Graphics;

class AnimatedSprite : public Sprite{ //publically inherits from sptire class.
public:
    AnimatedSprite();
    AnimatedSprite(Graphics &graphics, const std::string & filePath, int sourceX, int SourceY, int width, int height,
    float posX, float posY, float timeToUpdate);
    void playAnimation(std::string animation, bool loop = true);//once = false if not specified

    void update(int elapsedTime);

    void draw(Graphics &graphics, int x, int y);

protected:
    double _timeToUpdate;
    bool _currentAnimationLoop;
    std::string _currentAnimation;

    //adds an animation to the map of animations
    void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);

    //resets all animations associated with the sprite
    void resetAnimations();

    //stops current animation
    void stopAnimation();

    void setVisible(bool visible);

    //happens every time animation ends
    //=0 makes it pure virtual. It now cannot be implemented in animatedSprite.cpp, but only in classes that inherit animatedSprite
    virtual void animationDone(std::string currentAnimation) = 0;

    virtual void setupAnimations() = 0;//sets up all animations for a sprite

private:
    std::map<std::string, std::vector<SDL_Rect>> _animations;
    std::map<std::string, Vector2> _offsets;
    int _frameIndex;
    double _timeElapsed;
    bool _visible;
};

#endif
