#include "../include/Particle.hpp"

Particle::Particle(int x, int y): _x(x), _y(y), _solid(false){}
Particle::~Particle(){}

void Particle::moveTo(int x, int y){ 
    _x = x;
    _y = y;
 }

void Particle::setColor(int r, int g, int b){
    _r = r;
    _g = g;
    _b = b;
}

void Particle::setSolid(bool b){ _solid = b; }

// vector<int> Particle::color(){
//     vector<int> rgb = {_r, _g, _b};
//     return rgb;
// };

int Particle::x(){ return _x; }
int Particle::y(){ return _y; }
bool Particle::is_solid(){ return _solid; }