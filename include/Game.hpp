#pragma once

#include "Config.hpp"
#include "Resource.hpp"
#include "Enemy.hpp"
#include "Input.hpp"
#include "Bullet.hpp"
#include "Collision.hpp"
#include "Score.hpp"
#include "Hp.hpp"
#include "Boss.hpp"
#include "BossBullet.hpp"
#include "Gamestate.hpp"

void start()
{
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        sf::String(L"黄室战争"),
        sf::Style::Default
    );

    window.setFramerateLimit(30);

    init();

    initScore();

    initHP();

    initGameOver();
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (!gameOver)
        {
            //飞机移动
            if (playerAlive)
            {
                Input();

                shoot();
            }

            //生成敌机
            spawnEnemy();

            //敌机移动
            updateEnemy();

            //子弹
            updateBullet();

            //击毁
            checkCollision();

            //Boss达到分数
            checkBossSpawn();


            //生成Boss
            if (bossExist)
            {
                updateBoss();

                bossShoot();

            }

            updateBossBullet();
        }
        else
        {
            updateGameOverText();
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                restartGame();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        //清空窗口
        window.clear();

        //绘制背景
        window.draw(bgSprite);

        //绘制我方飞机
        window.draw(ourPlaneSprite);

        //绘制子弹
        for (auto& bullet : bullets)
        {
            window.draw(bullet.sprite);
        }   

        //绘制敌机
        for (auto& enemy : enemies) {
            window.draw(enemy.sprite);
        }

        //绘制Boss
        if (bossExist){
            window.draw(boss.sprite);

            window.draw(boss.HpText);
        }

        //Boss子弹
        for (auto& bullet : bossBullets){
            window.draw(bullet.sprite);
        }

        //绘制分数
        window.draw(scoreText);

        //绘制HP
        window.draw(HpText);

        if (gameOver)
        {
            window.draw(gameOverText);
            window.draw(finalScoreText);
            window.draw(restartText);
            window.draw(exitText);
        }

        //显示画面
        window.display();
    }
    window.close();
}