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
}

Program::~Program() {
    delete BH;
}

void Program::drawall() {
	window.clear();
    if (BH != nullptr) {
        window.draw(BH->Blh);
        window.draw(*(BH->particles));

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
        BH->phys(time);
        drawall();
    }


}
