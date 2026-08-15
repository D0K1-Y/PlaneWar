#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Config.hpp"
#include "Resource.hpp"
#include "Boss.hpp"

sf::Clock bossBulletTimer;

struct BossBullet
{
    sf::Sprite sprite;

    sf::Vector2f velocity;
};

std::vector<BossBullet> bossBullets;

void createBossBullet(float x, sf::Vector2f velocity)
{
    BossBullet bossbullet;

    bossbullet.sprite.setTexture(img[5]);


    sf::Vector2u textureSize = img[5].getSize();

    float scaleX = (float) BULLET_W / textureSize.x;
    float scaleY = (float) BULLET_H / textureSize.y;

    bossbullet.sprite.setScale(
        scaleX,
        scaleY
    );

    sf::Vector2f bossPos = boss.sprite.getPosition();

    bossbullet.sprite.setPosition(
        x,
        bossPos.y + BOSS_H
    );

    bossbullet.velocity = velocity;

    bossBullets.push_back(bossbullet);
}

void updateBossBullet()
{
    for (auto it = bossBullets.begin(); it != bossBullets.end(); ){
        it->sprite.move(it->velocity);

        if (it->sprite.getPosition().y > WINDOW_HEIGHT){
            it = bossBullets.erase(it);
        }else{
            ++it;
        }
    }
}


void fanAttack()
{
    sf::Vector2f pos = boss.sprite.getPosition();

    createBossBullet(
        pos.x + 20, sf::Vector2f(-3, 10)
    );

    createBossBullet(
        pos.x + BOSS_W / 2, sf::Vector2f(0, 10)
    );

    createBossBullet(
        pos.x + BOSS_W - 20, sf::Vector2f(3, 10)
    );
}

float getBossShootInterval()
{
    if (boss.phase == 1)
        return 800;

    if (boss.phase == 2)
        return 500;

    return 300;
}

void bossShoot()
{
    if (!bossExist){
        return;
    }

    if (bossBulletTimer.getElapsedTime().asMilliseconds() > getBossShootInterval()){
        updateBossPhase();

        switch(boss.phase)
        {
        case 1:
        {
            
            createBossBullet(
                boss.sprite.getPosition().x + BOSS_W / 2 - BULLET_W / 2,
                sf::Vector2f(0, 10)
            );

            break;
        }

        case 2:
        {
            float x = boss.sprite.getPosition().x;

            createBossBullet(x + 20, sf::Vector2f(0, 10));

            createBossBullet(x + BOSS_W / 2, sf::Vector2f(0, 10));

            createBossBullet(x + BOSS_W - 20, sf::Vector2f(0, 10));

            break;
        }

        case 3:
        {
            fanAttack();

            break;
        }
        }

        bossBulletTimer.restart();
    }
}