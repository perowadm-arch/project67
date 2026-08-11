//ProgConfig.cpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>
#include "Prog.h"
using namespace sf;
using namespace std;

Program::Program(){
	window.create(VideoMode(wwidth, wheight), "Supermassive Black Hole");
    loadtxs();
    BH = new BlackHole(t);
}

Program::~Program() {
    delete BH;
}

bool Program::loadtxs() {
    if (!t.loadFromFile("SMBH/BLH.png")) {
        throw runtime_error("failed to load BLH.png!");
    }
    t.setSmooth(false);

    return true;
}

void Program::drawall() {
	window.clear();
    if (BH != nullptr) {
        window.draw(BH->sprite);
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
        BH->anim(time);
        drawall();
    }


}
