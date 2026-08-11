#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Program {

	Program();
	~Program();

	int wheight = 750;
	int wwidth = 1280;
	RenderWindow window;
	Clock clock;
	Texture t;

	bool loadtxs();
};