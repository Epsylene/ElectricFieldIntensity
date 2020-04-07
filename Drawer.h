
#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"
#include "Field.h"

class Drawer
{
    private:

        sf::RenderWindow window;
        sf::Event sfEvent;

        sf::CircleShape particle;
        sf::RectangleShape fieldPoint;
        Field* field;

        void updateParticles();

        void drawField();
        void drawParticles();

    public:

        explicit Drawer(Field* field);

        void update();
        void render();
        void run();
};


