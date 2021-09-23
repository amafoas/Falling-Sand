#include <iostream>
#include <SDL2/SDL.h>

#include "../include/Game.hpp"
#include "../include/Particle.hpp"

int main(int argc, char const *argv[]){
    Game game;

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
