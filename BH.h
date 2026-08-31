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
	CircleShape Blh;

	float G = 6.674E-11; 
	float M = 8E+36; 

	BlackHole();
	~BlackHole();

	void phys(float time);

};
