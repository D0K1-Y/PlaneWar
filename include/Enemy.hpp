#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Config.hpp"
#include "Resource.hpp"
#include "Hp.hpp"

sf::Clock enemyTimer; //敌机生成时间


struct EnemyPlane
{
    sf::Sprite sprite;

    int HP = 1;

    bool alive = true;
};

std::vector<EnemyPlane> enemies;

void createEnemy()
{
    EnemyPlane enemy;
    enemy.sprite.setTexture(img[2]);

    sf::Vector2u textureSize = img[2].getSize();

    float scaleX = (float) OTHERPLANE_W / textureSize.x;
    float scaleY = (float) OTHERPLANE_H / textureSize.y;

    enemy.sprite.setScale(
        scaleX,
        scaleY
    );

    //随机x坐标
    float x = rand() % (WINDOW_WIDTH - OTHERPLANE_W);

    float y = -OTHERPLANE_H;

    enemy.sprite.setPosition(x, y);

    enemies.push_back(enemy);
}

void updateEnemy()
{
    for (auto it = enemies.begin(); it != enemies.end(); ){
        it->sprite.move(
            0, 
            3.0f
        );

        sf::Vector2f pos = it->sprite.getPosition();

        if (pos.y > WINDOW_HEIGHT){
            it = enemies.erase(it);

            updateHP(5);
        }else{
            ++it;
        }
    }

}

void spawnEnemy()
{
    if (enemyTimer.getElapsedTime().asSeconds() > 1){
        createEnemy();

        enemyTimer.restart();
    }
}