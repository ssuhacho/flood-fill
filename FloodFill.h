/**
* [Suha Cho]
* [FloodFill.h]
**/

#ifndef FLOODFILL_H
#define FLOODFILL_H

#include <iostream>
#include "OrderedPair.h" 
#include <queue>
#include <string>

using namespace std;

class FloodFill {
private:
	//A pointer to a 2-dimensional char array on the heap. 
	char** imagePtr;
	//The size of the array currently pointed to by imagePtr.
	int imageSize;
	//A pointer to a 2-dimensional bool array on the heap.
	bool** processed;

	/**
	* inField is a private helper method to check boundaries for 2d arrays.
	* @param row holds the position of row on the board.
	* @param col holds the position of col on the board.
	* @return false if the position is out of bound, otherwise, return true.
	*/
	bool inField(int row, int col);

public:	
	//Constructor
	FloodFill(int size);
	//destructor
	~FloodFill();

	/**
	 * generateImage creates a new array pointed to by imagePtr.
	 * @param size is the given size.
	 * @pre The array should be randomly populated with the chars
			‘c’, ‘m’, ‘y’, and ‘k’ with each char being equally likely. 
	 */
	void generateImage(int size);

	/**
	* displayImage displays the current chars in the array pointed to by imagePtr.
	* @pre Should display row numbers above the image and column numbers to the left of the image. 
			Row and column numbers should start over at zero once they pass 9.
	*/
	void displayImage();

	/**
	* fill flood fills beginning at[row][col] and replacing color there with newColor.
	* @param row is the given row size.
	* @param col is the given col size.
	* @param newColor is the given new color.
	*/
	void fill(int row, int col, char newColor);

};

#endif