//Prog.h

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "BH.h"
#include "Menu.h"
using namespace sf;
using namespace std;

class Program {
public:

	int wheight = 750;
	int wwidth = 1280;

	float panelWidth = 280.f;

	RenderWindow window;
	Clock clock;

	BlackHole* BH = nullptr;

	Program();
	~Program();

	void drawall();
	void start();

};
