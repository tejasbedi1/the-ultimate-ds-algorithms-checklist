#include <bits/stdc++.h>
#include "debug.h"

using namespace std;


int solve(int n, unordered_map <int, int> &uMap)
{
	if (uMap.find(n) == uMap.end())
	{
		debug(2, "No saved info for ", n, ", Calcualting\n");
		int temp = n;
		int ans;
		if (n % 2 == 0)
		{
			temp = temp / 2;
		}
		else if (n % 3 == 0)
		{
			temp = temp / 3;
		}
		else // -1
		{
			temp = temp-1;
		}
		ans = solve (temp, uMap) + 1;
		uMap.insert( make_pair(n, ans));
		debug (2, "For ", n, " no of steps = ", ans, "\n");
		return ans;
	}
	else
	{
		debug (2, "Save Found for ", n, ": ", uMap[n], "\n");
		return uMap[n];
	}
}


int main()
{	
	// TOP DOWN DP
	
	// Resource
	// Lecture notes, dynamioc programming
	
	// COMPLEXITY
	// Average : log(n), 
	// in case of many uses O(1)
	// IDK, not important
	
	LOG_LEVEL = 3;
	
	int n = 9;
	int ans;
	
	unordered_map <int, int> uMap;
	uMap.insert( make_pair(0,0) );
	uMap.insert( make_pair(1,1) );
	
	ans = solve(n, uMap);
	debug (1, ans, "\n");
	
	ans = solve(4, uMap);
	debug (1, ans, "\n");
	
	ans = solve(81, uMap);
	debug (1, ans, "\n");
}
