#include <bits/stdc++.h>
#include <iostream>
#include "extrasV3.h"

using namespace std;

struct data
{
	int nodeA;
	int nodeB;
	int capacity;
	int currentFlow;
	char state; // State e enabled d disabled u unspecified
};

void initVArray (int V, vector <data> **vArray)
{
	*vArray = new vector <data>[V];
}

void addEdge(vector <data> *vArray, int a, int b, int c)
{
	data d;
	d.nodeA = a;
	d.nodeB = b;
	d.capacity = c;
	d.state = 'u';
	d.currentFlow = 0;
	
	vArray[a].push_back(d);
	
	d.nodeA = b; 	// RESIDUAL EDGES
	d.nodeB = a; 
	d.capacity = 0;
	d.currentFlow = 0;
	d.state = 'u';
	vArray[b].push_back(d);
}

void displayEdgeData(stack <data> &sEdgeData)
{
	cout<<"Edge Data: ";
	stack <data> copy = sEdgeData;
	while (copy.empty() == false)
	{
		cout<<"("<<copy.top().nodeA<<","<<copy.top().nodeB<<")"<<" ";
		copy.pop();
	}
	cout<<endl;
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
			if (x.capacity == 0)
				cout<<x.nodeA<<","<<x.nodeB<<"("<<x.currentFlow<<","<<"R"<<")"<<" ";
			else
				cout<<x.nodeA<<","<<x.nodeB<<"("<<x.currentFlow<<","<<x.capacity<<")"<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void displayVector (int V, vector <int> &vec)
{
	cout<<"Active Nodes...\n";
	int i;
	for (i=0; i<vec.size(); i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

void displayArray (int size, int *levels)
{
	for (int i=0; i<size; i++)
		cout<<i<<": "<<levels[i]<<" | ";
	cout<<endl;
}

void displayStack (stack <data> &stk)
{
	cout<<"Displaying Stack...\n";
	stack <data> temp = stk;
	while (temp.empty() != true)
	{
		cout<<"("<<temp.top().nodeA<<","<<temp.top().nodeB<<") ";
		temp.pop();
	}
	cout<<endl;
}

void displayQueue (queue <data> &que)
{
	cout<<"Displaying Queue...\n";
	queue <data> temp = que;
	while (temp.empty() != true)
	{
		cout<<"("<<temp.front().nodeA<<","<<temp.front().nodeB<<") ";
		temp.pop();
	}
	cout<<endl;
}

struct NodeData
{
	int node;
	int height;
	int excess;	
	vector <int> parent;
};

void displayParents (NodeData *nodeData, int v)
{
	for (int i=0; i<nodeData[v].parent.size(); i++)
		cout<<nodeData[v].parent[i]<<",";
}

void displayNodeData (int V, NodeData *nodeData)
{ 
	cout<<"Node Data...\n";
	for (int i=0; i<V; i++)
	{
		cout<<i<<"("<<nodeData[i].height<<","<<nodeData[i].excess<<"(P-";
		displayParents(nodeData, i);
		cout<<")"<<")  ";
	}
	cout<<"\n";
}

void calculateResidualEdge(vector <data> *vArray, int nodeA, int nodeB, int val)
{
	for (auto &x: vArray[nodeB])
	{
		if (x.nodeB == nodeA)
			x.currentFlow += val;
	}
}

void PushRelabel(int V, vector <data> *vArray)
{
	int i;
	int src = 0;
	int sink  = 3;
	
	NodeData *nodeData;
	nodeData = new NodeData[V];
	
	for (i=0; i<V; i++)
	{
		nodeData[i].node = i;
		nodeData[i].height = 0;
		nodeData[i].excess = 0;
	}	
	
	nodeData[src].height = V;
	nodeData[src].excess = -1; 
	nodeData[sink].excess = -1; 
	
	int inFocus;
	bool flag;
	
	// These nodes need to be processed
	vector <int> activeNodes;
	activeNodes.push_back(src);
	
	inFocus = activeNodes[0];
	debug (2, "At node: ", inFocus, "\n");
	// For src node
	for (auto &x: vArray[inFocus])
	{
		if (nodeData[inFocus].excess == -1)
		{
			x.currentFlow = x.capacity;
			calculateResidualEdge(vArray, inFocus, x.nodeB, x.capacity);
			
			nodeData[x.nodeB].excess = x.currentFlow;
			nodeData[x.nodeB].parent.push_back(inFocus);
			
			activeNodes.push_back(x.nodeB);
		}	
	}
	activeNodes.erase(activeNodes.begin());
	if (LOG_LEVEL >= 2) display(V, vArray);
	if (LOG_LEVEL >= 2) displayNodeData(V, nodeData);
	if (LOG_LEVEL >= 2) displayVector(V, activeNodes);
	
	while (activeNodes.empty() != true)
	{
		flag = false;
		
		inFocus = activeNodes[0];
		debug (2, "\nAt node: ", inFocus, "\n");
		
		for (auto &x: vArray[inFocus])
		{
			if (x.capacity != 0)	// Only run for forard edges 
			{
				if (nodeData[inFocus].height > nodeData[x.nodeB].height)
				{
					flag = true;
					// Edge is full
					if (x.capacity-x.currentFlow == 0)
						continue;
					// If excess in node greater than what the edge can handle
					else if ( nodeData[inFocus].excess >= (x.capacity-x.currentFlow) )
					{
						nodeData[inFocus].excess = nodeData[inFocus].excess - 
													(x.capacity-x.currentFlow);
						nodeData[x.nodeB].excess += (x.capacity-x.currentFlow);
						nodeData[x.nodeB].parent.push_back(inFocus);
						x.currentFlow = x.capacity;
						calculateResidualEdge(vArray, inFocus, x.nodeB,
							(x.capacity-x.currentFlow));
					}
					// If excess in node lesser than the edge capacity
					else
					{
						x.currentFlow += nodeData[inFocus].excess;
						nodeData[inFocus].excess = 0;
						calculateResidualEdge(vArray, inFocus, x.nodeB, 
							(nodeData[inFocus].excess));
					}
				}	
			}
		}

		if (flag == false)	// Means that the height was never greater
		{
			debug(2, "Height inc for: ", inFocus, "\n");
			nodeData[inFocus].height += 1; 
		}
		else
		{
			if (nodeData[inFocus].excess == 0)
			{
				debug (2, "Removing ", inFocus, " from active nodes\n");
				activeNodes.erase(activeNodes.begin());
			}
			else
			{
				if (nodeData[ nodeData[inFocus].parent[0] ].height > 
					nodeData[inFocus].height)
				{
					debug(2, "Parent has greater height, Height inc for: ", inFocus, "\n");
					nodeData[inFocus].height += 1; 		
				}
				else
				{
					
				}
			}	
		}
		
		if (LOG_LEVEL >= 2) display(V, vArray);
		if (LOG_LEVEL >= 2) displayNodeData(V, nodeData);
		if (LOG_LEVEL >= 2) displayVector(V, activeNodes);
	}
	delete [] nodeData;
}

int main()
{
	// LIMITATION 
	
	// Resource 
	
	// Process
	
	// Complexity 
	
	// GRAPH
	// Ex 0 In Directory (43)
	// Ex 1 GFG https://media.geeksforgeeks.org/wp-content/uploads/Dinicalgorithm.png
	// Ex 2 Hacker https://he-s3.s3.amazonaws.com/media/uploads/6bf2e0d.png
	// Ex 3 In directory (42 No)
	
	LOG_LEVEL = 3;
	
	int nodes = 6;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	
	// YT 
	// Src 0 Sink 3 | MAX FLOW 12
	// s=0, P=1, L=2, t=3, F=4, N=5
	addEdge(vArray, 0, 1, 10);
	addEdge(vArray, 0, 2, 13);
	addEdge(vArray, 1, 2, 3);
	addEdge(vArray, 2, 3, 7);
	addEdge(vArray, 2, 4, 6);
	addEdge(vArray, 4, 5, 10);
	addEdge(vArray, 5, 3, 5);
		
	// GFG
	// Src 0 Sink 5 | MAX FLOW 19
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
	// Src S,0 Sink T,5 | MAX FLOW 17
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
	// SRC 0 Sink 10 | Max Flow: 30
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
	
	cout<<"Algorithm Output--\n";
	PushRelabel (nodes, vArray);
	delete [] vArray;
}
