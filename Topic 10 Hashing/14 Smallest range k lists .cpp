#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void findSmallestRange(int **arr, int n, int k)
{
	int i,j;
	// array of index's
	int ind[k];
	for (i=0; i<k; i++)
		ind[i] = 0;
	
	int max = -1;
	
	priority_queue < pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pQueue;
	int min_kth_array;
	
	int smol_range = INT_MAX;
	int smol_smol, smol_large;
	int curr_smol;
	
	for (i=0; i<k; i++)
	{
		if (max < arr[i][0])
			max = arr[i][0];
			
		pQueue.push ( make_pair(arr[i][0], i) );
	}
	
	debug (3, "INITIAL Min: ", pQueue.top().first, ", Max: ", max, "\n");
	
	smol_smol = pQueue.top().first;
	min_kth_array = pQueue.top().second;
	smol_large = max;
	smol_range = smol_large - smol_smol;
	
	while (1)
	{
		pQueue.pop();
		ind[min_kth_array]++;
		
		if (ind[min_kth_array] >= n)
			break;
			
		if (max < arr[ min_kth_array ][ ind[min_kth_array] ])
			max = arr[ min_kth_array ][ ind[min_kth_array] ];
		
		pQueue.push (make_pair(arr[ min_kth_array ][ ind[min_kth_array] ], min_kth_array) );
		
		curr_smol = pQueue.top().first;
		min_kth_array = pQueue.top().second;
		
		debug (3, "Curr Max, Min: ", max, ",", curr_smol, "\n");

		if (smol_range > max - curr_smol)
		{
			smol_range = max - curr_smol;
			smol_large = max;
			smol_smol = curr_smol;
		}
				
	}
	debug (1, "Smallest Range: ", smol_range, "\n");
	debug (1, "Ans: ", smol_smol, ",", smol_large, "\n");
}

void display (int *arr, int size)
{
	for (int i=0; i<size; i++)
	{
		debug (1, arr[i], " ");	
	}
	debug (1, "\n");
}

void display (int **arr, int n, int k)
{
	int i = 0, j = 0;
	
	for (i=0; i<k; i++)
	{
		for (j=0; j<n; j++)
		{
			debug (1, arr[i][j], " ");
		}
		debug (1, "\n");
	}
}

int main()
{	
	// RESOURCE 
	// https://www.geeksforgeeks.org/find-largest-d-in-array-such-that-a-b-c-d/
	
	// NOTE
	// In this question there are k lists (for the eg, we are using 3)
	// That does mean we can have n lists 
	
	// Explanation
	// So lots of stuff happening here, sorta
	// For our worst case we can have n * n lists, so its important we see the complexity
	//  that way
	// 
	// Here on out I assume you understand the question
	// to get our minimum range
	// we first have index pointers of every array, init with 0 of course
	// Now we simply find the minimum of all the first elements of the k arrays
	//  We are to leverage the power of a priority queue for that 
	//  so that getting the minimum is a O(log n) operation (rather than O(n))
	// 
	// Now we find the range (max - min)
	// 	max is a simple variable. checked everytime we focus on a new value
	// If the range is the smallest its ever been store, if not.. well continue
	// 
	// Now in the loop we do this
	// pop the smallest element from the prioirty queue and push the next one from
	//		the same array (that one is checked for maximum as well)
	// Range is calculated then (stored if smallest)
	// Next smaollest lement is identified from the priority queue
	//
	// if the index's of any of the array reaches the end. The while loop is stopped
	//  although I'm not a 100% sure if this is the correct thing to do.
	// anyhoo good luck
	
	LOG_LEVEL = 2;
	
	int k = 3;
	int n = 5;
	
	int arr1[] = {4, 7, 9, 12, 15};
	int arr2[] = {0, 8, 10, 14, 20};
	int arr3[] = {6, 12, 16, 30, 50};
	
	//display (arr1, n);
	//display (arr2, n);
	//display (arr3, n);
	
	int **arr = new int*[k];
	for(int i=0; i<n ; i++)
 		arr[i] = new int[n];
	
	arr[0] = arr1;
	arr[1] = arr2;
	arr[2] = arr3;
	
	display (arr, n, k);
	
	debug (2, "Smallest Range k lists...\n");
	findSmallestRange (arr, n, k);
}
