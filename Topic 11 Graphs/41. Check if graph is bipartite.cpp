#include <bits/stdc++.h>
#include <iostream>
#include "extrasV3.h"

using namespace std;

struct data
{
	int node;
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
		helperMap ['R'] = 17;
		helperMap ['S'] = 18;
		helperMap ['T'] = 19;
		helperMap ['U'] = 20;
		helperMap ['V'] = 21;
		helperMap ['W'] = 22;
		helperMap ['X'] = 23;
		helperMap ['Y'] = 24;
		helperMap ['Z'] = 25;
		
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
		helperMapInv [17] = 'R';
		helperMapInv [18] = 'S';
		helperMapInv [19] = 'T';
		helperMapInv [20] = 'U';
		helperMapInv [21] = 'V';
		helperMapInv [22] = 'W';
		helperMapInv [23] = 'X';
		helperMapInv [24] = 'Y';
		helperMapInv [25] = 'Z';
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

hashMapClass mapObject;

initVArray(int V, vector <data> *(*vArray))
{
	*(vArray) = new vector <data>[V];
}

void addEdge(vector <data> *vArray, int a, int b)
{ 
	data d;
	
	d.node = b;
	vArray[a].push_back(d);
	
	d.node = a;
	vArray[b].push_back(d);
}

void addEdge(vector <data> *vArray, char a, char b)
{
	int e = mapObject.convert(a);
	int f = mapObject.convert(b);
	addEdge(vArray, e, f);
}

void display (int V, vector <data> *vArray)
{
	cout<<"All Nodes...\n";
	for(int i=0; i<V; i++)
	{
		cout<<i<<"- ";
		for (data x : vArray[i])
		{
			cout<<x.node<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void displayChars (int V, vector <data> *vArray)
{
	cout<<"All Nodes...\n";
	for(int i=0; i<V; i++)
	{
		cout<<mapObject.convert(i)<<"- ";
		for (data x : vArray[i])
		{
			cout<<mapObject.convert(x.node)<<" ";
		}
		cout<<endl;	
	}
	cout<<endl;
}


void BipartiteCheck(int V, vector <data> *vArray)
{
	// A simple BFS will do the trick
	
	int i;
	int src = 0;
	int front;
	
	bool *visited;
	visited = new bool[V];
	for (i=0; i<V; i++)
		visited[i] = false;
		
	int *type;
	type = new int[V];
	for (i=0; i<V; i++)
		type[i] = 0;
		
	queue <int> que;
	que.push(src);
	visited[src] = true;
	type[src] = 1;
	
	bool flag = true;
	
	while (que.empty() != true)
	{
		front = que.front();
		debug(1, "Currently at ", mapObject.convert(front), "\n");
		
		for (i=0; i<vArray[front].size(); i++)
		{
			if (visited[vArray[front][i].node] == false)
			{
				que.push(vArray[front][i].node);
				visited[vArray[front][i].node] = true;
				debug(2, " visiting ", mapObject.convert(vArray[front][i].node), "\n");
				if (type[front] == 1)
				{
					type[vArray[front][i].node] = 2;
					debug (2, "  node ", mapObject.convert(front),
						" has type 1 assigning ", mapObject.convert(vArray[front][i].node),
						" type 2\n");
				}
				else
				{
					type[vArray[front][i].node] = 1;
					debug (2, "  node ", mapObject.convert(front),
						" has type 2 assigning ", mapObject.convert(vArray[front][i].node),
						" type 1\n");
				}
			}
			else 
			{
				debug (2, " already visited ", mapObject.convert(vArray[front][i].node),
					 "\n");
				debug (2, "  checking if the types are appropriate\n");
				debug (2, "   ", mapObject.convert(front),
					" type ", type[front], "\n");
				debug (2, "   ", mapObject.convert(vArray[front][i].node), 
					" type ", type[vArray[front][i].node], "\n");
				if (type[front] == type[vArray[front][i].node])
				{
					flag = false;
					debug (1, "Voilation In Edge made by nodes ", mapObject.convert(front),
						"-", mapObject.convert(vArray[front][i].node), "\n");
				}
			}
		}
		debug (2, "\n");
		que.pop();
	}
	
	if (flag == true)
		debug (1, "\nGraph is Bipartite :)\n");
	else if (flag == false)
		debug (1, "\nGraph is NOT Bipartite :(\n");
		
	delete [] visited;
	delete [] type;
}

int main()
{
	// Resource
	//
	// GFG
	// https://www.geeksforgeeks.org/bipartite-graph/
	// Technical Defination
	// https://www.youtube.com/watch?v=HqlUbSA9cEY
	// Good explanation
	// https://www.youtube.com/watch?v=HqlUbSA9cEY
	
	// Process
	// The process is quite simple and can be done while grpah traversal is going on
	// Traverse the graph by BFS
	// 
 	// Assign the root node a type (eg 1) and start traversal
 	// whenever it sees a unvisted node assign that node the opposite type (eg 2)
	// whnever a already visited node is seen (by our node in focus)
	// check if the type of that node is not the same as our node (the one from which 
	// 	currently traversal is happening)
	// if two connected nodes have the same type then the graph is not bipartite
	
	// Complexity 
	// O (V+E) // A simple traversal is enough
	
	// GRAPHS          
	// In line
	
	LOG_LEVEL = 2;
	
	hashMapClass map;
	
	int nodes = 6;
	
	vector <data> *vArray;
	initVArray(nodes, &vArray);
	
	// Ex 1 
	addEdge(vArray, 'A', 'B');
	addEdge(vArray, 'A', 'F');
	addEdge(vArray, 'B', 'E');
	addEdge(vArray, 'B', 'C');
	addEdge(vArray, 'F', 'E');
	addEdge(vArray, 'C', 'D');
	addEdge(vArray, 'D', 'E');
	addEdge(vArray, 'D', 'F'); // MAKES is non bipartite
	
	if (LOG_LEVEL >= 1) displayChars(nodes, vArray);
	
	debug(1, "Algorithm: Checking if graph is Bipartite...\n");
	BipartiteCheck(nodes, vArray);
	
	delete [] vArray;
}
