#include "SnakeGame.h"

//gameeee
Game::Game() {

}

void Game::run() {
    //men1.displayTitle();
    //men1.displayMenu();
    //m1.print();

    char ch;
    char ch2 = ' ';
    int x, y;
    bool moved = true;
    bool apple = false;

    while (true) {
        ch = p1.getInput();
        if (ch == ' ') {
            ch = ch2;  // keep previous direction
        }

        // Current snake position
        x = m1.getxIndex();
        y = m1.getYIndex();

        // Update direction
        if (ch == 'w') x--;
        else if (ch == 's') x++;
        else if (ch == 'a') y--;
        else if (ch == 'd') y++;

        ch2 = ch;  // remember last direction

        // Move and check apple in one go
        moved = m1.moveSnake(x, y, apple);

        // Collision = game over
        if (!moved) {
            system("cls");
            //m1.print();
            //men1.gameOver();
            cout << "Final Score: " << p1.getScore() << endl;
            break;
        }

        // Add score if apple eaten
        if (apple) {
            p1.addScore(5);
            apple = false;
            if (m1.checkAppleEnd() == true)
            {
                //men1.gameOver();
                break;
            }
        }

        // Draw
        system("cls");
        //m1.print();
        cout << "Score: " << p1.getScore() << endl;

        //Sleep(300);
    }
}