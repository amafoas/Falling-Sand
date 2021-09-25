#include "../include/ParticleSystem.hpp"

ParticleSystem::ParticleSystem(){}
ParticleSystem::ParticleSystem(int dimX, int dimY): _dimX(dimX), _dimY(dimY),
_grid(vector<vector<int>>(dimX, vector<int>(dimY, AIR))) {}
ParticleSystem::~ParticleSystem(){}

bool ParticleSystem::createElement(int x, int y, int elem) {
    if (_grid[x][y] != AIR) return false;

    _grid[x][y] = elem;
    return true;
}

Color ParticleSystem::getColor(int x, int y){
    Color res;

    switch (_grid[x][y]) {
    case AIR:
        res.r = 255; res.g = 255; res.b = 255;
        break;
    case SAND:
        res.r = 243; res.g = 236; res.b = 143;
        break;
    case STONE:
        res.r = 170; res.g = 170; res.b = 170;
        break;
    }

    return res;
};

void ParticleSystem::doLogic( int& x, int& y ){
    const vector<vector<int>> _buffer = _grid;

    // SAND
    if ( _grid[x][y] == SAND && y + 1 > 0 && y + 1 < _dimY ){
        if (_buffer[x][y + 1] == AIR) {
            // move the particle
            _grid[x][y + 1] = _grid[x][y];
            _grid[x][y] = AIR;
            // update the values
            y++;

        } else if (x + 1 < _dimX  && _buffer[x + 1][y + 1] == AIR) {
            // avoid leaks
            if (_buffer[x + 1][y] == AIR) {
                // move the particle
                _grid[x + 1][y + 1] = _grid[x][y];
                _grid[x][y] = AIR;
                // update the values
                y++; x++;
            }

        } else if (x - 1 >= 0      && _buffer[x - 1][y + 1] == AIR) {
            // avoid leaks
            if (_buffer[x - 1][y] == AIR) {
                // move the particle
                _grid[x - 1][y + 1] = _grid[x][y];
                _grid[x][y] = AIR;
                // update the values
                y++; x--;
            }
        }
    }

}