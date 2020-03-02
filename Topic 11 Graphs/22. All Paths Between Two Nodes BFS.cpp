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

void initVectorBool (int V, vector <bool> &vecBool)
{
	int i;
	for (i=0; i<V; i++)
		vecBool.push_back(false);
}

struct containerS
{
	vector <int> path;
	vector <bool> visited;
	queue <int> que;
	bool complete;
};

void displayV(vector <int> &vArray)
{
	for (auto x: vArray)
	{
		cout<<x<<" ";
	}
	cout<<endl;
}

void showAll(vector <containerS> &containerV)
{
	for (containerS x : containerV)
	{
		for (int y : x.path)
		{
			cout<<y<<" ";
		}
		if (x.complete == false)
			cout<<"Que: "<<x.que.front();
		else 
			cout<<"complete";
		cout<<endl;
	}	
}

void showAllClean(vector <containerS> &containerV)
{
	for (containerS x : containerV)
	{
		for (int y : x.path)
			cout<<y<<" ";
		cout<<endl;
	}	
}

void showPath(containerS contS)
{
	for (int y : contS.path)
	{
		cout<<y<<" ";
	}
	if (contS.complete == false)
		cout<<"que: "<<contS.que.front();
	else 
		cout<<"complete";
	cout<<endl;
}

bool checkIfAllReachedSink(vector <containerS> &containerV)
{
	int i;
	for (i=0; i<containerV.size(); i++)
	{
		if (containerV[i].complete == false)
			return false;
	}
	return true;
}

void allPaths (int V, vector <data> *vArray)
{	
	int src = 0;
	int sink = 5;
	
	queue <int> que;
	vector <int> path;
	vector <bool> visited;
	initVectorBool (V, visited);
	
	int size = 0;
	
	vector <containerS> containerV;
	
	que.push(src);
	visited[src] = true;
	size++;
	
	int i;
	int front;
	int containerVSizeBeforeLoop = 0;
	
	containerS contS;
	contS.path = path;
	contS.visited = visited;
	contS.que = que;
	contS.complete = false;
	
	containerV.push_back(contS);
	
	while ( checkIfAllReachedSink(containerV) == false)
	{
		//cout<<"Not all paths completed, continuing..\n";
		containerVSizeBeforeLoop = containerV.size();
		//cout<<"Current container size: "<<containerV.size()<<endl;
		
		for (i=0; i<containerVSizeBeforeLoop; i++)
		{
			contS = containerV[i];
			
			// If path already goes from scr to sink, break
			if ( contS.complete == true)
				continue;
					
			path = contS.path;
			visited = contS.visited;
			que = contS.que;
			
			front = que.front();
			que.pop();
			path.push_back(front);
			
			int j = 0;
			for (data x : vArray[front])
			{
				if (j == 0) // For the first path only
				{
					if (contS.visited[x.node] == false)
					{
						que.push(x.node);
						visited[x.node] = true;
						
						contS.path = path;
						contS.visited = visited;
						contS.que = que;
						if (x.node == sink)
						{
							contS.complete = true;
							contS.path.push_back(x.node);
							contS.que.pop();
						}
						
						containerV[i] = contS;
						//cout<<"Previous Path Modified.. ";
						//showPath(containerV[i]);
												
						que.pop();
						visited[x.node] = false;
						
						j++;
					}
				}
				else if (j > 0) // For any other path than the second
				{
					if (contS.visited[x.node] == false)
					{
						que.push(x.node);
						visited[x.node] = true;
						
						contS.path = path;
						contS.visited = visited;
						contS.que = que;
						if (x.node == sink)
						{
							contS.complete = true;
							contS.path.push_back(x.node);
							contS.que.pop();
						}
						else
							contS.complete = false;
							
						containerV.push_back(contS);
						//cout<<"New Path created.. ";
						//showPath(contS);
							
						que.pop();
						visited[x.node] = false;
						
						j++;
					}
				}
			}
		}
		//cout<<"Loop completed, current paths\n";
		//showAll(containerV);
		//cout<<endl;
	}
	showAllClean(containerV);
}

int main()
{
	// Resource 
	// Came up with this when practicing Edmonds Karp
	// Because it invloves finding all augmenting paths
	//
	// GRAPH - https://www.geeksforgeeks.org/wp-content/uploads/ford_fulkerson11.png
	
	// Process
	// We use BFS to traverse everyhting appropriately
	// The main problem here is of storing and processing the path themselves
	// Those we do step by step. 
	// Explained in pic, check in folder
	
	// NOTE - Distance data is useles here, it was a reminant of the example we're
	//		using
	
	// Resources 
	//https://www.geeksforgeeks.org/print-paths-given-source-destination-using-bfs/
	
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
