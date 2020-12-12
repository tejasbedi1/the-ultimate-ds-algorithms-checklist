#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

using namespace std;

void checkRedundantBracket(char *c)
{
	int i = 0;
	stack <char> stk;
	
	while (i < strlen(c))
	{
		//debug (1, c[i], " ");		
		if (c[i] == '(' || c[i] == '+' || c[i] == '-' || c[i] == '/' || c[i] == '*')
		{	
			stk.push(c[i]);
		}
		else if (c[i] == ')')
		{
			if (stk.top() == '+' || stk.top() == '-' || stk.top() == '*' || stk.top() == '/')
			{
				while (stk.top() != '(')
				{
					stk.pop();
				}
				stk.pop();
			}
			else if (stk.top() == '(')
			{
				debug (1, "Redundancy Found...");
				return;
			}
		}
		i++;
	}
	debug (1, "No Redundancy...");
	
}

int main ()
{	
	// RESOURCES 
	// https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/
	
	// Process
	// Go figure 
	
	// ASSUMPTION
	// The input is valid
	
	LOG_LEVEL = 3;
	debug (3, "Algorithm Output--\n\n");
	
	//char c[] = "((a+b))";
	//char c[] = "(a+(b)/c)";
	char c[] = "(a/b*(c-d))";
	
	checkRedundantBracket(c);
}
