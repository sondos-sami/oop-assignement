#include <bits/stdc++.h>
#include "task2.h"

int main() {
    cout << " -----------------------------------------" << endl;
    cout << "|    Welcome to TicTacXperience :) !      |" << endl;
    cout << " -----------------------------------------" << endl;


    cout << endl <<  "We have here 4 types of Tic Tac Toe games! , let me know which one you wanna play :)" << endl << endl;
    cout << "(1) Normal 3x3 Tic Tac Toe" << endl;
    cout << "(2) Pyramid Tic Tac Toe" << endl;
    cout << "(3)  Four in a row Tic Tac Toe" << endl;
    cout << "(4)  5x5 Tic Tac Toe" << endl;
    cout << endl << "Your choice is:  ";
    int n; cin >> n;

    cout << "Let me know whether you want to play against a player (1) or against a computer (2):  " ;
    int choice;
    cin >> choice;
    cout << endl;

    cout <<"Let me know whether you want to play with (X) or (O)" << endl;
    cout <<"I want to play with:   ";
    char XorO; cin>>XorO;


    cout << "What is your name :)" << endl;
    Player* players[2];
    if(XorO == 'X' || XorO == 'x'){
        players[0] = new Player (1, 'x');
    }
    else if(XorO == 'O' || XorO == 'o'){
        players[1] = new Player (2, 'o');
    }


    if (choice == 1){
        cout << "What is player 2 name :)" << endl;
        if(XorO == 'O' || XorO == 'o'){
            players[0] = new Player (1, 'x');
        }
        else if(XorO == 'X' || XorO == 'x'){
            players[1] = new Player (2, 'o');
        }
    }

    else if(choice == 2){

        if(XorO == 'O' || XorO == 'o'){
            players[0] = new RandomPlayer ('x', 7);
        }
        else if(XorO == 'X' || XorO == 'x'){
            players[1] = new RandomPlayer ('o', 7);
        }
    }


    if(n == 1){
        GameManager x_o_game (new X_O_Board , players);
        x_o_game.run();
    }
    else if(n == 2){
        GameManager x_o_game (new Pyramic_X_O_Board , players);
        x_o_game.run();
    }
    else if(n == 3){
        GameManager x_o_game (new Four_X_O_Board , players);
        x_o_game.run();
    }
    else if(n == 4){
        GameManager x_o_game (new game3_Board , players);
        x_o_game.run();
    }

    system ("pause");
}
