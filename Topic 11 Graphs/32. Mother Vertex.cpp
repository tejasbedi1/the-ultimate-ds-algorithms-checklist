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
	
	// Traversal done once lets see is supspect can traverse all
	debug (1, "Suspected Mother Vertex: ", solution.top(), "\n");
	
	for (i = 0; i < V; i++)
		visited[i] = false;
	
	dfsRecur(vArray, solution.top(), visited, processed, solution.top());
	
	if (whichNodeNotVisited(V, visited) == -1)
		debug(1, "Confirmed Mother Vertex, ", solution.top(), 
			" and its strongly connected components\n");
	else
		debug(1, "Suspect is not the Mother Vertex, hence no mother vertex found..\n");
	
	// Make a reverse graph & process it to find strongly connected components
	
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
	// Youtube Kosaraju's Algo [PREREQUISITE]
	// https://www.youtube.com/watch?v=RpgcYiky7uw
	
	// Process
	// FOR DIRECTED GRAPH
	//
	// [ASSUMING A FULLY CONNECTED GRAPH]
	// 
	// We follow the process similiar to that of Kosaraju's algorithm
	// fully dfs a graph and store popped vertex's in a solution stack
	// 
	// The topmost element is the supspected mother
	// Cobnfirm it by traversing the whole graph with it as source
	// if the whole graph is traversed its and its strongly connected components
	// 	are the mothers
	// if not oh-well, we tried
	// 
	// The basis of the theory is that:
	// 	- if multiple strongly connected components exist then they should be
	// 		a single component
	//  - if no mother vertex's exist then the conrimtion stage will point it out 
	// 	- and if one exists then the confirmation stage will point it out, again
	
	// Complexity 
	// O (V+E)x3 
	
	// GRAPHS
	// Inline
	
	LOG_LEVEL = 1;
	
	int nodes = 9;
	
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
	/*
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
	*/
	
	// Ex 3
	//  0 < 2 	3 < 4 
	//  v ^	 ^ v  v	^
	//  1 	  6		5
	// 		 v ^  
	// 		7 > 8
	addEdge(vArray, 0, 1);
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 0);
	
	addEdge(vArray, 3, 5);
	addEdge(vArray, 5, 4);
	addEdge(vArray, 4, 3);
	
	addEdge(vArray, 6, 7);
	addEdge(vArray, 7, 8);
	addEdge(vArray, 8, 6);
	
	//addEdge(vArray, 2, 6);
	addEdge(vArray, 6, 2);
	addEdge(vArray, 3, 6);
	
	
	if (LOG_LEVEL >= 1) display(nodes, vArray);
	
	debug(1, "DFS\n");
	dfs(nodes, vArray);
	
	delete [] vArray;
}
