#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

int getSum(int *arr, int a, int b)
{
	int sum=0 ,i;
	for (i=a; i<b; i++)
		sum+= arr[i];
	return sum;
}

int paintersUsed(int *arr, int n, int k, int target)
{
	int i;
	int total = 0;
	int painters = 1;
	for (i=0; i<n; i++)
	{
		total+= arr[i];
		if (total > target)
		{
			total = arr[i];
			painters++;
		}
	}
	return painters;
}

void recursive(int *arr, int n, int k, int min, int max)
{
	debug (2, "Min, Max: ", min, ",", max, "\n");
	if (min < max)
	{
		int mid;
		mid = (min+max) / 2;
		
		if (paintersUsed(arr, n, k, mid) <= k)
			max = mid;
		else
			min = mid+1;
			
		recursive(arr, n, k, min, max);
	}
	else
	{
		debug (1, "ANSWER: ", min, "\n");
	}
}

void solve(int *arr, int n, int k)
{
	// A mimimum value that a painter will be assisgned
	//  Every painter has to be assigned, atleast a single board last one included
	int min = arr[n-1];
	// Max will be the maximum possible last (n-k boaards)
	int max = getSum(arr, n-k, n);
	
	recursive(arr, n, k, min, max);
}

int main()
{	
	// D & C
	
	// Resource
	// https://www.geeksforgeeks.org/painters-partition-problem-set-2/
	// Set 1 was useless to me at that time
	// 
	// SIMILAR - https://www.geeksforgeeks.org/allocate-minimum-number-pages/
	
	// COMPLEXITY 
	// O (nlogn)
	
	// QUESTION
	// There are k painters available and each takes 1 unit time to paint 1 unit of board. 
	// The problem is to find the minimum time to get this job done
	
	LOG_LEVEL = 3;
	
	// Ex 1
	// Size of consequiteve boards 
	// Always sorted
	int arr[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90}; 
	
	//EX 2
	//int arr[] = {12, 34, 67, 90}; 
	
	int n = sizeof(arr) / sizeof(arr[0]); 
	
	// No of painters 
	int k = 5; // EX 1 
	//int k = 2; // Ex 2
	
	solve(arr, n, k);
}
