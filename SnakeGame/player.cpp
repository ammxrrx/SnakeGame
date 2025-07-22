#include "SnakeGame.h"

using namespace std;

player::player() {
	score = 0;
}

direction player::getInputSFML(Event &obj) {
	if (Keyboard::isKeyPressed(Keyboard::W))	//UP
	{
		return UP;
	}
	if (Keyboard::isKeyPressed(Keyboard::S))	//DOWN
	{
		return DOWN;
	}
	if (Keyboard::isKeyPressed(Keyboard::D))	//RIGHT
	{
		return RIGHT;
	}
	if (Keyboard::isKeyPressed(Keyboard::A))	//LEFT
	{
		return LEFT;
	}
	return ERROR;
}

char player::getInput() {
	char x;
	if (_kbhit())
	{
		x = _getch();
	}
	else
	{
		x = ' ';
	}
	return x;
}
void player::addScore(int points) {
	score += points;
}


int player::getScore() {
	return score;
}