#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

using namespace std;


void maxArea(int *arr, int size)
{
	int max = 0;
	int topSize;
	int area;
	int i=0;
	stack <int> stk;
	
	while (i < size)
	{
		debug(3, "Processing bar with size, ", arr[i], "\n");
		if (stk.empty() == true)
		{
			debug(2, "Stack Empty, pushing bar ", i, "(", arr[i], ")", " in stack\n");
			stk.push(i);
		}
		else
		{
			while (stk.empty() == false && arr[stk.top()] > arr[i])
			{
				debug(2, "Stack top ", stk.top(), "(", arr[stk.top()], 
					") larger than size of bar ", i, "(", arr[i], ")",
					", hence popping top and calculating area...\n");
				// Top needs to be popped also the area has to be calculated
				topSize = arr[stk.top()];
				stk.pop(); 
				if ( stk.empty() == true )
				{
					area = topSize * i;
				}
				else
				{
					area = topSize * (i - stk.top() - 1);
				}
				if (area > max)
				{
					debug (2, "New area, ", area, ", Greater than max: ", max, "\n");
					max = area;
				}
				else 
				{
					debug (3, "New area, ", area, ", Lesser/Equal to max: ", max, "\n");
				}
			}
			if (stk.empty() == true)
			{
				debug(2, "Stack Empty, pushing bar  ", i, "(", arr[i], ")", 
					", in stack\n");
				stk.push(i); 
			}
			else
			{
				debug(2, "Stack top size smaller than size of bar ", i, "(", arr[i], ")", 
					", hence pushing\n");
				stk.push(i); 
			}
		}
		i++;
	}
	
	debug (1, "Max Area: ", max);
}

int main ()
{	
	// The QUESTION
	// Given a histogram with bar of different sizes find the largest rectangle
	// that can be formed. (Just see a resource, its simple)
	
	// RESOURCES 
	// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
	// Just the formula 
	// https://www.youtube.com/watch?v=MhQPpAoZbMc&t=915 
	
	// Process
	// For a O(n) implementation we use stacks (obviously)
	// 
	// Our aim with the stack will be to make sure that from any bar we are able to
	// 	find the next smaller and the previous smaller bar. Like so we will 
	//  be able to find the area occupied by it.
	// So the whole program is made to make sure that we can achieve the stated 
	//  goal.
	//
	// Refer the image as well
	// So while travesing trough all bars if the topmost element is 
	//  larger than the one the index is curretly at then calculate the area 
	//  for the topmost one and pop it
	// If the topmost is smaller then simply push it into stack
	// if we follow this process every bar will eventuially get there area calculated
	// // There are specfic simple formula's for calculating the area
	
	// IMAGE 13
	
	LOG_LEVEL = 3;
	debug (3, "Algorithm Output--\n\n");
	
	// Each bar has one horzontal area
	
	//int size = 6;
	//int arr[] = {6,5,4,3,2,1};
	
	int size = 7;
	//int arr[] = {6,2,5,4,5,1,6};	
	int arr[] = {6,5,6,1,5,4,5};
	
	maxArea(arr, size);
}
