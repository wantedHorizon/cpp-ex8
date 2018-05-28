#include "Board.h"

#include <iostream>

using namespace std;
void printMat(int* mat,int size);



int main() {

	Board board;
  cin>>board;
	cout<<board<<endl;

//x=[0];
//	cout<<bd<<bd.length()<<endl;

	string filename = board.draw(1600);
	cout << filename << endl;
}

void printMat(int* mat,int size){
for (size_t i = 0; i < size-1; i++) {
			/* code */
			cout<<mat[i];
		}
		cout<<endl;
}
