#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

int longestSubarray (int *arr, int size, int k)
{
	int i;
	int currSum = 0;
	int rem; // remainder
	unordered_map <int, int> un_map;
	
	int maxLen = 0;
	int lpos = 0, rpos = 0;
	
	for (i=0; i<size; i++)
	{
		currSum += arr[i];
		rem = currSum % k;
		
		if (rem == 0)
		{
			if (maxLen < i+1) // Redundant check but still here
			{
				maxLen == i+1;
				lpos = 0;
				rpos = i;
			}
		}
		else
		{
			// Following if else can be shorter but easily
			// understandable this way
			
			if ( un_map.find (rem) != un_map.end() )
			{
				if (maxLen < i-un_map[rem])
				{
					maxLen = i-un_map[rem];
					lpos = un_map[rem]+1;
					rpos = i;
				}
				else
				{
					debug (2, "New candiate found but current maxlength is sufficient\n");
					debug (2, "New candidate length: ", i-un_map[rem], "\n");
				}
			}
			
			else if ( un_map.find (currSum % k) == un_map.end())
				un_map.insert( make_pair(currSum % k, i) );
		}
	}
	
	debug(1, "Max Length: ", maxLen, " (", lpos, ",", rpos, ")", 
		" (", arr[lpos], ",", arr[rpos], ")\n");
	
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
	// https://www.geeksforgeeks.org/longest-subarray-sum-divisible-k/?ref=lbp
	
	// Explanation
	// This question bears a slight resemblance to the previous one (Q8)
	// The main functionality of this being
	//  we save the remainder of the currentSum and k in a map
	//  That also only the unique remainders, along with there first occurance
	//
	// So upon reaching a currsum we would have the remainder and finding in the 
	//  map we can know the remainder to be removed
	//
	// This can be easily modified to print the sum as well 
	// (just modify the map to hold the current sum <int, pair<int,int>>) Maybe?
	
	LOG_LEVEL = 3;
	
	int k;
	
	k = 3;
	int arr[] = {2, 7, 6, 1, 4, 5};
	
	//k = 3;
	//int arr[] = {-2, 2, -5, 12, -11, -1, 7};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	display (arr, size);
	debug (2, "Finding longest Subarray...\n");
	longestSubarray (arr, size, k);
	//display (arr, size);
}
