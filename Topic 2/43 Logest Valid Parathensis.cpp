#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void displayVec(vector <int> vec)
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


bool findInDict(string s, unordered_set <string> &uSet)
{	
	if (uSet.find(s) != uSet.end())
		return true;	
	
	return false;
}

void displayVec(vector <bool> vec)
{
	int i;
	debug (1, vec.size(), "[");
	
	for (i=0; i<vec.size()-1; i++)
	{
		debug (1, vec[i], " ");
	}
	
	debug (1, vec[i]);
	debug(1, "]\n");
}

int longestValidParenthesesOriginal(string &str)
{
	if (str.size() <= 1)
		return 0;

	int i;
	int size = str.size();
	int ans = 0;
	
	vector <bool> vec;
	vec.resize( str.size() );
	
	stack <int> stk;
	
	if (LOG_LEVEL >= 2) displayVec(vec);

	for (i=0; i<size; i++)
	{
		if (str[i] == ')')
		{
			if (stk.size() != 0)
			{
				vec[stk.top()] = true;
				vec[i] = true;
				stk.pop();
			}
		}
		else if (str[i] == '(')
		{
			stk.push(i);
		}
	}
	
	if (LOG_LEVEL >= 2) displayVec(vec);
	
	int s = -1;
	for (i=0; i<size; i++)
	{	
		if (s == -1 && vec[i] == true)
			s = i;
			
		else if (vec[i] == false)
		{
			if (s!= -1 && i-s > ans)
				ans = i-s;
			s = -1;
		}
	}
	if ( s!= -1 && i-s > ans)
		ans = i-s;
				
	return ans;
}

int longestValidParentheses(string &str)
{
	if (str.size() <= 1)
		return 0;

	int i, s;
	int size = str.size();
	int ans = 0;
	
	stack <int> stk;
	
	debug (2, str, "\n");
	
	for (i=0; i<size; i++)
	{
		if (str[i] == ')')
		{
			if (stk.size() != 0)
			{
				str[stk.top()] = '|';
				str[i] = '|';
					
				stk.pop();
			}
		}
		else if (str[i] == '(')
		{
			stk.push(i);
		}
	}
	
	debug (2, str, "\n");

	s = 0;
	for (i=0; i<size; i++)
	{	
		if (str[i] == '|')
		{
			s++;
			if (s > ans)
				ans = s;
		}
		else 
			s = 0;
	}
		
	return ans;
}

int main()
{	
	// Iterative O(N)
	
	// Resource
	//https://www.interviewbit.com/problems/longest-valid-parentheses/
	//https://leetcode.com/problems/longest-valid-parentheses/

	// Explanition
	// MAke all closures and the clouse itself by a |
	// Count all |'s...

 	LOG_LEVEL = 3;
	
	string str;
	
	// Ex 1 - A.2
	//str = "(()";
	
	// EX 1 - A.4
	//str = ")()())";
	
	// Ex 2 - A.2
	//str = ")())())";
	
	// Ex 3 - A.6
	//str = ")((()))";
	
	// Ex 4 - A.8	
	//str = ")(()(()))";
	
	// Ex 5 - A.4
	//str = ")()((())";
	
	// Ex 6 - A.0
	//str = ")(";
	
	debug (1, "Q. ", str, "\n");
	
	int ans = longestValidParentheses (str);
	debug (1, "Ans: ", ans);
}
