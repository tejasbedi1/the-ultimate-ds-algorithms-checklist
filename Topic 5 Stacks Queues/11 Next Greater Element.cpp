#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

using namespace std;

void nextGreater(int *arr, int size)
{
	int i;
	int ans;
	stack <int> stk;
	
	for (i = size-1; i>=0; i--)
	{
		while (stk.empty() == false)
		{
			if (stk.top() > arr[i])
			{
				ans = stk.top();
				break;
			}
			else
				stk.pop();
		}
		if (stk.empty() == true)
			ans = -1;
			
		stk.push(arr[i]);
		debug(1, arr[i], " ", ans, "\n");
	}
}

int main ()
{	
	// RESOURCES https://www.geeksforgeeks.org/next-greater-element-in-same-order-as-input/
	// Follow only the algorithmic part
	// better yet ee the picture only
	
	// IMAGE: 11
	
	LOG_LEVEL = 3;
	debug (3, "Algorithm Output--\n\n");
	
	int size = 5;
	int arr[] = {4,5,2,25,10};
	//int arr[] = {7,6,5,4,10};
	
	nextGreater(arr, size);
}
