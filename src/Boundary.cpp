#include "Boundary.hpp"
#include <SFML/Graphics/Vertex.hpp>

Boundary::Boundary(sf::Vector2f b1, sf::Vector2f b2, sf::Color color)
{
  p1 = b1;
  p2 = b2;
  bg = color;
}

Boundary::Boundary()
{
  bg = sf::Color::White;
}

Boundary::~Boundary()
{
}

sf::Vector2f Boundary ::getP1()
{
  return p1;
}

sf::Vector2f Boundary ::getP2()
{
  return p2;
}

void Boundary ::setP1(sf::Vector2f p)
{
  p1 = p;
}
void Boundary ::setP2(sf::Vector2f p)
{
  p2 = p;
}

void Boundary ::setColor(sf::Color color)
{
  bg = color;
}

void Boundary ::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
  sf::Vertex line[] =
      {
          sf::Vertex(p1),
          sf::Vertex(p2)
      };

  line[0].color = bg;
  line[1].color = bg;

  target.draw(line, 2, sf::Lines);
}