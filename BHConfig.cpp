#include <SFML/Graphics.hpp>
#include <iostream>
#include "BH.h"
using namespace sf;
using namespace std;


BlackHole::BlackHole(Texture& image) {
    sprite.setTexture(image);
    sprite.setTextureRect(IntRect(0, 0, 512, 512));

    currframe = 0;
};
