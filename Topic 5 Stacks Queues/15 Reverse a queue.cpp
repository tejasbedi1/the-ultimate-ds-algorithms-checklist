#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

using namespace std;

void displayQueue (queue <int> &que)
{
	queue <int> temp = que;
	debug(1, "Queue... ");	
	while (temp.empty() != true)
	{
		debug(1, temp.front(), " ");
		temp.pop();
	}
	debug (1, "\n");
}

void reverseQueue(queue <int> &que)
{
	stack <int> stk;
	
	displayQueue(que);
	
	while (que.empty() != true)
	{
		stk.push(que.front());
		que.pop();
	}
	while (stk.empty() != true)
	{
		que.push(stk.top());
		stk.pop();
	}
	
	displayQueue(que);
}

int main ()
{	
	// RESOURCES 
	// https://www.geeksforgeeks.org/reversing-a-queue/
	
	// Process
	// This is happening in O(1) space btw...
	
	LOG_LEVEL = 3;
	debug (3, "Algorithm Output--\n\n");
	
	queue <int> que;
	
	que.push(5);
	que.push(4);
	que.push(3);
	que.push(2);
	
	reverseQueue(que);
}
