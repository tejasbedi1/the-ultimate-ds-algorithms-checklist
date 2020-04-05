#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

using namespace std;

struct data
{
	int data;
	int pos;
};

void stockSpanProblem(int s, int *arr)
{
	int i = 0;
	data d;
	stack <data> stk;
	
	d.data = arr[i];
	d.pos = i;
	stk.push(d);
	debug (1, "s0: 1\n");
	
	for (i=1; i<s; i++)
	{
		d.data = arr[i];
		d.pos = i;
		
		if (d.data < stk.top().data)
		{
			stk.push(d);
			debug(1, "s", i, ": 1\n");
		}
		else
		{
			while (stk.top().data <= d.data)
			{
				stk.pop();
				if (stk.empty() == true)
					break;
			}
			
			if (stk.empty() == true)
			{
				debug (1, "s", i, ": ", i+1, "\n");
				stk.push(d);
			}
			else
			{
				debug (1, "s", i, ": ", i-stk.top().pos, "\n");
				stk.push(d);
			}
		}
	}
}

int main ()
{	
	// RESOURCES 
	// https://www.geeksforgeeks.org/the-stock-span-problem/
	
	// Process
	// Go figure
	
	LOG_LEVEL = 3;
	debug (3, "Algorithm Output--\n\n");
	
	int size;
	// I
	int arr[] = {100, 80, 60, 70, 60, 75, 85};
	
	// II Going down
	//int arr[] = {80, 70, 60, 50, 40, 30};
	
	// III Going up
	//int arr[] = {30, 40, 50, 60, 70, 80};
	
	size = sizeof(arr)/sizeof(arr[1]);
	
	//debug (1, size);
	stockSpanProblem(size, arr);
	
}
