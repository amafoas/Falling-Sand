#ifndef PARTICLE_SYSTEM_HPP
#define PARTICLE_SYSTEM_HPP

#include <vector>

using namespace std;

// ELEMENTS
enum elements { AIR, SAND, STONE };

// COLORS
struct Color {
    int r = 0;
    int g = 0;
    int b = 0;
};

class ParticleSystem {
public:
    ParticleSystem();
    ParticleSystem(int dimX, int dimY);
    ~ParticleSystem();

    bool createElement(int x, int y, int elem);
    Color getColor(int x, int y);

    void doLogic(int& x, int& y);
private:
    int _dimX, _dimY;
    vector<vector<int>> _grid;
};

#endif