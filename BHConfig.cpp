//BHConfig.cpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include "BH.h"
using namespace sf;
using namespace std;

BlackHole::BlackHole() {
    particles = new VertexArray(Points, 1000);
    for (int i = 0; i < 1000; i++) {
        (*particles)[i].position = Vector2f(700, 370);
        (*particles)[i].color = Color::White;
    }

    Blh.setRadius(100.f);
    Blh.setOrigin(100.f, 100.f); // “очка прив€зки в центре круга
    Blh.setPosition(400.f, 370.f);
    Blh.setFillColor(Color::Black);
    Blh.setOutlineColor(Color::White);
    Blh.setOutlineThickness(1.f);
}; 

BlackHole::~BlackHole() {
    delete particles;
};

void BlackHole::att(VertexArray* partcs) {
    Vector2f center = Blh.getPosition();

    for (int i = 0; i < partcs->getVertexCount(); i++) {

        Vector2f pos = (*partcs)[i].position;

        // Ќаходим разницу координат между частицей и центром
        float dx = center.x - pos.x;
        float dy = center.y - pos.y;

        // —читаем точное рассто€ние (гипотенузу)
        float dist = sqrt(dx * dx + dy * dy);


        
    }
}

void BlackHole::phys(float time) {
    Blh.rotate(10 * time);

    float speed = 1.f;

    for (int i = 0; i < 1000; i++) {
        att(particles);
        (*particles)[i].position.y += speed * time;
        (*particles)[i].position.x += speed * time;
    }
}
