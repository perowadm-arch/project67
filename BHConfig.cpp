//BHConfig.cpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include "BH.h"
using namespace sf;
using namespace std;

BlackHole::BlackHole() {};

BlackHole::BlackHole(Texture& image) {
    sprite.setTexture(image);
    sprite.setTextureRect(IntRect(0, 0, 128, 128));
    sprite.setScale(4.f,4.f);
    sprite.setPosition(100, 100);

    currframe = 0;
    pause = false;
}; 

void BlackHole::anim(float time) {
    currframe += 1 * time; //движение 

    if (currframe > 3) { //анимация
        currframe -= 3;
    }

    sprite.setTextureRect(IntRect(128 * int(currframe), 0, 128, 128));
}
