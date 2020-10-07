#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void displayArr(int *arr, int size)
{
	for (int i=0; i<size; i++)
		debug (1, arr[i], " ");
	debug (1, "\n");
}

void displayAllStacks(vector <stack<int>> vec)
{
	int i;
	for (i=0; i<vec.size(); i++)
	{
		if (vec[i].size() != 0)
		{
			while (vec[i].empty() == false)
			{
				debug (1, vec[i].top()," ");
				vec[i].pop();
			}	
			debug (1, " | ");	
		}
	}	
	debug (1, "\n");
}

// Non DP
int solve(int *arr, int size)
{
	// The logic here is printing all outputs
	// but knowing how the outputs are limited in number
	// REFER Explanaton

	int i, j;
	stack <int> stk;
	vector <stack<int>> vec;
	bool flag;
	
	for (i=1; i<size; i++)
		vec.push_back(stk);
	
	stk.push(arr[0]);
	vec[0] = stk;
	
	for (i=1; i<size; i++)
	{
		debug (2, "In Focus: ", arr[i], "\n");
		
		for (j=0; j<vec.size(); j++)
		{
			debug (3, "Current Vector Stack: ", j, "\n");
			flag = false;
			
			if (vec[j].empty() == true)
			{
				debug (2, "Stack is empty\n");
				if (vec[j-1].top() < arr[i])
				{
					debug (2, "Previous Stack top: ", vec[j-1].top() , 
						" is less than ", arr[i], "\n");
						
					stk = vec[j-1];
					stk.push(arr[i]);
					vec[j] = stk;
				}
				flag = true;
			}
			else if (vec[j].top() > arr[i])
			{
				debug (2, "Stack top: ", vec[j].top() , " is less than ", arr[i], "\n");
				
				if (vec[j].size() == 1)
				{	
					vec[j].pop();
					vec[j].push(arr[i]);
				}
				else
				{
					stk = vec[j-1];
					if (stk.top() < arr[i])
					{
						stk.push(arr[i]);
						vec[j] = stk;	
					}
				}
			}
			
			if (flag == true)
				break;
		}
		if (LOG_LEVEL >= 2) displayAllStacks(vec);
		
		debug (2, "\n");
	}

	int max = vec[0].size();
	for (i=1; i<vec.size(); i++)
		if (max < vec[i].size())
			max = vec[i].size();
			
	return max;
}

// DP sol
int solveDP(int *arr, int size)
{
	// 
	// i j
	// i _ j
	// _ i j
	// i _ _ j
	// _ i _ j
	// _ _ i j
	// i _ _ _ j
	// if (arr[i] < arr[j]) lis[j](if more than current) = lis[i] + 1
	
	int i, j;
	int lis[size];
	
	for (i=0; i<size; i++)
		lis[i] = 1;
	
	for (j=0; j<size; j++)
	{
		for (i=0; i<j; i++)
		{
			if (arr[i] < arr[j])
			{
				if (lis[i] + 1 > lis[j])
					lis[j] = lis[i] + 1;
			}
		}
		if (LOG_LEVEL >= 2) displayArr(lis, size);
	}
	
	int max = lis[i];
	for (i=1; i<size; i++)
		if (max < lis[i])
			max = lis[i];
	
	return max;
}


int main()
{	
	// DP O(n^2)
	// Non DP O(N logN)
	
	// Resource
	// O(n^ 2)
	//https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
	//https://www.youtube.com/watch?v=fV-TF4OvZpk
	// O (nlogn)
	//https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
	
	
	// Explanation
	
	// O (N^2)
	// i j
	// i _ j
	// _ i j
	// i _ _ j
	// _ i _ j
	// _ _ i j
	// i _ _ _ j
	// if (arr[i] < arr[j]) lis[j](if more than current) = lis[i] + 1
	
	
	// O (N LogN)
	// The logic here is printing all outputs
	// but knowing how the outputs are limited in number
	// REFER Explanaton
	
	// For arr 1 
	// All outputs are 
	// 10 (10) LIS 1
	// 9, (10)(9) LIS 1
	// 3, (10)(9)(3) LIS 1
	// 5, (10)(9)(3)(5)(3,5) LIS 2
	// 4, (10)(9)(3)(5)(3,5)(4)(3,4) LIS 2
	// 11 (10)(9)(3)(5)(3,5)(4)(3,4)(11)(10,11)(9,11)(3,11)(5,11)(3,5,11)(3,4,11)
	// 7  (10)(9)(3)(5)(3,5)(4)(3,4)(11)(10,11)(9,11)(3,11)(5,11)(3,5,11)(3,4,11)
	// 	   (7)(3,7)(5,7)(3,5,7)(4,7)(3,4,7)
	// 8  (10)(9)(3)(5)(3,5)(4)(3,4)(11)(10,11)(9,11)(3,11)(5,11)(3,5,11)(3,4,11)
	//     (7)(3,7)(5,7)(3,5,7)(4,7)(3,4,7)
	// 		(8)(3,7,8)(5,7,8)(3,5,7,8)(4,7,8)(3,4,7,8)
	
	// POINT TO NOTE HERE 
	// Theortically there will not exists so many possibilities
	// There will be only one array of a specific size
	// Think about it, you have (3,4,7) or (3,4,8)
	// (3,4,7) is the better bet, it has a lower higher number and is the same size
	// I hope you understand this point
	 
	LOG_LEVEL = 3;
	
	// Ex 0, 4
	int arr[] = {3, 10, 2, 1, 20, 2, 3, 4};
	
	// Ex 1, 4
	//int arr[] = {10, 9, 3, 5, 4, 11, 7, 8};
	
	// Ex 2, 3
	//int arr[] = {3, 10, 2, 1, 20};
	
	// Ex 3, 6
	//int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	int ans = solve(arr, size);
	debug (1, ans, "\n");
}
