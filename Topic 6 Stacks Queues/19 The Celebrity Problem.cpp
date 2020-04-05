#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

using namespace std;

#define N 4
#define N 7

void findCelebrity(bool matrix[N][N])
{
	// ADD all to stack and check
	int i;
	stack <int> stk;
	
	for (i=0; i<N; i++)
		stk.push(i);
	
	int a, b;
	
	while (true)
	{
		a = stk.top();
		stk.pop();
		b = stk.top();
		stk.pop();
		
		// IF A knows B, then A defiently not the celebrity
		if (matrix[a][b] == true)
		{
			// If B knows A, then B is also not the celebrity
			if (matrix[b][a] == true)
			{
				
			}
			else
			{
				stk.push(b);
			}
		}
		// If B knows A, then B definetly not the celebrity
		else if (matrix[b][a] == true)
		{
			// If A knows B, then A is also not the celebrity
			if (matrix[a][b] == true)
			{
				
			}
			else
			{
				stk.push(a);
			}
		}
		// IF both don't know each other then no one is the celebrity
		
		if (stk.size() == 1 || stk.size() == 0)
			break;
	}
	
	if (stk.size() == 0)
	{
		debug (1, "No celebrity...\n");
	}
	else if (stk.size() == 1)
	{
		// Check celeb, If you dont do this cheeck, EX III fails
		for (i=0; i<N; i++)
		{
			if (matrix[stk.top()][i] == true)
			{
				debug (2, stk.top(), " not a true celebrity...\n");
				debug (1, "No celebrity found...\n");
				return;
			}
		}
		debug (1, "Celebrity: ", stk.top());
	}
	else
	{
		debug (1, "Out with size: ", stk.size());
	}
}

int main ()
{	
	// RESOURCES 
	// 1. https://www.youtube.com/watch?v=LtGnA5L6LIk
	// 2. https://www.geeksforgeeks.org/the-celebrity-problem/
	
	// Process
	// If A knows B, then A can’t be celebrity. Discard A, and B may be celebrity.
	// If A doesn’t know B, then B can’t be celebrity. Discard B, and A may be celebrity.
	// Repeat above two steps till we left with one person OR no person.
	// Ensure the remained person is celebrity
	
	// ASSUMPTION
	// The input is valid
	
	LOG_LEVEL = 3;
	debug (3, "Algorithm Output--\n\n");
	
	// I
	/* bool matrix[4][4] = { {0,1,0,1},
						  {1,0,0,1},
						  {0,1,0,1},
						  {0,0,0,0} };
	*/					  
	/*
	// II
						// A,B,C,D,E,F,G
	bool matrix[7][7] = { {0,1,1,1,0,0,0}, 	// A
						  {1,0,1,1,0,0,0},  // B
						  {0,1,0,0,0,0,0}, 	// C
						  {1,1,1,0,0,0,0},	// D
						  {0,0,0,0,0,1,1},	// E
						  {0,0,1,0,1,0,1},	// F
						  {0,0,1,0,1,1,0} };// G
    */
   	// III
						// A,B,C,D,E,F,G
	bool matrix[7][7] = { {0,1,1,1,0,0,0}, 	// A
						  {1,0,1,1,0,0,0},  // B
						  {0,1,0,0,0,0,0}, 	// C
						  {1,1,1,0,0,0,0},	// D
						  {0,0,1,0,0,1,1},	// E
						  {0,0,1,0,1,0,1},	// F
						  {0,0,1,0,1,1,0} };// G
   
	findCelebrity(matrix);
}
