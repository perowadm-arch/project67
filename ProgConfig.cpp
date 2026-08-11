#include <SFML/Graphics.hpp>
#include <iostream>
#include "Prog.h"
using namespace sf;
using namespace std;

Program::~Program() {

}

bool Program::loadtxs() {
	if (!t.loadFromFile("SMBH/BLH.png")) {
		throw runtime_error("SMBH/BLH.png");
	}
	t.setSmooth(false);
}