#include "SnakeGame.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


int main() {
	/*Game G1;
	G1.run();*/
	RenderWindow window(VideoMode(960, 800), "Snakey Snake");
	window.setFramerateLimit(7);
	Event E1;
	Map meow(25, 30);
	player pp;
	direction d1;
	direction d2;
	bool apple = false;
	int x, y;
	int c=0;
	x = meow.getxIndex();
	y = meow.getYIndex();
	while (window.isOpen())
	{
		while (window.pollEvent(E1)) {
			if (E1.type == Event::Closed)
			{
				window.close();
			}
		}
		d1 = pp.getInputSFML(E1);
		switch (d1)
		{
		case UP:
			x--;
			break;
		case DOWN:
			x++;
			break;
		case LEFT:
			y--;
			break;
		case RIGHT:
			y++;
			break;
		default:
			switch (d2)
			{
			case UP:
				x--;
				break;
			case DOWN:
				x++;
				break;
			case LEFT:
				y--;
				break;
			case RIGHT:
				y++;
				break;
			default:
				break;
			}
		}

		apple = meow.checkAppleEat();
		d2 = d1;
		meow.moveSnake(x, y, apple);
		meow.printSFML(window);
		window.display();
	}
	return 0;
}