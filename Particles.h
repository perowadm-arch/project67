//Particles.h

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BH.h"
using namespace sf;
using namespace std;

class Particle {
public:
	bool pause;
	float currframe;
	VertexArray* particles = nullptr;

	float m = 4E-36;
	
	Particle();
	~Particle();

	void phys(float time, BlackHole* BH);
	void att(Vertex& partcs, BlackHole* BH, float time);
};

