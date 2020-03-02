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
		debug(1, "Eulerian Path\n");
	else
		debug(1, "Eulerian Circuit & Path\n");
	
	delete [] visited;
	delete [] inOut;
}

int main()
{
	// Resource 
	// GFG
	// https://www.geeksforgeeks.org/euler-circuit-directed-graph/
	// BEST EXPLANATION
	// https://www.youtube.com/watch?v=xR4sGgwtR2I
	// Printing the path - Dont follow it too closely its a bit loose
	// https://www.youtube.com/watch?v=8MpoO2zA2l4
	// Printing the path is covered in later implementations
	
	// Process
	// In an DIRECTED GRAPH 
	// Eulerian Path - At most 
	//					One Vertex has (out - in = 1)
	//					One Vertex has (in - out = 1)
	//					All other have equal (in & out)
	// Eulerian Circuit - Every vertex has equal inDegree and OutDegree
	
	// Complexity 
	// O (E)
	
	// GRAPH
	// In comments 
	
	LOG_LEVEL = 1;
	
	int nodes = 5;
	
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
	*/
	// Ex 2
	// 1 <- 0 <- 3
	// v >	  > ^
	// 2  	   4
	
	addEdge(vArray, 0, 1);	
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 0);
	addEdge(vArray, 0, 4);
	addEdge(vArray, 4, 3);
	addEdge(vArray, 3, 0);
	
	// Ex 3
	// 0 -	1	
	// |	|
	// 3 -	2 4
	//		5
	/*
	addEdge(vArray, 0, 1);
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 3);
	addEdge(vArray, 3, 0);
	addEdge(vArray, 2, 4);
	addEdge(vArray, 2, 5);
	addEdge(vArray, 4, 5);
	*/
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
	if (LOG_LEVEL >= 1) display(nodes, vArray);
	
	debug(1, "DFS\n");
	dfs(nodes, vArray);
	
	delete [] vArray;
}
