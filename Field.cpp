
#include "Field.h"

Field::Field()
{
    E = 0;
}

float Field::particleFieldAt(int x, int y, Particle &particle, bool realistic)
{
    if(realistic)
        return 1/(4*3.14f) * particle.q/(pow(x - particle.x, 2) + pow(y - particle.y, 2));
    else
        return 1/(4*3.14) * particle.q/sqrt(sqrt(sqrt(((pow(x - particle.x, 2) + pow(y - particle.y, 2))))));
}

bool Field::nearPositive(int x, int y, bool realistic)
{
    E = 0;

    for (auto &particle: particuli)
    {
        E += particleFieldAt(x, y, particle, realistic);
    }
    
    return E > 0;
}

std::vector<Field::Particle> *Field::getParticles()
{
    return &particuli;
}

float Field::fieldAtPoint(int x, int y, bool realistic)
{
    E = 0;

    for (auto &particle: particuli)
    {
        E += particleFieldAt(x, y, particle, realistic);
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
