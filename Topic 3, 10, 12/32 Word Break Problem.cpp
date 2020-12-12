#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void displayVecStr(vector <string> vec)
{
	int i;
	debug (1, vec.size(), "[");
	
	for (i=0; i<vec.size(); i++)
	{
		if (i == vec.size()-1)
			debug (1, vec[i]);
		else
			debug (1, vec[i], ",");	
	}
	debug(1, "]\n");
}

void copyInto (vector <string> &a, vector <string> &b)
{
	for (auto x: b)
	{
		a.push_back(x);
	}
}

void multiply(string s, vector <string> &list)
{
	debug (3, "Multiplying: ", s, " and ");
	if (LOG_LEVEL >= 3)displayVecStr(list);
	
	for (auto &x: list)
	{			
		x = s + " " + x; 
	}
}

bool findInDict(string s, unordered_set <string> &uSet)
{	
	if (uSet.find(s) != uSet.end())
		return true;	
	
	return false;
}

vector <string> solveD(	string s, unordered_set <string> &uSet, 
						unordered_map <string, vector <string>> &uMap )
{
	int i;
	string sub;
	string y;
	vector <string> temp;
	vector <string> temp2;
	bool flag;
	
	debug(2, "String: <", s, ">\n");
	
	if (uMap.find(s) != uMap.end())
	{
		debug (2, "Found, ", s, " in uMap ---- ");
		displayVecStr(uMap.find(s)->second);
		
		return uMap.find(s)->second;
	}
	
	i = 1;
	while (i <= s.size())
	{
		sub = s.substr(0, i);
		debug(3, "Evaluating: ", sub, "\n");
		
		temp.clear();
		if (findInDict(sub, uSet) == true)
		{
			flag = true;
			
			debug (3, "Found: ", sub, "\n");
			
			y = sub + " ";
			if (s.size() - i > 0 )
			{
				temp = solveD (s.substr(i, s.size()), uSet, uMap);
			}
			
			if (s.size() - i == 0) //temp.empty() == true && 
				temp.push_back(y);
			else
				multiply (y, temp);
				
		}
		if (flag == true)
		{
			copyInto(temp2, temp);
			flag = false;
		}
		i++;
	}
	
	debug (1, "Saving ", s, " as ");
	displayVecStr(temp2);
	uMap.insert(make_pair(s, temp2));
	
	debug (2, "Returning for <", s, "> this ---");
	displayVecStr(temp2);
	return temp2;
}

vector <string> solve(	string s, unordered_set <string> &uSet, 
						unordered_map <string, vector <string>> &uMap )
{
	int i;
	string sub;
	string y;
	vector <string> temp;
	vector <string> temp2;
	bool flag;
	
	if (uMap.find(s) != uMap.end())
		return uMap.find(s)->second;
	
	i = 1;
	while (i <= s.size())
	{
		sub = s.substr(0, i);

		if (findInDict(sub, uSet) == true)
		{
			flag = true;
			temp.clear();
			
			y = sub;
			if (s.size() - i > 0 )
			{
				temp = solve (s.substr(i, s.size()), uSet, uMap);
			}
			
			if (s.size() - i == 0)
				temp.push_back(y);
			else
				multiply (y, temp);
				
		}
		if (flag == true)
		{
			copyInto(temp2, temp);
			flag = false;
		}
		i++;
	}
	
	uMap.insert(make_pair(s, temp2));
	return temp2;
}


int main()
{	
	// DP O()
	
	
	// VV IMP QUESITON 
	
	// Resource
	// Q https://www.geeksforgeeks.org/word-break-problem-dp-32/
	// Q https://leetcode.com/problems/word-break-ii/
	// Best Eplanation so far
	// https://leetcode.com/problems/word-break-ii/discuss/776320/2-Solution-Hack-and-DFS-with-Memoizations
	
	
	// Explanition
	// Okay I spent too long on this Question than I should have
	// This can be solved useing Trie OR DP
	// This is the TOP DOWN DP approach because its the most Straight forward
	
	// Do this 
	// Eg "catsanddog:
	// Start procesiing each letter and try to find in Dictionary
	// "cat" found recusively find "sanddog"
	//		"sand" found recursively find "dog"
	// 			"dog" found 
	//			return 
	//		return
	// Save "cat sand dog"
	// Further
	// "cats" found recursively find "anddog"
	
	// The main problem here was how to save the returned fields ?
	// So we used vector <string> and multiplied by base string
	// Eg .. abc with dict a, b, c, bc
	// Process "a" rest is "bc" 
	// 		Further found "b c" & "bc"
	// Now multiply with a because a is original parent
	// it becomes "a b c" "a bc"
	// 
	// CYA
		
 	LOG_LEVEL = 2;
	
	// Ex 0 - A.2
	string s = "catsanddog";
	vector <string> wordDict = {"cat", "cats", "and", "sand", "dog"};
	
	// EX 1 - A.3
	//string s = "pineapplepenapple";
	//vector <string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
	
	// Ex 2 - A.0
	//string s = "catsandog";
	//vector <string> wordDict = {"cats", "dog", "sand", "and", "cat"};
	
	// Ex 3 - A.1
	//string s = "abc";
	//vector <string> wordDict = {"a", "b", "bc"};
	
	// Ex 4 - A.8
	//string s = "abcd";
	//vector <string> wordDict = {"a", "b", "c", "d", "ab", "bc", "cd", 
	//						"abc", "bcd", "abcd"};
	
	debug (1, "Q. ", s, "\n");
	displayVecStr(wordDict);
	debug (1, "\n");
	
	vector <string> ans;
	unordered_map <string, vector<string>> uMap;
	unordered_set <string> uSet;
	
	for (auto x: wordDict)
		uSet.insert(x);
	
	ans = solve (s, uSet, uMap);
	displayVecStr(ans);
}
