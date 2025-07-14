#pragma once

class Map {
private:
    char** arr;
    int row_size;
    int col_size;

public:
    Map(int rows = 50, int cols = 50);
    ~Map();

    char get(int i, int j) const;
    char** getArr() const; // for direct access if needed
    void setRandomApples();
    void snakeSpawn();
    void print() const;
};

class Game {
private:
    Map M1;
public:
    Game();
};