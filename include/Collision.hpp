#pragma once

#include "Enemy.hpp"
#include "Bullet.hpp"
#include "Resource.hpp"
#include "Score.hpp"
#include "Boss.hpp"
#include "BossBullet.hpp"

void BulletToEnemy()
{
    for (auto bullet = bullets.begin(); bullet != bullets.end(); ) {
        bool hit = false;

        for (auto enemy = enemies.begin(); enemy != enemies.end(); ){

            auto box = enemy->sprite.getGlobalBounds();

            box.left += 3;
            box.top  += 3;
            box.width -= 6;
            box.height -= 6;

            if (bullet->sprite.getGlobalBounds().intersects(box)){
                enemy = enemies.erase(enemy);

                addScore(5);
                
                hit = true;

                break;
            }else{
                ++enemy;
            }
        }

        if (hit){
            bullet = bullets.erase(bullet);
        }else{
            ++bullet;
        }
    }
}

void BulletToBoss()
{
    if (bossExist)
    {
        for (auto bullet = bullets.begin(); bullet != bullets.end(); )
        {
            auto boss_box = boss.sprite.getGlobalBounds();
            
            boss_box.left += boss_box.width * 0.15f;
            boss_box.top += boss_box.height * 0.15f;

            boss_box.width *= 0.7f;
            boss_box.height *= 0.7f;

            if (bullet->sprite.getGlobalBounds().intersects(boss_box))
            {
                updateBossHP(2);

                bullet = bullets.erase(bullet);

                if (!bossExist){
                    break;
                }
            }
            else
            {
                ++bullet;
            }
        }
    }
    else
    {
        return;
    }
}

void bossBulletToPlayer()
{
    if (!bossExist)
    {
        return;
    }

    for (auto b_bullet = bossBullets.begin(); b_bullet != bossBullets.end(); )
    {
        auto box = ourPlaneSprite.getGlobalBounds();

        box.left += box.width * 0.15f;
        box.top += box.height * 0.15f;

        box.width *= 0.7f;
        box.height *= 0.7f;

        if (b_bullet->sprite.getGlobalBounds().intersects(box))
        {
            updateHP(5);

            b_bullet = bossBullets.erase(b_bullet);
        }
        else
        {
            ++b_bullet;
        }
    }
}

void EnemyToPlayer()
{
    for (auto enemy = enemies.begin(); enemy != enemies.end(); )
    {
        auto box = ourPlaneSprite.getGlobalBounds();

        box.left += box.width * 0.15f;
        box.top += box.height * 0.15f;

        box.width *= 0.7f;
        box.height *= 0.7f;

        if (enemy->sprite.getGlobalBounds().intersects(box))
        {
            updateHP(5);

            enemy = enemies.erase(enemy);
        }
        else
        {
            ++enemy;
        }
    }
}

void checkCollision()
{
    BulletToEnemy();

    BulletToBoss();

    bossBulletToPlayer();

    EnemyToPlayer();
}