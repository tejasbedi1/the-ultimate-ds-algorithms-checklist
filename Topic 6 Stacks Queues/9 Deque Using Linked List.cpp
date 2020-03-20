#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

class deque
{
	struct node
	{
		int data;
		struct node *next;
		struct node *prev;
	};
	
	int s = -1;
	struct node *first;
	struct node *last; 
	
	void firstElement(int a)
	{
		s++;
	
	}

public:
	
	deque()
	{
		first = NULL;
		last = NULL;
	}
	
	bool isEmpty()
	{
		if (s == -1)
		{
			debug(3, "Stack Empty\n");
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void push_front(int a)
	{
		debug(1, "Pushing Front: ", a, "\n");
		
		struct node *temp;
		
		temp = new node();
		temp->data = a;
		temp->next = NULL;
		temp->prev = NULL;
		
		if (first == NULL)
		{
			first = temp;
			last = temp;
			s++;
			return;
		}
		
		first->prev = temp;
		temp->next = first;
		
		first = temp;
		s++;
	}
	
	void push_back(int a)
	{
		debug(1, "Pushing Back: ", a, "\n");	
		
		struct node *temp;
		
		temp = new node();
		temp->data = a;
		temp->next = NULL;
		temp->prev = NULL;
		
		if (last == NULL)
		{
			first = temp;
			last = temp;
			s++;
			return;
		}
		
		last->next = temp;
		temp->prev = last;
		
		last = temp;
		s++;
	}
	
	void pop_front()
	{
		if (isEmpty() == false)
		{
			debug(1, "Poping Front: ", first->data, "\n");
			
			struct node *temp;
			temp = first;
			if (first->next == NULL)
			{
				first = NULL;
				last = NULL;
			}
			else
			{
				first = first->next;
				first->prev = NULL;	
			}
			s--;
			
			delete temp;
		}
	}
	
	void pop_back()
	{
		if (isEmpty() == false)
		{
			debug(1, "Poping Back: ", last->data, "\n");
			
			struct node *temp;
			temp = last;
			if(last->prev == NULL)
			{
				first = NULL;
				last = NULL;
			}
			else
			{
				last = last->prev;
				last->next = NULL;	
			}
			s--;
			
			delete temp;		
		}
	}
	
	void front()
	{
		if (isEmpty() == false)
		{
			debug(1, "Front: ", first->data, "\n");
		}
	}
	
	void back()
	{
		if (isEmpty() == false)
		{
			debug(1, "Back: ", last->data, "\n");
		}
	}
	
	void size()
	{
		debug(1, "Size: ", s+1, "\n");
	}
	
	void displayAll()
	{
		if (isEmpty() == true)
		{
			debug(1, "Nothing to show...\n");
			return;
		}
		debug (1, "Queue- ");
		struct node *temp;
		temp = first;
		while (temp != last)
		{
			debug(1, temp->data, " ");
			temp = temp->next;
		}
		debug(1, temp->data, " ");
		debug (1, "(", s+1, ")" ,"\n");
	}
};


int main ()
{
	// OPERATONS
	// size
	// push front 
	// push back
	// pop front
	// pop back
	// front
	// back
	// isempty()
	
	LOG_LEVEL = 2;
	debug (3, "Algorithm Output--\n\n");
	
	deque dque;
	
	dque.size();
	
	// Ex 1 ONLY PUSH
	/*
	dque.push_front(10);
	dque.displayAll();
	
	dque.push_back(40);
	dque.displayAll();
	
	dque.push_front(30);
	dque.push_back(20);
	dque.push_front(6);
	dque.push_back(7);
	
	dque.displayAll();
	*/
	
	// Ex 2 ALL OPPS
	
	dque.push_front(30);
	dque.push_back(20);
	
	dque.displayAll();
	
	dque.pop_front();
	dque.displayAll();
	
	dque.pop_back();
	dque.pop_back();
	
	dque.push_front(30);
	dque.push_back(20);
	dque.push_front(6);
	dque.push_back(7);
	dque.displayAll();
	dque.pop_back();
	dque.pop_back();
	dque.pop_back();
	dque.pop_back();
	dque.displayAll();
	
}
