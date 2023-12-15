#include <bits/stdc++.h>
#include "task2.h"


int main() {

    cout << "Welcome to FCAI X-O Game. :)\n";

    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Press 1 if you want to play with computer: ";
    int choice;
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 5);

    GameManager x_o_game (new Four_X_O_Board, players);
    x_o_game.run();
    system ("pause");
}
