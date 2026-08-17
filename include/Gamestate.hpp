#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "Config.hpp"
#include "Resource.hpp"
#include "Gameset.hpp"
#include "Score.hpp"



sf::Text gameOverText;
sf::Text finalScoreText;
sf::Text restartText;
sf::Text exitText;

void initGameOver()
{
    gameOverText.setFont(font);
    gameOverText.setCharacterSize(80);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setString("GAME OVER");

    sf::FloatRect gameOverBounds = gameOverText.getLocalBounds();

    gameOverText.setPosition(
        WINDOW_WIDTH / 2.0f - gameOverBounds.width / 2.0f,
        WINDOW_HEIGHT / 2.0f - 150
    );

    finalScoreText.setFont(font);
    finalScoreText.setCharacterSize(40);
    finalScoreText.setFillColor(sf::Color::White);

    restartText.setFont(font);
    restartText.setCharacterSize(30);
    restartText.setFillColor(sf::Color::White);
    restartText.setString("R to restart");

    sf::FloatRect restartBounds =
        restartText.getLocalBounds();

    restartText.setPosition(
        WINDOW_WIDTH / 2.0f - restartBounds.width / 2.0f,
        WINDOW_HEIGHT / 2.0f + 20
    );

    exitText.setFont(font);
    exitText.setCharacterSize(30);
    exitText.setFillColor(sf::Color::White);
    exitText.setString("ESC to exit");

    sf::FloatRect exitBounds =
        exitText.getLocalBounds();

    exitText.setPosition(
        WINDOW_WIDTH / 2.0f - exitBounds.width / 2.0f,
        WINDOW_HEIGHT / 2.0f + 70
    );
}

void updateGameOverText()
{
    finalScoreText.setString(
        "final score: " + std::to_string(score)
    );

    sf::FloatRect bounds =
        finalScoreText.getLocalBounds();

    finalScoreText.setPosition(
        WINDOW_WIDTH / 2.0f - bounds.width / 2.0f,
        WINDOW_HEIGHT / 2.0f - 40
    );
}