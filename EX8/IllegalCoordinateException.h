

#ifndef _ILLEGALCOORDINATEEXCEPTION_H
#define _ILLEGALCOORDINATEEXCEPTION_H
#include <exception>
#include "Location.h"

#include <string>

using namespace std;


class IllegalCoordinateException:public exception{
private:
    Location loc;
    int num=0;
public:
    IllegalCoordinateException(const Location& loc){
      this->loc=loc;
    }
    IllegalCoordinateException(const int temp){      this->num=temp  ;}

        string theCoordinate() const{
          if(num!=0){

            string output=to_string(num);

            return output;

        } else{

            string output=to_string(loc.getx() )+","+to_string(loc.gety());

            return output;
        }
    }
};

#endif //
