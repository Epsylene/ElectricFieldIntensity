
#include "Field.h"

Field::Field()
{

}

double Field::particleFieldAt(int x, int y, Particle& particle)
{
//    if(x != particle.x || y != particle.y)
        return 1/(4*3.14)*abs(particle.q)/(pow(x - particle.x, 2) + pow(y - particle.y, 2));
}

double Field::fieldAtPoint(int x, int y)
{
    E = 0;
    for (auto &particle: particuli)
    {
        if(x != particle.x || y != particle.y)
            E += 1/(4*3.14)*particle.q/(pow(x - particle.x, 2) + pow(y - particle.y, 2));
    }

    return E;
}

void Field::addParticle(int x, int y, short charge)
{
    particuli.emplace_back(x, y, charge);
}

bool Field::nearPositive(int x, int y)
{
    E = 0;

    for (auto &particle: particuli)
    {
        particle.q > 0 ? E += particleFieldAt(x, y, particle)
                       : E -= particleFieldAt(x, y, particle);
    }
    
    return E > 0;
}

std::vector<Field::Particle> *Field::getParticles()
{
    return &particuli;
}
