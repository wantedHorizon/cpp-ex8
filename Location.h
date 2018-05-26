
#ifndef LOCATION_H
#define LOCATION_H

class Location
{
private:
    int x, y;
public:

    Location(int x=0, int y=0):x(x),y(y){}

    ~Location(){

    }



    int gety() const{return y;}
    int getx() const{
      return x;
    }
};



#endif //LOCATION_H
