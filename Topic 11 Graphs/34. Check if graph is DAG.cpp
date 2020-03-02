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

struct NodeDetails
{
	int low;
	int disc_time;
};

bool checkInStack (stack <int> &processed, int node)
{
	// Check if node is present in stack 
	// if yes, true
	// else false
	stack <int> temp = processed;
	while (temp.empty() != true)
	{
		if (temp.top() != node)
			temp.pop();
		else
			return true;
	}
	return false;
}

void dfsRecur(int V, vector <data> *vArray, bool *visited, NodeDetails *nodeDet,
	int &disc_time, int &low, int node, int parent, stack <int> &stk)
{
	debug (2, "Processing ", node, " with parent ", parent, "\n");
	
	stk.push(node);
	visited [node] = true;
	
	disc_time += 1;
	low += 1;
	
	nodeDet[node].disc_time = disc_time;
	nodeDet[node].low = low;
	
	debug (2, "Assigning ", node, " D,L ", disc_time, ",", low, "\n");
	
	for (auto x: vArray[node])
	{
		if (visited[x.node] == false)
		{
			debug(2,"\n");
			dfsRecur(V, vArray, visited, nodeDet, disc_time, low, x.node, node, stk);
		}
		else
		{
			debug(3, x.node, " already visited\n");
			// Proceed only if present in stack
			if(checkInStack(stk, x.node))
			{
				if (nodeDet[node].low > nodeDet[x.node].disc_time)
				{
					debug(2, "Low of: ", node, " is less than discovery time of ",
						x.node, ", hence taking it\n");
					debug (2, nodeDet[node].low, "->", nodeDet[x.node].disc_time), "\n";
					nodeDet[node].low = nodeDet[x.node].disc_time;
				}	
			}
		}
	}
	debug(2,"\n");
	
	debug (2, "popping ", node, " with parent ", parent, "\n");
	
	debug (3, "det[parent].disc_time: ", nodeDet[parent].disc_time,"\n");
	debug (3, "det[node].low: ", nodeDet[node].low,"\n");
	if (nodeDet[node].low < nodeDet[parent].disc_time)
	{
		debug(2, "Low of node, less than parent's discovery time, reassigning parents low..\n");
		debug (2, nodeDet[parent].low, "->", nodeDet[node].low,"\n");  
		nodeDet[parent].low = nodeDet[node].low;
	}
	
	debug (1, node, "\n");
	stk.pop();
}

void displayNodeDetails (int V, NodeDetails *nodeDet)
{
	int i;
	for (i=0; i<V; i++)
		debug(2, i, " (", nodeDet[i].disc_time, ",", nodeDet[i].low, ")\n");
}

int whichNodeNotVisited(int V, bool *visited)
{
	for(int i=0; i<V; i++)
		if (visited[i] == false)
			return i;
	return -1;
}

bool checkCyclePresence(int V, vector <data> *vArray)
{
	// USING TARGANS 
	int i;
	int stronglyConnectedComponents = 0;
	
	NodeDetails *nodeDet;
	nodeDet = new NodeDetails[V];
	
	bool *visited;
	visited = new bool[V];
	
	for (i=0; i<V; i++)
		visited[i] = false;
	
	int disc_time = -1;
	int low = -1;
	
	stack <int> stk;
	
	// The following loop ensures that all unvisted nodes after a dfs 
	// 		are also visited
	int toVisit = 0;
	while (toVisit != -1)
	{
		dfsRecur(V, vArray, visited, nodeDet, disc_time, low, toVisit, toVisit, stk);
		toVisit = whichNodeNotVisited(V, visited);
		debug (2, toVisit, ", not visited, Re-running dfs\n");
	}
	
	displayNodeDetails (V, nodeDet);
	
	// Just to store the unique subsets os lows/nodes
	unordered_set <int> uniqueLows;
	for (int i=0; i<V; i++)
	{
		if (uniqueLows.find(nodeDet[i].low) == uniqueLows.end())
			uniqueLows.insert(nodeDet[i].low);
	}
	debug (1, "Strongly Connected Components: ", uniqueLows.size(), "\n");
	
	// If number of strongly connected componets equal to nodes then no cycles
	stronglyConnectedComponents = uniqueLows.size();
	if (stronglyConnectedComponents == V)
		return false;
	else
		return true;
}

int main()
{
	// Resource 
	// Just check out resources on TARJANS
	
	// Process
	// 
	// Detection of a cycle will be done using Targan's Algorithm
	// It would basically spit out the number of strongly connected components
	//  	if its equal to the number of vertices then theres no cycles 
	// 		and so graph is a DAG 
	// 
	
	// Complexity 
	// Targans: O(V+E)
	
	// GRAPHS
	// 0: in directory
	// 1: inline
	// 2: inline
	// 3: inline
	
	LOG_LEVEL = 1;
	
	hashMapClass map;
	
	int nodes = 8;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	// EX 0
	///*
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
	//*/
	
	// EX 1
	// 		A 
	//  2 /   ^
	//  v	   \ 3
	//  B ----> C
	//      2
	/* 
	addEdge(vArray, map, 'A', 'B', 2);
	addEdge(vArray, map, 'B', 'C', 2);
	addEdge(vArray, map, 'C', 'A', 3);
	
	if (LOG_LEVEL >= 1) display(nodes, vArray, map);
	*/
	
	// EX 2
	// 	
	// 	B<-	A -> D 	 
	//  \  ^     |
	//  v /      v
	//  C        E
	/*
	addEdge(vArray, map, 'A', 'B', 2);
	addEdge(vArray, map, 'B', 'C', 2);
	addEdge(vArray, map, 'C', 'A', 2);
	addEdge(vArray, map, 'A', 'D', 2);
	addEdge(vArray, map, 'D', 'E', 2);
	addEdge(vArray, map, 'E', 'D', 2);
	
	if (LOG_LEVEL >= 1) display(nodes, vArray, map);
	*/
	
	// Ex 3
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
	
	display(nodes, vArray);
	*/
	debug(1, "Alogrithm Output...\n");
	
	if (checkCyclePresence(nodes, vArray) == true)
	{
		debug(1, "Cycle present, not a DAG."); 
	}
	else
	{
		debug(1, "Cycle not present, you've got a DAG."); 
	}
	
	delete [] vArray;
}
