#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

class queue
{
	int maxSize = 5;
	int arr[5];
	int s = -1;
	int first = -1;
	int last = -1;
	
public:
	
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
		debug(1, "Pushing: ", a, "\n");
		if (s == -1)
		{
			s++;
			first = 0;
			last = 0;
			
			arr[last] = a;
		}
		else
		{
			s++;
			if (s < maxSize)
			{
				last++;
				if (last >= maxSize)
					last = 0;
				arr[last] = a;	
			}
			else
			{
				debug(1, "Cannot Push: Queue at Capacity\n");
				s--;
			}
			
		}
	
	}
	
	void pop()
	{
		if (isEmpty() == false)
		{
			debug(1, "Popping: ", arr[first], "\n");
			arr[first] = 0;
			
			first++;
			if (first >= maxSize)
				first = 0;
			
			s--;
			if (s == -1)
			{
				first = 0;
				last = 0;
			}
		}
	}
	
	void front()
	{
		debug (1, "Current Front: ");
		if (isEmpty() == false)
		{
			debug(1, arr[first], "\n");
		}
	}
	
	void back()
	{
		debug (1, "Current Back: ");
		if (isEmpty() == false)
		{
			debug(1, arr[last], "\n");
		}
	}
	
	void size()
	{
		debug(1, "Current Size: ", s+1, "\n");
	}
};


int main ()
{
	// FIFO
	
	LOG_LEVEL = 3;
	debug (3, "Algorithm Output--\n\n");
	
	queue que;
	
	// Ex 1 NORMAL 
	/*
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
	*/
	
	// Ex2 MADE TO DETECT IF THE QUEUE CYCLES INDEX's
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
}
