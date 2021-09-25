#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <vector>
#include <utility> // pair

using namespace std;

#include "Window.hpp"
#include "ParticleSystem.hpp"

class Game{
public:
    Game();
    ~Game();

    void input();
    void update();
    void draw();
    void close();

    bool isRunning();
private:
    bool _gameRunning;
    int _zoom;

    // SANDBOX SIZE 
    int _sizeX = 80;
    int _sizeY = 80;
    ParticleSystem _ps;

    // SDL
    Window _window;
    SDL_Event _event;

    vector<pair<int, int>> notNull;
};


#endif // GAME_HPP