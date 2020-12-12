#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

int findVariables (int *arr, int size)
{
	int i,j;
	
	unordered_map <int, pair<int, int>> un_mapAB;
	unordered_map <int, pair<int, int>> un_mapCD;
	
	for (i=0; i<size; i++)
	{
		for (j=0; j<size; j++)
		{
			if (i != j)
			{
				if (un_mapAB.find( arr[i]+arr[j] ) == un_mapAB.end())
				{
					debug (2, arr[i]+arr[j], " ");
					un_mapAB.insert( make_pair(arr[i]+arr[j], make_pair(i, j) ) );
				}
			}
		}
	}
	debug (2, "\n");
	
	for (i=0; i<size; i++)
	{
		for (j=0; j<size; j++)
		{
			if (i != j && arr[i]-arr[j] >= 1)
			{
				debug (2, arr[i]-arr[j], " ");
				un_mapCD.insert( make_pair(arr[i]-arr[j], make_pair(i, j) ) );
			}			
		}
	}
	debug (2, "\n");
	
	unordered_map <int, pair<int, int>> :: iterator itr;
	
	debug (2, "AB - ");
	for (itr = un_mapAB.begin(); itr != un_mapAB.end(); itr++)
		debug (2, itr->first, " ");
	debug (2, "\n");
	
	debug (2, "CD - ");
	for (itr = un_mapCD.begin(); itr != un_mapCD.end(); itr++)
		debug (2, itr->first, " ");
	debug (2, "\n");
	
	int maxD = -1;
	pair <int, int> tAB;
	pair <int, int> tCD;
	int a, b, c, d;
	
	for (itr = un_mapCD.begin(); itr != un_mapCD.end(); itr++)
	{
		if (itr->first > maxD)
		{
			if (un_mapAB.find(itr->first) != un_mapAB.end())
			{
				tAB = un_mapAB.find(itr->first)->second;
				tCD = itr->second;
				if (tCD.first != tAB.first && tCD.first != tAB.second &&
					tCD.second != tAB.first && tCD.second != tAB.second)
				{
					maxD = itr->first;
					a = tAB.first;
					b = tAB.second;
					c = tCD.second;
					d = tCD.first;
				}
			}
		}
	}
	if (maxD == -1)
		debug (2, "No Solution...\n");
	else
	{
		debug (2, "Max: ", maxD, "\n");
		debug (2, "A: ", arr[a], "\n");
		debug (2, "B: ", arr[b], "\n");
		debug (2, "C: ", arr[c], "\n");
		debug (2, "D: ", arr[d], "\n");	
	}
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
	// a+b+c = d
	
	// RESOURCE 
	// https://www.geeksforgeeks.org/find-largest-d-in-array-such-that-a-b-c-d/
	
	// Constrints
	// All Positive & >= 1
	
	// Explanation
	// we find a+b's and store in map
	// then we find d-c's and store in map
	// This cuts down are complexity to O(n^2)
	//
	// Then we loop thru are d-c's
	// we check for maxD's (i.e max (d-c))
	// here if the element of d-c is present in a+b's aswell then we check further
	//  if all a, b, c, d index's are unique
	//  then we have our new max element 
	 
	LOG_LEVEL = 3;
	
	//int arr[] = {2, 3, 5, 7, 12};
	int arr[] = {12, 7, 5, 3, 2};
	//int arr[] = {2, 16, 64, 256, 1024};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	display (arr, size);
	debug (2, "Finding if subarray exists...\n");
	findVariables (arr, size);
}
