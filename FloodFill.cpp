/**
* [Suha Cho]
* [FloodFill.cpp]
**/

#include <iostream>
#include "FloodFill.h" 
#include "OrderedPair.h" 
#include <queue>
#include <time.h>

using namespace std;

FloodFill::FloodFill(int size) //constructor
{
	//initializes the object to contain a randomly generated array of the given int size.
	imagePtr = new char* [size];
	processed = new bool* [size];

	imageSize = size;
	char color[] = { 'c','m','y','k' };

	//creating 2D array
	for (int i = 0; i < imageSize; i++)
	{
		imagePtr[i] = new char[imageSize];
		processed[i] = new bool[imageSize];
	}

	srand(time(NULL));
	for (int i = 0; i < imageSize; i++)
	{
		for (int j = 0; j < imageSize; j++)
		{
			int temp = rand() % 4;
			imagePtr[i][j] = color[temp];
			processed[i][j] = false;
		}
	}
}

FloodFill::~FloodFill() //destructor
{
	for (int i = 0; i < imageSize; i++)
	{
		delete[] imagePtr[i];
		delete[] processed[i];
	}
	delete[] imagePtr;
	delete[] processed;
}

bool FloodFill::inField(int row, int col)
{
	//check boundaries
	if (row < 0 || row >= imageSize || col < 0 || col >= imageSize)
	{
		return false; //return false if the position is out of bound
	}
	return true;
}

void FloodFill::generateImage(int size)
{
	for (int i = 0; i < imageSize; i++)
	{
		delete[] imagePtr[i];
		delete[] processed[i];
	}
	delete[] imagePtr;
	delete[] processed;


	//The char stored in each element represents a color.
	char color[] = {'c','m','y','k'}; 

	//Creates a new array pointed to by imagePtr.
	imageSize = size;
	imagePtr = new char* [size];
	processed = new bool* [size];

	for (int i = 0; i < size; i++)
	{
		imagePtr[i] = new char[size];
		processed[i] = new bool[imageSize];
	}

	//randomly populate the array with the chars ‘c’, ‘m’, ‘y’, and ‘k’.
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int temp = rand() % 4;
			imagePtr[i][j] = color[temp];
			processed[i][j] = false;
		}
	}
}

void FloodFill::displayImage()
{
	int colNumber = 0;
	cout << "  ";
	for (int i = 0; i < imageSize; i++)
	{
		cout << " " << colNumber; //a single space between them.
		colNumber++;
		//Row and column numbers should start over at zero once they pass 9.
		if (colNumber == 10) {
			colNumber = 0;
		}
	}
	cout << endl;

	int rowNumber = 0;
	for (int i = 0; i < imageSize; i++)
	{
		cout << " " << rowNumber;
		rowNumber++;
		if (rowNumber == 10) {
			rowNumber = 0;
		}

			for (int j = 0; j < imageSize; j++)
			{
				cout << " " << imagePtr[i][j];
			}
		cout << endl;
	}
	cout << endl;

}

void FloodFill::fill(int row, int col, char newColor)
{
	//Create an empty queue that can contain OrderedPair objects.
	std::queue<OrderedPair> aQueue;
	OrderedPair pixel(row, col);

	cout << "\nBeginning at [" << row << "][" << col << "] I will flood fill and replace "
		<< imagePtr[row][col] << " with " << newColor << "." << endl;

	//matchColor = Original pixel color [row][col]
	char matchColor = imagePtr[row][col];

	//Enqueue the pixel at [row][col] and mark it processed.
	aQueue.push(pixel);
	processed[row][col] = true;

	while (!aQueue.empty())
	{
		//currentPixel = peek the queue
		int curRow = aQueue.front().getRow();
		int curCol = aQueue.front().getCol();

		aQueue.pop(); //Pop the queue
		imagePtr[curRow][curCol] = newColor; //Set currentPixel’s color to newColor

		//check all 8 pixels adjacent to currentPixel
		//top
		if (imagePtr[curRow - 1][curCol] == matchColor && processed[curRow - 1][curCol] == false)
		{
			//check if it's out of bound
			if (inField(curRow-1, curCol))
			{
				OrderedPair aPixel(curRow - 1, curCol);
				aQueue.push(aPixel); //enqueue the pixel
				processed[curRow - 1][curCol] = true; //mark it processed
			}
		}

		//top left
		if (imagePtr[curRow - 1][curCol - 1] == matchColor && processed[curRow - 1][curCol - 1] == false)
		{
			if (inField(curRow - 1, curCol - 1))
			{
				OrderedPair aPixel(curRow - 1, curCol - 1);
				aQueue.push(aPixel);
				processed[curRow - 1][curCol - 1] = true;
			}
		}

		//right
		if (imagePtr[curRow][curCol + 1] == matchColor && processed[curRow][curCol + 1] == false)
		{
			if (inField(curRow, curCol + 1))
			{
				OrderedPair aPixel(curRow, curCol + 1);
				aQueue.push(aPixel);
				processed[curRow][curCol+1] = true;
			}
		}


		//top right
		if (imagePtr[curRow - 1][curCol + 1] == matchColor && processed[curRow - 1][curCol + 1] == false)
		{
			if (inField(curRow - 1, curCol + 1))
			{
				OrderedPair aPixel(curRow - 1, curCol + 1);
				aQueue.push(aPixel);
				processed[curRow - 1][curCol + 1] = true;
			}
		}

		//bottom left
		if (imagePtr[curRow + 1][curCol - 1] == matchColor && processed[curRow + 1][curCol - 1] == false)
		{
			if (inField(curRow +1, curCol - 1))
			{
				OrderedPair aPixel(curRow+1, curCol - 1);
				aQueue.push(aPixel);
				processed[curRow + 1][curCol -1] = true;
			}
		}
		

		//left
		if (imagePtr[curRow][curCol - 1] == matchColor && processed[curRow][curCol - 1] == false)
		{
			if (inField(curRow, curCol - 1))
			{
				OrderedPair aPixel(curRow, curCol - 1);
				aQueue.push(aPixel);
				processed[curRow][curCol - 1] = true;
			}
		}

		//bottom
		if (imagePtr[curRow + 1][curCol] == matchColor && processed[curRow + 1][curCol] == false)
		{
			if (inField(curRow + 1, curCol))
			{
				OrderedPair aPixel(curRow + 1, curCol);
				aQueue.push(aPixel);
				processed[curRow + 1][curCol] = true;
			}
		}

		//bottom right
		if (imagePtr[curRow + 1][curCol + 1] == matchColor && processed[curRow + 1][curCol + 1] == false)
		{
			if (inField(curRow + 1, curCol + 1))
			{
				OrderedPair aPixel(curRow + 1, curCol + 1);
				aQueue.push(aPixel);
				processed[curRow + 1][curCol + 1] = true;
			}
		}

	}
}
