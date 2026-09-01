//BHConfig.cpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include "BH.h"
#include "Particles.h"
using namespace sf;
using namespace std;

BlackHole::BlackHole() {

    Blh.setRadius(100.f);
    Blh.setOrigin(100.f, 100.f); // Точка привязки в центре круга
    Blh.setPosition(400.f, 370.f);
    Blh.setFillColor(Color::Black);
    Blh.setOutlineColor(Color::White);
    Blh.setOutlineThickness(0.1);
}; 

BlackHole::~BlackHole() {

};

void BlackHole::phys(float time) {
    Blh.rotate(10 * time);
}
