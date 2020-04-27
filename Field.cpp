
#include "Field.h"

Field::Field()
{

}

float Field::particleFieldAt(int x, int y, Particle &particle)
{
    //@TODO: change E formula depending on style
//    return 1/(4*3.14f)*particle.q/(pow(x - particle.x, 2) + pow(y - particle.y, 2));
    return 1/(4*3.14) * particle.q/sqrt(sqrt(sqrt(((pow(x - particle.x, 2) + pow(y - particle.y, 2))))));
}

void Field::addParticle(short x, short y, short charge)
{
    particuli.emplace_back(x, y, charge);
}

bool Field::nearPositive(short x, short y)
{
    E = 0;

    for (auto &particle: particuli)
    {
        E += particleFieldAt(x, y, particle);
    }
    
    return E > 0;
}

std::vector<Field::Particle> *Field::getParticles()
{
    return &particuli;
}

float Field::fieldAtPoint(int x, int y)
{
    E = 0;

    for (auto &particle: particuli)
    {
        E += particleFieldAt(x, y, particle);
    }

    return E;
}

void Field::setFieldRange()
{
    for (auto &localField: fields)
    {
        if(upper < localField)
            upper = localField;
        if(lower > localField)
            lower = localField;
    }
}

std::vector<float> *Field::getFields()
{
    return &fields;
}
