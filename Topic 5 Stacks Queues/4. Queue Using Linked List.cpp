#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

class queue
{
	struct node
	{
		int data;
		struct node *next;
	};

	int s = -1;
	
public:
	struct node *first;
	struct node *last;
	
	queue()
	{
		first = NULL;
		last = NULL;
	}
	
	bool isEmpty()
	{
		if (s == -1)
		{
			debug(1, "Queue Empty\n");
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
		if (first == NULL && last == NULL)
		{
			node *newNode;
			newNode = new node();
			newNode->data = a;
			newNode->next = NULL;
			
			first = newNode;
			last = newNode;
		}
		else 
		{
			node *newNode;
			newNode = new node();
			newNode->data = a;
			newNode->next = NULL;
			
			last->next = newNode;
			
			last = newNode;
		}
	}
	
	void pop()
	{
		if (isEmpty() == false)
		{
			node *temp;
			temp = first;
			first = first->next;
			delete temp;
			
			s--;
		}
	}
	
	void front()
	{
		debug (1, "Current Front: ");
		if (isEmpty() == false)
		{
			debug(1, first->data, "\n");
		}
	}
	
	void back()
	{
		debug (1, "Current Back: ");
		if (isEmpty() == false)
		{
			debug(1, last->data, "\n");
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
	
	queue que;
	
	// Ex 1 NORMAL 
	///*
	que.size();
	que.front();
	
	que.push(9);
	que.front(); que.back();
	que.size();
	
	que.push(5);
	que.push(7);
	
	que.pop();
	que.front(); que.back();
	
	que.pop();
	que.pop();
	que.pop();
	//*/
	
	// Ex2 MADE TO DETECT IF THE QUEUE CYCLES INDEX's
	/*
	que.push(9);
	que.push(8);
	que.push(7);
	que.push(6);
	que.push(5);
	que.front(); que.back();
	que.size();
	
	que.push(4);
	que.front(); que.back();
	que.size();
	
	que.pop();
	que.pop();
	que.push(4);
	que.push(3);
	que.front(); que.back();
	que.size();
	*/
}
