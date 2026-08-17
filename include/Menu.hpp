#pragma once

#include <SFML/Graphics.hpp>
#include "Config.hpp"
#include "Button.hpp"
#include "Resource.hpp"

Button startButton;
Button exitButton;

void initMenu()
{
    startButton.shape.setSize(sf::Vector2f(300, 80));
    startButton.shape.setPosition(WINDOW_WIDTH / 2.0f - 150, 500);
    startButton.shape.setFillColor(sf::Color(100, 100, 100));
    startButton.shape.setOutlineThickness(3);
    startButton.shape.setOutlineColor(sf::Color::White);


    startButton.text.setFont(font);
    startButton.text.setCharacterSize(40);
    startButton.text.setFillColor(sf::Color::White);
    startButton.text.setString("START GAME");
    sf::FloatRect startBounds = startButton.text.getLocalBounds();

    startButton.text.setOrigin(
        startBounds.left + startBounds.width / 2.0f,
        startBounds.top + startBounds.height / 2.0f
    );

    startButton.text.setPosition(
        startButton.shape.getPosition().x +
            startButton.shape.getSize().x / 2.0f,

        startButton.shape.getPosition().y +
            startButton.shape.getSize().y / 2.0f
    );

    exitButton.shape.setSize(sf::Vector2f(300, 80));
    exitButton.shape.setPosition(WINDOW_WIDTH / 2.0f - 150, 600);
    exitButton.shape.setFillColor(sf::Color(100, 100, 100));
    exitButton.shape.setOutlineThickness(3);
    exitButton.shape.setOutlineColor(sf::Color::White);

    exitButton.text.setFont(font);
    exitButton.text.setCharacterSize(40);
    exitButton.text.setFillColor(sf::Color::White);
    exitButton.text.setString("EXIT");
    sf::FloatRect exitBounds = exitButton.text.getLocalBounds();

    exitButton.text.setOrigin(
        exitBounds.left + exitBounds.width / 2.0f,
        exitBounds.top + exitBounds.height / 2.0f
    );
    exitButton.text.setPosition(
        exitButton.shape.getPosition().x +
            exitButton.shape.getSize().x / 2.0f,

        exitButton.shape.getPosition().y +
            exitButton.shape.getSize().y / 2.0f
    );


}

void updateMenu(sf::RenderWindow& window)
{
    if (startButton.isMouseOver(window))
    {
        startButton.shape.setFillColor(sf::Color(50, 50, 50));

        startButton.text.setFillColor(sf::Color::Yellow);
    }
    else
    {
        startButton.shape.setFillColor(sf::Color(100, 100, 100));

        startButton.text.setFillColor(sf::Color::White);
    }

    if (exitButton.isMouseOver(window))
    {
        exitButton.shape.setFillColor(sf::Color(50, 50, 50));

        exitButton.text.setFillColor(sf::Color::Yellow);
    }
    else
    {
        exitButton.shape.setFillColor(sf::Color(100, 100, 100));

        exitButton.text.setFillColor(sf::Color::White);
    }
}