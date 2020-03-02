#include <bits/stdc++.h>
#include <iostream>
#include "extrasV3.h"

using namespace std;

struct data
{
	int node;
	int distance;
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
	
	d.node = a;
	vArray[b].push_back(d);
}

void populateHashSet(unordered_set<int> &markedNodes, int value)
{
	markedNodes.insert(value);
}

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

void bfs(int V, vector <data> *vArray, int src)
{
	int i;
	int node;
	queue <data> que;
	
	bool *visited;
	visited = new bool[V];
	for (i=0; i<V; i++)
		visited[i] = false;
	
	data d;
	d.node = src;
	d.distance = 0;
	
	que.push(d);
	
	while (que.empty() != true)
	{
		d = que.front();
		visited[d.node] = true;
		
		for (auto x: vArray[que.front().node])
		{
			if (visited[x.node] == false)
			{
				d.node = x.node;
				d.distance = x.distance + 1;
				debug (3,"Pushing ", d.node, " with distance-", d.distance,"\n");
				que.push(d);
			}
		}
		debug (1, que.front().node, " ");
		debug (2,"Popping ", que.front().node, " with distance-", que.front().distance,"\n");
		que.pop();
	}
	cout<<endl;
}

int main()
{
	// NOTE 
	// This question has an issue
	// The geeks for geeks answer is not accurate firstly
	//
	// The question is valid tho
	// The answer will eventually have to be devided into multiple parts
	// 
	// The concepts that come into play here are of Diameter, Radius, Eccentricity
	// https://en.wikipedia.org/wiki/Distance_(graph_theory)
	// 
	// Unfortunately for us in a proper graph
	// To count the number of common nodes in a set which are a particular distance
	// 		from the marked nodes
	// 	We will have to dfs from all marked nodes and add the reached ones in a set
	//  Eventually count the common ones
	//
	// Fortunatley for us its a undirected, non-weighted graph
	// WORST CASE
	// will take O ( CountOFMarkedNodes*(V+E) )
	// O (V^2)
	
	// IT CAN BE DONE FASTER, HOWEVER
	// But that's the stuff of research papers
	// https://math.stackexchange.com/questions/58198/all-pairs-shortest-path-in-undirected-and-unweighted-graphs
	
	// Resource 
	// [WRONG ANSWER]
	// https://www.geeksforgeeks.org/count-nodes-within-k-distance-from-all-nodes-in-a-set/
	// [WHY ITS DIFFICULT, ANOTHER SOURCE]
	// https://cs.stackexchange.com/questions/194/the-time-complexity-of-finding-the-diameter-of-a-graph
	
	// Process
	// Complexity 
	// GRAPHS
	// Inline
	
	LOG_LEVEL = 2;
	
	hashMapClass map;
	unordered_set <int> markedNodes;
	
	//debug(1, map.convert('K'), "\n");
	//debug(1, map.convert(10), "\n");
	
	int nodes = 10;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	
	// EX 0
	// 	*1 	*2 	*4
	// 	|  	|	|
	// 	0 -	3 - 5
	//  /  /\	\
	// 8  6  7  9
	///*
	populateHashSet(markedNodes, 1);
	populateHashSet(markedNodes, 2);
	populateHashSet(markedNodes, 3);
	addEdge(vArray, 1, 0);
	addEdge(vArray, 2, 3);
	addEdge(vArray, 4, 5);
	addEdge(vArray, 0, 8);
	addEdge(vArray, 3, 6);
	addEdge(vArray, 3, 7);
	addEdge(vArray, 5, 9);
	addEdge(vArray, 0, 3);
	addEdge(vArray, 3, 5);
	
	if (LOG_LEVEL >= 1) display(nodes, vArray);
	//*/
	
	// EX 1
	// 		 D		E - K
	//	      \	   / 
	//  J- F	*A      H
	//	   \   /  \   / 
	//	 	*B 	-  *C 
	//	  /			  \
	//   G		  L -  I
	/*
	populateHashSet(markedNodes, map.convert('A'));
	populateHashSet(markedNodes, map.convert('B'));
	populateHashSet(markedNodes, map.convert('C'));
	
	addEdge(vArray, map.convert('A'), map.convert('B'));
	addEdge(vArray, map.convert('B'), map.convert('C'));
	addEdge(vArray, map.convert('C'), map.convert('A'));
	
	addEdge(vArray, map.convert('A'), map.convert('D'));
	addEdge(vArray, map.convert('A'), map.convert('E'));
	addEdge(vArray, map.convert('E'), map.convert('K'));
	
	addEdge(vArray, map.convert('C'), map.convert('H'));
	addEdge(vArray, map.convert('C'), map.convert('I'));
	addEdge(vArray, map.convert('I'), map.convert('L'));
	
	addEdge(vArray, map.convert('B'), map.convert('G'));
	addEdge(vArray, map.convert('B'), map.convert('F'));
	addEdge(vArray, map.convert('F'), map.convert('J'));
	
	if (LOG_LEVEL >= 1) display(nodes, vArray, map);
	
	*/
	
	debug(1, "BFS\n");
	// RUN BFS once with any 
	bfs(nodes, vArray, 0);
	
	delete [] vArray;
}
