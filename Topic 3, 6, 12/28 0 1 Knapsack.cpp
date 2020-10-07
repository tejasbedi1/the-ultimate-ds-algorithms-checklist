#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

// NOT USED
struct hash_pair
{
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2> &p) const
	{
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);
		return hash1 ^ hash2;
	}
};

void displayArr(int **arr, int r, int c)
{
	int i, j;
	for (i=0; i<r; i++)
	{
		for (j=0; j<c; j++)
		{
			if (arr[i][j] >= 0 && arr[i][j] <= 9)
				debug (1, " ", arr[i][j], "  ");
			else
				debug (1, arr[i][j], "  ");
		}
		debug (1, "\n");
	}
	debug (1, "\n");
}

int min(int a, int b)
{
	return (a > b) ? b : a;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

// All values stored in 2D array
int solve(int *val, int *w, int cap, int size, int hcf)
{
	int i,j;
	int **arr;
	int col, row;
	
	col = cap/hcf;
	row = size+1;
	
	arr = new int*[row];
	for (i=0; i<row; i++)
		arr[i] = new int[col];
	
	// INIT
	for (i=1; i<row; i++)
		for (j=0; j<col; j++)
			arr[i][j] = -1;
	
	// First row 
	for (j=0; j<col; j++)
		arr[0][j] = 0;
	
	if (LOG_LEVEL >= 3) displayArr(arr, row, col);
	
	for (i=1; i<row; i++)
	{
		for (j=0; j<col; j++)
		{
			if ( w[i-1] < hcf*(j+1))
			{
				arr[i][j] = max (val [i-1] + arr[i-1][j-(w[i-1]/hcf)], arr[i-1][j] );
			}
			else if (w[i-1] == hcf*(j+1))
			{
				arr[i][j] = max (val [i-1], arr[i-1][j] );
			}
			else
				arr[i][j] = arr[i-1][j];
		}
		
		if (LOG_LEVEL >= 3) displayArr(arr, row, col);
	}
	
	if (LOG_LEVEL >= 2) displayArr(arr, row, col);
	
	// FIND ITEMS included
	i = row-1; 
	j = col-1;
	
	while (true)
	{
		if (i-1 <= -1 || j <= -1)
			break;
			
		if (arr[i][j] != arr[i-1][j])
		{
			debug (2, "Included, Item of Weight: ", w[i-1], "\n");
			j = j - (w[i-1]/hcf);
			i = i-1;	
		}
		else
			i = i-1;
	}
	
	return arr[row-1][col-1];
}

int solveSpaceOptimized(int *val, int *w, int cap, int size, int hcf)
{
	int i,j;
	int **arr;
	int col, row;
	
	col = cap/hcf;
	row = size+1;
	
	arr = new int*[2];
	for (i=0; i<row; i++)
		arr[i] = new int[col];
	
	// INIT
	for (i=1; i<row; i++)
		for (j=0; j<col; j++)
			arr[i][j] = -1;
	
	// First row 
	for (j=0; j<col; j++)
		arr[0][j] = 0;
	
	if (LOG_LEVEL >= 3) displayArr(arr, 2, col);
	
	int index = 1;
	
	for (i=1; i<row; i++)
	{
		for (j=0; j<col; j++)
		{
			if ( w[i-1] < hcf*(j+1))
			{
				arr[index][j] = max (val [i-1] + arr[!index][j-(w[i-1]/hcf)], arr[!index][j] );
			}
			else if (w[i-1] == hcf*(j+1))
			{
				arr[index][j] = max (val [i-1], arr[!index][j] );
			}
			else
				arr[index][j] = arr[!index][j];
		}
		
		// Flips between 1 & 0
		index = !index;
		
		if (LOG_LEVEL >= 3) displayArr(arr, 2, col);
	}
	
	if (LOG_LEVEL >= 2) displayArr(arr, 2, col);
	
	return max (arr[0][col-1], arr[1][col-1]);
}

int gcdArray(int *arr, int size)
{
	int i;
	int result;
	
	result = __gcd(arr[0],arr[1]);
	for (i=2; i<size; i++)
		result = __gcd(result, arr[i]);
		
	return result;
}

int main()
{	
	// DP O(n^2) Space (n^2)
	// DP O (n^2) Space OP (2n)
	
	// Resource
	// https://www.youtube.com/watch?v=cJ21moQpofY
	// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
	// 'Back to SWE' also has a good vid

	// POINTS TO REMEMBER 
	// Need GCD Algo
	// There is a NORMAL Solution & a
	// Space Optimized Solution 
	
	LOG_LEVEL = 3;
	
	// Ex 0 Ans 10
	int val[] = {2,2,3,4,5};
	int w[] = {3,1,2,3,4};
	int cap = 7;
	
	// EX 1 Ans.220
	//int val[] = {60,100,120};
	//int w[] = {10,20,30};
	//int cap = 50;
	
	// EX 2 Ans.60
	//int val[] = {10,20,30};
	//int w[] = {1,2,3};
	//int cap = 7;
	
	int size = sizeof(val)/sizeof(val[0]);
	
	int hcf = gcdArray(w, size);
	int ans = solveSpaceOptimized(val, w, cap, size, hcf);
	
	debug (1, ans, "\n");
}
