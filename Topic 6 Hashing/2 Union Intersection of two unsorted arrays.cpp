#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

int funcUnion (int *arr1, int *arr2, int size1, int size2)
{
	int i;
	unordered_set <int> hash;
	
	debug (1, "Union: ");
	for (i=0; i<size1; i++)
	{
		if (hash.find(arr1[i]) == hash.end())
		{
			hash.insert(arr1[i]);
			debug (1, arr1[i], " ");
		}
	}
	for (i=0; i<size2; i++)
	{
		if (hash.find(arr2[i]) == hash.end())
		{
			hash.insert(arr2[i]);
			debug (1, arr2[i], " ");
		}
	}
	debug (1, "\n");
}

int funcIntersection  (int *arr1, int *arr2, int size1, int size2)
{
	int i;
	unordered_set <int> hash;
	unordered_set <int> intersection_hash;
	
	debug (1, "Intersection: ");
	for (i=0; i<size1; i++)
	{
		hash.insert(arr1[i]);
	}
	for (i=0; i<size2; i++)
	{
		if (hash.find(arr2[i]) != hash.end())
		{
			debug (1, arr2[i], " ");
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
	// Resource
	// https://www.geeksforgeeks.org/find-union-and-intersection-of-two-unsorted-arrays/
	
	LOG_LEVEL = 3;
	
	int arr1[] = {7, 1, 5, 2, 3, 6};
	int arr2[] = {3, 8, 6, 20, 7};
	
	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	int size2 = sizeof(arr2)/sizeof(arr2[0]);
	
	display (arr1, size1);
	display (arr2, size2);
	
	funcUnion (arr1, arr2, size1, size2);
	funcIntersection (arr1, arr2, size1, size2);
}
