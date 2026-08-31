//ProgConfig.cpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>
#include "Prog.h"
using namespace sf;
using namespace std;

Program::Program(){
	window.create(VideoMode(wwidth, wheight), "Supermassive Black Hole");
    BH = new BlackHole;
    PRTCS = new Particle;
    MN = new Menu;
    MN->pause = false;
}

Program::~Program() {
    delete BH;
    delete PRTCS;
    delete MN;
}

void Program::drawall() {
	window.clear();
    if (BH != nullptr) {
        window.draw(BH->Blh);
        window.draw(*(PRTCS->particles));
        MN->drawMenu(window);
    }
	window.display();
}

void Program::start() {
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();  
        }
       
        MN->buttons(window);
        if (MN->pause) {
            time = 0;
        }
        BH->phys(time);
        PRTCS->phys(time, BH);
        drawall();
       
    }
}
