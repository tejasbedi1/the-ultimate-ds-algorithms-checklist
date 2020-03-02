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

void dfsRecur(int V, vector <data> *vArray, bool *visited, int node, 
	stack <int> &stk, stack <int> &topologicalOrder)
{
	debug(2, "Processing ", node, "\n");
	
	stk.push(node);
	visited [node] = true;
	
	for (auto x: vArray[node])
	{
		if (visited[x.node] == false)
		{
			dfsRecur(V, vArray, visited, x.node, stk, topologicalOrder);
		}
	}
	debug(2, "popping ", node, "\n");
	
	//debug(1, node, "\n");
	hashMapClass map;
	debug(1, map.convert(node), "\n");
	
	topologicalOrder.push(node);
	stk.pop();
}

int whichNodeNotVisited(int V, bool *visited)
{
	for(int i=0; i<V; i++)
		if (visited[i] == false)
			return i;
	return -1;
}

void topologicalSorting(int V, vector <data> *vArray, hashMapClass &map)
{
	int i;
	
	bool *visited;
	visited = new bool[V];
	
	for (i=0; i<V; i++)
		visited[i] = false;
	
	stack <int> stk;
	stack <int> topologicalOrder;
	
	int toVisit = 0;
	while (toVisit != -1)
	{
		dfsRecur(V, vArray, visited, toVisit, stk, topologicalOrder);
		toVisit = whichNodeNotVisited(V, visited);
		debug (2, toVisit, ", not visited, Re-running dfs\n");
	}
	
	debug (1,"\nTopological Order...\n");
	while(topologicalOrder.empty() != true)
	{ 
		debug(1,map.convert(topologicalOrder.top()), " ");
		topologicalOrder.pop();	
	}
	debug (1,"\n");
}

int main()
{
	// Resource 
	// https://www.youtube.com/watch?v=eL-KzMXSXXI&t=556s
	// https://www.geeksforgeeks.org/topological-sorting/
	
	// Process
	// 
	// First we check if the graph is indeed a DAG
	// Detection of a cycle will be done using Targan's Algorithm
	//
	// Topological Ordering - is an odering of the nodes in a directed graph here 
	//	for each directed edge from Node A to Node B, node A appearsbefore 
	// 	node B in the ordering
	//
	// Topological Sort - algorithm can find a topological ordering in O (V+E) time
	// Topological orderings are NOT unique. Trees follow topological orders
	
	// Complexity 
	// O(V+E)
	
	// GRAPHS
	// 0: in directory (34 G1)
	// 1: in directory
	
	LOG_LEVEL = 1;
	
	hashMapClass map;
	
	int nodes = 13;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	
	// EX 0
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
	
	// Ex 1 
	
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

	debug(1, "Topological Sorting...\n");
	
	topologicalSorting(nodes, vArray, map);
	
	delete [] vArray;
}
