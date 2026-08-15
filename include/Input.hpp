#pragma once
#include <SFML/Graphics.hpp>
#include "Config.hpp"
#include "Resource.hpp"


void Input() 
{
    sf::Vector2f pos = ourPlaneSprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        if (pos.y > 0){
            ourPlaneSprite.move(0.0f, -15.0f);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        if (pos.y < WINDOW_HEIGHT - OURPLANE_H){
            ourPlaneSprite.move(0.0f, 15.0f);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        if (pos.x > 0){
            ourPlaneSprite.move(-15.0f, 0.0f);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if (pos.x < WINDOW_WIDTH - OURPLANE_W){
            ourPlaneSprite.move(15.0f, 0.0f);
        }
    }
}