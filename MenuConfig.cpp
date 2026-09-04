//MenuConfig.cpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "Prog.h"
using namespace sf;
using namespace std;

Menu::Menu() {
	shape.setPosition(1000, 0);
	shape.setSize(Vector2f(280.f, 750.f));
	shape.setFillColor(Color::White);

	buttonPause.setPosition(1100, 200);
	buttonPause.setSize(Vector2f(80.f, 40.f));
	buttonPause.setOutlineColor(Color::Black);
	buttonPause.setOutlineThickness(2.f);
	buttonPause.setFillColor(Color::White);
	if (font.loadFromFile("STENCIL.TTF")) {
		BP.setFont(font);
		BL.setFont(font);
		degree.setFont(font);
	}
	BP.setString("pause");
	BP.setFillColor(Color::Black);
	BP.setPosition(1110, 210);
	BP.setCharacterSize(18);

	buttonLight.setPosition(1100, 300);
	buttonLight.setSize(Vector2f(80.f, 40.f));
	buttonLight.setOutlineColor(Color::Black);
	buttonLight.setOutlineThickness(2.f);
	buttonLight.setFillColor(Color::White);
	BL.setString("light");
	BL.setFillColor(Color::Black);
	BL.setPosition(1110, 310);
	BL.setCharacterSize(18);

	line.setPosition(1135, 400);
	line.setSize(Vector2f(5.f, 200.f));
	line.setFillColor(Color::Black);
	degreeSlider.setPosition(1130, 500);
	degreeSlider.setSize(Vector2f(15.f, 10.f));
    degreeSlider.setOutlineColor(Color::Black);
    degreeSlider.setOutlineThickness(2.f);
	degreeSlider.setFillColor(Color::White);
	//degree.setString("0");
	//degree.setFillColor(Color::Black);
	//degree.setPosition(1130, 450);
	//degree.setCharacterSize(15);

}

Menu::~Menu() {

}

void Menu::drawMenu(RenderWindow& window) {

	window.draw(shape);

	window.draw(buttonPause);
	window.draw(BP);

	window.draw(buttonLight);
	window.draw(BL);

	window.draw(line);
	window.draw(degreeSlider);
	//window.draw(degree);

};

void Menu::buttons(RenderWindow& window) {
	Vector2i MousePos = Mouse::getPosition(window);

	static bool wasPressed_P = false;
	bool isPressed_P = Mouse::isButtonPressed(Mouse::Left);

	if (MousePos.x >= 1100 && MousePos.x <= 1180 &&
		MousePos.y >= 200 && MousePos.y <= 240) {

		buttonPause.setFillColor(Color::Black);
		BP.setFillColor(Color::White);

		// Срабатывает ТОЛЬКО если сейчас кнопка нажата, а в прошлом кадре была отпущена
		if (isPressed_P && !wasPressed_P) {
			pause = !pause; // Меняем состояние на противоположное (true на false, false на true)
		}

	}
	else {
		buttonPause.setFillColor(Color::White);
		BP.setFillColor(Color::Black);

	}

	static bool wasPressed_L = false;
	bool isPressed_L = Mouse::isButtonPressed(Mouse::Left);

	if (MousePos.x >= 1100 && MousePos.x <= 1180 &&
		MousePos.y >= 300 && MousePos.y <= 340) {

		buttonLight.setFillColor(Color::Black);
		BL.setFillColor(Color::White);

		if (isPressed_L && !wasPressed_L) {
			light = !light; // Меняем состояние на противоположное (true на false, false на true)
		}

	}
	else {
		buttonLight.setFillColor(Color::White);
		BL.setFillColor(Color::Black);

	}

	wasPressed_L = isPressed_L;
	wasPressed_P = isPressed_P;

	Vector2f slidepos = degreeSlider.getPosition();
	Vector2f slidesize = degreeSlider.getSize();

	if (MousePos.x >= slidepos.x && MousePos.x <= slidepos.x + slidesize.x
		&& MousePos.y >= slidepos.y && MousePos.y <= slidepos.y + slidesize.y) {
		degreeSlider.setFillColor(Color::Black);	
	}
	else {
		degreeSlider.setFillColor(Color::White);
	}

	if (MousePos.x >= 1120 && MousePos.x <= 1150
		&& MousePos.y >= 400 && MousePos.y <= 600) {		
		if (Mouse::isButtonPressed(Mouse::Left)) {
		degreeSlider.setPosition(1130, MousePos.y - 5);
		}
	}

}