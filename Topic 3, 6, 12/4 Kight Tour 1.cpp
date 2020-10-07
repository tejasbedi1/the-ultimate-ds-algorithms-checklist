#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void displayGrid(int **arr, int n)
{
	int i, j;
	system("cls");
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

void solve(int **arr, int n, int a, int b, int posID)
{
	// Current Pos a, b
	arr[a][b] = posID;
	
	if (LOG_LEVEL >= 2) displayGrid (arr,n);
	
	if (posID >= 63)
	{
		displayGrid (arr,n);
		system("pause");
	}
	
	// Loop eligible places 
	// IF the last possible place is not 63 then backtrack
	{
		// Down
		if (a+2 < n && b+1 < n && arr[a+2][b+1] == -1)
		{
			solve (arr, n, a+2, b+1, posID+1);
		}
		if (a+2 < n && b-1 > -1 && arr[a+2][b-1] == -1)
		{
			solve (arr, n, a+2, b-1, posID+1);
		}
		// Left
		if (a-1 > -1 && b-2 > -1 && arr[a-1][b-2] == -1)
		{
			solve (arr, n, a-1, b-2, posID+1);
		}
		if (a+1 < n && b-2 > -1 && arr[a+1][b-2] == -1)
		{
			solve (arr, n, a+1, b-2, posID+1);
		}
		// Top 
		if (a-2 > -1 && b+1 < n && arr[a-2][b+1] == -1)
		{
			solve (arr, n, a-2, b+1, posID+1);
		}
		if (a-2 > -1 && b-1 > -1 && arr[a-2][b-1] == -1)
		{
			solve (arr, n, a-2, b-1, posID+1);
		}
		// Right
		if (a-1 > -1 && b+2 < n && arr[a-1][b+2] == -1)
		{
			solve (arr, n, a-1, b+2, posID+1);
		}
		if (a+1 < n && b+2 < n && arr[a+1][b+2] == -1)
		{
			solve (arr, n, a+1, b+2, posID+1);
		}
		
		// IF you run out of possiblities then turn the array at curr pos back 0
		arr[a][b] = -1;
		debug (2, "Backtracking\n");
	}
}

int main ()
{
	// Resource
	// https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/
	
	// Naive Backtracking Very Slow
	
	LOG_LEVEL = 1;
	
	int i;
	int n = 8;
    int **arr;
    arr = new int*[n];
    
    for (int i=0; i<n; i++)
		arr[i] = new int[n];
	
	clearGrid(arr, n);
	displayGrid(arr, n);
	
	solve (arr, n, 0, 0, 0);
	
	return 0;
}
