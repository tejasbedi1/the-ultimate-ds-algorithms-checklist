#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void displayArray(int *subset, int len)
{
	int i;
	for (i=0; i<len; i++)
		debug (1, subset[i], " ");
	debug (1, "\n");
}

// tSum Target Sum
// Pos Current Position
// Len Current lenght of subset
// sum the sum of the subset
void allSubsets(int *arr, int n, int tSum, int pos, int len, int subset[], int sum)
{
	if (n == pos)
	{
		if (sum == tSum)
			displayArray(subset, len);
		return;
	}
	
	//	Dont include this element
	allSubsets(arr, n, tSum, pos+1, len, subset, sum);
	
	// Inlcude current element
	subset[len] = arr[pos];
	sum += arr[pos];
	allSubsets(arr, n, tSum, pos+1, len+1, subset, sum);
}

int solving(int *arr, int n)
{
	int i;
	int sum=0;
	int subset[n];
	
	for (i=0; i<n; i++)
		sum += arr[i];
		
	if (sum % 2 == 0)
		allSubsets (arr, n, sum/2, 0, 0, subset, 0);
	else
		debug (1, "No possible solution\n");
}

int main()
{
	// PARTITION PROBLEM 
	// https://en.wikipedia.org/wiki/Partition_problem
	
	// RESOURCE 
	// https://www.geeksforgeeks.org/partition-problem-dp-18/
	// All subsets [Find in Directory]
	
	// NP Complete Problem (A famous one at that)
	// Greedy Approach only finds approximate solution
	// Dynamic Solution needs a lot of memory
	
	// Recursive Solution Complexity 2^n
	
	LOG_LEVEL = 1;
	
	int k;

	// Ex 1
    //int arr[] = {1, 5, 11, 5};
    // Ex 2
 	//int arr[] = {1, 5, 3};
 	// Ex 3
    int arr[] = {3, 4, 5, -3, 100, 1, 89, 54, 23, 20};
    
	int size = sizeof(arr)/sizeof(arr[0]);
	
	solving(arr, size);
}
