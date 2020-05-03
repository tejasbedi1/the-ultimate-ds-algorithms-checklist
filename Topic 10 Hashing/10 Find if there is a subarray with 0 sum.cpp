#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

int findSubarray (int *arr, int size, int k)
{
	int i;
	unordered_map <int, int> un_map;
	int currSum = 0;
	int diff;
	int l=0, r=0;
	
	bool flag = false;
	
	for (i=0; i<size; i++)
	{
		currSum += arr[i];
		diff = currSum - k;
		
		if ( un_map.find( diff ) != un_map.end())
		{
			l = un_map[diff] + 1;
			r = i;
			flag = true;
			break;
		}
		else
			un_map.insert( make_pair(currSum, i) ) ;
	}
	
	if (flag)
		debug (1, "Subarray Found. (", l, ",", r, ")", 
		" (", arr[l], ",", arr[r], ")\n");
	else
		debug (1, "No subarray with sum 0.", "\n");
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
	// https://www.geeksforgeeks.org/find-if-there-is-a-subarray-with-0-sum/
	
	// Explanation
	// 
	 
	LOG_LEVEL = 3;
	
	int k = 0;
	
	int arr[] = {4, 2, -3, 1, 6};
	//int arr[] = {4, 2, 0, 1, 6};
	//int arr[] = {-3, 2, 3, 1, 6};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	display (arr, size);
	debug (2, "Finding if subarray exists...\n");
	findSubarray (arr, size, k);
}
