#include "Ray.hpp"
#include <iostream>
#include <SFML/Graphics/Vertex.hpp>
#include "Utilities.hpp"
#include<cstdio>


Ray::Ray(float x, float y) 
{
  origin = sf::Vector2f(x, y);
  dir = sf::Vector2f(1, 0);
  scale = 80;
}

Ray::Ray()
{
  origin = sf::Vector2f(20, 20);
  dir = sf::Vector2f(1, 0);
  scale = 80;
}

Ray::~Ray() {

}

sf::Vector2f Ray ::setOrigin(float x, float y)
{
  origin = sf::Vector2f(x, y);
}

sf::Vector2f Ray ::setDir(float x, float y)
{
  dir = utils::normalize(sf::Vector2f(x, y));
  
}

sf::Vector2f Ray ::getOrigin()
{
  return origin;
}

sf::Vector2f Ray ::getDir()
{
  sf::Vector2f temp;
  temp = dir;
  utils::transform(temp.x, temp.y, origin);
  return temp;
}

bool Ray ::cast(Boundary wall, sf::Vector2f &point)
{
  return utils::intersect(wall.getP1(), wall.getP2(), getOrigin(), getDir(), point);
}

void Ray ::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  sf::Vector2f p1(0, 0);
  sf::Vector2f p2(dir.x*scale, dir.y*scale);
  utils::transform(p1.x, p1.y, origin);
  utils::transform(p2.x, p2.y, origin);
  sf::Vertex line[] =
      {
          sf::Vertex(p1),
          sf::Vertex(p2)
      };
  target.draw(line, 2, sf::Lines);
  utils::transform(p1.x, p1.y, -origin);
  utils::transform(p2.x, p2.y, -origin);
}

