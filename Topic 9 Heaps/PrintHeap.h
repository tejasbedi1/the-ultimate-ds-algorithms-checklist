#include <iostream>
#include <math.h>
#include <windows.h>

#define SetPos SetConsoleCursorPosition
#define GSH GetStdHandle
#define SOH STD_OUTPUT_HANDLE
// SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

int globalOffset = 0;

COORD easy(int x, int line)
{
	COORD coord;
	coord.X = x;
	coord.Y = line + globalOffset;
	return coord;
}

void clearLine (int h)
{
	SetPos(GSH(SOH), easy(0,h+2));
	std::cout<<"                                        \n";
	SetPos(GSH(SOH), easy(0,h+2));
}

void printTreeRecur(int h, int clvl, int positionsAvailable, int space, int* arr, 
									int *data, int currentPos, int arrSize, int prevP)
{
	if (clvl > h)
		return;
		
	int nodes; // No of nodes
	int initialSpace; // space to be left before each line
		
	nodes = pow(2,clvl-1); // nodes in current lvl 
	initialSpace = (positionsAvailable / (nodes*2))-2;
	
	int preDistance; 	// If this is not the first node then a set amount of disance is to be left so that it does not clash with
						// the previous node in the same level
	
	preDistance = arr[clvl-1] * space;
		
	arr[clvl-1] = arr[clvl-1] + 1; // Corresponds to the nth node
	
	SetPos(GSH(SOH), easy(initialSpace+preDistance ,clvl));
	
	if (currentPos >= arrSize)
		std::cout<<"?";
	else
		std::cout<<data[currentPos];
		//std::cout<<data[currentPos]<<","<<currentPos;
	
	currentPos++;
	if ( ((2*prevP) + 1) > currentPos)
		printTreeRecur(h, clvl, positionsAvailable, space, arr, data, 
												currentPos, arrSize, prevP);
	else
		printTreeRecur(h, clvl+1, positionsAvailable, space/2, arr, data,
												currentPos, arrSize, currentPos);
}

void printTreePrimer (int h, int *data, int arraySize, int offset)
{
	globalOffset = offset;

	int* arr = new int[h]; // The array which maintains on which node we currently are at
	for (int i=0;i<h;i++)
	{
		arr[i] = 0;
	}	
	int clvl = 1; // Start with lvl 1
	int nodes, space = 4; // number of nodes & space between the nodes
	
	int positionsAvailable; // How many blocks i.e 1 cursor space is available
	
	nodes = pow(2,h-1); // MAX nodes ie avaialble on last lvl
	positionsAvailable = nodes*space;  
	space = space*(pow(2,h-1)); // Max Space between consecutive nodes
	
	int currentPos = 0;
	int prevParent = 0;
	printTreeRecur(h, clvl, positionsAvailable, space, arr, data, currentPos, arraySize, prevParent);
	
	SetPos(GSH(SOH), easy(0,h+2)); // LAST POSITION
}
