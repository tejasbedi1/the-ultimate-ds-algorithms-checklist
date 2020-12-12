#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

using namespace std;

struct data
{
	int val;
	int no;	// Number of next greater elements
};

void nextGreater(int *arr, int size)
{
	int i;
	int ans;
	stack <data> stk;
	
	data d;
	
	int *noOfNGE; // Number of next greater elements
	noOfNGE = new int[size];
	
	for (i = size-1; i>=0; i--)
	{
		while (stk.empty() == false)
		{
			if (stk.top().val > arr[i])
			{
				ans = stk.top().val;
				noOfNGE[i] = 1 + stk.top().no;
				break;
			}
			else
				stk.pop();
		}
		if (stk.empty() == true)
		{
			ans = -1;
			noOfNGE[i] = 0;
		}
		
		d.val = arr[i];
		d.no = noOfNGE[i];
		
		stk.push(d);
		
		debug(1, arr[i], " Next Greatest Element: ", ans, 
			" | No of Next Greatest Elements: ", noOfNGE[i], "\n");
		
	}
}

int main ()
{	
	// The QUESTION
	// Basically find the net greater elements And then the next greatest element of that
	// and hence forth.
	// Return the number of next greatest elements following this rule
	
	// RESOURCES https://www.geeksforgeeks.org/number-nges-right/
	// Follow only the algorithmic part
	// better yet see the picture only
	
	// IMAGE: 11
	
	LOG_LEVEL = 3;
	debug (3, "Algorithm Output--\n\n");
	
	int size = 8;
	int arr[] = { 3, 4, 2, 7, 5, 8, 10, 6 }; 
	
	nextGreater(arr, size);
}
