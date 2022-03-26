#pragma once
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Color.hpp>


class Boundary : public sf::Drawable
{
private:
    sf::Vector2f p1;
    sf::Vector2f p2;
    sf::Color bg;

public:
    Boundary(sf::Vector2f b1, sf::Vector2f b2, sf::Color color=sf::Color::White);
    Boundary();
    ~Boundary();
    
    sf::Vector2f getP1();
    sf::Vector2f getP2();
    void setColor(sf::Color color);
    void setP1(sf::Vector2f p);
    void setP2(sf::Vector2f p);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};