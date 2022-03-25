#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <memory>

#include "Utilities.hpp"
#include "Boundary.hpp"
#include "Ray.hpp"

void processInputs();
void update();
void draw();

sf::RenderWindow window(sf::VideoMode(1080, 720), "RayCasting Demo", sf::Style::Close);
sf::Vector2f mousePosition;
sf::Vector2f hitPos;

bool colorChange;

// Ray ray(400,200);
sf::Vector2f rayOrigin = sf::Vector2f(400, 400);
Ray rays[360];

Boundary walls[1];

sf::CircleShape shape(10.f);
int main()
{
    int i = 0;
    for (auto &wall : walls)
    {
        wall.setP1(sf::Vector2f(rand() % window.getSize().x, rand() % window.getSize().y));
            wall.setP2(sf::Vector2f(rand() % window.getSize().x, rand() % window.getSize().y));
    }
    for (auto &ray : rays)
    {
        ray.setOrigin(rayOrigin.x, rayOrigin.y);
        sf::Vector2f direction = utils::vectorFromAngle(utils::degreeToRadians(i));
        ray.setDir(
            direction.x,
            direction.y);
        i++;
    }
    shape.setOrigin(10, 10);
    auto desktop = sf::VideoMode::getDesktopMode();
    window.setPosition(sf::Vector2i(desktop.width / 2 - window.getSize().x / 2, desktop.height / 2 - window.getSize().y / 2));

    while (window.isOpen())
    {
        processInputs();
        update();
        draw();
    }
}

void processInputs()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
            break;
        }
        mousePosition = sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
    }
}

void update()
{

    for (auto &ray : rays)
    {
        ray.setOrigin(mousePosition.x, mousePosition.y);
    }
}

void draw()
{

    window.clear(sf::Color::Black);

    for (auto &wall : walls)
    {

        window.draw(wall);
    }
    for (auto &ray : rays)
    {
        for (auto &wall : walls)
        {
            if (ray.cast(wall, hitPos))
            {
                sf::Vector2f startPos = ray.getOrigin();
                Boundary ray1(startPos, hitPos);
                window.draw(ray1);
            }
        }
        
    }
    // window.draw(ray);

    window.display();
}
