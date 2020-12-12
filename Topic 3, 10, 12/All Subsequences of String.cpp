#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void allSubsequences(string &str, int n, int pos, string currStr)
{
	if (pos >= n)
	{
		debug (1, currStr, "\n");
		return;
	}
	
	allSubsequences(str, n, pos+1, currStr);
	
	currStr.push_back(str[pos]);
	allSubsequences(str, n, pos+1, currStr);
}

int solving(string str, int n)
{
	string currStr = "";
	
	if (n > 0)
		allSubsequences(str, n, 0, currStr);
}

int main()
{
	// Eerily Similar To "Find all possible subsets"
	// The process here is same
	// Subsequences would also mean find all subsets
	//  but all contents should be in order
	// If something comes before then in the subset is should come first
	
	// RESOURCE  
	// https://www.geeksforgeeks.org/print-subsequences-string/
	
	// Recursive Solution 
	// Complexity 2^n
	
	// IDEA BEHING IT ALL (JUST FOR REFERENCE)
	/*
	*										{}
	*					{}												{1}
	*		{}					  {2}						{1}						{1,2}
	*  {}  		{3} 		{2}			{2,3} 		 {1}		{1,3}		 {1,2} 		{1,2,3}		
	*{} {4}	 {3}  {3,4}   {2} {2,4}  {2,3}{2,3,4}  {1}{1,4}	 {1,3}{1,3,4} {1,2}{1,2,4}  {1,2,3}{1,2,3,4}
	*/
	LOG_LEVEL = 3;
	
	int k;

	// Ex 1
    string str = "abcd";
    
	int size = str.length();
	
	solving(str, size);
}
