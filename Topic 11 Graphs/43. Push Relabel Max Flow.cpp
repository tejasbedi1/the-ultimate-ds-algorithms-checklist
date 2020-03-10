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
	d.currentFlow = 0;
	vArray[a].push_back(d);
	
	d.nodeA = b; 	// RESIDUAL EDGES
	d.nodeB = a; 
	d.capacity = 0;
	d.currentFlow = 0;
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
			if (x.capacity == 0)
				cout<<x.nodeA<<","<<x.nodeB<<"("<<x.currentFlow<<","<<"R"<<")"<<" ";
			else
				cout<<x.nodeA<<","<<x.nodeB<<"("<<x.currentFlow<<","<<x.capacity<<")"<<" ";
		}
		cout<<endl;
	}
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

void displayQueue (queue <int> &que)
{
	cout<<"Active Nodes...\n";
	queue <int> temp = que;
	while (temp.empty() != true)
	{
		cout<<temp.front()<<" ";
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
};

void displayNodeData (int V, NodeData *nodeData)
{ 
	cout<<"Node Data...\n";
	for (int i=0; i<V; i++)
	{
		cout<<i<<"("<<nodeData[i].height<<","<<nodeData[i].excess<<")  ";
	}
	cout<<"\n";
}

void calculateResidualEdge(vector <data> *vArray, int nodeA, int nodeB, int val)
{
	for (auto &x: vArray[nodeB])
	{
		if (x.nodeB == nodeA)
			x.currentFlow = val;
	}
}

void calculateForwardEdge(vector <data> *vArray, int nodeA, int nodeB, int val)
{
	for (auto &x: vArray[nodeB])
	{
		if (x.nodeB == nodeA)
			x.currentFlow = val;
	}
}

void ifNotAreadyInQueueAddInQueue(queue <int> &activeNodes, int node)
{	
	queue <int> temp = activeNodes;
	// Find it, if not found add to queue
	while (temp.empty() != true)
	{
		if (temp.front() == node)
			return;
		temp.pop();
	}
	debug(3, "Adding ", node, " in Active Nodes Queue\n");
	activeNodes.push(node);
}

void PushRelabel(int V, vector <data> *vArray)
{
	int i;
	int src = 0;
	int sink  = 10;
	
	int maxFlow = 0;
	
	int inFocus;
	bool flag;
	int carryingCap;
	
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
	
	// These nodes need to be processed
	//vector <int> activeNodes;
	queue <int> activeNodes;
	
	activeNodes.push(src);
	
	inFocus = activeNodes.front();
	debug (2, "At node: ", inFocus, "\n");
	
	// For src node
	for (auto &x: vArray[inFocus])
	{
		if (nodeData[inFocus].excess == -1)
		{
			x.currentFlow = x.capacity;
			calculateResidualEdge(vArray, inFocus, x.nodeB, x.capacity);
			
			nodeData[x.nodeB].excess = x.currentFlow;
			
			debug (3, "Pushing ", x.nodeB, "\n");
			activeNodes.push(x.nodeB);
		}	
	}
	activeNodes.pop();
	if (LOG_LEVEL >= 2) display(V, vArray);
	if (LOG_LEVEL >= 2) displayNodeData(V, nodeData);
	if (LOG_LEVEL >= 2) displayQueue(activeNodes);
	
	//system("cls");
	
	while (activeNodes.empty() != true)
	{	
		flag = false;
		inFocus = activeNodes.front();
		debug (2, "\nAt node: ", inFocus, "\n");
		
		for (auto &x: vArray[inFocus])
		{
			// Check height
			if (nodeData[inFocus].height > nodeData[x.nodeB].height)
			{
				// Check edge carrying capacity
				// If forward
				if (x.capacity != 0)
				{
					// If the edge has edge carrying capacity 
					carryingCap = x.capacity-x.currentFlow;
					if (carryingCap > 0)
					{
						// IF excess is more than the carryign capacit of the edge
						if (nodeData[inFocus].excess >= carryingCap)
						{ 
							x.currentFlow = x.capacity;
							nodeData[inFocus].excess -= carryingCap;
							
							// Give the node at the end, the excess
							if (x.nodeB != sink)
							{
								nodeData[x.nodeB].excess += carryingCap;
								ifNotAreadyInQueueAddInQueue(activeNodes, x.nodeB);	
							}
						}
						else if (nodeData[inFocus].excess < carryingCap)
						{
							x.currentFlow += nodeData[inFocus].excess;
							
							// Give the node at the end, the excess
							if (x.nodeB != sink)
							{
								nodeData[x.nodeB].excess += nodeData[inFocus].excess;
								ifNotAreadyInQueueAddInQueue(activeNodes, x.nodeB);
							}
							
							nodeData[inFocus].excess = 0;
						}
						// Modify Residual Edge as well 
						calculateResidualEdge(vArray, x.nodeA, x.nodeB, x.currentFlow);
						flag = true;
					}
				}
				// If backward 
				else 
				{
					// If the edge has edge carrying capacity 
					carryingCap = x.currentFlow;
					if (carryingCap > 0)
					{
						// IF excess is more than the carryign capacit of the edge
						if (nodeData[inFocus].excess >= carryingCap)
						{ 
							x.currentFlow = 0;
							nodeData[inFocus].excess -= carryingCap;
							
							// Give the node at the end, the excess
							if (x.nodeB != src)
							{
								nodeData[x.nodeB].excess += carryingCap;
								ifNotAreadyInQueueAddInQueue(activeNodes, x.nodeB);
							}	
						}
						else if (nodeData[inFocus].excess < carryingCap)
						{
							x.currentFlow -= nodeData[inFocus].excess;
							
							// Give the node at the end, the excess
							if (x.nodeB != src)
							{
								nodeData[x.nodeB].excess += nodeData[inFocus].excess;
								ifNotAreadyInQueueAddInQueue(activeNodes, x.nodeB);
							}

							nodeData[inFocus].excess = 0;
						}
						// Modify Forward Edge as well 
						calculateForwardEdge(vArray, x.nodeA, x.nodeB, x.currentFlow);
						flag = true;
					}
				}
			}
		}
		
		if (flag == false)
		{
			// No work was done increase the height
			debug(3, "Increasing Height for ", inFocus, "\n");
			nodeData[inFocus].height += 1;
		}
		else if (nodeData[inFocus].excess == 0) 
		{
			debug(3, "Popping ", inFocus, "\n");
			activeNodes.pop();
		}
		
		if (LOG_LEVEL >= 2) display(V, vArray);
		if (LOG_LEVEL >= 2) displayNodeData(V, nodeData);
		if (LOG_LEVEL >= 2) displayQueue(activeNodes);
		//system("cls");
	}
	
	debug (2, "Active Nodes Empty, Calculating Flow...\n");
	for (auto x: vArray[src])
	{
		maxFlow += x.currentFlow;
	}
	debug (0, "MAXFLOW: ", maxFlow, "\n");
	delete [] nodeData;
}

int main()
{
	// LIMITATION 
	// This algorithm badly needs the usage of Hashing
	// At many points we are looping to find/check existance of edges/ nodes in particular queues
	// All this ill greatly benifit, if we use Hashing
	// ..
	// We might have an issue if the source node has a input edge
	
	// Resource 
	// Mediocre explanations all around
	// GFG I https://www.geeksforgeeks.org/push-relabel-algorithm-set-1-introduction-and-illustration/
	// GFG II https://www.geeksforgeeks.org/push-relabel-algorithm-set-2-implementation/
	// Wikipedia Example https://en.wikipedia.org/wiki/Push%E2%80%93relabel_maximum_flow_algorithm
	// Youtube Meh explanation: https://www.youtube.com/watch?v=dZpE_7Nr-Zk
	
	// Process
	// OMFG this one is a bitch to write about
	// See some of the sources (YT or wiki) and read this along
	//
	// okay, so lets see
	// The main algorithm is inside the main algorithm function itself
	// Thankfully we can do everything inside a clean loop
	// 
	// Firstly similiarize ourself with the structures we are going to use
	//   NodeData and data (edgeData)
	// We start at the src node, process it first
	//  The source node will first staturate its outgoing edges 
	//  meaning the edges are completely filed and the nodes at the ends will have 
	//  an excess of whatever the edge can deliver 
	//
	// Nodes with an excess are added to the actve nodes queue, so that they 
	// 	can be processed. Whenever the activeNodes queue is empty the algorithm will stop.
	// 
	// After the source has been delt with, our main loop begins. Here whichever node
	//  is on top of the activeNodes queue will be delt with.
	// Now the main objective for the node inFocus is to lose the excess flow it has
	// So it will go through iterations in heights so that it can pass off the excess 
	//  	to the neighbourng nodes OR ultimately regect the excess and push it back
 	// All push backed excess will eventually reach the src
 	// ANy node which recieves the excess flow will get added to the active nodes queue
 	// 
 	// This loop will continue unitl there are no more activeNodes. 
 	// Sunmming up the output of the src will give us the maxFlow
	
	// Complexity 
	// O(V^2 E) or O (V^2 sqrroot(E))
	
	// GRAPH
	// Ex 0 In Directory (43)
	// Ex 1 GFG https://media.geeksforgeeks.org/wp-content/uploads/Dinicalgorithm.png
	// Ex 2 Hacker https://he-s3.s3.amazonaws.com/media/uploads/6bf2e0d.png
	// Ex 3 In directory (42 No)
	
	LOG_LEVEL = 3;
	
	int nodes = 11;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	
	// YT 
	// Src 0 Sink 3 | MAX FLOW 12
	// s=0, P=1, L=2, t=3, F=4, N=5
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
	
	
	if (LOG_LEVEL >= 1) display(nodes, vArray);
	debug (1,"\n");
	
	cout<<"Algorithm Output--\n";
	PushRelabel (nodes, vArray);
	delete [] vArray;
}
