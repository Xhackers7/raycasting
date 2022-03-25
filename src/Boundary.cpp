#include "Boundary.hpp"
#include <SFML/Graphics/Vertex.hpp>

Boundary::Boundary(sf::Vector2f b1, sf::Vector2f b2)
{
  p1 = b1;
  p2 = b2;
}

Boundary::Boundary()
{
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

void Boundary ::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
  sf::Vertex line[] =
      {
          sf::Vertex(p1),
          sf::Vertex(p2)
      };

  target.draw(line, 2, sf::Lines);
}