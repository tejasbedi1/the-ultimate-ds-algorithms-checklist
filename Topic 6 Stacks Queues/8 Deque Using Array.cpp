#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

class deque
{
	int arr[5];
	int s = -1;
	int first = -1;
	int last = -1;
	int maxSize = 5;
	
	void firstElement(int a)
	{
		s++;
		first = 0;
		last = 0;
		arr[first] = a;
	}

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
	
	void push_front(int a)
	{
		if (s >= 4)
		{
			debug(1, "Deque Full\n");
			return;
		}
		debug(1, "Pushing Front: ", a, "\n");
		
		if (s == -1)
		{
			firstElement(a);
			return;
		}
		
		first++;
		if (first == maxSize) 	// LOOP
			first = 0;
		
		s++;
		arr[first] = a;
	}
	
	void push_back(int a)
	{
		if (s >= 4)
		{
			debug(1, "Deque Full\n");
			return;
		}
		debug(1, "Pushing Back: ", a, "\n");
		
		if (s == -1)
		{
			firstElement(a);
			return;	
		}
		
		last--;
		if (last == -1) 	// LOOP
			last = maxSize-1;
			
		s++;
		arr[last] = a;
	}
	
	void pop_front()
	{
		if (isEmpty() == false)
		{
			debug(1, "Poping Front: ", arr[first], "\n");
			
			arr[first] = 0;
			
			first -= 1;
			if (first == -1) 	// LOOP
				first = maxSize-1;
			s--;
		}
	}
	
	void pop_back()
	{
		if (isEmpty() == false)
		{
			debug(1, "Poping Back: ", arr[last], "\n");	
			
			arr[last] = 0;
			
			last += 1;	
			if (last == maxSize) // LOOP
				last = 0;
			s--;
		}
	}
	
	void front()
	{
		if (isEmpty() == false)
		{
			debug(1, "Front: ", arr[first], "\n");
		}
	}
	
	void back()
	{
		if (isEmpty() == false)
		{
			debug(1, "Back: ", arr[last], "\n");
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
		int f = first;
		while (f != last)
		{
			arr[f];
			debug(1, arr[f], " ");
			f--;
			
			if ( f == -1)	// LOOP
				f = maxSize-1;	
		} 
		debug(1, arr[f], " ");
		
		debug (1, "\n");
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
	
	LOG_LEVEL = 3;
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
	dque.pop_back();
	dque.pop_back();
	dque.pop_back();
	dque.pop_back();
	dque.displayAll();
}
