#include <bits/stdc++.h>
#include <iostream>
#include "extrasV3.h"

using namespace std;

struct data
{
	int nodeA;
	int nodeB;
};

void initVArray (int V, vector <data> **vArray)
{
	*vArray = new vector <data>[V];
}

void addEdge(vector <data> *vArray, vector <data> &vEdges, int a, int b)
{
	data d;
	d.nodeA = a;
	d.nodeB = b;
	vArray[a].push_back(d);
	
	vEdges.push_back(d);
	
	d.nodeA = b; 	// RESIDUAL EDGES
	d.nodeB = a; 
	vArray[b].push_back(d);
}

void display (int V, vector <data> *vArray)
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

struct Subset
{
	int parent;
	int rank;
};

void displaySubset (int size, Subset *sub)
{
	cout<<"Subsets- ";
	for (int i=0; i<size; i++)
		cout<<i<<" ("<<sub[i].parent<<","<<sub[i].rank<<") ";
	cout<<endl;
}


void displayVector (vector <data> &vec)
{
	cout<<"Edges- ";
	int i;
	for (i=0; i<vec.size(); i++)
	{
		cout<<"("<<vec[i].nodeA<<","<<vec[i].nodeB<<") ";
	}
	cout<<endl;
}

int returnRandomEdge (vector <data> &vEdge)
{
	int i;
	i = rand() % vEdge.size();
	debug (2, "Random Edge: (", vEdge[i].nodeA, ",", vEdge[i].nodeB, ")\n");
	return i;
}

void pointFromTo(vector <data> &vEdge, int b, int a)
{
	for (auto &x: vEdge)
	{
		if (x.nodeA == b)
		{
			x.nodeA = a;	
		}
		else if (x.nodeB == b)
		{
			x.nodeB = a;
		}	
	}	
}

int findUniqueSubsets(int size, Subset *subset)
{
	int i;
	int uniqueSubsetCount = 0;
	
	bool *subber;
	subber = new bool[size];
	for (i=0; i<size; i++)
		subber[i] = false;
			
	for (i=0; i<size; i++)
		if (subset[i].parent != -1)
			subber[subset[i].parent] = true;
		else // It itself is its parent
			subber[i] = true;
	
	for (i=0; i<size; i++)
		if (subber[i] == true)
			uniqueSubsetCount++;
	
	delete [] subber;
	return uniqueSubsetCount;
}

int find(Subset *sub, int i)
{
	if (sub[i].parent == -1)
		return i;
	find(sub, sub[i].parent);
}

void unionFunc(Subset *sub, int a, int b)
{
	int aPar = find (sub, a);
	int bPar = find (sub, b);
	
	if (aPar != bPar)
	{
		if (sub[bPar].rank >= sub[aPar].rank)
		{
			sub[aPar].parent = bPar;
			sub[bPar].rank += sub[aPar].rank + 1;
			debug (2, a, "'s parent ", aPar, " has been assigned a new parent ", bPar,
				"Because the former has a higher rank\n");
		}
		else
		{
			sub[bPar].parent = a;
			sub[aPar].rank += sub[bPar].rank + 1;
			debug (2, b, "'s parent ", bPar, " has been assigned a new parent ", aPar,
				"Because the former has a higher rank\n");
		}
	}
	else
	{
		// If this runs then it would also mean that .. 
	 	// a cycle was just detected
		cout<<" ..Hmmm, seems like both belong to the same subset i.e "<<bPar<<endl;
		cout<<"Nothing to do/see here, carry on.\n";
	}
}

int whichOneToPrefer(Subset *subset, int nodeA, int nodeB)
{
	//unionFunc(subset, nodeA, nodeB);
	if (subset[nodeA].parent == -1  && subset[nodeB].parent == -1)
	{
		debug(2, "Both dont have parents\n");
		if (subset[nodeA].rank >= subset[nodeB].rank)
		{
			debug(2, nodeA, " has a higher rank\n");
			subset[nodeB].parent = nodeA;
			subset[nodeA].rank++;	
			
			return 1; // Prefer First One
		}
		else
		{
			debug(2, nodeB, " has a higher rank\n");
			subset[nodeA].parent = nodeB;
			subset[nodeB].rank++;
			
			return 2; // Prefere Second One
		}
	}
	else if (subset[nodeA].parent != -1  && subset[nodeB].parent == -1)
	{
		cout<<"NodeA has a parent\n";
		unionFunc (subset, nodeB, nodeA); // Sending parentless first
	}
	else if (subset[nodeA].parent == -1  && subset[nodeB].parent != -1)
	{
		cout<<"NodeB has a parent\n";
		unionFunc (subset, nodeA, nodeB); // Sending parentless first
	}
	else if ( subset[nodeA].parent != -1  && subset[nodeB].parent != -1 )
	{
		cout<<"Both have parents\n";
		unionFunc (subset, nodeA, nodeB); // Any order
	}
}

