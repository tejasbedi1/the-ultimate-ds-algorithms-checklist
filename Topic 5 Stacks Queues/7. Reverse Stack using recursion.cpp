#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

using namespace std;

class RevStack
{
	int i;
	stack <int> stk;
	
public:
	bool isEmpty()
	{
		if(stk.empty() == true)
		{
			debug(3, "Stack Empty, cannot proceed with operation...\n");
			return true;
		}
		else 
			return false;
	}
	
	void insertAtBottom(int toAdd) 
	{
		int a;
		
		if (isEmpty() == true)
		{
			stk.push (toAdd);
			return;
		}
		
		a = stk.top();
		stk.pop();
		
		insertAtBottom(toAdd);
		
		stk.push(a);
	}
	
	void revStack()
	{
		int temp;
			
		if (isEmpty() == true)
		{
			debug(2, "revStack: Emptying Done, Refillig Stack\n");
			return;
		}
		
		temp = stk.top();
		debug(2, "revStack: Stored and popping ", temp, "\n");
		stk.pop();
		revStack();

		debug(2, "revStack: Inserting At Bottom ", temp, "\n");
		insertAtBottom(temp);
		
	}
	
	void push(int a)
	{
		stk.push(a);
	}
	
	void pop()
	{
		if (isEmpty() == false)
			stk.pop();
	}
	
	void top()
	{
		if (isEmpty() == false)
			debug(1, "Topmost: ", stk.top(), "\n");
	}
	
	void size()
	{
		debug(1, "Size: ", stk.size(), "\n");
	}
	
	void displayStack()
	{
		stack <int> temp = stk;
		debug(1, "Stack Output (top->bottom)...\n");
		while (temp.empty() != true)
		{
			debug(1, temp.top(), " ");
			temp.pop();
		}
		debug(1, "\n");
	}
	
};

int main ()
{
	// RESOURCE
	// https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/
	
	// PROCESS
	// The process goes like this
	// If we have a stack (top)1,2,3(bottom)
	// Then first using recursion we pop all and store them in variables
	// 
	// After that, we take each one and insert them at the bottom
	// First 3, then 2, then 1. The resulting stack will be (top)3,2,1(bottom)
	//
	// The 2 main procedures where we use recursion are revStack() and insertAtBottom()
	// At revStack 
	//  	i) we recureively loop till the stack is empty and hence we will be 
	// 			processing the bottom most element first
	//	At insertAtBottom
	// 		i) we recurcively loop whenever an element is added. All elements are 
	//			popped and stored
	// 		ii)  the first element to be pushed will be the newly added one
	// 				the rest are pushed after because of the recursive nature
	
	// EXAMPLES
	// Inline  
	
	LOG_LEVEL = 3;
	debug (3, "Algorithm Output--\n\n");
	
	RevStack stk;
	
	stk.size();
	stk.top();
	
	stk.push(9);
	stk.push(7);
	stk.push(5);
	stk.push(3);
	stk.push(1);
	
	stk.size();
	stk.top();
	
	stk.displayStack();
	
	stk.reverse();
	stk.displayStack();
}
