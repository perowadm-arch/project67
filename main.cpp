#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;
int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 750), "Supermassive Black Hole");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw();
        window.display();
    }

    return 0;
}