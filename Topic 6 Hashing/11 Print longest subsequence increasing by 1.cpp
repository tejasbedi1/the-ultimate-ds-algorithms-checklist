#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

int longestSubsequence (int *arr, int size)
{
	int i;
	
	// Next element wanted / current length / first element position
	unordered_map <int, pair<int,int>> un_map;
	
	int maxEle = -1;
	int maxLen = 0;
	pair <int, int> temp;
	
	un_map.insert ( make_pair(arr[0]+1, make_pair(1, 0) ) );
	
	maxEle = arr[0]+1;
	maxLen = 1;
	
	for (i=1; i<size; i++)
	{
		if ( un_map.find( arr[i] ) != un_map.end())
		{
			debug (2, "Processing ", arr[i], ", found in map\n");
			
			// Before entering +1 in map need to see if it already exists
			if (un_map.find (arr[i]+1) == un_map.end())
			{
				debug (2, " Further ", arr[i]+1, ", is not in map\n");
				
				temp = un_map[arr[i]];
				un_map.insert (make_pair(arr[i]+1, 
										make_pair((temp.first)+1, temp.second) ) );
				if (temp.first + 1 > maxLen)
				{
					maxLen = temp.first + 1;
					maxEle = arr[i]+1;
				}
				
				un_map.erase( arr[i] );
			}
			else	// +1 exists
			{
				debug (2, " Further ", arr[i]+1, ", in map, keeping one with more length\n");
				// If length of already existing is greater than the one which
				//  is to be added
				if (un_map[arr[i]+1].first > un_map[arr[i]].first + 1)
				{
					un_map.erase( arr[i] );
				}
				else
				{
					un_map.erase( arr[i]+1 );
					temp = un_map[arr[i]];
					un_map.insert( make_pair(arr[i]+1, 
											make_pair((temp.first)+1, temp.second) ) );
					
					if (temp.first + 1 > maxLen)
					{
						maxLen = temp.first + 1;
						maxEle = arr[i]+1;
					}
					
					un_map.erase( arr[i] );
				}
			}
		}
		else
		{
			debug (2, "Processing ", arr[i], ", its not in map\n");
			
			if ( un_map.find( arr[i]+1 ) == un_map.end())
			{
				debug (2, " Further ", arr[i]+1, ", is not in map, adding\n");
				un_map.insert( make_pair(arr[i]+1, make_pair(1, i)) );
			}
			else // +1 exists
			{
				debug (2, " Further ", arr[i]+1, ", already in map, ignoring\n");
				// Do nothing, because existsing one will 
				// always have a higher length or atleast equal length
			}
		}
	}
	
	debug (1, "Max Length: ", maxLen, "\n");
	debug (1, "Max Ele: ", maxEle, "\n");
	
	debug (1, "Subsequence \n");
	int t = arr[ un_map[maxEle].second ];
	for (i=0; i<size; i++)
	{
		if (t == arr[i])
		{
			debug (1, t, " ");
			t++;
		}
	}
	debug (1, "\n");
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
	// Objective 
	// Printing longest Increasing consecutive subsequence
	// Given n elements, write a program that prints the longest increasing subsequence 
	// 	whose adjacent element difference is one.
	
	// RESOURCE 
	// (not useful)
	// https://www.geeksforgeeks.org/printing-longest-increasing-consecutive-subsequence/
	//
	// IMAGE - 11
	// Explanation
	// Could be shorted but more readable this way
	//
	// Image 11 has a explanation
	// We maintatin the element to find, curr elength and position of first element 
	//  in a map
	
	 
	LOG_LEVEL = 3;
	
	int arr[] = {3, 2, 3, 3, 5, 4, 5, 10, 6, 11, 12};
	//int arr[] = {3, 10, 3, 11, 4, 5, 6, 7, 8, 12};
	//int arr[] = {6, 7, 8, 3, 4, 5, 9, 10};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	display (arr, size);
	debug (2, "Finding longest subsequence...\n");
	longestSubsequence (arr, size);
}
