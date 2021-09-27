#include <iostream>
#include <SDL2/SDL.h>

#include "../include/Game.hpp"

int main(int argc, char const *argv[]){
    int window_width = 800;
    int window_height = 800;

    if (argc == 3){
        window_width  = atoi(argv[1]) == 0 ? 800 : atoi(argv[1]);
        window_height = atoi(argv[2]) == 0 ? 800 : atoi(argv[2]);
    }

    Game game(window_width, window_height);

    unsigned int lastTime = 0, currentTime;
    unsigned int timeStep = 1000/60;

    while(game.isRunning()){
        game.input();

        currentTime = SDL_GetTicks();
        if (currentTime > lastTime + timeStep){
            game.update();
            game.draw();

            lastTime = currentTime;
        }
    }

    game.close();

    return 0;
}
