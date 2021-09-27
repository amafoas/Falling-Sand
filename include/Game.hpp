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
    //Game();
    Game(int width = 800, int height = 800);
    ~Game();

    void input();
    void update();
    void draw();
    void close();

    bool isRunning();
private:
    bool _gameRunning;

    // WINDOW SETTINGS
    int _width;
    int _height;
    int _zoom = 10;

    // SANDBOX
    ParticleSystem _ps;

    // SDL
    Window _window;
    SDL_Event _event;

    vector<pair<int, int>> notNull;
};


#endif // GAME_HPP