#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

class stack
{
	int arrSize;
	int k;
	int s = -1;
	
	int *dataArr;
	int *freeArr; // Index of next free index in array (-1 means occupied)
	int freeLoc; // Represents the location of the next free location
	int *nextArr; // Points to the next element in stack (-1 if no more avaiable)
	
	int *stacks; // Points to top of kth stack

public:
	
	stack(int k, int size)
	{
		this->k = k;
		
		stacks = new int[k];
		for (int i=0; i<k; i++)
			stacks[i] = -1; 
		
		arrSize = size;
		
		dataArr = new int[size];
		freeArr = new int[size];
		nextArr = new int[size];
		
		for (int i=0; i<size; i++)
		{
			dataArr[i] = -1;
			freeArr[i] = i+1;
			nextArr[i] = -1;
		} 
		
		// In the starting, everyhing is free
		freeLoc = 0;
	}
	
	bool isEmpty(int kth)
	{
		if (stacks[kth] == -1)
		{
			debug(1, "Stack ", kth, " empty\n");
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void push(int kth, int a)
	{
		debug (1, "Pushing ", a, " in stack ", kth, "\n");
		s++;
		int nextFreeLoc;
		int prevStackTopmostIndex;

		// If stack not started yet
		if (stacks[kth] == -1)
		{
			nextFreeLoc = freeArr[freeLoc];
			freeArr[freeLoc] = -1;
			
			// Get free location and put element there
			dataArr[freeLoc] = a;
			stacks[kth] = freeLoc;
			
			freeLoc = nextFreeLoc;
		}
		else
		{
			nextFreeLoc = freeArr[freeLoc];
			freeArr[freeLoc] = -1;
			
			// Get free location and put element there
			dataArr[freeLoc] = a;
			
			// Get Previous Stack Topmost, Ask current topmost to point to it 
			prevStackTopmostIndex = stacks[kth];
			nextArr[freeLoc] = prevStackTopmostIndex;
			
			stacks[kth] = freeLoc;
			
			freeLoc = nextFreeLoc;
		}
	}
	
	void pop(int kth)
	{
		int nextAvailFreeLoc;
		int locOfElementToPop;
		
		if (isEmpty(kth) == false)
		{	
			debug(1, "Popping ", dataArr[stacks[kth]], "\n");
			
			s--;	
			nextAvailFreeLoc = freeLoc;	
			locOfElementToPop = stacks[kth];
			
			// If this is the only element in the stack
			if (nextArr[locOfElementToPop] == -1)
			{
				dataArr[locOfElementToPop] = -1;
				stacks[kth] = -1; // Basically no more elements in array
			}
			else
			{
				dataArr[locOfElementToPop] = -1;
				// Previous element of stack is now the top one
				stacks[kth] = nextArr[locOfElementToPop];	
			}
			
			freeLoc = locOfElementToPop;
			freeArr[locOfElementToPop] = nextAvailFreeLoc; 
		}
	}
	
	void top(int kth)
	{
		if (isEmpty(kth) == false)
		{
			debug(1, "Topmost element of ", kth, " stack: " ,dataArr[stacks[kth]], "\n");
		}
	}
	
	void size()
	{
		debug(1, "Stack Size: ", s+1, "\n");
	}
};


int main ()
{
	// RESOURCE
	// https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/
	
	// PROCESS 
	// Good Question
	// Here we are using 2 extra arrays as helpers
	// these point to the next avaiable nodes
	// The free array points to the next avaialbe free location
	// The next array points to the next topmost element in the stack
	// The stacks array keeps track of the index for the topmost element in each array
	
	// EXAMPLES
	// IUnline 
	
	LOG_LEVEL = 3;
	debug (3, "Algorithm Output--\n\n");
	
	stack stk(3,20);
	
	// Ex 1 - No POP's
	/* 
	stk.size();
	
	stk.push(0, 1);
	stk.top(0);
	stk.push(0, 2);
	stk.push(0, 3);
	stk.top(0);
	
	stk.top(1);
	stk.top(2);
	
	stk.push(2, 10);
	stk.push(2, 20);
	stk.top(2);
	
	stk.push(1, 100);
	stk.push(1, 200);
	stk.push(2, 30);
	stk.top(0);
	stk.top(1);
	stk.top(2);
	*/
	
	// Ex 2 - Pops Also
	stk.size();
	stk.push(0, 1);
	stk.push(1, 10);
	stk.push(0, 2);
	stk.push(1, 20);
	stk.push(0, 3);
	stk.push(1, 30);
	
	stk.top(0);
	stk.top(1);
	
	stk.pop(0); 
	stk.top(0);
	stk.pop(0); 
	stk.top(0);
	
	stk.push(1, 40);
	stk.top(0);
	stk.top(1);
	
}
