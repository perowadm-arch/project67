//Menu.h

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;
using namespace std;

class Menu {
public:

    Menu();
    ~Menu();

    RectangleShape shape;
    RectangleShape buttonLight;
    RectangleShape buttonPause;
    RectangleShape line;
    RectangleShape degreeSlider;

    Text BP;
    Text BL;
    Text degree;
    Font font;

    bool pause;
    bool light;
    float DG;

    
    void drawMenu(RenderWindow& window);
    void buttons(RenderWindow& window);
    
};