#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

int removeDuplicates(int *arr, int size)
{
	unordered_set <int> hash;
	for (int i=0; i<size; i++)
	{
		if (hash.find(arr[i]) == hash.end())
		{
			hash.insert(arr[i]);
		}
		else
		{
			arr[i] = -1;
		}
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
	LOG_LEVEL = 3;
	
	int arr[] = {1,1,1,2,2,3};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	display (arr, size);
	debug (2, "Removing Duplicates...\n");
	removeDuplicates (arr, size);
	display (arr, size);
}
