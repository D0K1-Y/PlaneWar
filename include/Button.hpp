#pragma once

#include <SFML/Graphics.hpp>
#include <string>

struct Button
{
    sf::RectangleShape shape;

    sf::Text text;

    bool isMouseOver(sf::RenderWindow& window)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        return shape.getGlobalBounds().contains(
            static_cast<float>(mousePos.x),
            static_cast<float>(mousePos.y)
        );
    }
};