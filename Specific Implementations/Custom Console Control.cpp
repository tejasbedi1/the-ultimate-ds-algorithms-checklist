#include <iostream>
#include <windows.h>
#include <math.h>

#define SetPos SetConsoleCursorPosition
#define GSH GetStdHandle
#define SOH STD_OUTPUT_HANDLE
// SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

using namespace std;

COORD easy(int x, int line)
{
	COORD coord;
	coord.X = x;
	coord.Y = line;
	return coord;
}

void printTree (int h)
{
	int nodes, space = 4; // number of nodes & space between the nodes
	int j;
	int clvl = 1; //current level
	
	int positionsAvailable; // How many blocks i.e 1 cursor space is available
	nodes = pow(2,h-1);
	positionsAvailable = nodes*space; 
	
	space = space*(pow(2,h-1)); // Space between consecutive nodes
	
	while (clvl <= h)
	{
		nodes = pow(2,clvl-1);
		j = (positionsAvailable / (nodes*2))-2;
		
		for (int i=0; i<nodes; i++)
		{
			SetPos(GSH(SOH), easy(j,clvl));
			cout<<"?";
			j += space;
		}
		clvl++;
		space = space / 2; 
	}
	SetPos(GSH(SOH), easy(0,h+1));
	cout<<"END";
	
}


void printTreeRecur(int h, int clvl, int positionsAvailable, int space, int* arr)
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
	cout<<"?";
	
	SetPos(GSH(SOH), easy(0,h+2));
	system("pause");
		
	printTreeRecur(h, clvl+1, positionsAvailable, space/2, arr);
	printTreeRecur(h, clvl+1, positionsAvailable, space/2, arr);
}

void printTreePrimer (int h)
{
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
	
	printTreeRecur(h, clvl, positionsAvailable, space, arr);
}

int main()
{
	int h;
	cout<<"Enter height.. ";
	cin>>h;
	system("CLS");
	
	//printTree(h);
	printTreePrimer(h);
}
