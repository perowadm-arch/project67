//Particles.h

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "BH.h"
using namespace sf;
using namespace std;

class Particle {
public:
	bool pause;
	float currframe;
	VertexArray* particles = nullptr;
	vector<Vector2f> V;

	float m = 4E-36; 
	float MperPixel = 1E+7f;
	Vector2f center = Vector2f(400, 370);
	
	Particle();
	Particle(BlackHole* BH);
	~Particle();

	void phys(float time, BlackHole* BH);
	void att(Vertex& partcs, Vector2f& vel, BlackHole* BH, float time);
};

class Light : public Particle {
public:
	Light();
	~Light();


	float c = 3E+8;
	bool on;

	void direction(RenderWindow& window);
};