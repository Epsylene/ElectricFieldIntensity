//
// Created by Victor Rodriguez on 23/03/2020.
//

#pragma once

#include <array>
#include <iostream>
#include <cmath>
#include <vector>
#include <SFML/System/Vector2.hpp>

class Field
{
    private:

        class Particle
        {
            public:

                short x, y;
                short q;

                Particle(short x, short y, short charge):
                        x(x), y(y), q(charge)
                        {

                        }
        };

        std::vector<Particle> particuli;
        std::vector<float> fields;
        float E;

        float particleFieldAt(int x, int y, Particle &particle, bool realistic);

    public:

        Field();

        float lower = 0;
        float upper = 0;

        bool nearPositive(int x, int y, bool realistic);
        float fieldAtPoint(int x, int y, bool realistic);
        void setFieldRange();
        std::vector<Particle>* getParticles();
        std::vector<float>* getFields();
};
