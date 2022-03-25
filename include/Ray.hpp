#pragma once
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Boundary.hpp"


class Ray : public sf::Drawable
{
private:
    sf::Vector2f origin;
    sf::Vector2f dir;
    
public:
    float scale;
    Ray(float x, float y);
    Ray();
    ~Ray();

    sf::Vector2f setOrigin(float x, float y);
    sf::Vector2f getOrigin();
    sf::Vector2f setDir(float x, float y);
    sf::Vector2f getDir();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    bool cast(Boundary wall, sf::Vector2f &point);
    bool interSection(sf::Vector2f A, sf::Vector2f B, sf::Vector2f C, sf::Vector2f D, sf::Vector2f &point);
};