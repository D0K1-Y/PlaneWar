#pragma once

enum class GameState
{
    MENU,
    PLAYING,
    GAME_OVER
};

inline GameState gameState = GameState::MENU;