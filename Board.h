//board game class for tic tac toe game X||O

#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

#include <iostream>
#include <vector>
#include "Location.h"

#include "Data.h"
#include "IllegalCharException.h"
#include <string>
#include "IllegalCoordinateException.h"
#include <fstream>
using namespace std;

class Board{

private:
    vector<vector<Data> > brd;
    string testFileLOC;
    int length;
public:
  //  Board();
  //constrator

    Board(int nLength=2);
    ~Board(){}
    void print();
    string draw(int sz);
//opertaors
friend  bool operator!=(const Board& a,const Board& b);
friend  bool operator ==(const Board& a,const Board& b);

    Board& operator=(const char newVal);
    Board& operator=(const Board& other);
    int getL() const;
    friend ostream& operator<<(ostream& os, const Board& other);
    friend istream& operator>>(istream& in, Board& board) ;
       bool verify(const char ch);
    bool verify(const Board& other);
    Data& operator [](Location loc);

};


#endif //TICTACTOE_BOARD_H
