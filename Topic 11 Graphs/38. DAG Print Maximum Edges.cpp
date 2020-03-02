#include <bits/stdc++.h>
#include <iostream>
#include "extrasV3.h"

using namespace std;

struct data
{
	int node;
	int distance;
};

class hashMapClass
{
	unordered_map <char, int> helperMap;
	unordered_map <int, char> helperMapInv;
	
	unordered_map<char, int>:: iterator itr;
	unordered_map<int, char>:: iterator itrInv;
	
	public :
	hashMapClass()
	{
		populateHashMap();
		populateInvHashMap();
	}
	
	private :
	void populateHashMap()
	{
		helperMap ['A'] = 0;
		helperMap ['B'] = 1;
		helperMap ['C'] = 2;
		helperMap ['D'] = 3;
		helperMap ['E'] = 4;
		helperMap ['F'] = 5;
		helperMap ['G'] = 6;
		helperMap ['H'] = 7;
		helperMap ['I'] = 8;
		helperMap ['J'] = 9;
		helperMap ['K'] = 10;
		helperMap ['L'] = 11;
		helperMap ['M'] = 12;
		helperMap ['N'] = 13;
		helperMap ['O'] = 14;
		helperMap ['P'] = 15;
		helperMap ['Q'] = 16;
	}		
	
	void populateInvHashMap()
	{
		helperMapInv [0] = 'A';
		helperMapInv [1] = 'B';
		helperMapInv [2] = 'C';
		helperMapInv [3] = 'D';
		helperMapInv [4] = 'E';
		helperMapInv [5] = 'F';
		helperMapInv [6] = 'G';
		helperMapInv [7] = 'H';
		helperMapInv [8] = 'I';
		helperMapInv [9] = 'J';
		helperMapInv [10] = 'K';
		helperMapInv [11] = 'L';
		helperMapInv [12] = 'M';
		helperMapInv [13] = 'N';
		helperMapInv [14] = 'O';
		helperMapInv [15] = 'P';
		helperMapInv [16] = 'Q';
	}	
	
	int getIntFromHashMap(char a)
	{
		itr = helperMap.find(a);
		if ( itr == helperMap.end() )
			return -1;
		else 
			return itr->second;
	}
    
	char getCharFromHashMap(int a)
	{
		itrInv = helperMapInv.find(a);
		if ( itrInv == helperMapInv.end() )
			return '0';
		else 
			return itrInv->second;
	}
	
	public: 
	int convert(char a)
	{
		return getIntFromHashMap(a);
	}
	char convert(int a)
	{
		return getCharFromHashMap(a);
	}
};

void initVArray (int V, vector <data> **vArray)
{
	*vArray = new vector <data>[V];
}

void addEdge(vector <data> *vArray, int a, int b)
{ 
	//DIRECTED
	data d;
	d.distance = 0;
	d.node = b;
	vArray[a].push_back(d);
}

void addEdge(vector <data> *vArray, int a, int b, int c)
{
	//DIRECTED
	data d;
	d.distance = c;
	d.node = b;
	vArray[a].push_back(d);
}

