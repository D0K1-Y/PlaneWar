#pragma once

#include "Config.hpp"
#include "Resource.hpp"
#include "Score.hpp"
#include "Hp.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Boss.hpp"
#include "BossBullet.hpp"
#include "Gameset.hpp"



void restartGame()
{
    HP = 100;
    playerAlive = true;

    bossExist = false;
    bossSpawned = false;

    boss.HP = 100;
    boss.alive = false;
    boss.phase = 1;

    enemies.clear();

    bullets.clear();

    bossBullets.clear();

    score = 0;

    scoreText.setString("Score: 0");
    HpText.setString("HP: 100");

    ourPlaneSprite.setPosition(
        WINDOW_WIDTH / 2.0f - OURPLANE_W / 2.0f,
        WINDOW_HEIGHT - OURPLANE_H - 30.0f
    );

    enemyTimer.restart();
    bulletTimer.restart();
    bossBulletTimer.restart();

    gameOver = false;

    gameState = GameState::PLAYING;
}