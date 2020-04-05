
#include "Field.h"

Field::Field()
{

}

double Field::particleFieldAt(int x, int y, Particle& particle)
{
    if(x != particle.x || y != particle.y)
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

sf::Vector2f Field::getPosition(int index)
{
    if(!particuli.empty())
        return sf::Vector2f(particuli[index].x, particuli[index].y);
    else
        return sf::Vector2f(0, 0);
}

bool Field::nearPositive(int x, int y)
{
    double E_pos = 0;
    double E_neg = 0;

    for (auto &particle: particuli)
    {
        if(particle.q > 0)
            E_pos += particleFieldAt(x, y, particle);
        else
            E_neg += particleFieldAt(x, y, particle);
    }
    
    return E_pos > E_neg;
}

std::vector<Field::Particle> *Field::getParticles()
{
    return &particuli;
}
