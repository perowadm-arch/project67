#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class BlackHole {
public:
	Sprite sprite;
	FloatRect rect;
	bool pause = false;
	float currframe;

	BlackHole(Texture& image);

	void update(float time);

	void anim(float time);
};