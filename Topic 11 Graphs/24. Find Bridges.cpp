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
	data d;
	d.node = b;
	vArray[a].push_back(d);
	
	d.node = a;
	vArray[b].push_back(d);
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
			if (x.node != parent)
			{
				/*if (det[node].low > det[x.node].low)
				{
					debug (2, "Low is higher for current node, reassigning..");
					
					debug (2, det[node].low, "->");
					debug (2, det[x.node].low); 
					det[node].low = det[x.node].low;
				}
				*/
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
	else if (det[node].low > det[parent].disc_time)
	{
		debug(1, "Bridge Found: ", parent, true);        
		debug(1, ":", node);
	}
	processed.pop();
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
	
	dfsRecur(vArray, src, visited, processed, disc_time, low, det, src);
	
	debug(1, "\nFinal Details");
	for (int i=0; i<V; i++)
	{
		debug(1, i, " (");
		debug(1, det[i].disc_time, ",");
		debug(1, det[i].low, ")\n");
	}
	debug(2, "\n\nDFS ended.");
	delete [] visited;
	delete [] det;
}

int main()
{
	// Resource 
	// <Read between the lines>
	// https://www.geeksforgeeks.org/bridge-in-a-graph/
	
	// Detailed - https://www.youtube.com/watch?v=aZXi1unBdJA
	
	// Process
	// Every thing will take place in a recursive loop as we are  DFS traversing
	// Every node has a discovery time and low
	// Node which are pushed to the stack and visited are given a 
	// 		new discovery time and low (basically a new value(++ the previous ones))
	// Th main logic takes place in 3 if statements
	// When some connected already visiting node is found
	// 		if some connected node (which is not the parent) has a low value 
	// 			lower than the current node, then the current node is also assigned 
	//				that low value
	// When a node is about to be popped from the stack, two checks are performed
	// 	If low[node] < disc_time[parent]
	// 		then det[parent].low = det[node].low;
	//	If low[node] > disc_time[parent]
	//		then a bridge has been found
	
	// Bridges are usually serched for in undirected graphs, because 
	//  finding bridges in directed graphs is a slightly 
	//  more complicated process and out of our scope
	
	// Complexity 
	// O (V+E)
	
	// GRAPH
	// Ex 1 GFG https://media.geeksforgeeks.org/wp-content/cdn-uploads/Bridge1.png
	// Ex 2 William Fest's video https://www.youtube.com/watch?v=aZXi1unBdJA (13:00 ish)
	
	LOG_LEVEL = 2;
	
	int nodes = 6;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	
	// EX 1
	/*
	addEdge(vArray, 0, 1);	
	addEdge(vArray, 0, 3);
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 0);
	addEdge(vArray, 3, 4);
	*/
	// Ex 2
	/*
	addEdge(vArray, 0, 1);
	addEdge(vArray, 0, 2);
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 3);
	addEdge(vArray, 2, 5);
	addEdge(vArray, 3, 4);
	addEdge(vArray, 5, 6);
	addEdge(vArray, 6, 7);
	addEdge(vArray, 7, 8);
	addEdge(vArray, 8, 5);
	*/
	// Ex 3
	//  1 \	  /	3
	//	|	0 	|
	//  2 /	  \	4
	/*
	addEdge(vArray, 0, 1);
	addEdge(vArray, 0, 2);
	addEdge(vArray, 0, 3);
	addEdge(vArray, 0, 4);
	addEdge(vArray, 1, 2);
	addEdge(vArray, 3, 4);
	*/
	addEdge(vArray, 0, 1);
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 3);
	addEdge(vArray, 3, 0);
	addEdge(vArray, 2, 4);
	addEdge(vArray, 2, 5);
	addEdge(vArray, 4, 5);
	
	if (LOG_LEVEL >= 1) display(nodes, vArray);
	
	debug(1, "DFS\n");
	dfs(nodes, vArray);
	
	delete [] vArray;
}
