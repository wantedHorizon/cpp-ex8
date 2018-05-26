/*THIS CLASS REPERSENTS SAVED CHAR DATA AS OBJECT
*/

#ifndef DATA_H
#define DATA_H

#include <iostream>
#include "Location.h"

#include "IllegalCharException.h"


using namespace std;

class Data {

private:
    char ch;
public:
    Data();
    Data(char s); //check input - throw execption
    ~Data();

    friend ostream& operator<<(ostream& os, const Data& other);

    void operator= (char s);

     operator char() const { return ch; }

    void setCH(char ch);
};



#endif //DATA_H
