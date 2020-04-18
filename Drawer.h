
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
        void updateField();

        void drawParticles();
        static sf::Color getThreeGradientColor(float val);

    public:

        explicit Drawer(Field* field);
        virtual ~Drawer();

        void update();
        void render();
        void run();
};


