/**
* [Suha Cho]
* [OrderedPair.cpp]
**/

#include "OrderedPair.h"

//constructor
OrderedPair::OrderedPair(int r, int c)
{
	row = r;
	col = c;
}

//accessor
int OrderedPair::getRow()
{
	return row;
}

//accessor
int OrderedPair::getCol()
{
	return col;
}
