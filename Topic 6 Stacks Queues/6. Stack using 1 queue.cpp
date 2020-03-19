#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

using namespace std;

class stackOneQueue
{
	int i;
	queue <int> que;
	
public:
	bool isEmpty()
	{
		return que.empty();
	}
	
	void push(int a)
	{
		que.push(a);
		for (i=0; i<que.size()-1; i++)
		{
			que.push(que.front());
			que.pop(); 
		}
	}
	
	void pop()
	{
		if (isEmpty() == false)
			que.pop();
	}
	
	void top()
	{
		if (isEmpty() == false)
			debug(1, "Topmost: ", que.front(), "\n");
	}
	
	void size()
	{
		debug(1, "Size: ", que.size(), "\n");
	}
};

int main ()
{
	// RESOURCE
	// https://www.geeksforgeeks.org/implement-a-stack-using-single-queue/
	
	// PROCESS 
	// The main highlight here is the push function
	// Whenever a new push is done
	// We push all the previously added elements again and simultaneously also
	//  pop them
	// This creates a sort of cycle which brings the actual element to be 
	//  pushed in front of the queue hence in front of the stack
	
	// EXAMPLES
	// Inline 
	
	LOG_LEVEL = 3;
	debug (3, "Algorithm Output--\n\n");
	
	stackOneQueue stk;
	
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
