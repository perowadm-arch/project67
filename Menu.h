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

    Text BP;
    Text BL;
    Font font;

    bool pause;
    bool light;


    
    void drawMenu(RenderWindow& window);
    void buttons(RenderWindow& window);
    
};