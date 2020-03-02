#include <bits/stdc++.h>
#include <iostream>
#include "extrasV3.h"

using namespace std;

struct data
{
	int nodeA;
	int nodeB;
	int capacity;
	int currentFlow;
	char state; // State e enabled d disabled u unspecified
};

void initVArray (int V, vector <data> **vArray)
{
	*vArray = new vector <data>[V];
}

void addEdge(vector <data> *vArray, int a, int b, int c)
{
	data d;
	d.nodeA = a;
	d.nodeB = b;
	d.capacity = c;
	d.state = 'u';
	d.currentFlow = 0;
	
	vArray[a].push_back(d);
	
	d.nodeA = b; 	// RESIDUAL EDGES
	d.nodeB = a; 
	d.capacity = 0;
	d.currentFlow = 0;
	d.state = 'u';
	vArray[b].push_back(d);
}

void displayEdgeData(stack <data> &sEdgeData)
{
	cout<<"Edge Data: ";
	stack <data> copy = sEdgeData;
	while (copy.empty() == false)
	{
		cout<<"("<<copy.top().nodeA<<","<<copy.top().nodeB<<")"<<" ";
		copy.pop();
	}
	cout<<endl;
}

void display (int V, vector <data> *vArray)
{
	int i;
	for (i=0; i<V; i++)
	{
		cout<<"Node "<<i<<"- ";
		for (auto x : vArray[i])
		{
			if (x.capacity == 0)
				cout<<x.nodeA<<","<<x.nodeB<<"("<<x.currentFlow<<","<<"R"<<")"<<" ";
			else
				cout<<x.nodeA<<","<<x.nodeB<<"("<<x.currentFlow<<","<<x.capacity<<")"<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void displayState (int V, vector <data> *vArray)
{
	cout<<"Edge States...\n";
	int i;
	for (i=0; i<V; i++)
	{
		cout<<"Node "<<i<<"- ";
		for (auto x : vArray[i])
		{
			if (x.capacity == 0)
				cout<<x.nodeA<<","<<x.nodeB<<"("<<x.currentFlow<<","<<"R"<<
					","<<x.state<<")"<<" ";
			else
				cout<<x.nodeA<<","<<x.nodeB<<"("<<x.currentFlow<<","<<x.capacity<<
					","<<x.state<<")"<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void displayStack (stack <int> &path)
{
	stack <int> temp = path;
	while (temp.empty() != true)
	{
		cout<<temp.top()<<" ";
		temp.pop();
	}
}

void displayArray (int size, int *levels)
{
	for (int i=0; i<size; i++)
		cout<<i<<": "<<levels[i]<<" | ";
	cout<<endl;
}

void assignLevels(int V, vector <data> *vArray, int *levels)
{
	debug(2, "Assigning Levels...\n");
	
	int front;
	
	queue <int> que;
	que.push(0);
	levels[0] = 0;
	
	while (que.empty() != true)
	{
		front = que.front();
		debug (3, "Accessing ", front, "\n");
		for (auto &x: vArray[front])
		{
			debug (3, " Checking ", x.nodeB, "\n");
			// Checking if node has not been already visited & is not a backward edge
			if (levels[x.nodeB] == -1 && x.capacity != 0)
			{
				que.push(x.nodeB);
				levels[x.nodeB] = levels[front] + 1;
				x.state = 'e';
				debug (3, "  Level not assigned, Capacity not zero\n");
			}
			// Node already visited
			else if (levels[x.nodeB] != -1)
			{
				// Check if forward or backward edge and if has the capacity to carry 
				// anything 
				
				// Not a resedual edge
				if (x.capacity != 0 && x.currentFlow < x.capacity)
				{ 
					if (levels[front] < levels[x.nodeB])
						x.state = 'e';
					else
						x.state = 'd';
				}
				// Residual edge 
				else if (x.capacity == 0 && x.currentFlow > 0)
				{
					if (levels[front] < levels[x.nodeB])
						x.state = 'e';
					else
						x.state = 'd';
				}
				else
				{
					x.state = 'd';
				}
				debug (3, "  Level already assigned\n");
			}
			// In case of residual edges with 
			else
			{
				x.state = 'd';
				debug (3, "  Level not assigned, buts its a residual graph\n");
			}	
				
		}
		que.pop();
	}
}

void DinicsAlgorithm(int V, vector <data> *vArray)
{
	int i;
	
	// Consruct a Level graph easy, it is, We will do it BFS's ly
	int *levels;
	levels = new int[V];
	for (i=0; i<V; i++)
		levels[i] = -1;
	
	assignLevels(V, vArray, levels);
	if (LOG_LEVEL >= 2) displayArray (V, levels);
	
	if (LOG_LEVEL >= 2) displayState(V, vArray);
	
	// Next using edges that are enabled find paths dfs'ly
	
	
	delete [] levels;
}

int main()
{
	// Resource 
	
	// Detailed - 
	// Visualize - 
	
	// Process

	
	// Complexity 
	
	// GRAPH
	// Ex 1 GFG https://media.geeksforgeeks.org/wp-content/uploads/Dinicalgorithm.png
	// Ex 2 Hacker https://he-s3.s3.amazonaws.com/media/uploads/6bf2e0d.png
	// Ex 3 
	
	LOG_LEVEL = 3;
	
	int nodes = 6;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	
	// GFG
	// Src 0 Sink 5 | MAX FLOW 
	addEdge(vArray, 0, 1, 10);
	addEdge(vArray, 0, 2, 10);
	addEdge(vArray, 1, 3, 4);
	addEdge(vArray, 1, 4, 8);
	addEdge(vArray, 1, 2, 2);
	addEdge(vArray, 2, 4, 9);
	addEdge(vArray, 4, 3, 6);
	addEdge(vArray, 3, 5 ,10);
	addEdge(vArray, 4, 5, 10);
	
	// Hacker earth
	// Src S,0 Sink T,5 | MAX FLOW
	/*
	addEdge(vArray, 0, 1, 10);
	addEdge(vArray, 0, 2, 8);
	addEdge(vArray, 1, 2, 2);
	addEdge(vArray, 1, 3, 8);
	addEdge(vArray, 2, 3, 6);
	addEdge(vArray, 2, 4, 7);
	addEdge(vArray, 3, 5, 10);
	addEdge(vArray, 4, 5 ,10);
	*/
	
	// YOUTUBE 
	// SRC 0 Sink 10 | Max Flow: 20
	/*
	addEdge(vArray, 0, 1, 5);
	addEdge(vArray, 0, 4, 10);
	addEdge(vArray, 0, 7, 15);
	addEdge(vArray, 1, 2, 10);
	addEdge(vArray, 4, 1, 15);
	addEdge(vArray, 4, 5, 20);
	addEdge(vArray, 7, 8, 25);
	addEdge(vArray, 2, 5, 25);
	addEdge(vArray, 2, 3, 10);
	addEdge(vArray, 5, 6, 30);
	addEdge(vArray, 8, 6, 20);
	addEdge(vArray, 8, 9, 10);
	addEdge(vArray, 3, 10, 5);
	addEdge(vArray, 6, 10, 15);
	addEdge(vArray, 6, 9, 15);
	addEdge(vArray, 9, 10, 10);
	*/
	if (LOG_LEVEL >= 1) display(nodes, vArray);
	
	cout<<"Algorithm Output--\n";
	DinicsAlgorithm (nodes, vArray);
	delete [] vArray;
}
