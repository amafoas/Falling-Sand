#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <vector>
#include <utility> // pair

using namespace std;

#include "Particle.hpp"
#include "Window.hpp"

class Game{
public:
    Game();
    ~Game();

    void input();
    void update();
    void draw();
    void close();

    bool isRunning();
    Particle* getCell(int x, int y);
private:
    bool _gameRunning;
    int _zoom;

    // SANDBOX SIZE 
    int _sizeX = 80;
    int _sizeY = 80;

    // SDL
    Window _window;
    SDL_Event _event;

    vector<pair<int, int>> notNull;
    vector<vector<Particle*>> _matrix;

    void moveANDdeleteFrom(int x, int y, int offsetX, int offsetY);
    void logic();
};


#endif // GAME_HPP