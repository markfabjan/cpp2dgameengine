#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;

class Graphics {
    public:
        Graphics();
        ~Graphics();
        //loads image into _spriteSheets map if it doesn't exist
        //each image is only loaded once
        //returns image from map whether it was loaded now or not.
        SDL_Surface* loadImage(const std::string &filepath);

        //draws a texture to a part of the screen
        void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

        //renders everything to screen
        void flip();

        //clears the screen
        void clear();

        //returns the renderer
        SDL_Renderer* getRenderer() const;
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;

        std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif
