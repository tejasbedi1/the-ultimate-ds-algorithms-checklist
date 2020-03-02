#include <bits/stdc++.h>
#include <iostream>
#include "extras.h"

using namespace std;

struct data
{
	int nodeA;
	int nodeB;
	int capacity;
	int currentFlow;
};

struct pathData
{
	stack <int> path;
	int pathNo;
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
	d.currentFlow = 0;
	vArray[a].push_back(d);
	
	d.nodeA = b; 	// RESIDUAL EDGES
	d.nodeB = a; 
	d.capacity = 0;
	d.currentFlow = 0;
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
			cout<<x.nodeA<<","<<x.nodeB<<"("<<x.currentFlow<<","<<x.capacity<<")"<<" ";
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

void displayQueue (queue <pathData> &que)
{
	queue <pathData> temp = que;
	while (temp.empty() != true)
	{
		cout<<temp.front().pathNo<<": ";
		displayStack(temp.front().path);
		cout<<endl;
		
		temp.pop();
	}
}

void modifyAllEdges(vector <data> *vArray, stack <data> &stackData, int minCapacity )
{
	int nodeA;
	int nodeB;
	int i,j;
	data edge;
	data residualEdge;
	
	while (stackData.empty() == false)
	{
		nodeA = stackData.top().nodeA;
		nodeB = stackData.top().nodeB;
		for (i=0; i<vArray[nodeA].size(); i++)
		{
			if ( vArray[nodeA][i].nodeB == nodeB )
			{
				if ( vArray[nodeA][i].capacity != 0) // Normal Edge 
				{
					vArray[nodeA][i].currentFlow += minCapacity;
					for ( j=0; j<vArray[nodeB].size(); j++)
						if ( vArray[nodeB][j].nodeB == nodeA)
							vArray[nodeB][j].currentFlow += minCapacity;
				}
				else	// Residual Edge 
				{
					vArray[nodeA][i].currentFlow -= minCapacity;
					for ( j=0; j<vArray[nodeB].size(); j++)
						if ( vArray[nodeB][j].nodeB == nodeA)
							vArray[nodeB][j].currentFlow -= minCapacity;
				}
			}
		}
		stackData.pop();
	}
}

int findMinCapacity(stack <data> &stackData)
{
	int minCapacity = INT_MAX;
	stack <data> copy = stackData;
	
	while (copy.empty() == false)
	{
		if (copy.top().capacity != 0)		// Normal Edge
			if ( copy.top().capacity < minCapacity )
				minCapacity = copy.top().capacity;
		else if (copy.top().capacity == 0) // Resdual Edge
			if ( copy.top().currentFlow < minCapacity )
				minCapacity = copy.top().currentFlow;		
				
		copy.pop();
	}	
	return minCapacity;
}

void falsifyEverything(int V, bool *visited)
{
	for (int i=0; i<V; i++)
		visited[i] = false;
}

void populateStackWithEdgeData(vector <data> *vArray, stack <int> validPath,
	stack <data> &stackData)
{
	debug(2,"Sink Found, Populate this ..\n");
	if (LOG_LEVEL >= 2) displayStack(validPath);
	//cout<<endl;	
	
	// will have to do this backwards, such challenges 
	
	int secondNode = validPath.top();
	validPath.pop();
	
	while (validPath.empty() != true)
	{
		for (data x : vArray[validPath.top()])
		{
			if (x.nodeB == secondNode)
			{
				stackData.push(x);
				secondNode = validPath.top();
				validPath.pop();
			}
		}
	}
	if (LOG_LEVEL >= 2) displayEdgeData(stackData);
}

bool pathExists(int V, vector <data> *vArray, int src, int sink, bool *visited,
	stack <data> &stackData)
{
	debug(3,"Finding Path..\n");
	int pathNo = 0;
	int j;
	
	queue <pathData> que;
	
	pathData pd;
	pd.path.push(src);
	pd.pathNo = pathNo;
	visited[src] = true;
	
	que.push(pd);

	bool pathFound = false;
	
	while (que.empty() != true)
	{
		j = 0;
		pd = que.front();
		
		for (data x : vArray[pd.path.top()])
		{
			if (j == 0)
			{
				if (visited[x.nodeB] == false)
				{
					if ((x.capacity != 0 && x.currentFlow < x.capacity) ||
						(x.capacity == 0 && x.currentFlow != 0))
					{
						que.front().path.push(x.nodeB);
						visited[x.nodeB] = true;
						
						if (x.nodeB == sink)
						{
							pathFound = true;
							populateStackWithEdgeData(vArray, que.front().path, stackData);
							break;
						}
						
						j++;
					}
				}
			}
			else if (j > 0)
			{
				if (visited[x.nodeB] == false)
				{
					if ((x.capacity != 0 && x.currentFlow < x.capacity) ||
						(x.capacity == 0 && x.currentFlow != 0))
					{
						pathNo ++;
					
						pd.pathNo = pathNo;
						pd.path.push(x.nodeB);
						visited[x.nodeB] = true;
						que.push(pd);
						
						if (x.nodeB == sink)
						{
							pathFound = true;
							populateStackWithEdgeData(vArray, pd.path, stackData);
							break;
						}
						
						pd.path.pop(); 	// Pop cause if this loop runs again 
										// we need to input a fresh node 
						
						j++;
					}
				}
			}
		}
		// If J dosent change that would mean that no valid path exist
		// in the current queue
		if (j == 0)
			que.pop();
		debug(2,"After one while iteration..\n");
		if (LOG_LEVEL >= 2) displayQueue(que);
		if ( pathFound == true)
			break;
	}
	
	debug(3,"Path Finding Over..\n");
	if (pathFound == true)
		return true;
	else
		return false;	
}

void edmondsKarp(int V, vector <data> *vArray)
{
	int i;
	int src = 0;
	int sink = 5;
	int flow = 0;
	
	int minCapacity;
	
	bool *visited;
	visited = new bool[V];
	falsifyEverything(V, visited);
	
	// DATA OF THE FOUND PATH
	stack <data> stackData;
	
	while (pathExists(V, vArray, src, sink, visited, stackData))
	{
		debug(1, "Current Path\n");
		if (LOG_LEVEL >= 1) displayEdgeData(stackData);

		debug(1, "Calculating min possible Capacity\n");
		minCapacity = findMinCapacity(stackData);
		debug(1, "Min: ");
		debug(1, minCapacity, true);
		
		flow += minCapacity;
		modifyAllEdges(vArray, stackData, minCapacity);
		debug(1, "After Edge Modification\n");
		if (LOG_LEVEL >= 1) display(V, vArray);
		
		falsifyEverything(V, visited);
		//system("pause");
	}
	cout<<"Flow: "<<flow<<endl;
}

void modifyBackwardEdge(vector <data> *vArray, int a, int b, int c)
{
	int i;
	for (i=0; i<vArray[a].size(); i++)
	{
		if (vArray[a][i].nodeB == b)
		{
			vArray[a][i].currentFlow += c;
		}
	}
}

int main()
{
	// Resource 
	// <Read between the lines>
	// https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
	// https://brilliant.org/wiki/edmonds-karp-algorithm/
	
	// Detailed - https://www.youtube.com/watch?v=RppuJYwlcI8
	// Visualize - https://visualgo.net/en/maxflow
	
	// Process
	// Its simple
	// We need to loop until we can't find any more paths that connect source to sink
	// 
	// We need a Stack and a visited array
	// We'll store the path data in the stack
	//
	// The algorithm we use to spit out a possible path is based on BFS in edmonds karp
	// After a path has been decided, find min capacity for that path
	// Update flow on all the edges
	// Keep running until no more path found
	
	// Complexity 
	// O(|V|·|E|^2) 
	
	// GRAPH
	// Ex 1 GFG https://www.geeksforgeeks.org/wp-content/uploads/ford_fulkerson11.png
	// Ex 2 Hacker https://he-s3.s3.amazonaws.com/media/uploads/61e8b57.png
	
	LOG_LEVEL = 3;
	
	int nodes = 6;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	
	// GFG
	
	addEdge(vArray, 0, 1, 16);
	addEdge(vArray, 0, 2, 13);
	addEdge(vArray, 1, 2, 10);
	//addEdge(vArray, 2, 1, 4);
	modifyBackwardEdge(vArray, 2, 1, 4);
	addEdge(vArray, 1, 3, 12);
	addEdge(vArray, 2, 4, 14);
	addEdge(vArray, 3, 2, 9);
	addEdge(vArray, 4, 3 ,7);
	addEdge(vArray, 3, 5, 20);
	addEdge(vArray, 4, 5, 4);
	
	// Hacker earth
	/*
	addEdge(vArray, 0, 1, 10);
	addEdge(vArray, 0, 3, 8);
	addEdge(vArray, 1, 2, 5);
	addEdge(vArray, 1, 3, 2);
	addEdge(vArray, 3, 4, 10);
	addEdge(vArray, 2, 5, 7);
	addEdge(vArray, 4, 2, 8);
	addEdge(vArray, 4, 5 ,10);
	*/
	
	if (LOG_LEVEL >= 1) display(nodes, vArray);
	
	cout<<"Algorithm Output--\n";
	edmondsKarp(nodes, vArray);
	delete [] vArray;
}
