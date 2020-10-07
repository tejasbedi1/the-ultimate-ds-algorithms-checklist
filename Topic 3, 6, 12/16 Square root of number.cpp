#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

double sqOf(double &a)
{
	return a * a; 
}

void findSqRoot(double no, double l, double r, double prevHalf)
{
	debug (2, "Between: ", l, ",", r, "\n");
	
	double half = (l+r) / 2;
	
	int a = 100000 * l;
	int b = 100000 * r;
	
	debug (3, "Between: ", a, ",", b, "\n");
	
	if ( a == b)
	{
		debug (1, "SqRoot: ", half, "\n");
		return;
	}
	
	if ( sqOf(half) > no )
		findSqRoot(no, l, half, prevHalf);
	else if (sqOf(half) < no)
		findSqRoot(no, half, r, prevHalf);
	else
		debug (1, "SqRoot: ", half, "\n");
		
}

int main()
{
	// Resource
	// https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/
	
	// Divide and Conquor Example 
	
	LOG_LEVEL = 1;
	
	double no = 11l;
	
	if (no > 1)
		findSqRoot(no, 1, no, 0);
}
