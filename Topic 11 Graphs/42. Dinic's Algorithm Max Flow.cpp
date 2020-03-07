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

void displayStack (stack <data> &stk)
{
	cout<<"Displaying Stack...\n";
	stack <data> temp = stk;
	while (temp.empty() != true)
	{
		cout<<"("<<temp.top().nodeA<<","<<temp.top().nodeB<<") ";
		temp.pop();
	}
	cout<<endl;
}

void displayQueue (queue <data> &que)
{
	cout<<"Displaying Queue...\n";
	queue <data> temp = que;
	while (temp.empty() != true)
	{
		cout<<"("<<temp.front().nodeA<<","<<temp.front().nodeB<<") ";
		temp.pop();
	}
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
			// Forward Edge
			if (x.capacity != 0) 
			{
				// If connection is possible
				if (x.capacity-x.currentFlow > 0)
				{
					// Unvisited
					if (levels[x.nodeB] == -1)
					{
						que.push(x.nodeB);
						levels[x.nodeB] = 1 + levels[x.nodeA];
						x.state = 'e';
					}
					else
					{
						if (levels[x.nodeA] < levels[x.nodeB])
							x.state = 'e';
						else
							x.state = 'd';
					}
				}
				else
					x.state = 'd';
			}
			// Backard Edge
			else 
			{
				// If connection is possible
				if (x.currentFlow > 0)
				{
					// Unvisited
					if (levels[x.nodeB] == -1)
					{
						que.push(x.nodeB);
						levels[x.nodeB] = 1 + levels[x.nodeA];
						x.state = 'e';
					}
					else
					{
						if (levels[x.nodeA] < levels[x.nodeB])
							x.state = 'e';
						else
							x.state = 'd';
					}
				}
				else
					x.state = 'd';
			}	
		}
		que.pop();
	}
}

bool findPathDFS(int V, vector <data> *vArray, stack <int> &stk, int node, int sink,
	stack <data> &path)
{
	debug (3, "Path Finding...\n");
	bool pathFound = false;
	
	for (auto x: vArray[node])
	{
		if (x.state == 'e')
		{
			// Forward edge
			if (x.capacity != 0)
			{
				if (x.currentFlow < x.capacity)
				{
					debug(3, " Pushing- ", "(", x.nodeA, ",", x.nodeB, ")", "\n");
					path.push(x);
					if (x.nodeB == sink)
						pathFound = true;
					else if (findPathDFS(V, vArray, stk, x.nodeB, sink, path))
						pathFound = true;
					else
					{
						debug(3, " Popping\n");
						path.pop();
					}
						
				}
			}
			// Residual edge
			else if (x.capacity == 0)
			{
				if (x.currentFlow > 0)
				{
					debug(3, " Pushing- ", "(", x.nodeA, ",", x.nodeB, ")", "\n");
					path.push(x);
					if (x.nodeB == sink)
						pathFound = true;
					else if (findPathDFS(V, vArray, stk, x.nodeB, sink, path))
						pathFound = true;
					else
					{
						debug(3, " Popping\n");
						path.pop();
					}
						
				}
			}
			
			if (pathFound == true)
				return true;
		}
	}
	return false;
}

int findMinCapacity(stack <data> stk)
{
	data edgeData;
	int minCap = INT_MAX;
	while (stk.empty() != true)
	{
		edgeData = stk.top();
		// FRONT EDGE
		if (edgeData.capacity != 0)
		{
			if (minCap > (edgeData.capacity - edgeData.currentFlow))
				minCap = edgeData.capacity - edgeData.currentFlow;
		}
		// RESIDUAL 
		else if (edgeData.capacity == 0)
		{
			if (minCap > edgeData.currentFlow)
				minCap = edgeData.currentFlow;
		}
		stk.pop();
	}
	return minCap;
}

int modifyAllEdges(int V, vector <data> *vArray, stack <data> &stk, int minCapacity)
{
	data edgeData;
	while (stk.empty() != true)
	{
		edgeData = stk.top();
		for(data &x: vArray[edgeData.nodeA])
		{
			if (x.nodeB == edgeData.nodeB)
			{
				// Forward Edge
				if (x.capacity != 0)
				{
					x.currentFlow += minCapacity;
					for (data &y: vArray[edgeData.nodeB])
						if (y.nodeB == edgeData.nodeA)
							y.currentFlow += minCapacity;
				}
				// Residual 
				else if (x.capacity == 0)
				{
					x.currentFlow -= minCapacity;
					for (data &y: vArray[edgeData.nodeB])
						if (y.nodeB == edgeData.nodeA)
							y.currentFlow -= minCapacity;
				}
			}
		}
		stk.pop();
	}
}

