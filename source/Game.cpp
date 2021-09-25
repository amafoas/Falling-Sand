#include "../include/Game.hpp"
#include <iostream>

Game::Game(): _gameRunning(true), _zoom(2), _ps(ParticleSystem(_sizeX, _sizeY)){}

Game::~Game(){}

enum mouseButtons { MOUSE_NONE, MOUSE_LEFT, MOUSE_RIGHT };
int mButton = MOUSE_NONE;

void Game::input(){

    while (SDL_PollEvent(&_event) != 0){

        if ( _event.type == SDL_QUIT ) {
            _gameRunning = false;

        } else if ( _event.type == SDL_MOUSEBUTTONDOWN ){
            cout << "Button is pressed" << endl;
            switch (_event.button.button){
                case SDL_BUTTON_LEFT:
                    mButton = MOUSE_LEFT;
                    break;
                case SDL_BUTTON_RIGHT:
                    mButton = MOUSE_RIGHT;
                    break;
            }
        } else if ( _event.type == SDL_MOUSEBUTTONUP ) {
            cout << "Button isn't pressed" << endl;
            mButton = MOUSE_NONE;
        }
    }
}

void Game::update(){
    if ( mButton != MOUSE_NONE ) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        // keep the values in the limits
        x = min(800, max(0, x));
        y = min(800, max(0, y));
        // transform cordinates from px to grid
        x = x / 10;
        y = y / 10;

        int elem = mButton == MOUSE_LEFT ? SAND : STONE; 
        if ( _ps.createElement(x, y, elem) ) notNull.emplace_back(x, y); 
    }

    for (int i = 0; i < notNull.size(); i++){

        _ps.doLogic(notNull[i].first, notNull[i].second);

    }

}

void Game::draw(){
    _window.clear();

    int x,y;
    for (pair<int, int> cord : notNull) { 
        x = cord.first; 
        y = cord.second;
        Color color = _ps.getColor(x, y); 
        _window.render(x, y, color.r, color.g, color.b);
    }

    _window.display();
}

void Game::close(){
    _window.destroy();
    SDL_Quit();
}

bool Game::isRunning(){ return _gameRunning; }