//ParticlesConfig.cpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Particles.h"
#include "BH.h"
using namespace sf;
using namespace std;

Particle::Particle() {
    particles = new VertexArray(Points, 10000);
    V.resize(particles->getVertexCount());

    for (int i = 0; i < particles->getVertexCount(); i++) {
        (*particles)[i].position = Vector2f((rand()%1280), (rand() % 750));
        (*particles)[i].color = Color::White;

        V[i] = Vector2f(30.f, -10.f);
    }
}

Particle::~Particle() {
    delete particles;
};

void Particle::att(Vertex& partcs, Vector2f& vel, BlackHole* BH, float time) {

    float MperPixel = 1E+7f;

    Vector2f center = BH->Blh.getPosition();
    Vector2f pos = partcs.position;

    float dx = center.x - pos.x;
    float dy = center.y - pos.y;

    // Считаем точное расстояние (гипотенузу)
    float Dist = sqrt(dx * dx + dy * dy);
    if (Dist < 100) {
        partcs.position = Vector2f(rand() % 1280, rand() % 750);
        vel = Vector2f(30.f, -10.f);
        return;
    }

    float Dist_real = Dist * MperPixel;

    //F = G * (M * m) / r^2
    float F = BH->G * ((BH->M * this->m) / (Dist_real * Dist_real));

    //a = F / m (Ускорение)
    float a = F / this->m;

    float a_pixel = a / MperPixel;

    // Проекция вектора ускорения на х или у (направление ускорения)
    float ax = (dx / Dist) * a_pixel;
    float ay = (dy / Dist) * a_pixel;


    vel.x += ax * time;
    vel.y += ay * time;

    //(позиция += ускорение * время)
    partcs.position.x += vel.x * time;
    partcs.position.y += vel.y * time;


}

void Particle::phys(float time, BlackHole* BH) {
    for (int i = 0; i < particles->getVertexCount(); i++) {
        att((*particles)[i], V[i], BH, time);
    }
}