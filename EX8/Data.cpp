



#include "Data.h"


Data::Data()
{
    ch ='.';
}

  Data::Data(char s)
  {
    if (s =='O' || s == 'X'){
        ch = s;
      } else{
        IllegalCharException ss;
        ss.setChar(s);
        throw ss;
    }
}

Data::~Data(){ }
////////////////////////////////////////////////
ostream& operator<<(ostream& os, const Data& other)
{

    return os << other.ch;

}



void Data::operator= (char s){
    if (s =='X' || s== 'O'){
        ch = s;
    } else{
        IllegalCharException ce;
        ce.setChar(s);
        throw ce;
    }

}
////////////////////////////////////
void Data::setCH(char s) {
  if (s =='O' || s == 'X'){
        Data::ch = s;
    } else{
        IllegalCharException ce;
        ce.setChar(s);
        throw ce;
    }
}
