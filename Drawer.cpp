
#include "Drawer.h"

Drawer::Drawer(Field* field): field(field)
{
    sf::VideoMode windowBounds = sf::VideoMode::getDesktopMode();
    windowBounds.width = 800;
    windowBounds.height = 450;
    window.create(windowBounds, "Lignes de champ", sf::Style::Titlebar | sf::Style::Close);
}

void Drawer::update()
{
    while(window.pollEvent(sfEvent))
    {
        if(sfEvent.type == sf::Event::Closed)
            window.close();
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        field->addParticle(sf::Mouse::getPosition().x - window.getPosition().x,
                          sf::Mouse::getPosition().y - window.getPosition().y, 1);
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        field->addParticle(sf::Mouse::getPosition().x - window.getPosition().x,
                          sf::Mouse::getPosition().y - window.getPosition().y, -1);
    }
}

void Drawer::render()
{
    window.clear();

    drawField();
    drawParticles();

    window.display();
}

void Drawer::updateDT()
{
    dt = dtClock.restart().asSeconds();
}

void Drawer::run()
{
    while(window.isOpen())
    {
        updateDT();
        update();
        render();
    }
}

void Drawer::drawField()
{

    for (int i = 0; i < window.getSize().x; i+=5)
    {
        for (int j = 0; j < window.getSize().y; j+=5)
        {
            fieldPoint.setPosition(i, j);
            fieldPoint.setSize(sf::Vector2f(5, 5));

//            std::cout << "M(" << i << "," << j << ") ";
            if(field->nearPositive(i, j))
                fieldPoint.setFillColor(sf::Color::Red);
            else
                fieldPoint.setFillColor(sf::Color::Blue);

            window.draw(fieldPoint);
        }
    }
}

void Drawer::drawParticles()
{
    for (auto& particle: *field->getParticles())
    {
        this->particle.setPosition(particle.x, particle.y);

        if(particle.q > 0)
            this->particle.setFillColor(sf::Color::White);
        else
            this->particle.setFillColor(sf::Color::Black);

        this->particle.setRadius(10);

        window.draw(this->particle);
    }
}