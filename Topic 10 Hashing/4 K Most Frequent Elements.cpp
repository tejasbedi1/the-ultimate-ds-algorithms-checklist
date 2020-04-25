#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

int mostFreq_v1(int *arr, int size, int k)
{	
	multimap <int, int, greater<int>> mmap;
	unordered_map <int, int> umap;
	
	for (int i=0; i<size; i++)
		umap [arr[i]]++;
	
	for (auto i: umap)
	{
		debug (2, i.first, ": ", i.second, " | ");
		mmap.insert(make_pair(i.second, i.first));
	}
	
	debug (1, "\nAns: ");
	for (auto i: mmap)
	{
		debug (2, i.second, " ");

		k--;
		if (k == 0)
			break;
	}
}

int mostFreq_v2(int *arr, int size, int k)
{
	multimap <int, int, greater<int>> mmap; 
	unordered_map <int, int> umap;
	
	multimap <int, int> :: iterator itmm;
	unordered_map <int, int> :: iterator itum;
	
	for (int i=0; i<size; i++)
	{
		if (umap.find(arr[i]) == umap.end())
			umap.insert(make_pair(arr[i], 1));
			
		else
		{
			itum = umap.find(arr[i]);
			itum->second = itum->second + 1;
		}
	}
	
	for (itum = umap.begin(); itum != umap.end(); itum++)
	{
		debug (2, itum->first, ": ", itum->second, " | ");
		mmap.insert(make_pair(itum->second, itum->first));
	}
	debug (1, "\nAns: ");
	for (itmm = mmap.begin(); itmm != mmap.end(); itmm++)
	{
		debug (2, itmm->second, " ");

		k--;
		if (k == 0)
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
	// RESOURCE 
	// (Not that good)
	// https://www.geeksforgeeks.org/frequent-element-array/
	
	// NOTE 
	// THE [] operator will create new keys if they are not already present
	LOG_LEVEL = 3;
	
	int arr[] = {5,2,1,3,2,1,6,8,9,4,3,7,7,3,1};
	int size = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	
	display (arr, size);
	debug (2, "Finding K most frequent elements...\n");
	mostFreq_v2 (arr, size, k);
}
