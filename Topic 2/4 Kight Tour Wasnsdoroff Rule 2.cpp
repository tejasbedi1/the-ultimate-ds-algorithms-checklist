#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void displayGrid(int **arr, int n)
{
	int i, j;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			// Just for asthetic purposes
			if (arr[i][j] <= 9 && arr[i][j] >= 0) debug (1, arr[i][j], "  ");
			else debug (1, arr[i][j], " ");
		}
			
		debug (1, "\n");
	}
	debug (1, "\n");
}

void clearGrid(int **arr, int n)
{
	int i, j;
	
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			arr[i][j] = -1;
}

int returnAdjecentUnivisted(int a, int b, int **arr, int n)
{
	int count = 0;	
	// 8 positions
	// Too lazy to optimize this
	if (a-1 > -1 && b-1 > -1 && arr[a-1][b-1] == -1)
		count++;
	if (a-1 > -1 && arr[a-1][b] == -1)
		count++;
	if (a-1 > -1 && b+1 < n && arr[a-1][b+1] == -1)
		count++;
	
	if (b-1 > -1 && arr[a][b-1] == -1)
		count++;
	if (b+1 < n && arr[a][b+1] == -1)
		count++;
	
	if (a+1 < n && b-1 > -1 && arr[a+1][b-1] == -1)
		count++;
	if (a+1 < n && arr[a+1][b] == -1)
		count++;
	if (a+1 < n && b+1 < n && arr[a+1][b+1] == -1)
		count++;
	
	return count;
}

void populateNoOfUnvisited(int **unv, int **arr, int n)
{
	int i,j;
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			unv[i][j] = returnAdjecentUnivisted(i, j, arr, n);
	
}

void minusAllAdjecent(int **unv, int a, int b, int n)
{
	// If adjecent exists, decrease -1 from unv 
	// because current one is now visited
	if (a-1 > -1 && b-1 > -1)
		unv[a-1][b-1] -= 1;
	if (a-1 > -1)
		unv[a-1][b] -= 1;
	if (a-1 > -1 && b+1 < n)
		unv[a-1][b+1] -= 1;
	
	if (b-1 > -1)
		unv[a][b-1] -= 1;
	if (b+1 < n)
		unv[a][b+1] -= 1;
	
	if (a+1 < n && b-1 > -1)
		unv[a+1][b-1] -= 1;
	if (a+1 < n)
		unv[a+1][b] -= 1;
	if (a+1 < n && b+1 < n)
		unv[a+1][b+1] -= 1;
	
}

void plusAllAdjecent(int **unv, int a, int b, int n)
{
	// If adjecent exists, decrease -1 from unv 
	// because current one is now visited
	if (a-1 > -1 && b-1 > -1)
		unv[a-1][b-1] += 1;
	if (a-1 > -1)
		unv[a-1][b] += 1;
	if (a-1 > -1 && b+1 < n)
		unv[a-1][b+1] += 1;
	
	if (b-1 > -1)
		unv[a][b-1] += 1;
	if (b+1 < n)
		unv[a][b+1] += 1;
	
	if (a+1 < n && b-1 > -1)
		unv[a+1][b-1] += 1;
	if (a+1 < n)
		unv[a+1][b] += 1;
	if (a+1 < n && b+1 < n)
		unv[a+1][b+1] += 1;
	
}

void solve(int **arr, int **unv, int n, int a, int b, int posID);

void goToUnvisitedFromLeastAdgencentVisited(int **unv, int **arr, int a, int b, int posID, 
	int n)
{
	int i;
	for (i=1; i<=n; i++)
	{
		// Down
		if (a+2 < n && b+1 < n && arr[a+2][b+1] == -1 && unv[a+2][b+1] == i)
		{
			solve (arr, unv, n, a+2, b+1, posID+1);
		}
		if (a+2 < n && b-1 > -1 && arr[a+2][b-1] == -1 && unv[a+2][b-1] == i)
		{
			solve (arr, unv, n, a+2, b-1, posID+1);
		}
		// Left
		if (a-1 > -1 && b-2 > -1 && arr[a-1][b-2] == -1 && unv[a-1][b-2] == i)
		{
			solve (arr, unv, n, a-1, b-2, posID+1);
		}
		if (a+1 < n && b-2 > -1 && arr[a+1][b-2] == -1 && unv[a+1][b-2] == i)
		{
			solve (arr, unv, n, a+1, b-2, posID+1);
		}
		// Top 
		if (a-2 > -1 && b+1 < n && arr[a-2][b+1] == -1 && unv[a-2][b+1] == i)
		{
			solve (arr, unv, n, a-2, b+1, posID+1);
		}
		if (a-2 > -1 && b-1 > -1 && arr[a-2][b-1] == -1 && unv[a-2][b-1] == i)
		{
			solve (arr, unv, n, a-2, b-1, posID+1);
		}
		// Right
		if (a-1 > -1 && b+2 < n && arr[a-1][b+2] == -1 && unv[a-1][b+2] == i)
		{
			solve (arr, unv, n, a-1, b+2, posID+1);
		}
		if (a+1 < n && b+2 < n && arr[a+1][b+2] == -1 && unv[a+1][b+2] == i)
		{
			solve (arr, unv, n, a+1, b+2, posID+1);
		}
	}	
}

void solve(int **arr, int **unv, int n, int a, int b, int posID)
{
	// Current Pos a, b
	arr[a][b] = posID;
	// -1 from all adjecent nodes as this one is marked visited
	minusAllAdjecent(unv, a, b, n);
	
	system("cls");
	if (LOG_LEVEL >= 2) displayGrid (arr,n);
	if (LOG_LEVEL >= 2) displayGrid (unv,n);
	
	//system("pause");
	
	if (posID >= 55)
	{
		displayGrid (arr,n);
		displayGrid (unv,n);
		system("pause");
	}
	
	{
		// Go to one with least unvisted adjecent index's
		goToUnvisitedFromLeastAdgencentVisited(unv, arr, a, b, posID, n);
		
		// IF you run out of possiblities then turn the array at curr pos back 0
		arr[a][b] = -1;
		plusAllAdjecent(unv, a, b, n);
		unv[a][b] = returnAdjecentUnivisted(a, b, arr, n);
		debug (2, "Backtracking\n");
	} 
}

int main ()
{
	// Resource
	// https://www.geeksforgeeks.org/warnsdorffs-algorithm-knights-tour-problem/
	
	// Naive Backtracking + Warnsdoroff's Rule
	
	// Rule
	// a. We can start from any initial position of the knight on the board.
	// b. We always move to an adjacent, unvisited square with minimal degree 
	//    minimum number of unvisited adjacent).
	
	// So we need to maintain adgecents also now :(
	
	LOG_LEVEL = 1;
	
	int i;
	int n = 8;
    int **arr;
    int **unv; // Adjecent unvisited
    
    arr = new int*[n];
    unv = new int*[n];
    
    for (int i=0; i<n; i++)
    {
    	arr[i] = new int[n];
    	unv[i] = new int[n];
	}
	
	clearGrid(arr, n);
	displayGrid(arr, n);
	
	populateNoOfUnvisited(unv, arr, n);
	displayGrid(unv, n);
	 
	solve (arr, unv, n, 0, 0, 0);
	
	return 0;
}
