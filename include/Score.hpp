#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Resource.hpp"

int score = 0;

sf::Text scoreText;

void initScore()
{
    scoreText.setFont(font);

    scoreText.setCharacterSize(40);

    scoreText.setFillColor(sf::Color::Blue);

    scoreText.setPosition(20, 20);

    scoreText.setString("Score: 0");
}

void addScore(int value)
{
    score += value;

    scoreText.setString("Score: " + std::to_string(score));
}