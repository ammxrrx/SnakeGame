#include "SnakeGame.h"
#include <iostream>
#include <windows.h> // for SetConsoleTextAttribute
#include <cstdlib>
#include "utils.h"

#include <ctime>
using namespace std;


Map::Map(int rows, int cols) {
    row_size = rows;
    col_size = cols;

    arr = new char* [row_size];
    for (int i = 0; i < row_size; ++i) {
        arr[i] = new char[col_size];
    }

    for (int i = 0; i < row_size; ++i) {
        for (int j = 0; j < col_size; ++j) {
            arr[i][j] = ' ';
        }
    }

    for (int i = 0; i < row_size; i++)
    {
        arr[i][0] = '|';
    }

    for (int i = 0; i < row_size; i++)
    {
        arr[i][col_size - 1] = '|';
    }
    for (int i = 0; i < col_size; i++)
    {
        arr[0][i] = '-';
    }
    for (int i = 0; i < col_size; i++)
    {
        arr[row_size - 1][i] = '-';
    }
    srand(time(0)); // seed only once   
    setRandomApples();
    snakeSpawn();
}

Map::~Map() {
    for (int i = 0; i < row_size; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

char Map::get(int i, int j) const {
    return arr[i][j];
}

char** Map::getArr() const {
    return arr;
}

int Map::getxIndex() {
    return snakeX;
}

int Map::getYIndex() {
    return snakeY;
}


void Map::print() const {
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            char c = arr[i][j];

            if (c == 'o') setColor(10);          // green
            else if (c == 'T') setColor(14);     // yellow
            else if (c == '|' || c == '-') setColor(15); // white
            else setColor(7);                    // default


            cout << c;
        }
        cout << endl;
    }
    setColor(7); // Reset color after printing
}


void Map::setRandomApples() {
    int x, y;
    for (int i = 0; i < 2; i++)
    {
        do {
            x = 1 + rand() % (row_size - 2);
            y = 1 + rand() % (col_size - 2);
        } while (arr[x][y] != ' ');  // Only place on empty spots
        arr[x][y] = 'o';
    }
}


void Map::snakeSpawn() {
    int x, y;
    do {
        x = 1 + rand() % (row_size - 2);
        y = 1 + rand() % (col_size - 2);
    } while (arr[x][y] != ' ');

    arr[x][y] = 'T';
    snakeX = x;
    snakeY = y;
}
bool Map::moveSnake(int newX, int newY, bool& ateApple) {
    ateApple = false;

    // Out-of-bounds
    if (newX < 0 || newX >= row_size || newY < 0 || newY >= col_size)
        return false;

    // Collision with wall
    if (arr[newX][newY] == '|' || arr[newX][newY] == '-')
        return false;

    // Check for apple before overwriting
    if (arr[newX][newY] == 'o') {
        ateApple = true;
    }

    // Clear old position
    arr[snakeX][snakeY] = ' ';

    // Update position
    snakeX = newX;
    snakeY = newY;
    arr[snakeX][snakeY] = 'T';

    return true;
}


bool Map::checkAppleEat() {
    if (arr[snakeX][snakeY] == 'o')
    {
        return true;
    }
    return false;
}

bool Map::checkAppleEnd() {
    for (int i = 0; i <row_size ; i++)
    {
        for (int j = 0; j < col_size; j++) {
            if (arr[i][j]=='o')
            {
                return false;
            }
        }
    }
    return true;
}