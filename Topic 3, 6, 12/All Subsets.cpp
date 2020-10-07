#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void displayArray(int *subset, int len)
{
	int i;
	debug (1, "{");
	for (i=0; i<len; i++)
		debug (1, " ", subset[i]);
	debug (1, " }\n");
}

// Pos , position of element being focused on
// Len , lenght of current subset
// subset[] the subset itself 
void allSubsets(int *arr, int n, int pos, int len, int subset[])
{
	if (pos == n)
	{
		displayArray(subset, len);
		return;		
	}
	// Current element not added
	allSubsets(arr, n, pos+1, len, subset);
	
	// Current element added
	subset[len] = arr[pos];
	allSubsets(arr, n, pos+1, len+1, subset);
}

int solving(int *arr, int n)
{
	int subset[n];
	if (n > 0)
		allSubsets(arr, n, 0, 0, subset);
}

int main()
{
	// PRINTS ALL POSSIBLE SUBSETS
	
	// RESOURCE 
	// https://afteracademy.com/blog/print-all-subsets-of-a-given-set
	// (VV IMP) <https://s3.ap-south-1.amazonaws.com/afteracademy-server-uploads/print-all-subsets-of-a-given-set-recursion-tree-9bbcd4be963c54c8.jpg>
	
	// Recursive Solution 
	// Complexity 2^n
	
	// IDEA BEHING IT ALL
	/*
	*										{}
	*					{}												{1}
	*		{}					  {2}						{1}						{1,2}
	*  {}  		{3} 		{2}			{2,3} 		 {1}		{1,3}		 {1,2} 		{1,2,3}		
	*{} {4}	 {3}  {3,4}   {2} {2,4}  {2,3}{2,3,4}  {1}{1,4}	 {1,3}{1,3,4} {1,2}{1,2,4}  {1,2,3}{1,2,3,4}
	*/
	LOG_LEVEL = 1;
	
	int k;

	// Ex 1
    int arr[] = {1, 2, 3, 4};
    
	int size = sizeof(arr)/sizeof(arr[0]);
	
	solving(arr, size);
}
