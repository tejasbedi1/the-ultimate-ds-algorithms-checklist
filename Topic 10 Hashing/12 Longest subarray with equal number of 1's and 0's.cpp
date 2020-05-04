#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

int findSubarray (int *arr, int size)
{
	int i;
	unordered_map <int, int> un_map;
	
	int maxLen = -1;
	int currSum = 0;
	int diff;
	int l=0, r=0;
	
	for (i=0; i<size; i++)
		if (arr[i] == 0)
			arr[i] = -1;
	
	for (i=0; i<size; i++)
	{
		currSum	+= arr[i];
		
		if (currSum == 0)
		{
			l = 0;
			r = i;
			maxLen = r-l + 1;
		}
		else if (un_map.find (currSum) == un_map.end())
		{
			un_map.insert ( make_pair(currSum, i) );
		}
		else // if curr sum found in 
		{
			if (maxLen < i - un_map[currSum])
			{
				l = un_map[currSum] + 1;
				r = i;
				maxLen = i - un_map[currSum];
			}	
		} 
	}
	
	for (i=0; i<size; i++)
		if (arr[i] == -1)
			arr[i] = 0;
	
	if (maxLen == -1)
		debug (1, "No subarray found");
	else
		debug(1, "Max Length: ", maxLen, " (", l, ",", r, ")", 
			" (", arr[l], ",", arr[r], ")\n");
}

void display (int *arr, int size)
{
	for (int i=0; i<size; i++)
	{
		debug (1, arr[i], " ");	
	}
	debug (1, "\n");
}

int main()
{	
	// RESOURCE 
	// https://www.geeksforgeeks.org/largest-subarray-with-equal-number-of-0s-and-1s/
	
	// Explanation
	// We use maps here for <value, position>
	// The map will hold only unique values because only those are needed
	// 
	// Also to make things easier to compute we set all 0 as -1
	//  and hence The queston will essentially become find the longest subarray with
	//  sum 0
	//
	// So, in the for loop we will keep calculating the cumulative sum and store it
	//  in the map. 
	// For every added element we will check if there is any previous sum we could
	//  rumove to make the cumulative sum 0. If there is, we check if the new
	//  length is more than the previously calculated lenght
	 
	LOG_LEVEL = 3;
	
	int k = 0;
	
	//int arr[] = {1, 0, 1, 1, 1, 0, 0};
	//int arr[] = {1, 1, 1, 1};
	//int arr[] = {1, 1, 1, 0, 1};
	int arr[] = {0, 0, 1, 1, 0};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	display (arr, size);
	debug (2, "Finding longest subarray...\n");
	findSubarray (arr, size);
}
