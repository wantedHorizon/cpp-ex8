#include <iostream>
#include "Board.h"
#include <math.h>
#include <string.h>
#include <fstream>
#include <sys/stat.h>

using namespace std;


/*
struct RGB {
    uint8_t red, green, blue;
public:
    RGB() {}
    RGB(uint8_t red, uint8_t green, uint8_t blue): red(red), green(green), blue(blue) {}
};





*/


std::string Board::draw(int size){
Board aa{length};
aa=*this;
if(size>1600){
  cout<<"size is limited to 1600"<<endl;
  size=1600;

}

if(size>1000){
  cout<<"while opening the img plz zoom in to see correctly \n res is to high "<<endl;
}/*
	std::string NAME = "board"+to_string(length)+"_"+to_string(size)+"x"+to_string(size)+".ppm";*/


 string filename="Board_"+to_string(length)+"--"+to_string(size)+"x"+to_string(size);
    struct stat buffer ;
    string file=filename+".ppm";
    int i=0;
    //check for existing files
    while(stat (file.c_str(), &buffer) == 0){
        file=filename+"_"+to_string(i)+".ppm";
        i++;
    }
    filename=file;
	const int constX = size, constY = size;

	ofstream output(filename/*,ios::app |ios::binary*/);
//ios::noreplace דרישה שהקובץ לא יהיה קיים (מתאים לכתיבה)
	output << "P6" << endl << constX <<" " << constY << endl << 255 << endl;

	RGB img  [constX*constY];
              	     for (int j = 0; j < constY; j++)  {  // row
              		    for (int i = 0; i < constX; i++) { // column
              			img  [constX*j+i].red = (100);
              			img  [constX*j+i].green = (0);
              			img  [constX*j+i].blue = (255);
              		    }
              	}

	//********************************creating seperting lines*************************//

//creating colums
	for (int i = 0; i < length; ++i) {

		int fx = i * (constX/length);

		for (int r = 10; r < constY - 10 ; ++r) {

			img  [constY * (r) + fx].red = (255);

			img  [constY * (r) + fx].green = (0);

			img  [constY * (r) + fx].blue = (0);
		}
	}

	//creating rows
	for (int ii = 0; ii < length; ++ii) {

		    int YF = ii * (constY/length) ;
      for (int jj = 10; jj < constX - 10 ; ++jj) {

          			img  [(jj) + YF * constY].red = (255);

          			img  [(jj) + YF * constY].green = (0);

          			img  [(jj) + YF * constY].blue = (0);
		}
	}


	//CREATING X&Y SYM
	for (int row = 0; row < length; ++row) {
		for (int column = 0; column < length; ++column) {

			int fx = column * (constX/length);
			int tox = (column + 1) * (constX/length);//
			int fy = row * (constY/length) ;
			int toy = (row + 1) * (constY/length);

			if (aa[{row,column}] == 'X') {
      //  nB[{i,z}] = x;

				//Drawing X
				for (int r = 10; r < toy - fy - 10 ; ++r) {

					// \ x
          img  [constY * (r + fy) + fx + r].green = (0);

					img  [constY * (r + fy) + fx + r].red = (0);

					img  [constY * (r + fy) + fx + r].blue = (0);

					// / X
					     img  [constY * (r + fy) + tox - (r)].blue = (0);

               img  [constY * (r + fy) + tox - (r)].green = (0);

               img  [constY * (r + fy) + tox - (r)].red = (0);






				}
			}
			else if      (aa[{row,column } ] == 'O')
      {
				// circles 00000000 -----00
        int disY = (toy - fy) / 2;

				int RAD = (tox - fx) / 2;

				int disX = (tox - fx) / 2;


				for (int X = 0; X < toy - fy - 10 ; ++X)
        {

					int Y = sqrt (RAD*RAD - (X - disX)*(X - disX)) + disY;

					int glue = 5;

					//circle
          					img  [constY * ((fy+Y) - glue) + fx + X].green = (0);

          					img  [constY * ((fy+Y) - glue) + fx + X].blue = (0);

                    img  [constY * ((fy+Y) - glue) + fx + X].red = (0);


          					img  [constY * (toy+glue-Y) + fx + X].green = (0);

          					img  [constY * (toy+glue-Y) + fx + X].blue = (0);

                    img  [constY * (toy+glue-Y) + fx + X].red = (0);


				}
			}
		}
	}


	output.write (reinterpret_cast <char*>(& img),3 * size*size);

	output.close ();

	return filename;
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
/*
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
*/



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

istream& operator>>(istream& in,Board& b){
    string location ;
  //  cout<<in<<endl;
    int s = 0, loc = 0;
    in >> location;
//   cout<<location<<endl;
    if(location.find(".txt")>1000 ||location.find("X")<1000 ||location.find("O")<1000){
  //    cout<<"first if"<<location.find("<")<<endl;

    s = location.length();

    Board bb{s};
    b=bb;
    while (in)
    {
        for (int j = 0; j < s; j++){
          if(location[j]=='X'||location[j]=='O')
          b[{loc, j}] = location[j];

        }
        in >> location;
        loc++;
    }
    return in;}
    else{

  //   cout<<"sec"<<endl;
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
  b=nB;
  //cout<<"nB\n"<<nB<<endl;

  //cout<<"board\n"<<board<<endl;
  return in;
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
