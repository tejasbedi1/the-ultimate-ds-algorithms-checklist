#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

int findSubArrays (int *arr, int size, int k)
{
	int i;
	unordered_map <int, int> prevSums;
	int currSum = 0;
	int ans = 0;
	
	for (i=0; i<size; i++)
	{
		currSum += arr[i];
		
		if (currSum > k)
		{
			if (prevSums.find(currSum - k) != prevSums.end())
				ans += prevSums[currSum - k]; 	
		}		
		
		prevSums[currSum]++;

		if (currSum == k)
			ans++;
	}
	
	debug (1, "Number of Subarray's: ", ans, "\n");
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
	// (A little difficult to understand at first)
	// https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/
	
	// Explanation
	// 
	// NOTE - Finding exact subarrays is a much more tedious process/complex (O(n^2))(maybe), 
	// 	finding number of subarrays can be done in O(n)
	//
	// Ex [1, -2, 2, 3] k = 3  (Ans 2)(Example from comments)
	// So two vairables we maintain: currentSum[Int] and previousSums [Map][Sum: count]
	//
	// Now starting with 1, currSum = 1, prevSums 1,1 : 
	// 	here k > currSum (1), move forward
	//
	// -2, currSum = -1, prevSums 1,1 : -1,1
	//  here k > currSum (-2), move forward
	//
	// 2, currSum = 1, prevSums 1,2 : -1,1 
	//  here k > currSum (1), move forward
	//
	// 3, currSum = 4, prevSums 1,2 : -1:1 : 4,1
	//  here k < currSum
	//	 that means that the total length of the array is making the sum exceed 
	//		the desired amount 
	// 	 So we will have to remove some sumarrays and check if the sum comes down to
	// 		the desired amount (if we remove some subarray , we weill still obtain a 
	//       subarray, so its fine)
	//   Our currentSum is 4 and desired is 3
	//   If there are any subarrays that have a sum of (4 - 3) then we can remove them 
	//  	from our current  and get a  good smller subaray wth the apt subarray
	//   And because of our Map we know there are 2 prevSum of subarrays than can 
	//      be removed
	//   So numberOfSubarry += count of sum (1)
	//   End Ans = 2
	// I hope this explantion holds the test of time :\
	 
	LOG_LEVEL = 3;
	
	int k;
	
	//k = -10;
	//int arr[] = {10, 2, -2, -20, 10};
	
	k = 33;
	int arr[] = {9, 4, 20, 3, 10, 5};
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	display (arr, size);
	debug (2, "Finding number of subarray's...\n");
	findSubArrays (arr, size, k);
	//display (arr, size);
}
