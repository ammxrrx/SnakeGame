#pragma once

class Map {
private:


public:
    char** arr;
    int row_size;
    int col_size;
    int snakeX;
    int snakeY;
    Map(int rows = 25, int cols = 50);
    ~Map();
    int getxIndex();
    int getYIndex();
    char get(int i, int j) const;
    char** getArr() const; // for direct access if needed
    void setRandomApples(); //for apples
    void snakeSpawn();
    bool moveSnake(int newX, int newY, bool& ateApple);
    bool checkAppleEat();
    bool checkAppleEnd();
    void print() const;
};

class player {
public:
    char w;
    int score;
    player();
    char getInput();
    int getScore();
    void addScore(int points);
};
class menu {
public:
    menu();
    void credits();
    void displayTitle();
    void displayHelp();
    void displayMenu();
    void gameOver();
};

class Game {
private:
    menu men1;
    Map m1;
    player p1;
public:
    Game();
    void run();
};

