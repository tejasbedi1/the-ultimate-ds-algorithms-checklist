#include <bits/stdc++.h>
#include <iostream>
#include "extrasV2.h"

using namespace std;

struct data
{
	int node;
};

void initVArray (int V, vector <data> **vArray)
{
	*vArray = new vector <data>[V];
}

void addEdge(vector <data> *vArray, int a, int b)
{
	data d;
	d.node = b;
	vArray[a].push_back(d);
	
	d.node = a;
	vArray[b].push_back(d);
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

struct details
{
	int disc_time; 	// Discovery Time
	int low;	 	// LOW
};

void dfsRecur(vector <data> *vArray, int node, bool *visited, stack <int> processed,
	int &disc_time, int &low, details *det, int parent, int root)
{
	debug (2, "\nProcessing", node, ": ", true);
	debug (2, " with parent ", parent, ": ");
	
	processed.push(node);
	visited[node] = true;
	
	det[node].disc_time = disc_time;
	det[node].low = low;
	
	debug(1, node, " (");
	debug(1, disc_time, ",");
	debug(1, low, ")\n");
	
	disc_time++; low++;
	
	int child = 0; 
	// Used specifically for the root
	// In case root has more than or equal to 2 subtrees then its an AP
	
	for (auto x : vArray[node])
	{
		if (visited[x.node] == false)
		{
			debug(2, x.node, " not visited, visiting..\n");
			child ++;
			dfsRecur(vArray, x.node, visited, processed, disc_time, low, det, node, root);
		}
		else
		{
			debug(2, x.node, " already visited.\n");	
			if (x.node != parent)
			{
				if (det[node].low > det[x.node].disc_time)
				{
					debug (2, "Low is higher for current node, reassigning..");
					
					debug (2, det[node].low, "->");
					debug (2, det[x.node].disc_time);
					det[node].low = det[x.node].disc_time;
				}
			}
		}	
	}
	
	debug (2, "Popping", node, ": ", true);
	debug (2, " with parent ", parent, ": ");
	
	debug (3, "det[parent].disc_time: ", det[parent].disc_time);
	debug (3, "det[node].low: ", det[node].low);
	
	if (det[node].low < det[parent].disc_time && parent != -1)
	{
		debug(2, "Low of node, less than parent's discovery time, reassigning parents low..");
		debug (2, det[parent].low, "->");
		debug (2, det[node].low); 
		det[parent].low = det[node].low;
	}
	if (det[node].low > det[parent].disc_time && parent != -1)
	{
		debug(1, "Bridge Found: ", parent, true);        
		debug(1, ":", node);
	}
	if (det[node].low >= det[parent].disc_time && parent != -1)
	{
		if (parent == root)
		{
			debug(2, "Parent is root, different conditions apply...");
		}
		else 
		{
			debug(2, "Parent not root, go to town");
			debug(1, "Found Articulation Point: ", parent);
		}
	}
	if (node == root)
	{
		debug(2, "Root in focus...");
		debug(2, "Root's children: ", child);
		if (child >= 2)
				debug(1, "Found Articulation Point: ", root);
	}
	processed.pop();
}

void dfs(int V, vector <data> *vArray)
{
	int i;
	int src = 0;
	
	bool *visited = new bool[V];
	for (i = 0; i < V; i++)
		visited[i] = false;
		
	stack <int> processed;
	
	details *det;
	det = new details[V];
	
	int disc_time = 0;
	int low = 0;
	
	dfsRecur(vArray, src, visited, processed, disc_time, low, det, -1, src);
	
	debug(1, "\nFinal Details");
	for (int i=0; i<V; i++)
	{
		debug(1, i, " (");
		debug(1, det[i].disc_time, ",");
		debug(1, det[i].low, ")\n");
	}
	debug(2, "\n\nDFS ended.");
	delete [] visited;
	delete [] det;
}

int main()
{
	// Resource 
	// Good explanation, wrong solution
	// https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
	// Good Algorithm
	// https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/
	
	// Good Theory Explanation - https://www.youtube.com/watch?v=jFZsDDB0-vo
	// Basics Explanation - https://www.youtube.com/watch?v=aZXi1unBdJA&t=1036s
	
	// VISUAL ALGO - https://visualgo.net/en/dfsbfs
	
	// Process
	// The process here is the same as when finding bridges
	// So read up there on how to traverse, assign Discovery time's and low's 
	// 	for each node
	// We will add a few conditions to find articulation points
	// If low of node >= discovery time of parent AND Parent is not root
	// 	then the parent is a articulation point
	// If the node in focus is a root
	// 	Check its children, if there equal to or greater than 2.
	// 	then root is an AP
	
	// Complexity 
	// O (V+E)
	
	// GRAPH
	// Ex 1 GFG https://media.geeksforgeeks.org/wp-content/cdn-uploads/Bridge1.png
	// Ex 2 William Fest's video https://www.youtube.com/watch?v=aZXi1unBdJA (13:00 ish)
	// Rest of them drawn in comments
	
	LOG_LEVEL = 1;
	
	int nodes;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	
	// EX 1
	/*
	addEdge(vArray, 0, 1);	
	addEdge(vArray, 0, 3);
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 0);
	addEdge(vArray, 3, 4);
	*/
	// Ex 2
	/*
	addEdge(vArray, 0, 1);
	addEdge(vArray, 0, 2);
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 3);
	addEdge(vArray, 2, 5);
	addEdge(vArray, 3, 4);
	addEdge(vArray, 5, 6);
	addEdge(vArray, 6, 7);
	addEdge(vArray, 7, 8);
	addEdge(vArray, 8, 5);
	*/
	// Ex 3
	//  1 \	  /	3
	//	|	0 	|
	//  2 /	  \	4
	/*
	nodes = 5;
	addEdge(vArray, 0, 1);
	addEdge(vArray, 0, 2);
	addEdge(vArray, 0, 3);
	addEdge(vArray, 0, 4);
	addEdge(vArray, 1, 2);
	addEdge(vArray, 3, 4);
	*/
	// Ex 4
	// 0 -	1	
	// |	|
	// 3 -	2 4
	//		5
	/*
	nodes = 6;
	addEdge(vArray, 0, 1);
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 3);
	addEdge(vArray, 3, 0);
	addEdge(vArray, 2, 4);
	addEdge(vArray, 2, 5);
	addEdge(vArray, 4, 5);
	*/
	// Ex 4
	// 	1 	-	2
	//    \   /
	// 		0
	// 	  |	  \
	//  3 	 	4
	//	  \	  /
	//		5
	//    /   \
	//  6   -  	7
	/*
	addEdge(vArray, 0, 1);
	addEdge(vArray, 1, 2);
	addEdge(vArray, 2, 0);
	addEdge(vArray, 0, 3);
	addEdge(vArray, 0, 4);
	addEdge(vArray, 3, 5);
	addEdge(vArray, 4, 5);
	addEdge(vArray, 5, 6);
	addEdge(vArray, 5, 7);
	addEdge(vArray, 6, 7);
	*/
	
	if (LOG_LEVEL >= 1) display(nodes, vArray);
	
	debug(1, "DFS\n");
	dfs(nodes, vArray);
	
	delete [] vArray;
}
