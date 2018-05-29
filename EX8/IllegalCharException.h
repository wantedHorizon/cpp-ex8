

#ifndef _ILLEGALCHAREXCEPTION_H
#define _ILLEGALCHAREXCEPTION_H

#include <exception>
using namespace std;
//execption class for allerting Illegal chats not equal to : O, X, .
class IllegalCharException:public exception{

public:
    //GET
    char theChar() const{
        return note;
    }

    //SET
    void setChar(const char& c){
        this->note=c;
    }
  private:
      char note;
};
#endif //_ILLEGALCHAREXCEPTION_H
