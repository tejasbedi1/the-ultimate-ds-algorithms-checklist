#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

class stack
{
	struct node
	{
		int data;
		struct node *next;
		struct node *prev;
	};

	int s = -1;
	
public:
	//struct node *head;
	struct node *curr;
	
	stack()
	{
		//head = NULL;
		curr = NULL;
	}
	
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
		if (curr == NULL)
		{
			node *newNode;
			newNode = new node();
			newNode->data = a;
			newNode->next = NULL;
			newNode->prev = NULL;
			
			//head = newNode;
			curr = newNode;
		}
		else 
		{
			node *newNode;
			newNode = new node();
			newNode->data = a;
			newNode->next = NULL;
			newNode->prev = curr;
			
			curr->next = newNode;
			
			curr = newNode;
		}
	}
	
	void pop()
	{
		if (isEmpty() == false)
		{
			node *temp;
			temp = curr;
			curr = curr->prev;
			delete temp;
			
			s--;	
		}
	}
	
	void top()
	{
		if (isEmpty() == false)
		{
			debug(1, curr->data, "\n");
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
