#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

int mostFreq_v1(int *arr, int size)
{
	int value = 0;
	int key;
	unordered_map <int, int> map;
	
	for (int i=0; i<size; i++)
		map [arr[i]]++;
	
	for (auto i: map)
	{
		debug (2, i.first, ": ", i.second, "\n");
		if (i.second > value)
			key = i.first;
	}
	debug (1, "Ans: ", key);
}

int mostFreq_v2(int *arr, int size)
{
	int value = 0;
	int key;
	unordered_map <int, int> map;
	unordered_map <int, int> :: iterator itr;
	
	for (int i=0; i<size; i++)
	{
		if (map.find(arr[i]) == map.end())
		{
			map.insert(make_pair(arr[i], 1));
		}
		else
		{
			itr = map.find(arr[i]);
			itr->second = itr->second + 1;
		}
	}
	
	unordered_map <int, int> :: iterator i;
	for (i = map.begin(); i != map.end(); i++)
	{
		debug (2, i->first, ": ", i->second, "\n");
		if (i->second > value)
			key = i->first;
	}
	debug (1, "Ans: ", key);
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
	
	int arr[] = {1,1,1,2,2,3};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	display (arr, size);
	debug (2, "Finding most frequent...\n");
	mostFreq_v2 (arr, size);
}
