#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void displayArray(int *subset, int len, int sum)
{
	int i;
	
	for (i=0; i<len; i++)
		debug (1, subset[i], " ");
	debug (1, "\tSum: ", sum, "\n");
	//debug (1, "\n");
}

void fillAns(int *subset, int len, int *ans)
{
	int i;
	for (i=0; i<len; i++)
		ans[i] = subset[i];
}

void mostEffecient(int *subset, int len, int sum, int tSum, int &diff, bool &flag, int *ans)
{
	debug (3, "Current Diff: ", diff, "\n");
	
	// Temp is the difference (modulus)
	int temp = (tSum-sum) - sum;
	if (temp < 0)
		temp = temp * -1;
		
	if ( temp < diff)
	{
		diff = temp;
		if (temp == 0)
			flag = true;
		
		debug (2, "New minimum diff\n");
		if (LOG_LEVEL >= 2) displayArray(subset, len, sum);
		
		fillAns(subset, len, ans);
	}
}

// tLen, target length (Subset Should not be more than this length)
// Pos Current Position
// Len Current lenght of subset
// sum, the current sum of the subset
// tSum, total Sum of full Array
// cDiff, Current miminum difference between two equally sized subsets
// flag, if flag becomes true that would mean most optimal solution found

void allSubsets(int *arr, int n, int tLen, int pos, int len, int subset[], int sum, 
	int tSum, int &cDiff, bool &flag, int *ans)
{
	// If 
	if (flag == true)
		return;
		
	// End of array
	if (n == pos)
	{
		if (len == tLen)
			mostEffecient(subset, len, sum, tSum, cDiff, flag, ans);
			if (LOG_LEVEL >= 3) displayArray(subset, len, sum);
		return;
	}
	
	// If current length is already reached the target Length
	//  no need to proceed further, we are anyways not looking for a higher length
	if (len == tLen)
	{
		if (LOG_LEVEL >= 3) displayArray(subset, len, sum);
		mostEffecient(subset, len, sum, tSum, cDiff, flag, ans);
		return;
	}
		
	//	Dont include this element
	allSubsets(arr, n, tLen, pos+1, len, subset, sum, tSum, cDiff, flag, ans);
	
	// Inlcude current element
	subset[len] = arr[pos];
	sum += arr[pos];
	allSubsets(arr, n, tLen, pos+1, len+1, subset, sum, tSum, cDiff, flag, ans);
}

void displayAns (int *arr, int n, int *ans)
{
	int i;
	unordered_map <int, int> uMap;
	unordered_map<int, int>:: iterator itr;
	
	for (i=0; i<n; i++)
	{
		if (uMap.find(arr[i]) == uMap.end()) 
			uMap.insert( make_pair(arr[i], 1) );
		else
			uMap[arr[i]]++;
	}
	
	debug (1, "Resulting Subsets...\n<");
	for (i=0; i<n/2; i++)
	{
		debug (1, " ", ans[i]);
		
		if (uMap[ans[i]] > 1)
			uMap[ans[i]]--;
		else
			uMap.erase(ans[i]);
	}
	
	debug (1, " > <");
    for (itr = uMap.begin(); itr != uMap.end(); itr++) 
    	for (i=0; i<itr->second; i++)
    		debug (1, " ", itr->first);
    		
	debug (1, " >\n");
}

int solving(int *arr, int n)
{
	int i;
	int sum=0;
	int subset[n];
	
	for (i=0; i<n; i++)
		sum += arr[i];
	
	debug (2, "Total Sum: ", sum, "\n");
	debug (2, "Total Elements: ", n, "\n");	
	
	int diff = INT_MAX;
	bool flag = false;
	int ans[n/2];
	
	allSubsets (arr, n, n/2, 0, 0, subset, 0, sum, diff, flag, ans);
	
	displayAns(arr, n, ans);
}

int main()
{
	// BASED ON THE, PARTITION PROBLEM 
	// https://en.wikipedia.org/wiki/Partition_problem
	
	// RESOURCE 
	// https://www.geeksforgeeks.org/tug-of-war/
	// Find all All subsets [Find in Directory]
	
	// Find all subsets of half length and return the one with minimum distance
	
	// Recursive Solution Complexity 2^n
	
	LOG_LEVEL = 1;
	
	int k;

    // Ex 2
 	//int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
 	// Ex 1
    int arr[] = {3, 4, 5, -3, 100, 1, 89, 54, 23, 20};
    
	int size = sizeof(arr)/sizeof(arr[0]);
	
	solving(arr, size);
}
