#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

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

void displayArr(int l1, int l2, int **arr, string s1, string s2)
{
	int i, j;
	
	debug (1, "  O ");
	for (i=0; i<s2.size(); i++)
		debug (1, s2[i], " ");
	debug (1, "\n");
	
	s1 = "O"+s1;
	for (i=0; i<l1; i++)
	{
		debug (1, s1[i], " ");
		for (j=0; j<l2; j++)
			debug (1, arr[i][j], " ");
		debug (1, "\n");
	}
	debug (1, "\n");
}

void displayArr(int **arr, int n)
{
	int i, j;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if (arr[i][j] >= 0 && arr[i][j] <= 9)
				debug (1, " ", arr[i][j], "  ");
			else
				debug (1, arr[i][j], "  ");
		}
		debug (1, "\n");
	}
	debug (1, "\n");
}

int min(int a, int b)
{
	return (a > b) ? b : a;
}

// All values stored in 2D array
int solve(int *vals, int size)
{
	int i, j;
	int n = size-1;
	
	int **dp;
	dp = new int*[n];
	for (i=0; i<n; i++)
		dp[i] = new int[n];
	
	//INIT
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			dp [i][j] = -1;
		}
	}
	
	//
	for (i=0; i<n; i++)
	{
		dp [i][i] = 0;
	}
	if (LOG_LEVEL >= 3 ) displayArr(dp, n);
	
	for (i=1; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if (j+i < n)
			{
				// dp [j][j+i] = 0;
				dp[j][j+i] = min(	dp[j][j+i-1] + vals[j]*vals[j+i]*vals[j+i+1] ,
									dp[j+1][j+i] + vals[j]*vals[j+1]*vals[j+i+1] 
								);
				debug (3, "Eval DP ", "(",j,",",j+i,")\n");
				debug (3, vals[j], "*", vals[j+i], "*", vals[j+i+1], "\n");
				debug (3, vals[j], "*", vals[j+1], "*", vals[j+i+1], "\n");
			}
		}
		if (LOG_LEVEL >= 3 ) displayArr(dp, n);
	}
	
	if (LOG_LEVEL >= 2 ) displayArr(dp, n);
	
	return dp[0][n-1];
}

int main()
{	
	// DP O(n^2)
	
	// Resource
	// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
	// https://www.geeksforgeeks.org/matrix-chain-multiplication-a-on2-solution/
	// Screenshot 27
	
	// Explanation
	// HERE So, here we have to make sure that we mulitply matix's in 
	// 	such a manner that number of multiplications is reduced as much as it could
	//	The only way to do this is by finding all combinations. And then see number of
	// 	resulting multiplications
	//
	// 	eg if we have A,B,C,D
	// 		multiplications can be in these orders
	//	(ABCD) = (ABC)(D) -> (ABC) = (AB)(C)
	//							   = (A)(BC)
	//		   = (A)(BCD) -> (BCD) = (BC)(D)
	// 							   = (B)(CD)
	//		   = (AB)(CD)
	// 		   
	//  BUT here we can clearly see that some subproblems are repating and we could
	// 		store these. We can store it in a HashMAp but a 2D table would be simpler
	//		and faster
	//
	//	Storing these values in a 2D array is a bit piculiar tho.
	//	Instead of A.B,C if we use 1,2,3,4,5 then ...
	//  (Refer Img 27)
	//	
	//	First we solve for 1.1 , 2.2, 3.3 etc
	//	Then for 1.2 , 2.3, 3.4, 4.5,
	//	Simple enough ? Basically we are solving diagnally
	//	Next 1.3, 2.4, 3.5
	//	HERE (1.3) = (1.2)(3)
	//			   = (1)(2.3)
	// 	HERE (2.4) = (2.3)(4)
	// 			   = (2)(3.4)  .... etc
	//  NOTICE.. Some of these values we have precalculated
	//    	this is how DP happens here
	//  Next 1.4, 2.5 
	//	(1.4) = (123)(4) (123 or 1.3 has been pre calculated )
	//		  = (1)(234) (234 or 2.4 has been pre calculated )
	//  (2.5) likewise
	//
	// This approach will be a O(n^2) approch with space O(n^2) as well
	
	LOG_LEVEL = 2;
	
	// Ex 0 Ans 1200
	//int arr[] = {10,20,30,10,30};
	
	// EX 1 Ans.18
	//int arr[] = {1,2,3,4};
	
	// Ex 2 Ans.30
	//int arr[] = {1,2,3,4,3};
	
	// Ex 3 Ans.82
	int arr[] = {2,3,5,2,4,3};
	
	int ans = solve(arr, sizeof(arr)/sizeof(arr[0]) );
	debug (1, ans, "\n");
}
