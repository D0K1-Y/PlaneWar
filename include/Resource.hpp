#pragma once
#include "Config.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

std::vector<sf::Texture> img(6);
sf::Sprite bgSprite; //背景
sf::Sprite ourPlaneSprite; //我方飞机

sf::Font font;

//初始化
void init()
{
    //加载背景
    if (!img[0].loadFromFile("image/background.jpg")) {
        std::cerr << "错误：无法加载背景！" << std::endl;
    }else {
        bgSprite.setTexture(img[0]);

        //获取纹理的原始像素尺寸
        sf::Vector2u textureSize = img[0].getSize();
        if (textureSize.x != 0 && textureSize.y != 0) {
            float scaleX = (float)WINDOW_WIDTH / textureSize.x;
            float scaleY = (float)WINDOW_HEIGHT / textureSize.y;
            bgSprite.setScale(scaleX, scaleY);
        }else {
            std::cerr << "错误：读取失败！" << std::endl;
        }
    }

    //加载我方飞机
    if (!img[1].loadFromFile("image/ourPlane.png")) {
        std::cerr << "错误：无法加载飞机！" << std::endl;
    }else {
        img[1].loadFromFile("image/ourPlane.png");
        ourPlaneSprite.setTexture(img[1]);

        //获取纹理的原始像素尺寸
        sf::Vector2u textureSize = img[1].getSize();
        if (textureSize.x != 0 && textureSize.y != 0) {
            float scaleX = (float)OURPLANE_W / textureSize.x;
            float scaleY = (float)OURPLANE_H / textureSize.y;
            ourPlaneSprite.setScale(scaleX, scaleY);
        }else {
            std::cerr << "错误：读取失败！" << std::endl;
        }

        ourPlaneSprite.setPosition(
            WINDOW_WIDTH / 2.0f - OURPLANE_W / 2.0f,
            WINDOW_HEIGHT - OURPLANE_H - 30.0f
        );
    }

    //加载敌方飞机
    if (!img[2].loadFromFile("image/otherplane.png")) {
        std::cerr << "错误：无法加载飞机！" << std::endl;
    }

    if (!img[3].loadFromFile("image/bullet.png")) {
        std::cerr << "错误：无法加载子弹！" << std::endl;
    }

    if (!font.loadFromFile("font/msyh.ttc")){
        std::cerr << "字体加载失败！" << std::endl;
    }

    if (!img[4].loadFromFile("image/Boss.png")) {
        std::cerr << "错误：无法加载Boss！" << std::endl;
    }

    if (!img[5].loadFromFile("image/BossBullet.png")) {
        std::cerr << "错误：无法加载Boss子弹！" << std::endl;
    }
}
