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
	
	// DP O(Eggs * Floors * FLoors) 
	// somewhat like O(n * k * k)
	//
	// Fastest O (n * k log k )
	
	// VV IMP QUESITON 
	
	// Resource
	// https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/
	// https://www.youtube.com/watch?v=3hcaVyX00_4 (Helpful)
	// https://www.youtube.com/watch?v=iOaRjDT0vjc
	// https://brilliant.org/wiki/egg-dropping/ (Helpful)
	// FASTEST SOL
	// https://leetcode.com/problems/super-egg-drop/solution/
	
	// Explanition
	// This problem is a bit much to tell you the truth,
	// the fastest solution is'nt even a DP solution :(
	
	// Anyhoo
	// Understand the problem first, then we'll break it apart
	// I'm going the Brilliant.org route
	
	// IF we have 2 Eggs F Floors (like 100 or 10)
	// Then how do you solve this ?
	//
	// If you have no idea, kkep in mind that we need to make sure
	//  whatever route is taken, a certain minimum floors touched is kept
	//
	// Look at Fig 1 of Pic 31
	// For 2 Eggs and 10 Floors
	// If Egg breaks at 4th floor check 1,2,3
	// If not check floor 7, if breaks at floor 7 check 5,6
	// If not cjeck floor 9, if breaks at floor 9 check 8
	// If not check 10
	//
	// So basically if we can divide the floors into a right triangle like this then
	// we could find the answer just by looking at the Floors
	// 
	// There exists an formula which would help us calc 1+2+3+4+5 etc
	// Sum OF AP
	// Using this formaula
	// 10 floors = n/2 (2(starting val always 1) + (n - 1)(Difference, always 1))
	// this always boils down to 
	// 10 (floors) = n^2 + n  	OR
	// 100 (floors) = n^2 + n 
	// This is easily cacutable
	// Alas this only works with 2 Egss xD
	
	// Now what if we have N Eggs, F floors
	// 
	// The basis of the problem is as follows
	// 	IF we have 1 Egg and N Floors then Answer would be N
	// 	If we have 0 Eggs The 0 obviously'
	// Now if we have 2 Eggs
	//	2 Eggs 1 Floor - Answer.1 NP
	//	2 Eggs 2 Floor - (ie. 2,2)
	//		Try Floor 1 - 	(IF EGG Breaks)			(Problem Becomes (1,0)) // 0 cause no more floors
	// 						(If EGG Does not Break) (Problem Becomes (2,1))
	// 		Try Floor 2 - 	(IF EGG Breaks)			(Problem Becomes (1,1))
	//						(If EGG Does not Break)	(Problem Becomes (2,0)) // 0 cause if it does not break in top most floor where will it actually break /
	//  2 Eggs 3 Floors - (ir 2,3)
	// 		Try Floor 1 - 	(IF EGG Breaks)			(Problem Becomes (1,0)) 
	// 						(If EGG Does not Break) (Problem Becomes (2,2))
	// 		Try Floor 2 - 	(IF EGG Breaks)			(Problem Becomes (1,1))
	//						(If EGG Does not Break)	(Problem Becomes (2,1)) 
	//		Try Floor 2 - 	(IF EGG Breaks)			(Problem Becomes (1,2))
	//						(If EGG Does not Break)	(Problem Becomes (2,0)) 
	//	
	// This will continue like this... 
	// 
	// This is where we break down the problem, into a table
	// Its easily managable in a table, this might not be immediate apparant
	// This will be our DP solution 
	// 
	// Refer Fig 2 Pic 31 for the DP Table
	// 
	// FAQ 
	// Q. Why are trying multiple floors like this ? 
	// A. Because its like we are saying Waht happens if I start on Floor 1,
	//		What happens if I start from Floor 2? 
	//		What happens if I start from floor 3?
	//		Basially starting from which floor returns the minimum answer
	// 
	// Q. How do i calculate the Answer. (Prerequizite, Understand how the problem is
	// 		broken down)
	// A. Everytime we start cheking the individual floors when we have a certain 
	//		amount of eggs. For eg (2,3) We take maximum of Each Floor, Becuase it 
	// 		represents the maximum of tries to get the answer from that floor
	// 		After we get the maximum for each floor. Then we take minimum from
	//		all the floors, Because it reprents the floor from which it will
	//		take minimum tries to get the answer and plus 1 ofcourse
	//
	// Q. Formula
	// A. The fomla is simple if your get everyhting we discussed before
	// 		For Each Egg
	//			For Each Floor
	//				Evaluate all previous Floors
	//					res = min(res, (1+ max(dp[i][j-x],dp[i-1][x-1]) ) );	
	
	// O (N * K LOG K)
	// At this point of time i'm tired of this question so'll make this brief
	// You'll have to see the resource if your dont get what I'm trying ot say
	// 
	// The main point is when you see all floors one thing is apparent
	// dp[i][j-x] is decreasing and
	// dp[i-1][x-1] is increasing
	// Using both of these and at hteir convergence a binary seach could be done to find a
	// faster solution instead of recaculaing everything
	// do with that what you will, Cya
	
 	LOG_LEVEL = 3;
	
	// ARR is the coins
	// Ex 0 Ans 22
	int arr[] = {1,2,3};
	int N = 4;
	
	// EX 1 Ans.24
	int arr[] = {2,5,3,6};
	int N = 10;
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	int ans = solve(arr, size);
	debug (1, ans, "\n");
}
