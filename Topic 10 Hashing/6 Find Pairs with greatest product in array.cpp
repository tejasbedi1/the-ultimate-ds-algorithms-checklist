#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void display (int*, int);

int findPairs(int *arr, int size)
{
	int i_first = 0;
	int i_last = size-1; 
	int div;
	
	unordered_set <int> u_set;
	
	// Sorting array O(n logn)
	sort (arr, arr+size);
	//display (arr, size);
	
	for (int i=0; i<size; i++)
		u_set.insert(arr[i]);
	
	bool flag = false;
	
	while (flag != true)
	{
		while (1)
		{
			if (arr[i_last] % arr[i_first] == 0)
			{
				div = arr[i_last]/arr[i_first];
				if (u_set.find( div ) != u_set.end())
				{
					debug (1, "(", arr[i_first], ",", div, ") ");
					flag = true;
				}
					
			}
			i_first++;
			
			if (i_first >= i_last)
				break;	
		}
		i_last--; 
		i_first = 0;
		if (i_last == 0)
			break;
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
	// Question
	// Find pair in Array whose poduct eqauls the greatest possible value
	//	already in array 
	// O (n^2) (unlikely worst case though)
	
	// RESOURCE 
	// https://www.geeksforgeeks.org/find-pair-with-greatest-product-in-array/

	LOG_LEVEL = 3;
	
	// EX-1
	int arr[] = {10, 3, 5, 30, 35}; 
	int size = sizeof(arr)/sizeof(arr[0]);
	
	display (arr, size);
	debug (2, "Finding pairs...\n");
	findPairs (arr, size);
}
