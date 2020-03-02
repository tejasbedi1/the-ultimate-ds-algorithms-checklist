#include <bits/stdc++.h>
#include <iostream>

#define A 0
#define B 1
#define C 2
#define D 3
#define E 4

using namespace std;

class Graph
{
private:
	int V;
	int i;
	int j;
	
	int **arr;
	bool *visited;
	int *distances;
	int *previousNode;
	
	int currentNode;
	
	vector <int> *pathList;
	
public:		
	Graph(int V)
	{
		this->V = V;
		
		arr = new int*[V];
		for (i = 0; i<V; i++)
			arr[i] = new int[V];
 		
		for (i = 0; i<V; i++)
			for (j = 0; j<V; j++)
				arr[i][j] = 0;
		
		visited = new bool[V];		
		for (i = 0; i<V; i++)
			visited[i] = false;
		
		distances = new int[V];
		for (i = 0; i<V; i++)
			distances[i] = INT_MAX;
		
		previousNode = new int[V];
		for (i = 0; i<V; i++)
			previousNode[i] = -1;
		
		pathList = new vector <int> [V];
	}
	
	void addEdge(int a, int b, int c)
	{
		arr[a][b] = c;
		arr[b][a] = c;
	}
	
	void dijkstrasAlgo(int src)
	{
		distances[src] = 0;
		
		currentNode = nodeWithMinimumDistance();
		
		calcDistancesRecur(currentNode);
		
		viewDistances();
		viewPath();
	}
	
	void calcDistancesRecur(int currNode)
	{
		for (i = 0; i<V; i++)
		{
			if (arr[currNode][i] != 0 && currNode != i)	// Connection exists
			{
				if (visited[i] == false)	// The node is not already processed
				{
					// Give it a new distance if the
					// total distance = ongoing distance + current distance (betw nodes)
					if ( (distances[currNode] + arr[currNode][i]) < distances[i] )
					{
						distances[i] = distances[currNode] + arr[currNode][i];
						previousNode[i] = currNode;
					}	
				}
			}
		}
		// Finalize Node - Mark it visited + assign path
		visited[currNode] = true;
		assignPath(currNode);
		
		currNode = nodeWithMinimumDistance();
		if (currNode != -1)
			calcDistancesRecur(currNode); 
	}
	
	int nodeWithMinimumDistance()
	{
		int least = INT_MAX;
		for (i = 0; i<V; i++)
		{
			if (visited[i] == false)
			{
				if (distances[i] < least)
					least = i;
			}	
		}
		if (least == INT_MAX)
			return -1;
		else
			return least;
	}
	
	void assignPath(int currNode)
	{
		if (previousNode[currNode] != -1)
		{
			for (auto x : pathList[ previousNode[currNode] ])
			{
				pathList[currNode].push_back(x);
			}	
		}
		pathList[currNode].push_back(currNode);
	}
	
	void viewDistances ()
	{
		for (i = 0; i<V; i++)
		{
			cout<<distances[i]<<" ";
		}	
		cout<<endl;
	}	
	
	void viewPath ()
	{
		for (i = 0; i<V; i++)
		{
			cout<<i<<": ";
			for (auto j : pathList[i])
			{
				cout<<j<<" ";
			}
			cout<<endl;
		}
	}
	
	void displayMatrix ()
	{
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{
				cout<<arr[i][j]<<" ";
			}	
			cout<<endl;
		}
	}
	
	void deallocateMemory()
	{
		for (i = 0; i<V; i++)
			delete [] arr[i];
		delete [] arr;
		
		delete [] visited;
		
		delete [] distances;
		
		delete [] pathList;
	}
};

int main()
{
	// PROCESS 
	// Starting node = current node
	// Assign distances to all connected, non-visited nodes 
	// Mark current node as visited
	// Next move to a node which has the minimum distance to current node
	// Assign that as current
	// Rinse and Repeat till all visited
	// https://www.codingame.com/playgrounds/1608/shortest-paths-with-dijkstras
		//-algorithm/dijkstras-algorithm
	
	// WILL NOT WORK ON NEGATIVES CAUSE EG.
	/*
	*		100  	  -5000			-> A, B dist 1, C dist 100 | Next Minimum B
	*	    ----> C ----			-> B, D dist 2 | A,B and D are final | Next Min C
	*	  /				 \			-> C, C is final | D should be -4900 but
	* ->A ------> B ------> D		-> its already Final
	*		 1		   1			-> Hence WRONG solution
	* 	https://stackoverflow.com/questions/13159337/why-doesnt-dijkstras-algorithm-
	*		work-for-negative-weight-edges
	*/
	int nodes;
	nodes = 5;
	
	Graph graph(nodes);
	
	graph.addEdge(A, B, 3);
	graph.addEdge(A, C, 1);
    graph.addEdge(B, C, 7);
	graph.addEdge(B, D, 5);
	graph.addEdge(B, E, 1);
	graph.addEdge(C, D, 2);
	graph.addEdge(D, E, 7);
	
	cout<<"INPUT MATRIX\n";
	graph.displayMatrix();
	
	cout<<"\nAlgorithm Output\n";
	graph.dijkstrasAlgo(2);
	
	graph.deallocateMemory();
}

