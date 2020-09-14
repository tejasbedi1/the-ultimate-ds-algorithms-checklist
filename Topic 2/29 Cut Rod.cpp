#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

// NOT USED
struct hash_pair
{
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2> &p) const
	{
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);
		return hash1 ^ hash2;
	}
};

void displayArr(int *arr, int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		debug (1, arr[i], " ");
	}
	debug (1, "\n");
}

int min(int a, int b)
{
	return (a > b) ? b : a;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

// All values stored in 2D array
int solve(int *val, int size)
{
	int i,j;
	
	int ans[size+1];
	
	ans[0] = 0;
	ans[1] = val[0];
	
	int result;
	
	for (i=2; i<size+1; i++)
	{
		result = 0;
		for (j=1; j<i; j++)
		{
			result = max ( result, ans[j] + ans[i-j] );
		}	
		ans[i] = max (result, val[i-1]);
	}
	
	displayArr(ans, size+1);
	
	return ans[size];
}

int main()
{	
	// DP O(n^2) 
	
	// Resource
	// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
	
	// Explanition
	// We solve it bottomup ly
	// 
	// For Eg we need to know the Max profit for 
	// Lenght 8
	// 0 - 0
	// 1 - Ans 1
	// 2 - 1.(1), 2 (0)  (1 - Already calaculed)
	// 3 - 1.(2), 2.(1), 3.(0)   (1,2 - Already calaculed)
	// 4 - 1.(3), 2.(2), 3.(1) 4.(0) (1,2,3 - Already calaculed)
	// ... Continue
	
	LOG_LEVEL = 3;
	
	// Ex 0 Ans 22
	//			 1,2,3,4,5 ,6, 7, 8
	//int val[] = {1,5,8,9,10,17,17,20};
	
	// EX 1 Ans.24
	int val[] = {3,5,8,9,10,17,17,20};
	
	int size = sizeof(val)/sizeof(val[0]);
	
	int ans = solve(val, size);
	
	debug (1, ans, "\n");
}
