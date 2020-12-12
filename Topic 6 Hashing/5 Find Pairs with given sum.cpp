#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

int findPairs(int *arr, int size, int sum)
{
	unordered_multiset <int> set;
	
	for (int i=0; i<size; i++)
	{
		set.insert(arr[i]);
		if (set.find(sum-arr[i]) != set.end())
			debug (1, "(", arr[i], ",", sum-arr[i], ") ");
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
	// RESOURCE 
	// (Not that good)
	// https://www.geeksforgeeks.org/count-pairs-with-given-sum/
	// (good)
	// https://www.youtube.com/watch?v=XKu_SEDAykw
	
	// Our solution will not work for EX-2
	// That'll need a map to count frequency as well
	LOG_LEVEL = 3;
	
	// EX-1
	int arr[] = {10, 12, 10, 15, -1, 7, 6, 5, 4, 2, 1, 1, 1}; 
	// EX-2
	//int arr[] = {1, 1, 1, 1};									
	int size = sizeof(arr)/sizeof(arr[0]);
	
	int sum = 2;
	
	display (arr, size);
	debug (2, "Finding pairs...\n");
	findPairs (arr, size, sum);
}
