//Particles.h

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "BH.h"
#include "Menu.h"
using namespace sf;
using namespace std;



class Particle {
public:
	bool pause;
	float currframe = 0;
	VertexArray* particles = nullptr;
	vector<Vector2f> V;

	float m = 4E-36; 
	float MperPixel = 5E+6f;
	Vector2f center = Vector2f(400, 370);



	Particle();
	Particle(BlackHole* BH);
	~Particle();

	virtual void phys(float time, BlackHole* BH);
	virtual void att(Vertex& partcs, Vector2f& vel, BlackHole* BH, float time);
	float rk4(Vertex& partcs, Vector2f& vel, float h);
};

class Light : public Particle {
public:
	Light();
	~Light();

    
	float c_pix = c / MperPixel;
	bool on;
	float tail = 10;

	void phys(float time, BlackHole* BH);
	void att(Vertex& partcs, Vector2f& vel, BlackHole* BH, float time);
	void direction(RenderWindow& window);
};
