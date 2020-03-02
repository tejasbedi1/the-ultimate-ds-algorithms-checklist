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
	
	//d.node = a;
	//vArray[b].push_back(d);
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
	
	stack <int> stk;
	vector <int> path;
	
	showPathRecur(vArray, vBArray, stk, path, src);
	
	debug(1, "Final Path- ");
	// Run it ulta baby
	for (int i=path.size()-1; i>=0; i--)
	{
		debug(1, path[i], " ");
	}
	debug(1, "\n");
	
	delete [] vBArray;
}

struct InOutDetails
{
	int in;
	int out;
};

void dfsRecur(int V, vector <data> *vArray, stack <int> &dataStk, 
	bool *visited, InOutDetails *inOut, int node)
{
	dataStk.push(node);
	
	debug(1,dataStk.top(),"\n");
	visited[node] = true;
	node = dataStk.top();
	
	for (auto x : vArray[node])
	{
		if (visited[x.node] == false)
		{
			inOut[node].out++;
			inOut[x.node].in++;	
			dfsRecur(V, vArray, dataStk, visited, inOut, x.node);
		}
		else
		{
			inOut[node].out++;
			inOut[x.node].in++;
		}
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
	
	InOutDetails *inOut;
	inOut = new InOutDetails[V];
	InOutDetails x;
	x.in = 0;
	x.out = 0;
	for (int i=0; i<V; i++)
		inOut[i] = x;
	
	dfsRecur(V, vArray, dataStk, visited, inOut, src);
	debug(1,"\n");
	
	debug(2,"Checking if all visited...\n");
	for (int i=0; i<V; i++)
	{
		if (visited[i] == false)
		{
			debug(1,"Disconnected Graph\n");
			return;
		}
	}
	
	debug(2,"InOut Data:\n");
	for (int i=0; i<V; i++)
		debug(2, i, "-", "(", inOut[i].in, ",", inOut[i].out,") ");
	debug(2,"\n");
	
	
	int higherIn = 0;
	int higherOut = 0;
	debug(3,"Checking for Path & Curcuit\n");
	for (int i=0; i<V; i++)
	{
		if (inOut[i].in != inOut[i].out)
		{
			if (inOut[i].in - inOut[i].out == 1)
				higherIn ++;
			else if (inOut[i].out - inOut[i].in == 1)
				higherOut ++;
			else
				higherIn = -1;
		}
		if (higherIn == -1)
			break;
	}
	
	if (higherIn == -1)
		debug(1, "Not a Eulerian Path or curcuit\n");
	else if (higherIn == 1 && higherOut == 1)
	{
		debug(1, "Eulerian Path\n");
		// In case of a path, just start with the node which has less incoming 
		// (there will only be one)
		int node;
		for (int i=0; i<V; i++)
		{
			if (inOut[i].out - inOut[i].in == 1)
				node = i;
		}
		showPath(V, vArray, node);	
	}
	else
	{
		debug(1, "Eulerian Circuit & Path\n");
		showPath(V, vArray, src);
	}
	delete [] visited;
	delete [] inOut;
}

int main()
{
	// Resource 
	// GFG
	// https://www.geeksforgeeks.org/hierholzers-algorithm-directed-graph/
	
	// Process
	// In an DIRECTED GRAPH 
	// Eulerian Path - At most 
	//					One Vertex has (out - in = 1)
	//					One Vertex has (in - out = 1)
	//					All other have equal (in & out)
	// Eulerian Circuit - Every vertex has equal inDegree and OutDegree
	//
	// NOTE 
	// Online its stated that this algorithm is used for directed graphs which 
	// have a cycle. This is true, however we are using an implementation of this
	// for undirected graphs as well. So, huh ...
	// 
	// Now it was'nt specifically mentioned anywhere on how to use this algo in 
	// case we have a euelerian path but not a circuit
	// 
	// In that case just take the starting node as the one which has 
	// Less in-degree and more out-degree
	// The pathing algo will automatically stop on the one which has a 
	// higher in-degree
	//
	// It also helps to know that if you connect there two together it forms a cycle
	// Complexity 
	// O (E)
	
	// GRAPH
	// In comments 
	
	LOG_LEVEL = 1;
	
	int nodes = 7;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	
	// EX 1
	// 1 <- 0 -> 3
	// v >	   	v
	// 2  	   4
	/*
	addEdge(vArray, 0, 1);	
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 0);
	addEdge(vArray, 0, 3);
	addEdge(vArray, 3, 4);
	addEdge(vArray, 4, 0);
	*/
	// Ex 2
	// 1 <- 0 <- 3
	// v >	  > ^
	// 2  	   4
	/*
	addEdge(vArray, 0, 1);	
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 0);
	addEdge(vArray, 0, 4);
	addEdge(vArray, 4, 3);
	addEdge(vArray, 3, 0);
	*/
	// Ex 3
	// 0 >	1	
	// ^	v
	// 3 <	2 > 4
	//		^ <
	//		5
	/*
	addEdge(vArray, 0, 1);
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 3);
	addEdge(vArray, 3, 0);
	addEdge(vArray, 2, 4);
	addEdge(vArray, 5, 2);
	addEdge(vArray, 4, 5);
	*/
	// Ex 4
	//  0<------5<------4
	//  | \			  >	^
	// 	| <	 - >6 -	/ /	|
	//  v  \---  <--/   |
	// 	1------>2------>3
	// nodes = 5
	
	addEdge(vArray, 0, 1);	
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 3);
	addEdge(vArray, 3, 4);
	addEdge(vArray, 4, 5);
	addEdge(vArray, 5, 0);
	addEdge(vArray, 0, 6);
	addEdge(vArray, 6, 4);
	//addEdge(vArray, 4, 2);
	addEdge(vArray, 2, 0);
	
	if (LOG_LEVEL >= 1) display(nodes, vArray);
	
	debug(1, "DFS\n");
	dfs(nodes, vArray);
	
	delete [] vArray;
}
