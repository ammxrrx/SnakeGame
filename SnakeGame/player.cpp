#include "SnakeGame.h"
#include <iostream>
#include <windows.h> // for SetConsoleTextAttribute
#include <cstdlib>
#include <ctime>
#include <conio.h>  // for _getch()

using namespace std;

player::player() {
	score = 0;
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