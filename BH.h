//BH.h

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Consts.h"
using namespace sf;
using namespace std;

class BlackHole {
public:
	bool pause;
	float currframe;
	CircleShape Blh;

	
	double D = 1E+18;
	double M = D * (4.0 / 3.0) * pi * (100.0 * 100.0 *100.0);

	double Rs = (2 * G * M) / (c * c);

	BlackHole();
	~BlackHole();

	void phys(float time);

};
