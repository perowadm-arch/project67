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
    particles = new VertexArray(Points, 50000);
    V.resize(particles->getVertexCount());

    for (int i = 0; i < particles->getVertexCount(); i++) {

        float px = rand() % (1480 - (-200)) + (-200);
        float py = rand() % (1050 - (-200)) + (-200);

        (*particles)[i].position = Vector2f(px, py);

        Color color(Color::White);
        color.a = 50;

        (*particles)[i].color = color;

        float dx = center.x - px;
        float dy = center.y - py;

        // Считаем точное расстояние (гипотенузу)
        float Dist = sqrt(dx * dx + dy * dy);

        float Dist_real = Dist * MperPixel;

        float v = sqrt((BH->G * BH->M) / Dist_real);
        float v_pix = v / MperPixel;

        
        V[i] = Vector2f((dy / Dist) * v_pix, (-dx / Dist) * v_pix);

        if (Dist < 250) {
            color.a += 60;
            (*particles)[i].color = color;

            if (Dist < 200) {
                color.a += 50;
                (*particles)[i].color = color;

                if (Dist < 150) {
                    color.a += 85;
                    (*particles)[i].color = color;
                }
            }
        }
        
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

            if (Dist < 50) {
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

Light::Light() : Particle() {

    particles = new VertexArray(Points, 50000);
    V.resize(particles->getVertexCount());

    for (int k = 0; k < 9; k++) {

        (*particles)[k].position = Vector2f(1100, 375 + k);
        (*particles)[k].color = Color::Red;
        Vector2f curr_pos = (*particles)[k].position;

        float dx = center.x - curr_pos.x;
        float dy = center.y - curr_pos.y;
        float Dist = sqrt(dx * dx + dy * dy);

        V[k] = Vector2f(((dx / Dist) * (c_pix*5)), ((-dy / Dist) * (c_pix*5)));
        //V[k] = Vector2f(-10.f, 0.f);

    }

    for (int i = 10; i < particles->getVertexCount(); i++) {
      (*particles)[i].position = Vector2f(1000, 375);
      (*particles)[i].color = Color::Yellow;
            
      V[i] = Vector2f(0.f, 0.f);
    }

}

Light::~Light() {

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
            partcs.position = Vector2f(-9999, -9999);
            //vel = Vector2f((-dx / Dist) * c_pix, (dy / Dist) * c_pix);
            vel = Vector2f(0, 0);
        }
        return;
    }

}

void Light::phys(float time, BlackHole* BH) {

    float x_part = (particles->getVertexCount()-10) / 10.f;

    for (int i = 0; i < 9; i++) {
        att((*particles)[i], V[i], BH, time);

        Vector2f curr_pos = (*particles)[i].position;

        float tx = curr_pos.x - (*particles)[tail - 1].position.x;
        float ty = curr_pos.y - (*particles)[tail - 1].position.y;
        float Pyphagor = sqrt(tx * tx + ty * ty);

        if (tail < x_part && Pyphagor > 0.5f) {
            (*particles)[tail].position = curr_pos;
            //V[tail] = Vector2f(0, 0);
            tail++;
        }
        else {             
            x_part += x_part;
        }

    }
}

void Light::direction(RenderWindow& window) {



};