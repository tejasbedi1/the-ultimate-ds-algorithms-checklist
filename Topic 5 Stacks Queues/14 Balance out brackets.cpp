#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

using namespace std;

void displayStack(stack <char> &stk)
{
	debug(1, "Stack... ");
	
	stack <char> temp = stk;
	while (temp.empty() != true)
	{
		debug(1, temp.top(), "");
		temp.pop();
	}
	debug (1, "\n");
}

void balanceOut(char *c, int size)
{
	int i = 0;
	stack <char> stk;
	int switches = 0;
	
	debug (1, "Processing: ", c, "\n");
	
	stk.push(c[i]);
	i++;
	while (i < size)
	{
		if ( stk.top() == '(' && c[i] == ')')
		{
			debug(3, "Balanced something...\n");
			stk.pop();
		}
		else
			stk.push(c[i]);
		i++;
	}
	
	displayStack(stk);
	char t;
	
	while (stk.empty() != true)
	{
		t = stk.top();
		stk.pop();
		
		if (t == '(' && stk.top() == ')')
		{
			switches += 2;
			stk.pop();
		}
		else if(t == '(' && stk.top() == '(')
		{
			switches += 1;
			stk.pop();
		}
		else if (t == ')' && stk.top() == ')')
		{
			switches += 1;
			stk.pop();
		}
		else 
		{
			debug(2, "Whoaa unaccounted case\n");
		}
	}
	debug (1, "Reversals needed: ", switches, "\n");
}

int main ()
{	
	// RESOURCES 
	// Just see the question from the resource
	// Image will be more helpful for the answer
	// https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/
	
	// Process
	// 
	// Its straight forward
	// First process the string and keep adding things in stack
	// Filter out all naturally occuring bracket closures, then process the stack
	
	// For processing the stack, there are 3 cases which can happen
	// refer the if's for those and DONE
	
	// IMAGE 14
	
	LOG_LEVEL = 3;
	debug (3, "Algorithm Output--\n\n");
	
	//int size = 4;
	//char c[] = ")("; 			// 2
	//char c[] = "(((("; 		// 2
	//char c[] = "(((())";		// 1
	char c[] = ")(())(((";		// 3
	debug (3, "Size: ", sizeof(c), "\n");
	
	balanceOut(c, sizeof(c)-1);
}
