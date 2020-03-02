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

void displayStack (int V, stack <int> &solution)
{
	stack <int> temp = solution;
	while (temp.empty() != true)
	{
		cout<<temp.top()<<" ";
		temp.pop();
	}
	cout<<endl;
}

void dfsRecur(vector <data> *revVArray, int node, bool *visited, stack <int> processed,
	int parent)
{
	debug (2, "\nProcessing: ", node, " with parent", parent, "\n");
	debug (1, node, "\n");
	
	processed.push(node);
	visited[node] = true;
	
	for (auto x : revVArray[node])
	{
		if (visited[x.node] == false)
		{
			debug(2, x.node, " not visited, visiting..\n");
			dfsRecur(revVArray, x.node, visited, processed, node);
		}
		else
		{
			debug(2, x.node, " already visited.\n");
		}	
	}
	
	debug (2, "Popping: ", node, " with parent: ", parent, "\n");
	processed.pop();
}

void dfsRecur(vector <data> *vArray, int node, bool *visited, stack <int> processed,
	int parent, stack <int> &solution)
{
	debug (2, "\nProcessing: ", node, " with parent", parent, "\n");
	debug (1, node, "\n");
	
	processed.push(node);
	visited[node] = true;
	
	for (auto x : vArray[node])
	{
		if (visited[x.node] == false)
		{
			debug(2, x.node, " not visited, visiting..\n");
			dfsRecur(vArray, x.node, visited, processed, node, solution);
		}
		else
		{
			debug(2, x.node, " already visited.\n");
		}	
	}
	
	debug (2, "Popping: ", node, " with parent: ", parent, "\n");
	
	debug (2, "Save to Solution Stack... ", node);
	solution.push(node);
	
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

int nextNodeToVisit(int V, bool *visited, stack<int> &solution)
{
	while (solution.empty() != true)
	{
		if (visited[solution.top()] == true)
			solution.pop();
		else
			return solution.top();
	}
	return -1;
}

void populateRevGraph(int V, vector<data> *vArray, vector<data> *revVArray) 
{
	for (int i=0; i<V; i++)
	{
		debug(3, "Evaluating node.. ", i, "\n");
		for (auto x : vArray[i])
			addEdge(revVArray, x.node, i);
	}
}

void dfs(int V, vector <data> *vArray)
{
	int i;
	int src = 0;
	
	bool *visited = new bool[V];
	for (i = 0; i < V; i++)
		visited[i] = false;
		
	stack <int>  processed;
	stack <int>  solution;
	
	int toVisit = src;
	while (true)
	{
		dfsRecur(vArray, toVisit, visited, processed, toVisit, solution);
		toVisit = whichNodeNotVisited(V, visited);
		if (toVisit == -1)
			break;
		debug (2, toVisit, ", not visited, Re-running dfs\n");
	}
	
	debug(1, "\nSolution Stack: ");
	if (LOG_LEVEL >= 1) displayStack(V, solution);
	debug(1,"");
	
	// Make a reverse graph & process it
	
	vector <data> *revVArray; 
	initVArray(V, &revVArray);
	
	populateRevGraph(V, vArray, revVArray);	
	
	debug(1, "Reverse Graph...\n");
	if (LOG_LEVEL >= 1) display(V, revVArray);
	
	for (i = 0; i < V; i++)
		visited[i] = false;
	
	int noOfStronglyConneected = 0;
	toVisit = solution.top();
	solution.pop();
	while (true)
	{
		debug (2, toVisit, " at stack top, running dfs");
		dfsRecur(revVArray, toVisit, visited, processed, toVisit);
		noOfStronglyConneected++;
		toVisit = nextNodeToVisit(V, visited, solution);
		if (toVisit == -1)
			break;
	}	
	debug (1, "Strongly Connected Components: ", noOfStronglyConneected);
	
	delete [] visited;
}

int main()
{
	// Resource 
	// 
	// Youtube Kosaraju's Algo
	// https://www.youtube.com/watch?v=RpgcYiky7uw
	
	// Process
	// FOR DIRECTED GRAPH
	// Firstly process the graph, basically dfs traverse
	// the only difference being stored poped elements in seperate solution stack
	//
	// Now we reverse the edges of the graph
	// and start dfs traversal from the topost element of the solution stack
	// if any element of the solution stack has already been visited, obviously
	// 	don't traverse from it
	// 
	// the number of times we have to end the reverse graph traversal and go again siting
	// 	avaialbe nodes in the solution stack, that is the number of strongly conncected 
	// 	elements
	
	// Complexity 
	// O (V+E)x2 
	
	// GRAPHS
	// Inline
	
	LOG_LEVEL = 1;
	
	int nodes = 8;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	
	// EX 0
	// 1 -> 0 -> 3
	// ^  / 	 |
	// | v		 v
	// 2		4
	/*
	addEdge(vArray, 0, 2);	
	addEdge(vArray, 0, 3);
	addEdge(vArray, 1, 0);
	addEdge(vArray, 2, 1);
	addEdge(vArray, 3, 4);
	*/
	
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
