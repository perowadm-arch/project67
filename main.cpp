//main.cpp

#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <iostream>
#include "Prog.h"

using namespace sf;
using namespace std;


int main()
{
    
    try {

        Program prog;

        prog.start();

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "Unknown error!" << endl;
        return 1;
    }

    return 0;
}
