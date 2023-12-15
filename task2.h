#ifndef ANAS_S_TASK2_TASK2_H
#define ANAS_S_TASK2_TASK2_H

#include "bits/stdc++.h"
using namespace std;

class Board {
protected:
    int n_rows, n_cols;
    char** board;
    int  n_moves = 0;

public:

    virtual bool update_board (int x, int y, char symbol) = 0;
    virtual bool is_winner() = 0;
    virtual bool is_draw() = 0;
    virtual void display_board() = 0;
    virtual bool game_is_over() = 0;
};

//-------------------------------------------------\\


class X_O_Board:public Board {
public:
    X_O_Board ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

//-------------------------------------------------\\


class Four_X_O_Board : public Board{
public:
    Four_X_O_Board();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};


//-------------------------------------------------\\

class Player {
protected:
    string name;
    char symbol;
public:

    Player (char symbol);
    Player (int order, char symbol);

    virtual void get_move(int& x, int& y);

    string to_string();

    char get_symbol();
};

//-------------------------------------------------\\

class RandomPlayer: public Player {
protected:
    int dimension;
public:

    RandomPlayer (char symbol, int dimension);
    void get_move(int& x, int& y);
};

//-------------------------------------------------\\

class GameManager {
private:
    Board* boardPtr;
    Player* players[2]{};
public:
    GameManager(Board*, Player* playerPtr[2]);
    void run();

};

//-------------------------------------------------\\

#endif //ANAS_S_TASK2_TASK2_H
