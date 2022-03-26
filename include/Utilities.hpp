#include <SFML/Graphics.hpp>
#include <cmath>

namespace utils
{

  float length(sf::Vector2f vector);
  sf::Vector2f normalize(sf::Vector2f vector);

  void transform(float &x, float &y, sf::Vector2f origin);
  bool intersect(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3, sf::Vector2f &point);
  sf::Vector2f vectorFromAngle(float angle);
  float degreeToRadians(float degree);
  float dist(sf::Vector2f p1, sf::Vector2f p2);
  int random(int max);
  int time();
  
}