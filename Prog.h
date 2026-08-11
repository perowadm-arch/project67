//Prog.h

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BH.h"
using namespace sf;
using namespace std;

class Program {
public:

	int wheight = 750;
	int wwidth = 1280;
	RenderWindow window;
	Clock clock;
	Texture t;

	BlackHole* BH = nullptr;

	Program();
	~Program();

	bool loadtxs();
	void drawall();
	void start();

};
