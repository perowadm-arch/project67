//BH.h

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class BlackHole {
public:
	bool pause;
	float currframe;
	VertexArray* particles = nullptr;
	CircleShape Blh;

	BlackHole();
	~BlackHole();

	//void update(float time);

	void phys(float time);
	void att(VertexArray* partcs);
};
