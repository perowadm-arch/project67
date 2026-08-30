//ParticlesConfig.cpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Particles.h"
#include "BH.h"
using namespace sf;
using namespace std;

Particle::Particle() {
    particles = new VertexArray(Points, 1000);
    for (int i = 0; i < 1000; i++) {
        (*particles)[i].position = Vector2f((rand()%750), (rand() % 1280));
        (*particles)[i].color = Color::White;
    }
}

Particle::~Particle() {
    delete particles;
};

void Particle::att(Vertex& partcs, BlackHole* BH, float time) {
    Vector2f center = BH->Blh.getPosition();
    Vector2f pos = partcs.position;

    float dx = center.x - pos.x;
    float dy = center.y - pos.y;

    // Считаем точное расстояние (гипотенузу)
    float Dist = sqrt(dx * dx + dy * dy);

    //F = G * (M * m) / r^2
    float F = BH->G * ((BH->M * this->m) / (Dist * Dist));

    //a = F / m (Ускорение)
    float a = F / this->m;



    // Проекция вектора ускорения на х или у (направление ускорения)
    float ax = (dx / Dist) * a;
    float ay = (dy / Dist) * a;


    float Vx = ((dx / Dist) * time) * ax;
    float Vy = ((dy / Dist) * time) * ay;

    //(позиция += ускорение * время)
    partcs.position.x += Vx * time;       
    partcs.position.y += Vy * time;

}

void Particle::phys(float time, BlackHole* BH) {
    for (int i = 0; i < 1000; i++) {
        att((*particles)[i], BH, time);
    }
}