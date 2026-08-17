#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Resource.hpp"
#include "Gamestate.hpp"


int HP = 100;

sf::Text HpText;

bool playerAlive = true;

void initHP()
{
    HpText.setFont(font);

    HpText.setCharacterSize(40);

    HpText.setFillColor(sf::Color::Green);

    HpText.setPosition(300, 20);

    HpText.setString("HP: 100");
}

void updateHP(int value)
{
    if (HP <= 0)
    {
        HP = 0;

        playerAlive = false;

        gameOver = true;

        gameState = GameState::GAME_OVER;
    }
    else
    {
        HP -= value;
    }

    HpText.setString("HP: " + std::to_string(HP));
}