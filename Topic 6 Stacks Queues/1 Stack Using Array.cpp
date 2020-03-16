#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

class stack
{
	int arr[100];
	int s = -1;

public:
	
	bool isEmpty()
	{
		if (s == -1)
		{
			debug(1, "Stack Empty\n");
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void push(int a)
	{
		s++;
		arr[s] = a;
	}
	
	void pop()
	{
		if (isEmpty() == false)
		{
			arr[s] = 0;
			s--;	
		}
	}
	
	void top()
	{
		if (isEmpty() == false)
		{
			debug(1, arr[s], "\n");
		}
	}
	
	void size()
	{
		debug(1, s+1, "\n");
	}
};


int main ()
{
	// LIFO 
	
	LOG_LEVEL = 3;
	debug (3, "Algorithm Output--\n\n");
	
	stack stk;
	
	stk.size();
	
	stk.top();
	
	stk.push(9);
	stk.push(5);
	stk.push(7);
	stk.top();
	
	stk.pop();
	stk.top();
	
	stk.pop();
	stk.pop();
	stk.pop();
}
