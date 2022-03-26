#include "Utilities.hpp"
#include <cmath>
#include <ctime>


  float utils:: length(sf::Vector2f vector)
  {
    return sqrt((vector.x * vector.x) + (vector.y * vector.y));
  }

  sf::Vector2f utils ::normalize(sf::Vector2f vector)
  {
    return sf::Vector2f(
        (vector.x / utils::length(vector)),
        (vector.y / utils::length(vector)));
  }

  void utils ::transform(float &x, float &y, sf::Vector2f origin)
  {
    x += origin.x;
    y += origin.y;
  }

  bool utils ::intersect(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Vector2f &point)
  {
   
    float A1 = p1.y - p0.y,
        B1 = p0.x - p1.x,
        C1 = A1 * p0.x + B1 * p0.y,
        A2 = p3.y - p2.y,
        B2 = p2.x - p3.x,
        C2 = A2 * p2.x + B2 * p2.y,
        denominator = A1 * B2 - A2 * B1;

    if (denominator == 0)
    {
      return false;
    }

    float intersectX = (B2 * C1 - B1 * C2) / denominator,
        intersectY = (A1 * C2 - A2 * C1) / denominator,
        rx0 = (intersectX - p0.x) / (p1.x - p0.x),
        ry0 = (intersectY - p0.y) / (p1.y - p0.y),
        rx1 = (intersectX - p2.x) / (p3.x - p2.x),
        ry1 = (intersectY - p2.y) / (p3.y - p2.y);

    if (((rx0 >= 0 && rx0 <= 1) || (ry0 >= 0 && ry0 <= 1)) &&
        ((rx1 >= 0) || (ry1 >= 0)))
    {
      point = sf::Vector2f(intersectX, intersectY);
      return true;
    }
    else
    {
      return false;
    }
  }

sf::Vector2f utils ::vectorFromAngle(float angle)
{
  return sf::Vector2f(
    cos(angle),
    sin(angle)
  );
}
float utils ::degreeToRadians(float degree)
{
  float pi = 3.1416;
  return (degree * (pi/180));
}

float utils ::dist(sf::Vector2f p1, sf::Vector2f p2)
{
  return sqrt(((p2.x - p1.x)*(p2.x - p1.x))+((p2.y-p1.y)*(p2.y-p1.y)));
}

int utils ::time()
{
  return std::time(0);
}

int utils ::random(int max)
{
  return rand()%max;
}
