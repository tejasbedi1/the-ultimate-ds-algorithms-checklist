#include <bits/stdc++.h>
#include <iostream>

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

void addEdge(vector <data> *vArray, int a, int b, int c)
{
	data d;
	d.node = b;
	d.distance = c;
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

void displayStack(stack <int> &paths)
{
	stack <int> copy = paths;
	while (copy.empty() != true)
	{
		cout<<copy.top()<<" ";
		copy.pop();
	}
	cout<<endl;
}

template <class T>
void recur(int &src, int &sink, T *vArray, bool *visited, stack <int> &paths)
{
	//cout<<"Pushing "<<src<<endl;
	paths.push(src);
	visited[src] = true;
	for (data x : vArray[src])
	{
		if (x.node == sink)
		{
			//cout<<"Pushing Sink "<<x.node<<endl;
			paths.push(x.node);
			displayStack (paths);
			//cout<<"Poping Sink "<<paths.top()<<endl;
			paths.pop();
			break;
		}
		if (visited[x.node] == false)
			recur(x.node, sink, vArray, visited, paths);
	}
	visited[src] = false;
	//cout<<"Poping "<<paths.top()<<endl;
	paths.pop();
}

void allPaths (int V, vector <data> *vArray)
{
	int i;
	
	int src = 0;
	int sink = 5;
	
	bool *visited;
	visited = new bool[V];	
	for (i=0; i<V; i++)
		visited[i] = false;
	
	stack <int> paths;
	
	recur(src, sink, vArray, visited, paths);
	
	delete [] visited;
}

int main()
{
	// Resource 
	// Came up with this when practicing Ford Fulkerson
	// Because it invloves finding all augmenting paths
	//
	// GRAPH - https://www.geeksforgeeks.org/wp-content/uploads/ford_fulkerson11.png
	
	// Process
	// We use DFS to traverse everyhting appropriately
	// The visited array is important here 
	// Also, path <stack> is already used to properly show the resulting info
	// NOTE - Distance data is useles here, it was a reminant of the example we're
	//		using
	
	int nodes = 6;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	
	addEdge(vArray, 0, 1, 16);
	addEdge(vArray, 0, 2, 13);
	addEdge(vArray, 1, 2, 10);
	addEdge(vArray, 2, 1, 4);
	addEdge(vArray, 1, 3, 12);
	addEdge(vArray, 2, 4, 14);
	addEdge(vArray, 3, 2, 9);
	addEdge(vArray, 4, 3 ,7);
	addEdge(vArray, 3, 5, 20);
	addEdge(vArray, 4, 5, 4);
	
	display(nodes, vArray);
	
	cout<<"All Paths --\n";
	allPaths(nodes, vArray);
	
	delete [] vArray;
}
