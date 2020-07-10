#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

struct Data
{
	int f;
	int l;
	
	Data(int a, int b)
	{
		f = a;
		l = b;
	}
	
	// To support unoredred map
	// In case of collision
	bool operator ==(const Data &d) const
	{
		return f == d.f && l == d.l;
	}
};

struct hash_struct
{
	size_t operator()(const Data &d) const
	{
		auto hash1 = hash<int>{}(d.f);
		auto hash2 = hash<int>{}(d.l);
		return hash1 ^ hash2;
	}
};

int solve(int *arr, int f, int l, unordered_map <Data, int, hash_struct> &uMap, int time)
{
	debug (2, "At ", f, ",", l, " with time ", time, "\n");
	if (f == l)
	{
		debug (2, "Returning ", arr[f]*time, "\n");
		return arr[f]*time;
	}
	
	Data d(f,l);
	if (uMap.find(d) == uMap.end())
	{
		int a, b;
		a = solve(arr, f, l-1, uMap, time+1);
		b = solve(arr, f+1, l, uMap, time+1);
		
		debug (2, "a: ", a, "  b: ", b, "\n");
		if ((a + arr[l]*time) >= (b + arr[f]*time))
		{
			debug (3, "Inserting in map ", d.f, ",", d.l, " :", a+arr[l]*time, "\n");
			uMap.insert( make_pair(d, a + arr[l]*time) );
		}
		else
		{
			debug (3, "Inserting in map ", d.f, ",", d.l, " :", b+arr[f]*time, "\n");
			uMap.insert( make_pair(d, b + arr[f]*time) );
		}
		
	}
	else
	{
		debug (3, "Map for ", d.f, ",", d.l, " found :", uMap.find(d)->second, "\n");
	}
	return uMap.find(d)->second;
}


int main()
{	
	// Naive O(2^n)
	// Greedy O(n) Approximate
	// DP O(n^2)
	
	// TOP DOWN DP
	
	// Resource
	// Lecture notes, dynamioc programming
	
	// COMPLEXITY
	// Average : log(n), 
	// in case of many uses O(1)
	// IDK, not important
	
	LOG_LEVEL = 3;
	
	int ans;
	
	// Ex 1 // 64
	//int arr[] = {2,4,6,2,5};
	
	// Ex 2 // 50
	int arr[] = {2,3,5,1,4};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	unordered_map <Data, int, hash_struct> uMap;
	
	ans = solve(arr, 0, size-1, uMap, 1);
	
	debug (1, ans, "\n");
}
