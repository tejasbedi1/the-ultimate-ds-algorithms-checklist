#include <bits/stdc++.h>
#include <iostream>
#include "extrasV3.h"

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

void initVArray (int V, vector <bool> **vBArray)
{
	*vBArray = new vector <bool>[V];
}

void showPathRecur(vector <data> *vArray, vector <bool> *vBArray, stack <int> &stk, 
	vector <int> &path, int node)
{
	debug(3, "Processing, pushing to stack ", node, "\n");
	stk.push(node);
	for (auto x: vArray[node])
	{
		if (vBArray[node][x.node] == false)
		{
			vBArray[node][x.node] = true;
			vBArray[x.node][node] = true;
			debug(2, "Edge: ", node, "-", x.node," not visited yet, visiting...\n");
			showPathRecur(vArray, vBArray, stk, path, x.node);
		}
	}
	
	path.push_back(stk.top());
	debug(2, "Popping & Adding to Path ", node, "\n");
	stk.pop();
}

void showPath(int V, vector <data> *vArray, int src)
{
	debug(2, "Calculating Path...\n");
	// Making an array of pointers to a vector boolean array
	// The array checks if an edge has been used up or not already
	vector <bool> *vBArray; 
	initVArray(V, &vBArray);
	
	for (int i=0; i<V; i++)
	{
		for (auto x : vArray[i])
		{
			vBArray[i].push_back(false);	
		}	
	}
	/*
	for (int i=0; i<V; i++)
	{
		debug(1, i, "- ");
		for (auto x : vBArray[i])
		{
			debug(1, x, " ");
		}	
		debug(1, "\n");
	}
	*/
	
	stack <int> stk;
	vector <int> path;
	
	showPathRecur(vArray, vBArray, stk, path, src);
	
	debug(1, "Final Path- ");
	for (int x : path)
	{
		debug(1, x, " ");
	}
	debug(1, "\n");
	
	delete [] vBArray;
}

void dfsRecur(int V, vector <data> *vArray, stack <int> &dataStk, 
	bool *visited, int *degrees, int node)
{
	dataStk.push(node);
	
	debug(1,dataStk.top(),"\n");
	visited[node] = true;
	node = dataStk.top();
	
	for (auto x : vArray[node])
	{
		if (visited[x.node] == false)
		{
			degrees[node]++;
			dfsRecur(V, vArray, dataStk, visited, degrees, x.node);
		}
		else
			degrees[node]++;
	}
	
	dataStk.pop();
}

void dfs(int V, vector <data> *vArray)
{
	int src = 0;
	
	bool *visited;
	visited = new bool[V];
	for (int i=0; i<V; i++)
		visited[i] = false;
	
	stack <int> dataStk;
	
	int *degrees;
	degrees = new int[V];
	for (int i=0; i<V; i++)
		degrees[i] = 0;
	
	dfsRecur(V, vArray, dataStk, visited, degrees, src);
	debug(1,"\n");
	
	debug(2,"Degree Data:\n");
	for (int i=0; i<V; i++)
		debug(2, "(", i, ",", degrees[i], ") ");
	debug(2,"\n");
	
	int oddCount = 0;
	debug(2,"Checking for Path & Curcuit\n");
	for (int i=0; i<V; i++)
	{
		if (degrees[i] & 1)
		{
			debug(2,"Odd ");
			oddCount ++;
		}
		else
			debug(2,"Even ");
	}
	debug (2,"\n");
	
	for (int i=0; i<V; i++)
		visited[i] = false;
	if (oddCount == 0)
	{
		debug(1, "Eulerian Circuit & Path\n");
		showPath(V, vArray, src);
	}	
	else if (oddCount == 2)
	{
		debug(1, "Eulerian Path\n");
		// finding a odd degree vertex
		int node;
		for (int i=0; i<V; i++)
		{
			if (degrees[i] & 1)
			{
				node = i;
				break;
			}
		}
		showPath(V, vArray, node);
	}
	else
		debug(1, "Not a Eulerian Path or curcuit\n");
	
	delete [] visited;
	delete [] degrees;
}

int main()
{
	// Resource 
	// GFG
	// https://www.geeksforgeeks.org/eulerian-path-undirected-graph/
	
	// Process
	// REMEMBER ---
	// 	In an UNDIRECTED GRAPH 
	// 		Eulerian Path - Either every vertex has even degree or 
	//							exactly two vertices has odd degree
	// 		Eulerian Circuit - Every vertex has an even degree
	//  ALSO IF
	//  A graph has a eulerian curcuit then by default it also has a path, duh 
	// ------------
	// Everything here is about the edges , 
	// WE Will TRACK EDGES
	// Bacically traverse the graph from the edges and keep marking them as 
	// Visited, pop the formed stack as it happens normally in DFS 
	// While poping keep adding to path 
	
	// Complexity 
	// O (E)
	
	// GRAPH
	// In comments
	
	LOG_LEVEL = 1;
	
	int nodes = 6;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	
	// EX 1
	// 1 - 0 - 3
	// | /	   |
	// 2  	   4
	/*
	addEdge(vArray, 0, 1);	
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 0);
	addEdge(vArray, 0, 3);
	addEdge(vArray, 3, 4);
	*/
	// Ex 2
	// 1 - 0 - 3
	// | /	\  |
	// 2  	   4
	/*
	addEdge(vArray, 0, 1);	
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 0);
	addEdge(vArray, 0, 3);
	addEdge(vArray, 3, 4);
	addEdge(vArray, 4, 0);
	*/
	// Ex 3
	// 0 -	1	
	// |	|
	// 3 -	2 4
	//		5
	
	addEdge(vArray, 0, 1);
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 3);
	addEdge(vArray, 3, 0);
	addEdge(vArray, 2, 4);
	addEdge(vArray, 2, 5);
	addEdge(vArray, 4, 5);
	
	// Ex 4
	//   ---------------
	//  |				|
	// 	1 	-	0 	-	3
	//  |	/			|
	// 	2				4
	// nodes = 5
	/*
	addEdge(vArray, 0, 1);	
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 0);
	addEdge(vArray, 0, 3);
	addEdge(vArray, 3, 4);
	addEdge(vArray, 1, 3);
	*/
	//addEdge(vArray, 0, 4);
	
	if (LOG_LEVEL >= 1) display(nodes, vArray);
	
	debug(1, "DFS\n");
	dfs(nodes, vArray);
	
	delete [] vArray;
}
