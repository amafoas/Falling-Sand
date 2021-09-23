#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include "Particle.hpp"

class Window{
public:
    Window();
    ~Window();

void render(Particle p);

void clear();
void display();

void destroy();

private:
    int _width, _height, _zoom;
    SDL_Window* _window;
    SDL_Surface* _screenSurface;
    SDL_Renderer* _renderer;
};

#endif // WINDOW_HPP