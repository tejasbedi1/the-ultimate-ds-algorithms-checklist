#include <iostream>
#include <queue>

using namespace std;

struct data 
{
	int id;
	int power;
		
};

struct comparisonGreaterStruct
{
	bool operator () (data const &a, data const &b)
	{
		return a.power < b.power;
	}		
};

int main()
{
	// Resourse 1
	// https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/
	
	priority_queue<data, vector<data>, comparisonGreaterStruct > pQueue;
	
	data d;
	
	d.id = 101;
	d.power = 4;
	pQueue.push(d);
	
	d.id = 287;
	d.power = 8;
	pQueue.push(d);
	
	d.id = 54;
	d.power = 2;
	pQueue.push(d);
	
	cout<<pQueue.top().id;
}
