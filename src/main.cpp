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

sf::RenderWindow window(sf::VideoMode(1400, 1000), "RayCasting Demo", sf::Style::Close);
sf::Vector2f mousePosition;
sf::Vector2f hitPos;

bool colorChange;

sf::Vector2f rayOrigin = sf::Vector2f(400, 400);
Ray rays[1440];

Boundary walls[12];

bool drawWalls=false;

sf::CircleShape shape(10.f);
int main()
{

    int len = sizeof(walls)/sizeof(walls[0]);
    srand(utils ::time());
 
    for (int w = 0; w < len-5; w++)
    {
        walls[w].setP1(sf::Vector2f(utils ::random(window.getSize().x), utils ::random(window.getSize().y)));
        walls[w].setP2(sf::Vector2f(utils ::random(window.getSize().x), utils ::random(window.getSize().y)));
    }
    int startPos = len-4;

    walls[startPos].setP1(sf::Vector2f(0, 0));
    walls[startPos].setP2(sf::Vector2f(0, window.getSize().y));

    walls[startPos + 1].setP1(sf::Vector2f(0, window.getSize().y));
    walls[startPos+1].setP2(sf::Vector2f(window.getSize().x, window.getSize().y));

    walls[startPos + 2].setP1(sf::Vector2f(window.getSize().x, window.getSize().y));
    walls[startPos + 2].setP2(sf::Vector2f(window.getSize().x, 0));

    walls[startPos + 3].setP1(sf::Vector2f(window.getSize().x, 0));
    walls[startPos+3].setP2(sf::Vector2f(0, 0));


    float i = 0;

    for (auto &ray : rays)
    {
        ray.setOrigin(rayOrigin.x, rayOrigin.y);
        sf::Vector2f direction = utils::vectorFromAngle(utils::degreeToRadians(i));
        ray.setDir(
            direction.x,
            direction.y);
        i+=0.25;
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
        } else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::R:
                drawWalls = !drawWalls;
                break;
            
            default:
                break;
            }
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

    window.clear(sf::Color(1,1,1));
    if (drawWalls)
    {
    for (auto &wall : walls)
    {
        window.draw(wall);
    }

    }

    for (auto &ray : rays)
    {
        sf::Vector2f closest;
        bool found = false;
        float record = 300;
        for (auto &wall : walls)
        {
            if (ray.cast(wall, hitPos))
            {
                float d = utils ::dist(ray.getOrigin(), hitPos);
                if (d < record)
                {
                    record = d;
                    closest = hitPos;
                    found = true;
                }
                
            }
        }
        if (found)
        {
            sf::Vector2f startPos = ray.getOrigin();
            Boundary ray1(startPos, closest, sf::Color(255,255,255,80));
            window.draw(ray1);
        }
        if (!found)
        {
            window.draw(ray);
        }
    }
    
    window.display();
}
