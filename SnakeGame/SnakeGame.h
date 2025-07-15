#pragma once

class Map {
private:
    

public:
    char** arr;
    int row_size;
    int col_size;
    int snakeX;
    int snakeY;
    Map(int rows = 50, int cols = 50);
    ~Map();
    bool moveSnake(int newX, int newY, bool& ateApple);
    int getxIndex();
    int getYIndex();
    char get(int i, int j) const;
    char** getArr() const; // for direct access if needed
    void setRandomApples(); //for apples
    void snakeSpawn();
    bool moveSnake(int newX,int newY);
    bool checkAppleEat();
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

class Game {
private:
    Map m1;
    player p1;
public:
    Game();
    void run();
};

