#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

int findPairs(int *arr, int size, int k)
{
	unordered_multimap <int, int> un_mmap;
	int i=0;
	
	for (i=0; i<size; i++)
	{
		un_mmap.insert ( make_pair(arr[i] % k, arr[i]) );
	}
	
	debug (2, "\nCurrent MultiMap\n");
	for (auto x: un_mmap)
	{
		debug (2, x.first, ",", x.second, "\n");
	}
	
	debug (2, "\nPairs-\n");
	unordered_multimap <int, int> :: iterator itun_mmap;
	// Just declare them auto
	pair <unordered_multimap <int, int> :: iterator, 
			unordered_multimap <int, int> :: iterator> i1;
			pair <unordered_multimap <int, int> :: iterator, 
			unordered_multimap <int, int> :: iterator> i2;
	
	itun_mmap = un_mmap.begin();
	int key1;
	int key2;
	int count1;
	int count2;
	
	while (1)
	{
		itun_mmap = un_mmap.begin();
		if (itun_mmap == un_mmap.end())
			break;
			
		key1 = itun_mmap->first;
		count1 = un_mmap.count(key1);
		
		key2 = k - key1;
		count2 = un_mmap.count(key2);
		
		if (count1 == count2)
		{
			if (key1 == key2)
			{
				auto i1 = un_mmap.equal_range(key1);
				for (auto it1 = i1.first; it1 != i1.second; it1++)
				{
					debug (1, "(", it1->second, ",");
					it1++;
					debug (1, it1->second, ")\n");
				}
				un_mmap.erase(key1);
			}
			else
			{
				i1 = un_mmap.equal_range(key1);
				i2 = un_mmap.equal_range(key2);
				
				auto it1 = i1.first;
				auto it2 = i2.first;
				for (; it1 != i1.second; it1++, it2++)
				{
					debug (1, "(", it1->second, ",", it2->second, ")\n");
				}
				un_mmap.erase(key1);
				un_mmap.erase(key2);
			}
		}
		else
		{
			debug (1, "No pair found for: ", (un_mmap.find(key1))->second, "\n");
			break;
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
	// Objective 
	// Check if an array can be divided into pairs whose sum is divisible by k
	// The whole array is to be divided
	
	// RESOURCE 
	// (Loosely Related)
	// Check if an array can be divided into pairs whose sum is divisible by k
	
	LOG_LEVEL = 3;
	
	// EX-1
	//int arr[] = {9, 7, 5, 3}; 
	//int k = 6;
	// EX-2
	int arr[] =  {92, 75, 65, 48, 45, 35};									
	int k = 10;
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	display (arr, size);
	debug (2, "Finding pairs...\n");
	findPairs (arr, size, k);
}
