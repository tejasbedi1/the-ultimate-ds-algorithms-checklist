#include <bits/stdc++.h>
#include <iostream>

#define INF 9000
using namespace std;

struct data
{
	int node;
	int distance;
};

struct edge
{
	int distance;
	int nodeA;
	int nodeB;
	
	edge ()
	{ }
	
	edge (int a, int b, int c ) : nodeA (a), nodeB (b), distance (c)
	{ }
	
	set (int a, int b, int c)
	{
		nodeA = a;
		nodeB = b; 
		distance = c;
	}
};

struct comparison
{
	bool operator() (edge const &a, edge const &b)
	{
		return a.distance < b. distance;		
	}
};

void initVArray(int V, vector<data> **vArray)
{
	*vArray = new vector <data> [V];
}

void addEdge(vector<data> *vArray, int a, int b, int c)
{
	data da;
	
	da.node = b; 
	da.distance = c;
	vArray[a].push_back(da);
}

void display(int V, vector<data> *vArray)
{
	int i;
	for (i = 0; i < V; i++)
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

void displayMST(vector <edge> mst)
{
	cout<<"Current Kruskals MST\n";
	if (mst.empty() == true)
	{
		cout<<"MST Empty\n";
		return;
	}
	for (edge x : mst)
	{
		cout<<x.nodeA<<" "<<x.nodeB<<" "<<x.distance<<endl;
	}
	cout<<endl;
}

void displayVector(vector <edge> &edgeVector)
{
	for (edge x : edgeVector)
	{
		cout<<x.nodeA<<" "<<x.nodeB<<" "<<x.distance<<endl;
	}
}

struct subset
{
	int parent;
	int rank;	
};
// UNION FIND WITH PAGE COMPRESSION 
int find(subset *sub, int i)
{
	if ( sub[i].parent != i )
		sub[i].parent = find(sub, sub[i].parent); 
	
	return sub[i].parent;
}

bool unionFunc(subset *sub, int a, int b)
{
	int aPar = find(sub, a);
	int bPar = find(sub, b);
	
	if (aPar != bPar)
	{
		if (sub[bPar].rank >= sub[aPar].rank)
		{
			sub[aPar].parent = bPar;
			sub[bPar].rank += sub[aPar].rank + 1;
			//cout<<a<<"'s parent "<<aPar<<" has been assigned a new parent ";
			//cout<<bPar<<endl;
			//cout<<"Because "<<bPar<<" has a higher rank\n";
		}
		else
		{
			sub[bPar].parent = a;
			sub[aPar].rank += sub[bPar].rank + 1;
			//cout<<b<<"'s parent "<<bPar<<" has been assigned a new parent ";
			//cout<<aPar<<endl;
			//cout<<"Because "<<aPar<<" has a higher rank\n";
		}
		return false;
	}
	else	// Cycle DETECTED
	{
		//cout<<"Hmmm, seems like both belong to the same subset i.e "<<bPar<<endl;
		//cout<<" Nothing to do/see here, carry on.\n";
		return true;
	}
}

bool doTheyHaveTheSameParent(subset *sub, int a, int b)
{
	return unionFunc(sub, a, b);
}

void kruskalsAlgorithm(int V, vector <data> *vArray, vector <edge> mst)
{
	cout<<"\nKruskals --\n";
	
	int i;
	edge e;
	vector <edge> edgeVector;
	// 1- SET DATA 
	for (i=0; i<V; i++)
	{
		for (auto x : vArray[i])
		{
			e.set(i, x.node, x.distance);
			edgeVector.push_back(e);	
		}
	}
	
	// 2- SORT DATA
	sort(edgeVector.begin(), edgeVector.end(), comparison());
	displayVector(edgeVector);
	
	// 3- MAKE TREE FROM SORTED DATA
	subset *sub;
	sub = new subset[V];
	for (i=0; i<V; i++)
	{
		sub[i].parent = i;
		sub[i].rank = 0; 	
	}
	
	for (i=0; i<edgeVector.size(); i++)
	{
		//cout<<"Evaluating "<<edgeVector[i].nodeA<<", "<<edgeVector[i].nodeB<<endl;
		if ( doTheyHaveTheSameParent(sub, edgeVector[i].nodeA, edgeVector[i].nodeB) == false)
		{
			mst.push_back(edgeVector[i]);
			//cout<<"Added "<<edgeVector[i].nodeA<<", "<<edgeVector[i].nodeB<<" to MST"<<endl;
		}
	}
	
	displayMST(mst);
	delete [] sub;
}

int main()
{
	// Resource
	// GFG : https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/
	// Brilliant : https://brilliant.org/wiki/kruskals-algorithm/
	// Youtube : https://www.youtube.com/watch?v=71UQH7Pr9kU
	// Detect Cycle : https://stackoverflow.com/questions/29998332/detect-cycle-in-a-graph-using-kruskals-algorithm
	// PIC : https://www.geeksforgeeks.org/wp-content/uploads/Fig-0-300x139.jpg
	// Why NO directed : https://stackoverflow.com/questions/22649416/why-cant-prims-or-kruskals-algorithms-be-used-on-a-directed-graph/22649601
	
	// Process 
	// Simple,
	// Store the graph in a suitable DS
	// Sort that DS according to distance lowest first
	// Start making a graph from that sorted DS
	// To make sure that no cycle's are being made during the process
	//		we use union-find and page compression
	
	// Complexity n nodes m nodes/edges whichever is larger
	// Sorting will take O(m log(m))
	// Then for merges and finds we take O(1) time
	// So O(m log(m))
	// OR O (E Log(E))
	
	int nodes = 9;
	
	vector <data> *vArray;
	
	vector <edge> mst;
	
	initVArray(nodes, &vArray);
	
	addEdge(vArray, 0, 1, 4);
	addEdge(vArray, 0, 7, 8);
	addEdge(vArray, 1, 2, 8);
	addEdge(vArray, 1, 7, 11);
	addEdge(vArray, 2, 3, 7);
	addEdge(vArray, 2, 8, 2);
	addEdge(vArray, 2, 5, 4);
	addEdge(vArray, 3, 4, 9);
	addEdge(vArray, 3, 5, 14);
	addEdge(vArray, 4, 5, 10);
	addEdge(vArray, 5, 6, 2);
	addEdge(vArray, 6, 8, 6);
	addEdge(vArray, 6, 7, 1);
	addEdge(vArray, 7, 8, 7);
	
	display(nodes, vArray);
	
	displayMST(mst);
	
	kruskalsAlgorithm (nodes, vArray, mst);
	
	delete [] vArray;
}

