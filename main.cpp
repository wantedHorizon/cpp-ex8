#include "Board.h"

#include <iostream>

using namespace std;




int main() {/*
	string s;
cin>>s;
cout<<s.find('<')<<endl;

*/
	Board board;
  cin>>board;



	string filename = board.draw(600);
	cout << filename << endl;
}
