#include <bits/stdc++.h>
#include "task2.h"

//------------------------------------------------\\

GameManager::GameManager(Board* bPtr, Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}
void GameManager::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();

            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }

            if (boardPtr->is_winner()){
                cout  << players[i]->to_string() << " wins\n";
                return;
            }

        }
    }

    if(boardPtr->is_draw()){
        cout <<"Draw!" << endl;
        return;
    }

    else if(boardPtr ->is_winner()){
        cout << players[0]->to_string() << " wins!" <<endl;
        return;
    }

    else if(!boardPtr ->is_winner()){
        cout << players[1]->to_string() << " wins!" <<endl;
        return;
    }
}



//-------------------------------------------------\\-

Four_X_O_Board ::Four_X_O_Board() {
    n_rows =  6;
    n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool Four_X_O_Board ::update_board(int x, int y, char mark) {
    if(!(x < 0 || x > 5 || y < 0 || y > 6) && (board[x][y] == 0) ){
        if( x == 5 ){
            board[x][y] = toupper(mark);
            n_moves++;
            return true;
        }
        else if( board[x+1][y] == 'X' || board[x+1][y] == 'O'){
            board[x][y] = toupper(mark);
            n_moves++;
            return true;
        }
    }
    else
        return false;
}
void Four_X_O_Board ::display_board() {
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " | ";
        }
        cout << "\n-----------------------------------------------------------------------";
    }
    cout << endl;
}
bool Four_X_O_Board ::is_winner() {

    for (int i = 0; i < 6 ; ++i) {
        for (int j = 0; j < 3 ; ++j) {
            if( (board[i][j] == board[i][j+1]) && (board[i][j+1] == board[i][j+2]) && (board[i][j] == 'X' || board[i][j] =='O') ){
                return true;
            }
        }
    }

    for (int i = 0; i < 7 ; ++i) {
        for (int j = 0; j < 4 ; ++j) {
            if( (board[j][i] == board[j+1][i]) && (board[j+1][i] == board[j+2][i]) && (board[j][i] == 'X'|| board[j][i] =='O') ){
                return true;
            }
        }
    }

    for (int i = 0; i < 4 ; ++i) {
        for (int j = 0; j < 5 ; ++j) {
            if((board[i][j] == board[i+1][j+1]) && (board[i+1][j+1] == board[i+2][j+2]) && (board[i][j] == 'X'|| board[i][j] =='O')){
                return true;
            }
            if((board[i][j+2] == board[i+1][j+1]) && (board[i+1][j+1] == board[i+2][j]) && (board[i][j+2] == 'X' || board[i][j+2] =='O')){
                return true;
            }

        }
    }

    return false;
}
bool Four_X_O_Board ::is_draw() {
    return (n_moves >= 42 && !is_winner());
}
bool Four_X_O_Board ::game_is_over() {
    return n_moves >= 42;
}


//---------------------------------------\\

Player::Player(char symbol) {
    this->symbol = symbol;
}
Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}
void Player::get_move (int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}
string Player::to_string(){
    return "Player: " + name ;
}
char Player::get_symbol() {
    return symbol;
}

//-------------------------------------------------\\

RandomPlayer::RandomPlayer (char symbol, int dimension):Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}
void RandomPlayer::get_move (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
}

//-------------------------------------------------\\


