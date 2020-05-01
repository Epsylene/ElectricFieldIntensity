
#pragma once

#include <cmath>
#include <vector>

class Field
{
    private:

        class Particle
        {
            public:

                short x, y;
                short q;

                Particle(short x, short y, short charge):
                        x(x), y(y), q(charge) {}
        };

        std::vector<Particle> particuli;
        std::vector<float> fields;
        float E;

        float particleFieldAt(int x, int y, Particle &particle, bool realistic);

    public:

        Field();

        float lower = 0;
        float upper = 0;

        float fieldAtPoint(int x, int y, bool realistic);
        void fieldRange();
        std::vector<Particle>* getParticles();
        std::vector<float>* getFields();
};
