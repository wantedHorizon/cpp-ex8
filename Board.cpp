#include <iostream>
#include "Board.h"
#include <math.h>       /* sqrt */

using namespace std;

string Board::draw(int sz){

int mat[sz][sz];
string name="board"+to_string(size)+".txt";


return name;

}


















Board::Board(int nLength)
{
    this->length = nLength;
    for (int i = 0; i < length; i++)
        brd.push_back(vector<Data>(length));
      }

int Board::getL() const {return length;}

//-----operators----
Board& Board::operator=(char ch)
{
    if(ch == '.')
        *this=Board{length};

    else{
        IllegalCharException cc;
        cc.setChar(ch);
        throw cc;
    }

    return *this;
}






Board& Board::operator=(const Board& other)
{
    if(other.length!=length){
      this->length=other.length;
      Board* bbd=new Board{other.length};
      this->brd=bbd->brd;
      delete bbd;
    }

      for (int i = 0; i <length ; ++i) {
          for (int j = 0; j <length ; ++j) {
              brd[i][j]=other.brd[i][j];
          }

      }





    return *this;
}
ostream& operator<<(ostream& os, const Board& other){

    for (size_t i = 0; i <other.length ; ++i){
        for (size_t t = 0; t <other.length ; ++t){
            os<<other.brd[i][t];
          }
        os<<endl;
}
    return os;

}

void Board::print(){

    for (size_t i = 0; i <length ; ++i){
        for (size_t t = 0; t <length ; ++t){
            cout<<brd[i][t];
          }
        cout<<endl;
}
cout<<endl;


}

 istream& operator>>(istream& in, Board& board)
{
  string location="";
  in>>location;
  string bd="";
  ifstream infile;
  infile.open(location);
  string temp;
  while(infile>>temp){
    bd+=temp;
  }
//cout<<bd<<endl;
infile.close();
int lng=sqrt(bd.length() );
///cout<<bd<<'\n'<<lng<<endl;
Board nB{lng};
//nB.print();
int size=0;

for (int i = 0; i < lng; i++) {
    for (int z = 0; z < lng; z++) {
      //cout<<bd[size];
      char x= bd[size];
      if((bd[size]=='X')||(bd[size]=='O'))
      nB[{i,z}] = x;

      size++;
    }
}

//nB[1][1] = 'X';
board=nB;
//cout<<"nB\n"<<nB<<endl;

//cout<<"board\n"<<board<<endl;
return in;
}
////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
bool operator==(const Board& a,const Board& b){
   if(a.length!=b.length)
return false;
  for (size_t i = 0; i <a.length ; ++i){
      for (size_t t = 0; t <a.length ; ++t){
          if(a.brd[i][t]!=b.brd[i][t])
          return false;
}}
return true;
}
bool operator!=(const Board& a,const Board& b){
  return !(a==(b) );
}




Data& Board::operator [](Location loc)
{
    if(loc.getx() < 0 || loc.gety() < 0 ||
       loc.getx() >= length || loc.gety() >= length){
        IllegalCoordinateException ss{loc};
        throw ss;
    }
    return brd[loc.getx()][loc.gety()];
}

//
bool Board::verify(const char ch){
  if(ch=='X'||ch=='O'||ch=='.')
    return true;
  else{
      IllegalCharException cc;
      cc.setChar(ch);
      throw cc;

      return false;
    }
}

bool Board::verify(const Board& other){
  for (int i = 0; i <length ; ++i)
      for (int j = 0; j <length ; ++j){
        if(!verify(other.brd[i][j]))
        return false;


      }
      return true;

}
