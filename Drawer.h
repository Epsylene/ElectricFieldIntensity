
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
        sf::Image fieldImage;
        sf::Texture fieldTexture;
        sf::Sprite fieldSprite;
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


