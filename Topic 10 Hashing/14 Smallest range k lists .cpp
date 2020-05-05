#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void findSmallestRange(int *arr1, int size, int k, int *arr2, int *arr3)
{
	int in1 = 0, in2 = 0, in3 = 0;
	int i = 0;
	
	priority_queue <int, vector<int>, greater<int>> pQueue;
	pQueue.push(arr1[in1]);
	pQueue.push(arr2[in2]);
	pQueue.push(arr3[in3]);
	
	debug (2, pQueue.top(), "\n");
	
	
    while (in1 < size && in2 < size && in3 < size)
    {
    	in1++;
    	in2++;
    	in3++;
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
	// https://www.geeksforgeeks.org/find-largest-d-in-array-such-that-a-b-c-d/
	
	// NOTE
	// In this question there are k lists (for the eg, we are using 3)
	// That does mean we can have n lists 
	
	// Explanation

	LOG_LEVEL = 3;
	
	int k = 3;
	
	int arr1[] = {4, 7, 9, 12, 15};
	int arr2[] = {0, 8, 10, 14, 20};
	int arr3[] = {6, 12, 16, 30, 50};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	display (arr, size);
	debug (2, "Smallest Range k lists...\n");
	findSmallestRange (arr1, size, k, arr2, arr3);
}
