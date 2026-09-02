//ParticlesConfig.cpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Particles.h"
#include "BH.h"
#include "Menu.h"
using namespace sf;
using namespace std;

Particle::Particle() {

};

Particle::Particle(BlackHole* BH) {
    particles = new VertexArray(Points, 10000);
    V.resize(particles->getVertexCount());

    for (int i = 0; i < particles->getVertexCount(); i++) {

        float px = rand() % (1480 - (-200)) + (-200);
        float py = rand() % (1050 - (-200)) + (-200);

        (*particles)[i].position = Vector2f(px, py);
        (*particles)[i].color = Color::White;

        float dx = center.x - px;
        float dy = center.y - py;

        // Считаем точное расстояние (гипотенузу)
        float Dist = sqrt(dx * dx + dy * dy);

        float Dist_real = Dist * MperPixel;

        float v = sqrt((BH->G * BH->M) / Dist_real);
        float v_pix = v / MperPixel;

        
        V[i] = Vector2f((dy / Dist) * v_pix, (-dx / Dist) * v_pix);
        
    }
}

Particle::~Particle() {
    delete particles;
};

void Particle::att(Vertex& partcs, Vector2f& vel, BlackHole* BH, float time) {
    Vector2f pos = partcs.position;

    float dx = center.x - pos.x;
    float dy = center.y - pos.y;

    // Считаем точное расстояние (гипотенузу)
    float Dist = sqrt(dx * dx + dy * dy);

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

    if (Dist < 100) {

        float factor = (100.f / Dist) * (100.f / Dist);
        float a_pix_s = a_pixel * factor;

        float Ax = (dx / Dist) * a_pix_s;
        float Ay = (dy / Dist) * a_pix_s;

        vel.x += Ax * time;
        vel.y += Ay * time;

        if (Dist < 50){
            partcs.position = Vector2f(-9999.f, -9999.f);
        vel = Vector2f(0, 0);
    }
        return;
    }

}

void Particle::phys(float time, BlackHole* BH) {

    for (int i = 0; i < particles->getVertexCount(); i++) {
        att((*particles)[i], V[i], BH, time);
    }
}


//-----------------------------------------------------------LIGHT

Light::Light(Menu* MN) : Particle() {

    particles = new VertexArray(Points, 10000);
    V.resize(particles->getVertexCount());


    if (on) {
        for (int i = 0; i < particles->getVertexCount(); i++) {
            (*particles)[i].position = Vector2f(1000+i, 375+i);
            (*particles)[i].color = Color::Yellow;

            Vector2f pos = Vector2f(1000, 375 + i*0.0f);
            float dx = center.x - pos.x;
            float dy = center.y - pos.y;
            float Dist = sqrt(dx * dx + dy * dy);
            float c_pix = c / MperPixel;
            V[i] = Vector2f((dy / Dist) * c_pix, (-dx / Dist) * c_pix);
        }
    }

}

Light::~Light() {
    delete particles;
}

void Light::att(Vertex& partcs, Vector2f& vel, BlackHole* BH, float time) {
    Vector2f pos = partcs.position;

    float dx = center.x - pos.x;
    float dy = center.y - pos.y;

    // Считаем точное расстояние (гипотенузу)
    float Dist = sqrt(dx * dx + dy * dy);

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

    if (Dist < 100) {

        float factor = (100.f / Dist) * (100.f / Dist);
        float a_pix_s = a_pixel * factor;

        float Ax = (dx / Dist) * a_pix_s;
        float Ay = (dy / Dist) * a_pix_s;

        vel.x += Ax * time;
        vel.y += Ay * time;

        if (Dist < 50) {
            partcs.position = Vector2f(-9999.f, -9999.f);
            vel = Vector2f(0, 0);
        }
        return;
    }

}

void Light::phys(float time, BlackHole* BH) {

    for (int i = 0; i < particles->getVertexCount(); i++) {
        att((*particles)[i], V[i], BH, time);
    }
}

void Light::direction(RenderWindow& window) {


};