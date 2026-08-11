//BHConfig.cpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include "BH.h"
using namespace sf;
using namespace std;

BlackHole::BlackHole() {};

BlackHole::BlackHole(Texture& image) {
    sprite.setTexture(image);
    sprite.setTextureRect(IntRect(0, 0, 512, 512));
    sprite.setScale(2.f, 2.f);
    sprite.setPosition(100, 500);

    currframe = 0;
    pause = false;
}; 

void BlackHole::anim(float time) {
    currframe += 3 * time; //движение 

    if (currframe > 2) { //анимация
        currframe -= 2;
    }

    sprite.setTextureRect(IntRect(512 * int(currframe), 0, 512, 512));
}
