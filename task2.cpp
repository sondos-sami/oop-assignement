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

//-------------------------------------------------\\

X_O_Board::X_O_Board () {
    n_rows = n_cols = 3;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool X_O_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 2 || y < 0 || y > 2) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}
void X_O_Board::display_board() {
    for (int i: {0,1,2}) {
        cout << "\n| ";
        for (int j: {0,1,2}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
bool X_O_Board::is_winner() {
    char row_win[3], col_win[3], diag_win[2];
    for (int i:{0,1,2}) {
        row_win[i] = board[i][0] & board[i][1] & board[i][2];
        col_win[i] = board[0][i] & board[1][i] & board[2][i];
    }
    diag_win[0] = board[0][0] & board[1][1] & board[2][2];
    diag_win[1] = board[2][0] & board[1][1] & board[0][2];

    for (int i:{0,1,2}) {
        if ( (row_win[i] && (row_win[i] == board[i][0])) ||
             (col_win[i] && (col_win[i] == board[0][i])) )
        {return true;}
    }
    if ((diag_win[0] && diag_win[0] == board[1][1]) ||
        (diag_win[1] && diag_win[1] == board[1][1]))
    {return true;}
    return false;
}
bool X_O_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}
bool X_O_Board::game_is_over () {
    return n_moves >= 9;
}

//-------------------------------------------------\\

Pyramic_X_O_Board::Pyramic_X_O_Board() {
    n_rows =  3;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool Pyramic_X_O_Board :: update_board (int x, int y, char mark){
    if ( !((x < 0 || x > 2 || y < 0 || y > 4) || ( (x == 0 && y == 0) || (x == 0 && y == 1) || (x == 0 && y == 3) || (x == 0 && y == 4 ) || (x == 1 && y == 0) || (x == 1 && y == 4))) && (board[x][y] == 0) ) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;

    }
    else{
        return false;
    }

}
void Pyramic_X_O_Board :: display_board(){
    for (int i: {0,1,2}) {
        cout << "\n ";
        for (int j: {0,1,2,3,4}) {
            if(!((i == 0 && j == 0) || (i == 1 && j == 0) ||(i == 0 && j == 1) ||(i == 0 && j == 4) || (i == 1 && j == 4) ||(i == 0 && j == 3))){
                if(i == 0){cout << "                   ";}
                if(i == 1){cout << "     ";}
                if(i == 2){cout << "  ";}
                cout << "(" << i << "," << j << ")";
                cout << setw(2)<< board [i][j] << " |";
            }
        }
        cout << "\n-----------------------------------------------------------";
    }
    cout << endl;
}
bool Pyramic_X_O_Board :: is_winner(){
    if(((board[2][0] == board[2][1]) && ((board[2][1] == board[2][2]))) && (board[2][0] == 'X' || board[2][0] == 'O') ){
        return true;
    }
    else if(((board[2][1] == board[2][2]) && ((board[2][2] == board[2][3]))) && (board[2][1] == 'X' || board[2][1] == 'O')){
        return true;
    }
    else if(((board[2][2] == board[2][3]) && ((board[2][3] == board[2][4]))) && (board[2][2] == 'X' || board[2][2] == 'O')){
        return true;
    }
    else if(((board[1][1] == board[1][2]) && ((board[1][2] == board[1][3]))) && (board[1][1] == 'X' || board[1][1] == 'O')){
        return true;
    }
    else if(((board[0][2] == board[1][2]) && ((board[1][2] == board[2][2]))) && (board[0][2] == 'X' || board[0][2] == 'O') ){
        return true;
    }
    else if(((board[2][0] == board[1][1]) && ((board[1][1] == board[0][2]))) && (board[2][0] == 'X' || board[2][0] == 'O') ){
        return true;
    }
    else if(((board[2][4] == board[1][3]) && ((board[1][3] == board[0][2]))) && (board[2][4] == 'X' || board[2][4] == 'O') ){
        return true;
    }
    else
        return false;

}
bool Pyramic_X_O_Board :: is_draw(){
    return (n_moves == 9 && !is_winner());
}
bool Pyramic_X_O_Board :: game_is_over(){
    return n_moves >= 9;
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

//-------------------------------------------------\\

game3_Board::game3_Board () {
    n_rows = n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
bool game3_Board::update_board (int x, int y, char mark){
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}
void game3_Board::display_board() {
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " | ";
        }
        cout << "\n--------------------------------------------------";
    }
    cout << endl;
}
bool game3_Board ::is_winner() {

    int x_count = 0 , o_count =0;

    for (int i = 0; i < 5 ; ++i) {
        for (int j = 0; j < 3 ; ++j) {
            if( (board[i][j] == board[i][j+1]) && (board[i][j+1] == board[i][j+2]) && (board[i][j] == 'X') ){
                x_count++;
            }
        }
    }

    for (int i = 0; i < 5 ; ++i) {
        for (int j = 0; j < 3 ; ++j) {
            if( (board[j][i] == board[j+1][i]) && (board[j+1][i] == board[j+2][i]) && (board[j][i] == 'X') ){
                x_count++;
            }
        }
    }

    for (int i = 0; i < 3 ; ++i) {
        for (int j = 0; j < 3 ; ++j) {
            if((board[i][j] == board[i+1][j+1]) && (board[i+1][j+1] == board[i+2][j+2]) && (board[i][j] == 'X')){
                x_count++;
            }
            if((board[i][j+2] == board[i+1][j+1]) && (board[i+1][j+1] == board[i+2][j]) && (board[i][j+2] == 'X')){
                x_count++;
            }

        }
    }

    //------------------------------\\

    for (int i = 0; i < 5 ; ++i) {
        for (int j = 0; j < 3 ; ++j) {
            if( (board[i][j] == board[i][j+1]) && (board[i][j+1] == board[i][j+2]) && (board[i][j] == 'O') ){
                o_count++;
            }
        }
    }

    for (int i = 0; i < 5 ; ++i) {
        for (int j = 0; j < 3 ; ++j) {
            if( (board[j][i] == board[j+1][i]) && (board[j+1][i] == board[j+2][i]) && (board[j][i] == 'O') ){
                o_count++;
            }
        }
    }

    for (int i = 0; i < 3 ; ++i) {
        for (int j = 0; j < 3 ; ++j) {
            if((board[i][j] == board[i+1][j+1]) && (board[i+1][j+1] == board[i+2][j+2]) && (board[i][j] == 'O')){
                o_count++;
            }
            if((board[i][j+2] == board[i+1][j+1]) && (board[i+1][j+1] == board[i+2][j]) && (board[i][j+2] == 'O')){
                o_count++;
            }

        }
    }


    //--------------------------------\\

    X = x_count;
    O = o_count;

    return (n_moves == 24 && X > O);

}
bool game3_Board ::is_draw() {
    return (n_moves == 24 && X == O);
}
bool game3_Board ::game_is_over() {
    return n_moves == 24;
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


