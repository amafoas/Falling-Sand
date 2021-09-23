#include "../include/Game.hpp"

#include <iostream>

Game::Game(): _gameRunning(true), _zoom(2)
, _matrix(vector<vector<Particle*>>(_sizeX, vector<Particle*> (_sizeY, NULL))){}

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

        if (_matrix[x][y] == NULL){
            cout << x << ", " << y << endl;
            notNull.emplace_back(x, y); 
            Particle* p = new Particle (x, y);
            if ( mButton == MOUSE_RIGHT ) p->setSolid(true);
            _matrix[x][y] = p;
        }
    }

    // Do all the logic of the particles
    logic();
}

void Game::draw(){
    _window.clear();
    for (pair<int, int> cord : notNull) { 
        _window.render(*_matrix[cord.first][cord.second]);
    }
    _window.display();
}

void Game::close(){
    for (vector<Particle*> row : _matrix) {
        for (Particle* pointer : row ) {
            if (pointer != NULL) delete pointer;
        }
    }

    _window.destroy();
    SDL_Quit();
}

bool Game::isRunning(){ return _gameRunning; }
Particle* Game::getCell(int x, int y){ return _matrix[x][y]; }

/// PRIVATE

void Game::moveANDdeleteFrom(int x, int y, int offsetX, int offsetY){
    // move
    _matrix[x][y]->moveTo(x + offsetX, y + offsetY);
    _matrix[x + offsetX][y + offsetY] = _matrix[x][y];

    // delete
    _matrix[x][y] = NULL;
};

void Game::logic(){
    vector<vector<Particle*>> _buffer = _matrix;

    for (int i = 0; i < notNull.size(); i++){
        int x = notNull[i].first;
        int y = notNull[i].second;

        bool is_solid = _matrix[x][y]->is_solid();

        // SAND
        if ( !is_solid && y + 1 > 0 && y + 1 < _sizeY ){
            if (_buffer[x][y + 1] == NULL) {
                // move the particle
                moveANDdeleteFrom(x, y, 0, 1);
                // update the values
                notNull[i].second = y + 1;
            } else if (x + 1 < _sizeX  && _buffer[x + 1][y + 1] == NULL) {
                // avoid leaks
                if (_buffer[x + 1][y] == NULL) {
                    // move the particle
                    moveANDdeleteFrom(x, y, 1, 1);
                    // update the values
                    notNull[i].second = y + 1;
                    notNull[i].first = x + 1;
                }

            } else if (x - 1 >= 0      && _buffer[x - 1][y + 1] == NULL) {
                // avoid leaks
                if (_buffer[x - 1][y] == NULL) {
                    // move the particle
                    moveANDdeleteFrom(x, y, -1, 1);
                    // update the values
                    notNull[i].second = y + 1;
                    notNull[i].first = x - 1;
                }

            }
        }

    }

}