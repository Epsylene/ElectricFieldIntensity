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

                int x, y;
                short q;

                Particle(int x, int y, short charge):
                        x(x), y(y), q(charge)
                {

                }
        };

        std::vector<Particle> particuli;
        double E;

        double particleFieldAt(int x, int y, Particle& particle);

        int counter = 0;

    public:

        Field();

        void addParticle(int x, int y, short charge);
        double fieldAtPoint(int x, int y);
        bool nearPositive(int x, int y);
        sf::Vector2f getPosition(int index);
        std::vector<Particle>* getParticles();
};