void DinicsAlgorithm(int V, vector <data> *vArray)
{
	int i;
	int src = 0;
	int sink = 5;
	int minCapacity;
	int flow = 0;
	
	int *levels;
	levels = new int[V];
	
	while (true)
	{
		for (i=0; i<V; i++)
			levels[i] = -1;
		
		// Consruct a Level graph easy, it is, We will do it BFS's ly
		assignLevels(V, vArray, levels);
		if (LOG_LEVEL >= 2) displayArray (V, levels);
		if (LOG_LEVEL >= 2) displayState(V, vArray);
		
		if (levels[sink] == -1)
			break;
			
		// Next using edges that are enabled find paths dfs'ly
		stack <int> stk;
		stack <data> path;
		stk.push(src);
		
		while (findPathDFS(V, vArray, stk, src, sink, path))
		{
			debug (2, "Chosen Path...\n");
			if (LOG_LEVEL >= 2) displayStack(path);
			
			// Walk the selected path & Find minimum capacity
			minCapacity = findMinCapacity(path);
			flow += minCapacity;
			debug (2, "Max Capacity of Path: ", minCapacity, "\n");
			
			// Remove that capacity from all involved edges
			modifyAllEdges(V, vArray, path, minCapacity);
			if (LOG_LEVEL >= 2) display(V, vArray);	
			//break;	
		}
	}
	debug(1, "MAXFLOW: ", flow,"\n");
	delete [] levels;
}

int main()
{
	// LIMITATION 
	// One of the pitfalls of the current implementation of Dinic's 
	//  algorithm at the moment is that the algorithm may encounter 
	//  multiple dead ends during the DFS phase
	// This can be fixed by making sure that it does not check
	//  dead end multiple times
	// RESOURCE: https://www.youtube.com/watch?v=M6cm8UeeziI&t=574s
	//
	// Also, just my observation
	// According the code its a good thing when the edge flow is from a smaller to higher
	//  level. However what if the sink node is at a lower level? if the code takes
	//  longer route its counter productive na
	
	// Resource 
	// GFG - https://www.geeksforgeeks.org/dinics-algorithm-maximum-flow/
	// Hacker Earth - https://www.hackerearth.com/practice/algorithms/graphs/maximum-flow/tutorial/
	// Detailed YT - https://www.youtube.com/watch?v=M6cm8UeeziI
	// Visualize - https://visualgo.net/en/maxflow
	
	// Process
	// The working of this algorithm than its slower counterparts
	// So, needless to say know them before you start this
	// 
	// Okay so the entire proeses here depends on LEVELS
	// Each node is assigned a level which increases as we traverse each layer
	// FIRST ,
	// Assign levels, Depending on the edge. If the edge has the capacity to carry anthing
	//  then a level is assigned to it. During the level assigning process edges are 
	//  also enabled OR disabled. That is done depending on if progress is made to 
	//  a higher level AND if the edges have the capacity to carry stuff
	// 
	// Then we find path depending on the enabled edges
	// Then find the max capacity that can be supoorted by the path
	// Modify all edges with that value
	// and find other eligible paths. 
	// 
	// LEvel assigning and path finding will continue till the sink cannot be reached.
	
	// Complexity 
	// Combionation of BFS & DFS O(V^2E)
	// For Bipartite Graph its O(sqrRoot(VE)) 
	// (Resource https://www.youtube.com/watch?v=M6cm8UeeziI&t=104s)
	
	// GRAPH
	// Ex 1 GFG https://media.geeksforgeeks.org/wp-content/uploads/Dinicalgorithm.png
	// Ex 2 Hacker https://he-s3.s3.amazonaws.com/media/uploads/6bf2e0d.png
	// Ex 3 In directory
	
	LOG_LEVEL = 1;
	
	int nodes = 11;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	
	// GFG
	// Src 0 Sink 5 | MAX FLOW 19
	/*
	addEdge(vArray, 0, 1, 10);
	addEdge(vArray, 0, 2, 10);
	addEdge(vArray, 1, 3, 4);
	addEdge(vArray, 1, 4, 8);
	addEdge(vArray, 1, 2, 2);
	addEdge(vArray, 2, 4, 9);
	addEdge(vArray, 4, 3, 6);
	addEdge(vArray, 3, 5 ,10);
	addEdge(vArray, 4, 5, 10);
	*/
	
	// Hacker earth
	// Src S,0 Sink T,5 | MAX FLOW 17
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
	// SRC 0 Sink 10 | Max Flow: 30
	
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
	addEdge(vArray, 5, 7, 5);
	addEdge(vArray, 8, 6, 20);
	addEdge(vArray, 8, 9, 10);
	addEdge(vArray, 3, 10, 5);
	addEdge(vArray, 6, 2, 15);
	addEdge(vArray, 6, 10, 15);
	addEdge(vArray, 6, 9, 15);
	addEdge(vArray, 9, 10, 10);
	
	if (LOG_LEVEL >= 1) display(nodes, vArray);
	
	cout<<"Algorithm Output--\n";
	DinicsAlgorithm (nodes, vArray);
	delete [] vArray;
}
