#include <bits/stdc++.h>
#include <iostream>
#include "extrasV2.h"

using namespace std;

struct data
{
	int node;
};

void initVArray (int V, vector <data> **vArray)
{
	*vArray = new vector <data>[V];
}

void addEdge(vector <data> *vArray, int a, int b)
{
	//DIRECTED
	data d;
	d.node = b;
	vArray[a].push_back(d);
}

void display (int V, vector <data> *vArray)
{
	int i;
	for (i=0; i<V; i++)
	{
		cout<<"Node "<<i<<"- ";
		for (auto x : vArray[i])
		{
			cout<<x.node<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

struct details
{
	int disc_time; 	// Discovery Time
	int low;	 	// LOW
};

bool checkInStack (stack <int> &processed, int node)
{
	// Check if node is present in stack 
	// if yes, true
	// else false
	stack <int> temp = processed;
	while (temp.empty() != true)
	{
		if (temp.top() != node)
			temp.pop();
		else
			return true;
	}
	return false;
}

void dfsRecur(vector <data> *vArray, int node, bool *visited, stack <int> processed,
	int &disc_time, int &low, details *det, int parent)
{
	debug (2, "\nProcessing", node, ": ", true);
	debug (2, " with parent ", parent, ": ");
	
	processed.push(node);
	visited[node] = true;
	
	det[node].disc_time = disc_time;
	det[node].low = low;
	
	debug(1, node, " (");
	debug(1, disc_time, ",");
	debug(1, low, ")\n");
	
	disc_time++; low++;
	
	for (auto x : vArray[node])
	{
		if (visited[x.node] == false)
		{
			debug(2, x.node, " not visited, visiting..\n");
			dfsRecur(vArray, x.node, visited, processed, disc_time, low, det, node);
		}
		else
		{
			debug(2, x.node, " already visited.\n");	
			// NO NEED CAUSE DIRECTED
			// if (x.node != parent) 
			if(checkInStack(processed, x.node))
			{
				if (det[node].low > det[x.node].disc_time)
				{
					debug (2, "Low is higher for current node, reassigning..");
					
					debug (2, det[node].low, "->");
					debug (2, det[x.node].disc_time);
					det[node].low = det[x.node].disc_time;
				}
			}
		}	
	}
	
	debug (2, "Popping", node, ": ", true);
	debug (2, " with parent ", parent, ": ");
	
	debug (3, "det[parent].disc_time: ", det[parent].disc_time);
	debug (3, "det[node].low: ", det[node].low);
	
	if (det[node].low < det[parent].disc_time)
	{
		debug(2, "Low of node, less than parent's discovery time, reassigning parents low..");
		debug (2, det[parent].low, "->");
		debug (2, det[node].low); 
		det[parent].low = det[node].low;
	}
	
	processed.pop();
}

int whichNodeNotVisited(int V, bool *visited)
{
	for(int i=0; i<V; i++)
	{
		if (visited[i] == false)
			return i;
	}
	return -1;
}

void dfs(int V, vector <data> *vArray)
{
	int i;
	int src = 0;
	
	bool *visited = new bool[V];
	for (i = 0; i < V; i++)
		visited[i] = false;
		
	stack <int> processed;
	
	details *det;
	det = new details[V];
	
	int disc_time = 0;
	int low = 0;
	
	int toVisit = src;
	while (toVisit != -1)
	{
		dfsRecur(vArray, toVisit, visited, processed, disc_time, low, det, toVisit);
		toVisit = whichNodeNotVisited(V, visited);
		debug (2, toVisit, ", not visited, Re-running dfs\n");
	}
		
	// CHECK IF ALL VISITED
	
	debug(1, "\nFinal Details");
	for (int i=0; i<V; i++)
	{
		debug(1, i, " (");
		debug(1, det[i].disc_time, ",");
		debug(1, det[i].low, ")\n");
	}
	
	unordered_set <int> uniqueLows;
	for (int i=0; i<V; i++)
	{
		if (uniqueLows.find(det[i].low) == uniqueLows.end())
			uniqueLows.insert(det[i].low);
	}
	debug (1, "Strongly Connected Components: ", uniqueLows.size());
	
	delete [] visited;
	delete [] det;
}

int main()
{
	// Resource 
	// If forgotten, do finding bridges first, you'll understand this as well
	// Youtube TARJANS ALGO 
	// https://www.youtube.com/watch?v=TyWtx7q2D7Y
	
	// Process
	// FOR DIRECTED GRAPH
	// The process is similar to how we find bridges
	// We need to assign DISC_TIME & LOWS to all nodes
	// The difference here is 
	// IF we see a already visited node with a lower low, we don't simply
	// 	take its low, we first check if it is present in the stack we are currently 
	// 	processing. 
	// 	Becuase if its not already present then it would mean that its part of some 
	// 	other strongly connected component.
	//
	// Also, when DFS'ing directed graphs we may find that the DFS is finished
	// but not all nodes are visited, So basically we check for all nodes being 
	// visited
	
	// Complexity 
	// O (V+E)
	
	// GRAPHS
	// Inline
	
	LOG_LEVEL = 1;
	
	int nodes = 8;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	
	// EX 1
	// 0 -> 1 -> 3
	// ^  / |	 |
	// | v  v    v
	// 2 -> 4 -> 5
	//        <-
	/*
	addEdge(vArray, 0, 1);	
	addEdge(vArray, 1, 2);
	addEdge(vArray, 1, 3);
	addEdge(vArray, 1, 4);
	addEdge(vArray, 2, 0);
	addEdge(vArray, 2, 4);
	addEdge(vArray, 3, 5);
	addEdge(vArray, 4, 5);
	addEdge(vArray, 5, 4);
	*/
	// Ex 2
	// 3 -> 4 <- 6 -> 2
	// |^   |  ^ |  / ^
	// v|   v /  v v  |
	// 7 -> 5 -> 0 -> 1
	
	addEdge(vArray, 0, 1);
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 0);
	addEdge(vArray, 3, 4);
	addEdge(vArray, 3, 7);
	addEdge(vArray, 4, 5);
	addEdge(vArray, 5, 0);
	addEdge(vArray, 5, 6);
	addEdge(vArray, 6, 0);
	addEdge(vArray, 6, 2);
	addEdge(vArray, 6, 4);
	addEdge(vArray, 7, 3);
	addEdge(vArray, 7, 4);
	
	
	if (LOG_LEVEL >= 1) display(nodes, vArray);
	
	debug(1, "DFS\n");
	dfs(nodes, vArray);
	
	delete [] vArray;
}
