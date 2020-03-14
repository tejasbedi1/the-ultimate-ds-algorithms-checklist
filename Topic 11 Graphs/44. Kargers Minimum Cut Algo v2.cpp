#include <bits/stdc++.h>
#include <iostream>
#include "extrasV3.h"

using namespace std;

struct EdgeData
{
	int nodeA;
	int nodeB;
	int setA;
	int setB;
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
	d.setA = -1;
	d.setB = -1;
	vArray[a].push_back(d);
	
	vEdges.push_back(d);
	
	d.nodeA = b; 	// RESIDUAL EDGES
	d.nodeB = a;
	d.setA = -1;
	d.setB = -1; 
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
		cout<<"("<<vec[i].nodeA<<","<<vec[i].nodeB<<")s["
			<<vec[i].setA<<","<<vec[i].setB<<"]\n";
	}
}

struct NodeData
{
	int set;
};

void displayNodeData (int size, NodeData *nodeData)
{
	cout<<"Node Data- ";
	for (int i=0; i<size; i++)
		cout<<i<<" ("<<nodeData[i].set<<") ";
	cout<<endl;
}

void displayNodeSet (int size, int *set)
{
	cout<<"Node Data- ";
	for (int i=0; i<size; i++)
		cout<<i<<" ("<<set[i]<<") ";
	cout<<endl;
}

int returnRandomEdgePosition (vector <EdgeData> &vEdge)
{
	int i;
	i = rand() % vEdge.size();
	debug (2, "Random Edge: (", vEdge[i].nodeA, ",", vEdge[i].nodeB, ")\n");
	return i;
}

void edgeRemover(vector <EdgeData> &vEdge, bool setFlagA, int nodeA, 
	bool setFlagB, int nodeB)
{
	int i;
	bool flag;
	do
	{
		flag = false;
		for (i=0; i<vEdge; i++)
		{
			if (setFlagA == false)
			{
				if (setFlagB == false)
				{
					if (nodeA == )	
				}
				else if (setFlagB == true)
				{
					
				}
			}
			else if (setFlagA == true)
			{
				if (setFlagB == false)
				{
					
				}
				else if (setFlagB == true)
				{
					
				}
			}	
		}
	} while( flag  = true)
}

void removeEdgesBetween(vector <EdgeData> &vEdge, int *set, int nodeA, int nodeB)
{
	if (set[nodeA] == -1 && set[nodeB] == -1)
	{
		edgeRemover(vEdge, false, nodeA, false, nodeB);
	}
	else if (set[nodeA] != -1 && set[nodeB] == -1)
	{
		debug(2, "A has a set, B dosen't\n");
	}
	else if (set[nodeA] == -1 && set[nodeB] != -1)
	{
		debug(2, "B has a set, A dosen't\n");
	}
	else
	{
		debug(2, "Both have sets\n");
	}
}

void modifyEdgeOf()
{
	
}

int Kargers(int V, vector <EdgeData> *vArray, vector <EdgeData> vEdge)
{
	int i;
	int setNo = 0;
	int pos;
	int nodeA;
	int nodeB;
	
	//NodeData *nodeData;
	//nodeData = new NodeData[V];
	//for (i=0; i<V; i++)
	//	nodeData[i].set = -1;
	int *set;
	set = new int[V];
	for (i=0; i<V; i++)
		set[i] = -1;
		
	if (LOG_LEVEL >= 2) displayNodeSet(V, set);
	if (LOG_LEVEL >= 2) displayEdges(vEdge);
	debug (2, "\n");
	
	while (true)
	{
		break;
		pos = returnRandomEdgePosition(vEdge);
		nodeA = vEdge[pos].nodeA;
		nodeB = vEdge[pos].nodeB;
		
		
		// Find out the edges needed to be removed
		// For that well need to know the sets :0
		if (set[nodeA] == -1 && set[nodeB] == -1)
		{
			debug(2, "Both dont have any sets\n");
			
			// Remove Edges 
			
			// Assign set
			set[nodeA] = setNo;
			set[nodeB] = setNo;
			
			// modify remaining edges
			
			setNo++;
		}
		else if (set[nodeA] != -1 && set[nodeB] == -1)
		{
			debug(2, "A has a set, B dosen't\n");
		}
		else if (set[nodeA] == -1 && set[nodeB] != -1)
		{
			debug(2, "B has a set, A dosen't\n");
		}
		else
		{
			debug(2, "Both have sets\n");
		}
		
		if (LOG_LEVEL >= 2) displayNodeSet(V, set);
		if (LOG_LEVEL >= 2) displayEdges(vEdge);
		debug (2, "\n");
	
		break;
	}
	
	delete [] set;
}

int main()
{
	// INCOMPLETE v3 is complete
	
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
	
	vector <EdgeData> *vArray; 
	vector <EdgeData> vEdges;
	
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
	
	cout<<"Algorithm Output--\n\n";
	
	Kargers (nodes, vArray, vEdges);
	/*
	int minCut = INT_MAX, temp;
	
	for (int i=0; i<nodes*nodes; i++)
	{
		temp = Kargers (nodes, vArray, vEdges);
		if (temp < minCut)
			minCut = temp;
	}
	debug (2, "Min Cut: ", minCut,"\n");
	*/
	delete [] vArray;
}
