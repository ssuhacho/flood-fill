/**
* [Suha Cho]
* [OrderedPair.h]
**/

#ifndef ORDEREDPAIR_H
#define ORDEREDPAIR_H

#include <iostream>

using namespace std;

class OrderedPair {
private:
	int row; //the private variable row 
	int col; //the private variable col 
public:
	OrderedPair(int r, int c); //constructor
	int getRow(); //accessor
	int getCol(); //accessor
};
#endif