int Kargers(int V, vector <data> *vArray, vector <data> vEdge)
{
	int i;
	Subset *subset;
	subset = new Subset[V];
	int chosenEdgePos;
	
	for (int i=0; i<V; i++)
	{
		subset[i].parent = -1;
		subset[i].rank = 0;
	}
	
	if (LOG_LEVEL >= 2) displayVector(vEdge);
	if (LOG_LEVEL >= 2) displaySubset(V, subset);
	debug (3, "\n");
	
	while (findUniqueSubsets(V, subset) > 2)
	{
		// Choose random Edge
		chosenEdgePos = returnRandomEdge(vEdge);
	
		// Contract Edge
		
		if (whichOneToPrefer(subset, vEdge[chosenEdgePos].nodeA, 
			vEdge[chosenEdgePos].nodeB) == 1)
		{
			//subset[vEdge[chosenEdgePos].nodeB] = subset[vEdge[chosenEdgePos].nodeA];
			pointFromTo(vEdge,vEdge[chosenEdgePos].nodeB, vEdge[chosenEdgePos].nodeA);	
			debug(2, "Removing position: ", chosenEdgePos, "\n");
			vEdge.erase(vEdge.begin() + chosenEdgePos);
		}
		else
		{
			//subset[vEdge[chosenEdgePos].nodeA] = subset[vEdge[chosenEdgePos].nodeB];
			pointFromTo(vEdge,vEdge[chosenEdgePos].nodeA, vEdge[chosenEdgePos].nodeB);
			debug(2, "Removing position: ", chosenEdgePos, "\n");
			vEdge.erase(vEdge.begin() + chosenEdgePos);
		}
			
		if (LOG_LEVEL >= 2) displayVector(vEdge);
		if (LOG_LEVEL >= 2) displaySubset(V, subset);
		debug (3, "\n");
	}
	
	debug (2, "Min Cut: ", vEdge.size(),"\n\n");
	
	delete [] subset;
	
	return vEdge.size();
}

int main()
{
	// LIMITATION 
	
	// Resource 
	
	// Process
	
	// Complexity 
	
	// GRAPH
	// Ex -1 https://media.geeksforgeeks.org/wp-content/cdn-uploads/Kargerfirst.png
	// Ex 0 In Directory (43)
	// Ex 1 GFG https://media.geeksforgeeks.org/wp-content/uploads/Dinicalgorithm.png
	// Ex 2 Hacker https://he-s3.s3.amazonaws.com/media/uploads/6bf2e0d.png
	// Ex 3 In directory (42 No)
	
	LOG_LEVEL = 2;
	
	int nodes = 4;
	
	vector <data> *vArray; 
	vector <data> vEdges;
	
	initVArray(nodes, &vArray);
	
	// GFG 
	addEdge(vArray, vEdges, 0, 1);
	addEdge(vArray, vEdges, 0, 2);
	addEdge(vArray, vEdges, 0, 3);
	addEdge(vArray, vEdges, 1, 3);
	addEdge(vArray, vEdges, 2, 3);
	
	
	// YT 
	/*
	addEdge(vArray, 0, 1, 10);
	addEdge(vArray, 0, 2, 13);
	addEdge(vArray, 1, 2, 3);
	addEdge(vArray, 2, 3, 7);
	addEdge(vArray, 2, 4, 6);
	addEdge(vArray, 4, 5, 10);
	addEdge(vArray, 5, 3, 5);
	*/
		
	// GFG
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
	
	debug (1,"\n");
	
	cout<<"Algorithm Output--\n";
	
	int minCut = INT_MAX, temp;
	
	for (int i=0; i<nodes*nodes; i++)
	{
		temp = Kargers (nodes, vArray, vEdges);
		if (temp < minCut)
			minCut = temp;
	}
	debug (2, "Min Cut: ", minCut,"\n");
	
	delete [] vArray;
}