void addEdge(vector <data> *vArray, hashMapClass &map, char e, char f, int g)
{
	//DIRECTED
	int a = map.convert(e);
	int b = map.convert(f);
	data d;
	d.distance = g;
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

void display (int V, vector <data> *vArray, hashMapClass &map)
{
	int i;
	for (i=0; i<V; i++)
	{
		cout<<"Node "<<map.convert(i)<<"- ";
		for (auto x : vArray[i])
		{
			cout<<map.convert(x.node)<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

struct NodeInfo
{
	int indegree;
	int outdegree;
};

void displayQueue(queue <int> &queInFocus);

void traverseAndPopulateOrder(int V, vector <data> *vArray, NodeInfo *nodeInfo,
	queue <int> &que, queue <int> &topologicalOrder)
{
	int node;
	hashMapClass map;
	
	int count = 0; // Keeps track of nodes being added in the top order
	while (que.empty() != true)
	{
		if (LOG_LEVEL >= 2) displayQueue(que);
		node = que.front();
		debug(2, "Processing ", map.convert(node), "\n");
		
		for (auto x: vArray[node])
		{
			// Edge Disable
			debug (2, "Visiting ", map.convert(x.node), "\n");
			nodeInfo[node].outdegree -= 1;
			nodeInfo[x.node].indegree -= 1;
			// If some node has zero indegrees add it to stk
			if (nodeInfo[x.node].indegree == 0)
			{
				debug (2, "Node ", map.convert(x.node), 
					" has zero indegrees adding to stack\n");
				que.push(x.node);
			}		
		}
		// Pop our processed node add to top sort
		debug(2, "Popping ", map.convert(node), "\n");
		que.pop();
		
		topologicalOrder.push(node);
		count++;
		if (count > V)
		{
			debug(1, "Given graph not a DAG...\nBREAKING OUT...\n");
			break;
		}
	}
	if (topologicalOrder.size() != V)
		debug(1, "Inappropriate topological order size, Graph not a DAG...\n");
}

void populateDegrees(int V, vector <data> *vArray, NodeInfo *nodeInfo)
{
	for(int i=0; i<V; i++)
	{
		nodeInfo[i].indegree = 0;
		nodeInfo[i].outdegree = 0;
	}
	for(int i=0; i<V; i++)
	{
		nodeInfo[i].outdegree += 1;
		for(auto x: vArray[i])
			nodeInfo[x.node].indegree += 1;
	}
}

void displayNodeDetails(int V, NodeInfo *nodeInfo)
{
	hashMapClass map;
	debug (2, "Initial Node Info\n");
	for (int i=0; i<V; i++)
		debug(2, "Node ", map.convert(i), " - ", "In-", nodeInfo[i].indegree,
			" Out-", nodeInfo[i].outdegree, "\n");
}

void findNodeWithZeroIndegree(int V, queue <int> &que, NodeInfo *nodeInfo)
{
	for (int i=0; i<V; i++)
		if (nodeInfo[i].indegree == 0)
			que.push(i);
}

void displayQueue(queue <int> &queInFocus)
{
	debug (1, "\nQueue Data...\n");
	queue <int> temp = queInFocus;
	hashMapClass map;
	while (temp.empty() != true)
	{
		debug(1, map.convert(temp.front()), " ");	
		//debug(1, temp.top(), " ");	
		temp.pop();
	}
	debug (1, "\n");
}

void printCountPossibleConnections(int V, vector <data> *vArray, queue <int> que);

void KhansAlgorithm(int V, vector <data> *vArray)
{
	int i;
	
	hashMapClass map;
	
	queue <int> que;
	queue <int> topologicalOrder;
	
	NodeInfo *nodeInfo;
	nodeInfo = new NodeInfo[V];
	
	// Find initial degrees for all 
	populateDegrees(V, vArray, nodeInfo);
	displayNodeDetails(V, nodeInfo);
	
	// Find zero degrees ones
	findNodeWithZeroIndegree(V, que, nodeInfo);
	if (LOG_LEVEL >= 2) displayQueue(que);
	
	// Traverse zero degree ones
	// Disable Edges then traverse more
	
	traverseAndPopulateOrder(V, vArray, nodeInfo, que, topologicalOrder);
	
	debug (1,"\nTopological Order...");
	displayQueue(topologicalOrder);
	debug (1, "\n");
	printCountPossibleConnections(V, vArray, topologicalOrder);
	
}

void printCountPossibleConnections(int V, vector <data> *vArray, queue <int> topOrder)
{
	hashMapClass map;
	
	int node;
	node = topOrder.front();
	
	queue <int> queCopy;
	
	unordered_set <int> uSet;
	
	int currConnecCount = 0;
	int newConnecCount = 0;
	
	while (topOrder.empty() != true)
	{
		node = topOrder.front();
		
		debug (1, "Current connections for ", map.convert(node), "\n");
		for (auto x : vArray[node])
		{
			debug (1, map.convert(node), "-", map.convert(x.node), " ");
			uSet.insert(x.node);
			currConnecCount ++;
		}
		debug (1, "\n");
		
		queCopy = topOrder;
		queCopy.pop(); // Dont need the first one
		
		debug (1, "Other possible connections for ", map.convert(node), "\n");
		while (queCopy.empty() != true)
		{
			if (uSet.find(queCopy.front()) == uSet.end())
			{
				debug (1, map.convert(node), "-", map.convert(queCopy.front()), " ");
				newConnecCount++;
			}
			else
				uSet.erase(queCopy.front());
				
			queCopy.pop();
		}
		debug (1, "\n");
		
		topOrder.pop();
	}
	debug (1, "Current Connection Count ", currConnecCount, "\n");
	debug (1, "New Connection Count ", newConnecCount, "\n");
}

int main()
{
	// Resource 
	// GFG
	// https://www.geeksforgeeks.org/maximum-edges-can-added-dag-remains-dag/
	
	// Process
	// 
	// ITERATING OVER KHANS ALGORITHM
	// Used khans to get topological order 
	//
	// Simply printed and counted non exisiting connections
	// Iterating more
	// Took first node, printed all possible connections for it
	// 		The already exissitng connections stored in a hashSet
	// 		If a connecton already idnt exist printed + counted it
	// Did this for all nodes
	// 
	
	// Complexity 
	// O(V+E) to find topo order 
	// To find all possible connections
	// O (V * (V/2))
	
	// GRAPHS
	// 0: in directory (34 G1)
	// 1: in directory (35 G1)
	// 2: in directory (37 G1)
	
	LOG_LEVEL = 1;
	
	hashMapClass map;
	
	int nodes = 11;
	
	vector <data> *vArray; 
	initVArray(nodes, &vArray);
	
	// EX 0 // nodes = 8
	/*
	addEdge(vArray, map, 'A', 'B', 3);
	addEdge(vArray, map, 'A', 'C', 6);
	addEdge(vArray, map, 'B', 'C', 4);
	addEdge(vArray, map, 'B', 'E', 11);
	addEdge(vArray, map, 'B', 'D', 4);
	addEdge(vArray, map, 'C', 'D', 8);
	addEdge(vArray, map, 'C', 'G', 11);
	addEdge(vArray, map, 'D', 'E', -4);
	addEdge(vArray, map, 'D', 'G', 2);
	addEdge(vArray, map, 'D', 'F', 5);
	addEdge(vArray, map, 'E', 'H', 9);
	addEdge(vArray, map, 'F', 'H', 1);
	addEdge(vArray, map, 'G', 'H', 2);
	
	if (LOG_LEVEL >= 1) display(nodes, vArray, map);
	*/
	
	// Ex 1  // nodes = 13
	/*
	addEdge(vArray, map, 'C', 'A', 0);
	addEdge(vArray, map, 'C', 'B', 0);
	addEdge(vArray, map, 'A', 'D', 0);
	addEdge(vArray, map, 'B', 'D', 0);
	addEdge(vArray, map, 'E', 'A', 0);
	addEdge(vArray, map, 'E', 'D', 0);
	addEdge(vArray, map, 'E', 'F', 0);
	addEdge(vArray, map, 'D', 'H', 0);
	addEdge(vArray, map, 'D', 'G', 0);
	addEdge(vArray, map, 'H', 'I', 0);
	addEdge(vArray, map, 'H', 'J', 0);
	addEdge(vArray, map, 'G', 'I', 0);
	addEdge(vArray, map, 'F', 'K', 0);
	addEdge(vArray, map, 'F', 'J', 0);
	addEdge(vArray, map, 'K', 'J', 0);
	addEdge(vArray, map, 'J', 'M', 0);
	addEdge(vArray, map, 'J', 'L', 0);
	addEdge(vArray, map, 'I', 'L', 0);
	
	if (LOG_LEVEL >= 1) display(nodes, vArray, map);
	*/
	
	// Ex 2 nodes = 11;
	addEdge(vArray, map, 'E', 'B', 0);
	addEdge(vArray, map, 'E', 'F', 0);
	addEdge(vArray, map, 'B', 'A', 0);
	addEdge(vArray, map, 'B', 'C', 0);
	addEdge(vArray, map, 'A', 'D', 0);
	//addEdge(vArray, map, 'D', 'B', 0); // INVALID, Will create a cycle
	addEdge(vArray, map, 'F', 'D', 0);
	addEdge(vArray, map, 'F', 'H', 0);
	addEdge(vArray, map, 'C', 'G', 0);
	addEdge(vArray, map, 'D', 'G', 0);
	addEdge(vArray, map, 'H', 'J', 0);
	addEdge(vArray, map, 'J', 'G', 0);
	addEdge(vArray, map, 'I', 'H', 0);
	addEdge(vArray, map, 'I', 'K', 0);
	addEdge(vArray, map, 'K', 'H', 0);
	
	if (LOG_LEVEL >= 1) display(nodes, vArray, map);
	
	debug(1, "Khans Algorithm...\n");
	KhansAlgorithm(nodes, vArray);
	
	delete [] vArray;
}
