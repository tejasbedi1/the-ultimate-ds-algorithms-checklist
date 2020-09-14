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
int solve(int *arr, int size)
{
	
}

int main()
{	
	// DP O(n^2) 
	
	// IMP QUESITON 
	
	// Resource
	// https://www.youtube.com/watch?v=DJ4a7cmjZY0 
	// https://www.geeksforgeeks.org/coin-change-dp-7/
	
	// Explanition
	// Not writing code for this as its a simple 2D graph with some ops
	// The more important thing is to understand how this question works
	// How to prepare a Native case and build a DP solution
	
	// REFER Pic 30 for the DP solution
	
	// Native Solution 1
	// I thought 1 recursive solution could be using each avialable coin 
	// in the maximum possible frequency
	// Evaluating Ex0
	// (1))()() [Less than 4, Rejected]
	// (1)()(3) [Exactly 4, Approved]
	// (1)(2)() [Rejected]
	// (1)(2,2)() [More than 4, Rejected]	
	// (1,1)()() [Rejected]
	// (1,1)()(3) [R] 
	// (1,1)(2)() [Approved]
	// (1,1,1)()() [R]
	// (1,1,1)()(3) [R]
	// (1,1,1)(2)() [R]
	// (1,1,1,1)()() [Approved]
	// (2)() [R]
	// (2)(3) [R]
	// (2,2)() [Approved]
	// (3) [R]
	// (3,3) [R] [STOP] [4 Approvals]
	// This naive solution is hard to DP, or atleast todays version of me found it hard
	// 
	// Naive Soltion 2
	// This I derived from the solution graph
	// Lets say in the Starting we have,
	// [1], To make 4, we can use 1, 1. W'ell be left with 3 
	// To make 3, we can use one 1 we'll be left with 2
	// Anyhoo, 
	// To make 1, (There exists 1 way), 2 (1 way), 3 (1 way), 4 (1 way)
	
	// Next we add [2] to our set (Our set is [1,2])
	// To make 4, if we use one 2. Then we are left with 2 (4-2)
	//		Now our question becomes in how many ways can we make 2?
	//		Just using 1's we have one way. Using 2's ? We also have one way
	//		So thats 2 WAYS in total.
	
	// Next we add [3] to our set (Our set is [1,2,3])
	// To make 4, if we use one 3. (Because if we dont use 3 then there are 3 ways till now)
	//		So if we use one 3. Then we have to find out in how many ways can we make 1 (4-3)
	// 		From our previous encounters we know we can only make 1 in one way
	//  	So total here is 1 Way
	
	// Total eventually adding all three set becomes 4.
	 
	// The DP solution is a Bottom- Solution 
	// It dicusses how all N's can be made from a certain Set. So that 
	// New ways can be added on...
	
	// Points to rember when constructing the table.
	// If the new member cannot create the current N (eg making 4 using 6)
	// 	then copy value of above cell
	// If the new member can create the current N (eg making 3 using 2)
	// The add (value of above cell) + (current N - member(same row))
	
	// For Top-Down 
	// Check out geeks for geeks, I dont like it tho
	// Its fairly untutive for me atleast,
	// Best of luck 
	
	LOG_LEVEL = 3;
	
	// ARR is the coins
	// Ex 0 Ans 4
	//int arr[] = {1,2,3};
	//int N = 4;
	
	// EX 1 Ans.5
	int arr[] = {2,5,3,6};
	int N = 10;
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	int ans = solve(arr, size);
	debug (1, ans, "\n");
}
