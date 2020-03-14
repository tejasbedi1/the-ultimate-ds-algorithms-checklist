#include <bits/stdc++.h>
#include <iostream>
#include "extrasV3.h"

using namespace std;

struct EdgeData
{
	int nodeA;
	int nodeB;
};

void initVArray (int V, vector <EdgeData> **vArray)
{
	*vArray = new vector <EdgeData>[V];
}

void addEdge(vector <EdgeData> *vArray, vector <EdgeData> &vEdges, int a, int b)
{
	EdgeData d;
	d.nodeA = a;
	d.nodeB = b;
	vArray[a].push_back(d);
	
	vEdges.push_back(d);
	
	d.nodeA = b; 	// RESIDUAL EDGES
	d.nodeB = a;
	vArray[b].push_back(d);
}

void display (int V, vector <EdgeData> *vArray)
{
	cout<<"Graph Data...\n";
	int i;
	for (i=0; i<V; i++)
	{
		cout<<"Node "<<i<<"- ";
		for (auto x : vArray[i])
		{
			cout<<x.nodeA<<","<<x.nodeB<<" ";
		}
		cout<<endl;
	}
}

void displayEdges (vector <EdgeData> &vec)
{
	cout<<"Edges- \n";
	int i;
	for (i=0; i<vec.size(); i++)
	{
		cout<<"("<<vec[i].nodeA<<","<<vec[i].nodeB<<") ";
	}
}

struct Subset
{
	int parent;
	int rank;
};

// Find runs till parent is it'self
// Also path compression is also done, on the fly
int find(Subset *sub, int i)
{
	if (sub[i].parent != i)
		sub[i].parent = find(sub, sub[i].parent);
	
	return sub[i].parent;
}

void unionFunc(Subset *sub, int x, int y)
{
	int xRoot = find(sub, x);
	int yRoot = find(sub, y);
	
	if (sub[xRoot].rank < sub[yRoot].rank)
	{
		sub[xRoot].parent = yRoot;
	}
	else if (sub[xRoot].rank > sub[yRoot].rank)
	{
		sub[yRoot].parent = xRoot;
	}
	else
	{
		sub[yRoot].parent = xRoot;
		sub[xRoot].rank++;
	}
}

int Kargers(int V, vector <EdgeData> *vArray, vector <EdgeData> vEdge)
{
	int i;

	Subset *subset;
	subset = new Subset[V];
	for (i=0; i<V; i++)
	{
		subset[i].parent = i;
		subset[i].rank = 0;
	}
	
	int vertices = V;
	int E = vEdge.size();
	int subset1;
	int subset2;
	
	while (vertices > 2)
	{
		i = rand() % E;
		
		subset1 = find(subset, vEdge[i].nodeA);
		subset2 = find(subset, vEdge[i].nodeB);	
		
		if (subset1 == subset2)
			continue;
		
		else
		{
			debug(2, "Contracting Edge: ", vEdge[i].nodeA, "-", vEdge[i].nodeB, "\n");
			vertices--;
			unionFunc (subset, subset1, subset2);
		}
	}
	
	int remainingEdges = 0;
	
	for (i=0; i<E; i++)
	{
		subset1 = find(subset, vEdge[i].nodeA);
		subset2 = find(subset, vEdge[i].nodeB);
		
		if (subset1 != subset2)
			remainingEdges++;
	}
	
	delete [] subset;
	return remainingEdges;
}

