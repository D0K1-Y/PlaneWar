#pragma once

#include <SFML/Graphics.hpp>
#include "Config.hpp"
#include "Resource.hpp"
#include "Score.hpp"
#include <string>
#include "Gameset.hpp"


bool bossSpawned = false;


struct Boss 
{
    sf::Sprite sprite;

    sf::Text HpText;

    int HP = 100;

    bool alive = false;

    float speed = 3.0f;

    int direction = 1;

    int phase = 1;
};

Boss boss;

bool bossExist = false;

void createBoss()
{
    boss.sprite.setTexture(img[4]);

    sf::Vector2u textureSize = img[4].getSize();

    float scaleX = (float) BOSS_W / textureSize.x;
    float scaleY = (float) BOSS_H / textureSize.y;

    boss.sprite.setScale(
        scaleX,
        scaleY
    );

    boss.sprite.setPosition(
        WINDOW_WIDTH / 2.0f - BOSS_W / 2.0f,
        200
    );

    boss.HP = 100;

    boss.alive = true;

    bossExist = true;

    boss.HpText.setFont(font);

    boss.HpText.setCharacterSize(40);

    boss.HpText.setFillColor(sf::Color::Red);

    boss.HpText.setString("BOSSHP: 100");

    boss.HpText.setPosition(
        boss.sprite.getPosition().x,
        boss.sprite.getPosition().y - 40
    );

}

void checkBossSpawn()
{
    if (score >= BOSS_SCORE && !bossSpawned){
        createBoss();

        bossSpawned = true;
    }
}

void updateBossPhase()
{
    if (boss.HP > 70)
    {
        boss.phase = 1;
    }
    else if (boss.HP > 30)
    {
        boss.phase = 2;
    }
    else
    {
        boss.phase = 3;
    }
}

void updateBoss()
{
    if (!bossExist){
        return;
    }

    //移动
    boss.sprite.move(
        boss.speed * boss.direction,
        0
    );

    sf::Vector2f pos = boss.sprite.getPosition();

    if (pos.x + BOSS_W >= BOSS_RIGHT){
        boss.direction = -1;
    }

    if (pos.x <= BOSS_LEFT){
        boss.direction = 1;
    }

    boss.HpText.setPosition(
        pos.x,
        pos.y - 40
    );
}
void updateBossHP(int value)
{
    if (boss.HP <= 0)
    {
        boss.HP = 0;

        addScore(100);

        boss.alive = false;

        bossExist = false;
        
        gameOver = true;

        gameWin = true;

        gameState = GameState::GAME_OVER;
    }
    else
    {
        boss.HP -= value;
    }

    boss.HpText.setString("BOSSHP: " + std::to_string(boss.HP));

    updateBossPhase();

}
