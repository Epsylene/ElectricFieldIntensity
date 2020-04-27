
#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"
#include "Field.h"

enum Style
{
    UGLY = 0, BEAUTY, TEXT
};

class Drawer
{
    private:

        sf::RenderWindow window;
        sf::Event sfEvent;

        sf::CircleShape particle;
        sf::Font font;
        sf::Text fieldText;
        sf::Image fieldImage;
        sf::Texture fieldTexture;
        sf::Sprite fieldSprite;
        Field& field;

        Style style;

        void updateParticles();
        void updateField();

        void drawParticles();
        static sf::Color getThreeGradientColor(float val);

    public:

        explicit Drawer(Field& field);

        void update();
        void render();
        void run();
};


