#include <bits/stdc++.h>
#include <iostream>

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

void modifyBackwardEdge(vector <data> *vArray, int a, int b, int c)
{
	int i;
	for (i=0; i<vArray[a].size(); i++)
	{
		if (vArray[a][i].nodeB == b)
		{
			vArray[a][i].currentFlow += c;
		}
	}
}

void display (int V, vector <data> *vArray)
{
	int i;
	for (i=0; i<V; i++)
	{
		cout<<"Node "<<i<<"- ";
		for (auto x : vArray[i])
		{
			cout<<x.nodeA<<","<<x.nodeB<<"("<<x.currentFlow<<","<<x.capacity<<")"<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void displayEdgeData(stack <data> &sEdgeData)
{
	stack <data> copy = sEdgeData;
	while (copy.empty() == false)
	{
		cout<<copy.top().nodeA<<","<<copy.top().nodeB<<endl;
		copy.pop();
	}
	cout<<endl;
}

void modifyAllEdges(vector <data> *vArray, stack <data> &stackData, int minCapacity )
{
	int nodeA;
	int nodeB;
	int i,j;
	data edge;
	data residualEdge;
	
	while (stackData.empty() == false)
	{
		nodeA = stackData.top().nodeA;
		nodeB = stackData.top().nodeB;
		for (i=0; i<vArray[nodeA].size(); i++)
		{
			if ( vArray[nodeA][i].nodeB == nodeB )
			{
				if ( vArray[nodeA][i].capacity != 0) // Normal Edge 
				{
					vArray[nodeA][i].currentFlow += minCapacity;
					for ( j=0; j<vArray[nodeB].size(); j++)
						if ( vArray[nodeB][j].nodeB == nodeA)
							vArray[nodeB][j].currentFlow += minCapacity;
				}
				else	// Residual Edge 
				{
					vArray[nodeA][i].currentFlow -= minCapacity;
					for ( j=0; j<vArray[nodeB].size(); j++)
						if ( vArray[nodeB][j].nodeB == nodeA)
							vArray[nodeB][j].currentFlow -= minCapacity;
				}
			}
		}
		stackData.pop();
	}
}

int findMinCapacity(stack <data> &stackData)
{
	int minCapacity = INT_MAX;
	stack <data> copy = stackData;
	
	while (copy.empty() == false)
	{
		if (copy.top().capacity != 0)		// Normal Edge
			if ( copy.top().capacity < minCapacity )
				minCapacity = copy.top().capacity;
		else if (copy.top().capacity == 0) // Resdual Edge
			if ( copy.top().currentFlow < minCapacity )
				minCapacity = copy.top().currentFlow;		
				
		copy.pop();
	}	
	return minCapacity;
}

bool pathExists(int V, vector <data> *vArray, stack <data> &stackData, 
					bool *visited, int src, int sink)
{
	if (src == sink)
		return true;
		
	bool pathStatus = false;
	for (auto x : vArray[src])
	{
		if (visited[x.nodeB] == false)
		{
			// Main Edge or Residual Edge
			//cout<<x.nodeA<<","<<x.nodeB<<" "<<x.currentFlow<<" "<<x.capacity<<endl;
			if ( x.capacity != 0 && x.currentFlow < x.capacity)
			{
				stackData.push(x);
				visited[src] = true;
				pathStatus = pathExists(V, vArray, stackData, visited, x.nodeB, sink);
				
				if (pathStatus == false)
					stackData.pop();
			}
			else if ( x.capacity == 0 && x.currentFlow != 0) 
			{
				stackData.push(x);
				visited[src] = true;
				pathStatus = pathExists(V, vArray, stackData, visited, x.nodeB, sink);
				
				if (pathStatus == false)
					stackData.pop();
			}	
			if (pathStatus == true)
				return true;
			else
				continue;
		}
	}
	return false;
}

void falsifyEverything(int V, bool *visited)
{
	for (int i=0; i<V; i++)
		visited[i] = false;
}

void fordFulkerson (int V, vector <data> *vArray)
{
	int i;
	int src = 0;
	int sink = 5;
	int flow = 0;
	
	int minCapacity;
	stack <data> stackData;
	
	bool *visited;
	visited = new bool[V];
	falsifyEverything(V, visited);
	
	while (pathExists(V, vArray, stackData, visited, src, sink))
	{
		//cout<<"Current Path\n";
		//displayEdgeData(stackData);
		//cout<<"Calculating min possible Capacity\n";
		minCapacity = findMinCapacity(stackData);
		//cout<<"Min: "<<minCapacity<<endl;
		flow += minCapacity;
		modifyAllEdges(vArray, stackData, minCapacity);
		//cout<<"After Edge Modification\n";
		//display(V, vArray);
		falsifyEverything(V, visited);
		//system("pause");
	}	
	
	cout<<"Flow: "<<flow<<endl;
}

void modify(vector <data> *vArray, int a, int b, int c, int f)
{
	for (auto x : vArray[a])
	{
		if (x.nodeB == b)
		{
			x.capacity = c;
			x.currentFlow =  f;
		}
	}
}

int main()
{
	// Resource 
	// https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/
	// https://www.hackerearth.com/practice/algorithms/graphs/maximum-flow/tutorial/
	// https://brilliant.org/wiki/ford-fulkerson-algorithm/
	// 5 mins - https://www.youtube.com/watch?v=Tl90tNtKvxs
	// Detailed - https://www.youtube.com/watch?v=LdOnanfc5TM
	// Visualize - https://visualgo.net/en/maxflow
	
	// Process
	// Its simple
	// We need a Stack and a visited array
	// Then a algorithm to spit out a possible path
	// After a path has been decided, find min capacity for that path
	// Update flow
	// Update flow on all the edges
	// False the visited array
	// Keep running until no more path found
	
	// Complexity 
	// O (E'. f*)
	// E' All edges including residual edges
	// f* The max flow (in some senario it flow could increase by 1 only so..)
	
	// GRAPH
	// Ex 1 GFG https://www.geeksforgeeks.org/wp-content/uploads/ford_fulkerson11.png
	// Ex 2 Hacker https://he-s3.s3.amazonaws.com/media/uploads/61e8b57.png
	
	int nodes = 6;
	
	vector <data> *vArray; 
	
	initVArray(nodes, &vArray);
	
	// GFG
	 
	addEdge(vArray, 0, 1, 16);
	addEdge(vArray, 0, 2, 13);
	addEdge(vArray, 1, 2, 10);
	//addEdge(vArray, 2, 1, 4);
	modifyBackwardEdge(vArray, 2, 1, 4);
	addEdge(vArray, 1, 3, 12);
	addEdge(vArray, 2, 4, 14);
	addEdge(vArray, 3, 2, 9);
	addEdge(vArray, 4, 3 ,7);
	addEdge(vArray, 3, 5, 20);
	addEdge(vArray, 4, 5, 4);
	
	// Hacker earth
	/*
	addEdge(vArray, 0, 1, 10);
	addEdge(vArray, 0, 3, 8);
	addEdge(vArray, 1, 2, 5);
	addEdge(vArray, 1, 3, 2);
	addEdge(vArray, 3, 4, 10);
	addEdge(vArray, 2, 5, 7);
	addEdge(vArray, 4, 2, 8);
	addEdge(vArray, 4, 5 ,10);
	*/
	//modify(vArray, );
	
	display(nodes, vArray);
	
	cout<<"Algorithm Output--\n";
	fordFulkerson(nodes, vArray);
	delete [] vArray;
}

// --------------------------------------------------------------------
/*
struct edgeData
{
	int nodeA;
	int nodeB;
	int capacity;
	int currentFlow;	
};
*/

/*
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
*/

/*
template <class T>
void recur(int &src, int &sink, T *vArray, bool *visited, stack <int> &paths)
{
	//cout<<src<<" ";
	//cout<<"Pushing "<<src<<endl;
	paths.push(src);
	visited[src] = true;
	for (data x : vArray[src])
	{
		if (x.node == sink)
		{
			//cout<<x.node;
			paths.push(x.node);
			//cout<<"Pushing Sink "<<x.node<<endl;
			displayStack (paths);
			//cout<<"Poping Sink "<<paths.top()<<endl;
			paths.pop();
		}
		else if (visited[x.node] == false)
			recur(x.node, sink, vArray, visited, paths);
	}
	visited[src] = false;
	//cout<<"Poping "<<paths.top()<<endl;
	paths.pop();
	//cout<<endl;
}

void fordFulkersonP (int V, vector <data> *vArray)
{
	int i;
	// List All Augmenting Paths then we'll see
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
*/