int main()
{
	// LIMITATION 
	// The current implementation of the code essentially finds random edges 
	//  from a list of all possible edges. Some of these might we invalid
	//   but still it searches
	// This is devestating for larger graphs
	// So what do we do ?
	// Combining the random valid edge finding with hashing and removing of 
	//  non useful nodes will massively imporve performance
	
	// Resource 
	// GFG 1 Implementation https://www.geeksforgeeks.org/kargers-algorithm-for-minimum-cut-set-1-introduction-and-implementation/
	// GFG 2 Complexity Analysis https://www.geeksforgeeks.org/kargers-algorithm-for-minimum-cut-set-2-analysis-and-applications/
	// YT Problem Explanation https://www.youtube.com/watch?v=KqMGeNZuwfI
	
	// Process
	// This question was a bit odd
	// It took 8hrs to come up with complicated answers
	// But those v1, v2 were so complicated that had to leave them mid way
	// Didn't have so much time
	//
	// The resulting answer is inspired (copied) from Geeks for Geeks
	// Good Answer but has some glaring limiations
	//
	// Anyhoo 
	// The working is as follows 
	// Every node has a parent and a rank
	// A random edge is chosen. Depeding on the parent of the nodes of that edge
	// They are combined. If one node has a higher rank. The other becomes
	// its child.
	// Whenever two nodes are combined vertex count also reduces by 1
	// That is how we keep track of stuff
	// ..
	// Lastly we count the numebr of edges with differnt nodes 
	// (Seriously read the code though, i was tired while writing this...)
	
	// Complexity 
	// O (V^5) // Lack of 
	//
	// When the algorithm is run, the probablity of returning a accurate answer is 1/n^2
	// So we have to run it atlease n^2 times, i.e V^2
	//
	// There exists a variation of this algorthm which achieves U (v^2)
	// Good luck finding it
	
	// GRAPH
	// Ex -1 https://media.geeksforgeeks.org/wp-content/cdn-uploads/Kargerfirst.png
	// Ex 0 In Directory (43)
	// Ex 1 GFG https://media.geeksforgeeks.org/wp-content/uploads/Dinicalgorithm.png
	// Ex 2 Hacker https://he-s3.s3.amazonaws.com/media/uploads/6bf2e0d.png
	// Ex 3 In directory (42 No)
	
	LOG_LEVEL = 1;
	
	int nodes = 6;
	
	vector <EdgeData> *vArray; 
	vector <EdgeData> vEdges;
	
	initVArray(nodes, &vArray);
	
	// GFG 
	/*
	addEdge(vArray, vEdges, 0, 1);
	addEdge(vArray, vEdges, 0, 2);
	addEdge(vArray, vEdges, 0, 3);
	addEdge(vArray, vEdges, 1, 3);
	addEdge(vArray, vEdges, 2, 3);
	*/
	
	// YT 
	/*
	addEdge(vArray, vEdges, 0, 1);
	addEdge(vArray, vEdges, 0, 2);
	addEdge(vArray, vEdges, 1, 2);
	addEdge(vArray, vEdges, 2, 3);
	addEdge(vArray, vEdges, 2, 4);
	addEdge(vArray, vEdges, 4, 5);
	addEdge(vArray, vEdges, 5, 3);
	*/
		
	// GFG
	/*
	addEdge(vArray, vEdges, 0, 1);
	addEdge(vArray, vEdges, 0, 2);
	addEdge(vArray, vEdges, 1, 3);
	addEdge(vArray, vEdges, 1, 4);
	addEdge(vArray, vEdges, 1, 2);
	addEdge(vArray, vEdges, 2, 4);
	addEdge(vArray, vEdges, 4, 3);
	addEdge(vArray, vEdges, 3, 5);
	addEdge(vArray, vEdges, 4, 5);
	*/
	
	// Hacker earth
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
	addEdge(vArray, 5, 7, 5);
	addEdge(vArray, 8, 6, 20);
	addEdge(vArray, 8, 9, 10);
	addEdge(vArray, 3, 10, 5);
	addEdge(vArray, 6, 2, 15);
	addEdge(vArray, 6, 10, 15);
	addEdge(vArray, 6, 9, 15);
	addEdge(vArray, 9, 10, 10);
	*/
	
	if (LOG_LEVEL >= 1) display(nodes, vArray);
	if (LOG_LEVEL >= 1) displayEdges(vEdges);
	debug (1,"\n\n");
	
	cout<<"Algorithm Output--\n\n";
	
	//debug(1, Kargers (nodes, vArray, vEdges));

	int minCut = INT_MAX, temp;
	
	for (int i=0; i<nodes*nodes; i++)
	{
		temp = Kargers (nodes, vArray, vEdges);
		if (temp < minCut)
			minCut = temp;
	}
	debug (1, "Min Cut: ", minCut,"\n");

	delete [] vArray;
}
