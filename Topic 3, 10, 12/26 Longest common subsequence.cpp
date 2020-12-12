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

// Recusion optimized by memoization
int solve(string s1, string s2, unordered_map <pair<int, int>, int, hash_pair> &uMap)
{
	debug (2, "Current s1: ", s1, "  s2: ", s2, "\n");
	int l1, l2;
	int m1, m2;
	int ans = 0;
	
	l1 = s1.size();
	l2 = s2.size();
	
	if (l1 == 0 || l2 == 0)
		ans = 0;
		
	else if (s1[l1-1] == s2[l2-1])
		if (uMap.find( make_pair((l1-1),(l2-1)) ) == uMap.end() )
			ans = 1 + solve( s1.substr(0,l1-1), s2.substr(0,l2-1), uMap);
		else
		{
			debug (3, "Found: ", l1-1, ",", l2-1, "\n");
			ans = uMap.find( make_pair((l1-1),(l2-1)) )->second;
		}
			
	else
	{
		if (uMap.find( make_pair((l1),(l2-1)) ) == uMap.end() )
			m1 = solve( s1.substr(0,l1), s2.substr(0,l2-1), uMap);
		else
		{
			debug (3, "Found: ", l1, ",", l2-1, "\n");
			m1 = uMap.find( make_pair((l1),(l2-1)))->second;
		}
		if (uMap.find( make_pair((l1-1),(l2)) ) == uMap.end() )
			m2 = solve( s1.substr(0,l1-1), s2.substr(0,l2), uMap);
		else
		{
			debug (3, "Found: ", l1-1, ",", l2, "\n");
			m2 = uMap.find( make_pair((l1-1),(l2)))->second;
		}
		if (m1 >= m2)
			ans = m1;
		else
			ans = m2;
	}
	debug (3, "Returning: ", ans, "\n");
	debug (2, "Saving: ", l1, ",", l2, "\n");
	uMap.insert(make_pair( make_pair(l1,l2), ans));
	return ans;
}

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

int max(int a, int b)
{
	return (a > b) ? a : b;
}

// All values stored in 2D array
int solve(string s1, string s2)
{
	int i, j;
	int l1, l2;
	int ans = 0;
	
	l1 = s1.size()+1;
	l2 = s2.size()+1;
	
	// INIT
	int **arr = new int*[l1];
	for (i=0; i<l2; i++)
		arr[i] = new int[l2];
	
	for (i=0; i<l1; i++)
	{
		for (j=0; j<l2; j++)
		{
			arr[i][j] = 0;
		}
	}
	
	if (LOG_LEVEL >= 2) displayArr(l1, l2, arr, s1, s2);
	
	// Main
	for (i=1; i<l1; i++)
	{
		for (j=1; j<l2; j++)
		{
			if (s1[i-1] == s2[j-1])
			{
				// 1 + plus the subproblem
				arr[i][j] = 1 + arr[i-1][j-1]; 
			}
			else
				arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
		}
	}
	
	if (LOG_LEVEL >= 2) displayArr(l1, l2, arr, s1, s2);
	
	return arr[l1-1][l2-1];
}

int main()
{	
	// DP O(n.m)
	
	// Resource
	//https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
	//https://www.youtube.com/watch?v=ASoaQq66foQ
	
	// Explanation
	// Here realize that approaching from the back will be more helpful
	// Then, for eg if we have AXYB, ACDB
	// If we have to get Longest Common Subsequence (LCS)
	// LCS(AXYB, ACDB) = 1 + (AXY, ACD), The back ones match cause
	// Then then in LCS(AXY, ACD) = Max OF ( LCS (AX, ACD), LCS(AXY, AC) ) 
	// One solution woould be to save these sub problems in map
	// 
	// The next and most optimal solution is to use a 2D array,
	// Run the prgram and see the 2D array. It is self explanitory
	
	LOG_LEVEL = 2;
	
	// Ex 0, 4 GTAB
	//string s1 = "AGGTAB";
	//string s2 = "GXTXAYB";
	
	// Ex 1, 3 ADH
	string s1 = "ABCDGH";
	string s2 = "AEDFHR";
	
	unordered_map <pair<int, int>, int, hash_pair> uMap; 
	
	//int ans = solve(s1, s2, uMap);
	
	int ans = solve(s1, s2);
	
	debug (1, ans, "\n");
}
