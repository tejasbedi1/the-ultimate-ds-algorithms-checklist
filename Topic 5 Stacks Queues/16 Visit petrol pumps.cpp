#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

using namespace std;

struct PumpData
{
	int petrol;
	int distanceToNext;
	
	PumpData(int a, int b)
	{
		petrol = a;
		distanceToNext = b;
	}
};

void addData(vector <PumpData> &vec, int a, int b)
{
	PumpData pd(a, b);
	vec.push_back(pd);
}

void solve(vector <PumpData> &vec, int size)
{
	int start = 0;
	int end = 0;
	int overallSum = 0;
	int difference;
	
	while (true)
	{
		if (end >= size)
			end = 0;
				
		if (end == start && overallSum != 0)
			break;
		
		debug (2, "Processing with start, end: ", start, ",", end, "\n");
		
		difference = vec[end].petrol - vec[end].distanceToNext;
		if (overallSum + difference >= 0)
		{
			// approved 
			end++;
			overallSum += difference;
		}
		else
		{
			overallSum = 0;
			end++;
			start = end;
			debug (2, "Changed Start, End to index: ", start, "\n");
		}
		
	}	
	debug (1, "Start, End: ", start, ",", end, "\n");
}

int main ()
{	
	// RESOURCES 
	// https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/
	
	// Process
	// - Have to do it in O(n)
	// - We'll work with the vector iteself and treat it as a queue
	// - Assuming- There exists a correct answer in the queue
	
	LOG_LEVEL = 3;
	
	int size;
	vector <PumpData> vec;
	
	// EX 1
	//addData(vec, 4, 6);
	//addData(vec, 6, 5);
	//addData(vec, 7, 3);
	//addData(vec, 4, 5);
	
	// Ex 2 
	addData(vec, 1, 3);
	addData(vec, 6, 3);
	addData(vec, 2, 6);
	addData(vec, 7, 2);
	
	size = vec.size();
	
	debug (3, "Algorithm Output--\n\n");
	solve(vec, vec.size());	
}
