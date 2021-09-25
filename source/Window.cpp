#include "../include/Window.hpp"

#include <iostream>

Window::Window(): _width(800), _height(800), _zoom(2)
, _window(NULL), _screenSurface(NULL) {

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return;
    }

    _window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _height, SDL_WINDOW_SHOWN );

    if( _window == NULL ){
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
}

Window::~Window(){}

void Window::render(int x, int y, int r, int g, int b){
    SDL_Rect part;
    part.x = x *10;
    part.y = y *10;
    part.h = 10;
    part.w = 10;

    SDL_SetRenderDrawColor(_renderer, r, g, b, 255);
    SDL_RenderFillRect(_renderer, &part);

}

void Window::clear() {  SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
                        SDL_RenderClear(_renderer); }
void Window::display(){ SDL_RenderPresent(_renderer); }

void Window::destroy() { SDL_DestroyWindow(_window); }