#include "SnakeGame.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


int main() {
	/*Game G1;
	G1.run();*/
	RenderWindow window(VideoMode(960,800),"Snakey Snake");
	Event E1;
	Map meow;
	

	while (window.isOpen())
	{
		while (window.pollEvent(E1)) {
			if (E1.type == Event::Closed)
			{
				window.close();
			}
		}
		meow.printSFML(window);
		window.display();
	}
	return 0;
}