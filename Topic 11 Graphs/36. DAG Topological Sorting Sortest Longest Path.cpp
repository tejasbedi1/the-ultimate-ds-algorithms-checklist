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
			cout<<map.convert(x.node)<<"("<<x.distance<<")"<<" ";
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

void calculateDistances(int V, vector <data> *vArray, bool *visited,
	stack <int> &stk, stack <int> topologicalOrder, int *distArr)
{
	int top;
	hashMapClass map;
	
	top = topologicalOrder.top();
	debug (1, "Top of Topological Order ", map.convert(top), "\n");
	
	distArr[top] = 0;
	
 	while (topologicalOrder.empty() != true)
	{
		top = topologicalOrder.top();
		debug (2, "Processing ", top, "\n");
		
		for (auto x: vArray[top])
		{
			debug (2, "analyzing ", x.node, "\n");
			
			if (distArr[x.node] > distArr[top] + x.distance)
			{
				distArr[x.node] = distArr[top] + x.distance;
			}
		}
		topologicalOrder.pop();
	}
}

template <class T>
void displayStack(T &stkInFocus)
{
	T temp = stkInFocus;
	hashMapClass map;
	while (temp.empty() != true)
	{
		debug(1, map.convert(temp.top()), " ");	
		//debug(1, temp.top(), " ");	
		temp.pop();
	}
	debug (1, "\n");
}

void shortestPath(int V, vector <data> *vArray)
{
	int i;
	hashMapClass map;
	
	bool *visited;
	visited = new bool[V];
	
	int *distArr;
	distArr = new int[V];
	
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
	displayStack(topologicalOrder);
	
	for (i=0; i<V; i++)
	{
		visited[i] = false;
		distArr[i] = INT_MAX;
	}
	
	// Distances have to be calculated using the topological order
	debug (1,"\nShortest Distance...\n");
	calculateDistances(V, vArray, visited, stk, topologicalOrder, distArr);
	
	debug (1, "Distances...\n");
	for (i=0; i<V; i++)
		debug(1, map.convert(i), "-", distArr[i], " ");
	debug(1, "\n");
	
	// For longest distance Negate all distance, calculate shortest path, negate it
	// 	and you got our answer
	for (i=0; i<V; i++)
	{
		visited[i] = false;
		distArr[i] = INT_MAX;
	}
	debug (1, "\nLongest Distance...\n");
	
	debug (2, "Negating distances...\n");
	for (i=0; i<V; i++)
	{
		for (int j=0; j<vArray[i].size(); j++)
			vArray[i][j].distance = vArray[i][j].distance * -1;
	}
	if (LOG_LEVEL >= 2) display(V, vArray, map);
	
	calculateDistances(V, vArray, visited, stk, topologicalOrder, distArr);
	
	debug (1, "Distances...\n");
	for (i=0; i<V; i++)
	{
		// Negating the distances back
		distArr[i] = distArr[i] * -1;
		debug(1, map.convert(i), "-", distArr[i], " ");
	}
	debug(1, "\n");
	
	delete [] visited;
	delete [] distArr;
}

int main()
{
	// Resource 
 	// Youtube
	//  https://www.youtube.com/watch?v=TXkDpqjDMHA
	// GFG (less important)
	// https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/
	
	// Process
	// 
	// First we check if the graph is indeed a DAG
	// IF it is then
	// 	Find the topological ordering (we keep that in a stack)
	//  Now for the shortest path/ longest path 
	// 		we will traverse all neighbours of the top most node in the top stack
	// 		After all the neighbours have been travesed and distances assigned 
	// 		The top node is popped
	// 		and the next topmost node is given the same tratment
	// 
	// this process will reveal the Single Source Shortest Path (SSSP)
	// Next for the, longest path (SSLP)
	// This is usually a NP hard problem in normal graphs
	// in case of a DAG though, Just negate all the distances 
	// Find the shortest distance (SSSP)
	// Then negate those distances as well
	// And wolla u have the longest distances, just like that
	
	// Complexity 
	// O (V+E)
	
	// GRAPHS
	// 0: in directory (34 G1)
	
	LOG_LEVEL = 1;
	
	hashMapClass map;
	
	int nodes = 8;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	
	// EX 0
	
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

	debug(1, "Shortest Path...\n");
	shortestPath(nodes, vArray);
	
	delete [] vArray;
}
