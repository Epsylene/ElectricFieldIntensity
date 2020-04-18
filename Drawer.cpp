
#include "Drawer.h"

Drawer::Drawer(Field* field): field(field)
{
    sf::VideoMode windowBounds = sf::VideoMode::getDesktopMode();
    windowBounds.width = 800;
    windowBounds.height = 450;
    window.create(windowBounds, "Lignes de champ", sf::Style::Titlebar | sf::Style::Close);

    fieldImage.create(window.getSize().x, window.getSize().y, sf::Color::White);
    fieldTexture.create(window.getSize().x, window.getSize().y);
    fieldSprite.setTexture(fieldTexture);
}

Drawer::~Drawer()
{
    delete field;
}

void Drawer::update()
{
    while(window.pollEvent(sfEvent))
    {
        if(sfEvent.type == sf::Event::Closed)
            window.close();
    }

    updateField();
    updateParticles();
}

void Drawer::updateParticles()
{
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        field->addParticle(sf::Mouse::getPosition(window).x,
                           sf::Mouse::getPosition(window).y, 1);
//        std::cout << "\nNew Particle:\n";
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        field->addParticle(sf::Mouse::getPosition(window).x,
                           sf::Mouse::getPosition(window).y, -1);
//        std::cout << "\nNew Particle:\n";
    }
}

void Drawer::updateField()
{
    for (int i = 0; i < window.getSize().x; ++i)
    {
        for (int j = 0; j < window.getSize().y; ++j)
        {
            if(!field->getParticles()->empty())
            {
//                field->nearPositive(i, j) ? fieldImage.setPixel(i, j, sf::Color::Red)
//                                          : fieldImage.setPixel(i, j, sf::Color::Blue);

                if(i % 30 == 0 && j % 30 == 0)
                {
                    field->getFields()->push_back(field->fieldAtPoint(i, j));
                    field->upper = field->getFields()->at(0);
                    field->lower = field->getFields()->at(0);
                    field->setFieldRange();
                }

                fieldImage.setPixel(i, j, getThreeGradientColor((field->fieldAtPoint(i, j) - field->lower) / (field->upper - field->lower)));
            }
        }
    }

    fieldTexture.update(fieldImage);
}

void Drawer::render()
{
    window.clear();

    window.draw(fieldSprite);
    drawParticles();

    window.display();
}

void Drawer::drawParticles()
{
    for (auto& particle: *field->getParticles())
    {
        this->particle.setPosition(particle.x - 5, particle.y + 5);

        particle.q > 0 ? this->particle.setFillColor(sf::Color::Red)
                       : this->particle.setFillColor(sf::Color::Blue);

//        this->particle.setRadius(10);

        window.draw(this->particle);
    }
}

sf::Color Drawer::getThreeGradientColor(float val)
{
    const int NC = 3;
    static float color[NC][3] = { {0,0,1}, {1,1,1}, {1,0,0} };

    int idx1, idx2;
    float localVal = 0;

    if(val <= 0)
        idx1 = idx2 = 0;
    else if(val >= 1)
        idx1 = idx2 = NC-1;
    else
    {
        val = val * (NC - 1);
        idx1  = std::floor(val);
        idx2  = idx1+1;
        localVal = val - (float)idx1;
    }

    sf::Uint8 red   = 255*((color[idx2][0] - color[idx1][0])*localVal + color[idx1][0]);
    sf::Uint8 green = 255*((color[idx2][1] - color[idx1][1])*localVal + color[idx1][1]);
    sf::Uint8 blue  = 255*((color[idx2][2] - color[idx1][2])*localVal + color[idx1][2]);

    return sf::Color(red, green, blue);
}

void Drawer::run()
{
    while(window.isOpen())
    {
        update();
        render();
    }
}
