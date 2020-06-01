#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void binarySearch(int *arr, int size, int l, int r, int toFind)
{
	if (l > r)
	{
		debug (1, "Not Found..\n");
		return;
	}
	
	int half = (l + r) / 2;
	
	if (arr[half] == toFind)
		debug(1, "Found: ", arr[half], "\n");
		
	else if	(arr[half] > toFind)
		binarySearch(arr, size, l, half-1, toFind);	
		
	else if (arr[half] < toFind)
		binarySearch(arr, size, half+1, r, toFind);
}

int main()
{
	// Divide and Conquor Example 
	
	LOG_LEVEL = 3;
	
	int k;

	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	
	int size = sizeof(arr)/sizeof(arr[1]);
	
	int l = 0;
	int r = size-1; 
	int toFind = 11;
	
	binarySearch(arr, size, l, r, toFind);
}
