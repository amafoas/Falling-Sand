#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SDL2/SDL.h>
#include <vector>

using namespace std;

class Particle{
public:
    Particle(int x = 0, int y = 0);
    ~Particle();

    void moveTo(int x, int y);
    void setColor(int r, int g, int b);
    void setSolid(bool b);

    //vector<int> color();

    int x();
    int y();
    bool is_solid();

protected:
    int _x, _y;
    int _r, _g, _b;
    bool _solid;
};

#endif // PARTICLE_HPP