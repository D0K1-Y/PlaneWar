#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Config.hpp"
#include "Resource.hpp"


sf::Clock bulletTimer; //子弹时间

struct Bullet
{
    sf::Sprite sprite;

    bool alive = true;
};

std::vector<Bullet> bullets;

void createBullet()
{
    Bullet bullet;

    bullet.sprite.setTexture(img[3]);

    sf::Vector2u textureSize = img[3].getSize();

    float scaleX = (float) BULLET_W / textureSize.x;
    float scaleY = (float) BULLET_H / textureSize.y;

    bullet.sprite.setScale(
        scaleX,
        scaleY
    );

    sf::Vector2f planePos = ourPlaneSprite.getPosition();

    bullet.sprite.setPosition(
        planePos.x + OURPLANE_W / 2 - BULLET_W / 2,
        planePos.y - BULLET_H
    );

    bullets.push_back(bullet);
}

void updateBullet()
{
    for (auto it = bullets.begin(); it != bullets.end(); ){
        it->sprite.move(0, -10.0f);

        if (it->sprite.getPosition().y < 0){
            it = bullets.erase(it);
        }else{
            ++it;
        }
    }
}

void shoot()
{
    if (bulletTimer.getElapsedTime().asMilliseconds() > 300){
        createBullet();

        bulletTimer.restart();
    }
}