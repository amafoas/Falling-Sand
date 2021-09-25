#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>

class Window{
public:
    Window();
    ~Window();

void render(int x, int y, int r, int g, int b);

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