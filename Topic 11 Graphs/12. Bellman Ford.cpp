#include <bits/stdc++.h>
#include <iostream>


#define S 0
#define A 1
#define B 2
#define C 3
#define D 4
#define E 5

using namespace std;

class Graph
{
private:
	int V;
	int i;
	int j;
	
	int **arr;
	int *distances;
	
	bool negativeWeightCycle;
	
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
		
		distances = new int[V];
		for (i = 0; i<V; i++)
			distances[i] = INT_MAX;
	}
	
	void addEdge(int a, int b, int c)
	{
		arr[a][b] = c;
	}
	
	void bellmanFord(int src)
	{
		
		distances[src] = 0;
		for (i = 0; i<V-1 ; i++) // V-1
		{
			//cout<<"Iteration "<<i<<"";
			for (j = 0; j<V; j++)
			{
				for (int k = 0; k<V; k++)
				{
					//cout<<"Processing "<<j<<endl;
					// Move forward if there is a distance &
					// the node is not caluclating the distance to iteself
					// and it has a distance other than infinite
					// An infinite distance means it has not been visited yet
					if (arr[j][k] != 0 && j != k && distances[j] != INT_MAX)
					{
						//cout<<"Processing "<<j<<" "<<k<<" ";
						if ( (distances[j] + arr[j][k]) < distances[k])
						{
							distances[k] = arr[j][k] + distances[j];
							//cout<<"New distance for "<<k<<" set as "<<distances[k];
						}
						//cout<<endl;
					}	
				}	
			}
			//cout<<endl;
			//viewDistances();
		}
		viewDistances();
		checkForANegativeWeightCycle();
	}
	
	void checkForANegativeWeightCycle()
	{
		negativeWeightCycle = false;
		for (j = 0; j<V; j++)
		{
			for (int k = 0; k<V; k++)
			{
				if (arr[j][k] != 0 && j != k && distances[j] != INT_MAX)
				{
					if ( (distances[j] + arr[j][k]) < distances[k])
					{
						distances[k] = arr[j][k] + distances[j];
						negativeWeightCycle = true;
					}
				}	
			}	
		}
		if (negativeWeightCycle)
			cout<<"Negative Cycle Exists\n";
		else
			cout<<"No, Negative Cycle found\n";
	}
	
	void viewDistances ()
	{
		for (int i = 0; i<V; i++)
		{
			cout<<distances[i]<<" ";
		}	
		cout<<endl;
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
		
		delete [] distances;
	}
};



int main()
{
	// THE PROCESS 
	// This one works on continious iterations
	// If we have 6 nodes then 6-1 5 iterations
	// In each iteration, distances of all nodes will be calculated from source
	// with every iteration the system will automatically boil down the most optimal values
	
	// If the distances do not change with each iteration
	// then it would mean we have arrived to the most optimum solution
	
	// Bellman ford can detect negative cycles as well
	// If the distance values change even after the V-1 iterations then 
	// there must be a negative cycle present
	
	// Resources on trello
	
	int nodes;
	
	//NORMAL EXAMPLE
	nodes = 6;
	
	Graph graph(nodes);
	
	graph.addEdge(S, A, 10);
	graph.addEdge(S, E, 8);
    graph.addEdge(A, C, 2);
	graph.addEdge(B, A, 1);
	graph.addEdge(C, B, -2);
	graph.addEdge(D, A, -4);
	graph.addEdge(D, C, -1);
	graph.addEdge(E, D, 1);
	
	/* NEAGATIVE CYCLE EXAMPLE
	nodes = 4;
	
	Graph graph(nodes);
	
	graph.addEdge(S, A, 1);
	graph.addEdge(A, B, -1);
    graph.addEdge(B, C, -1);
	graph.addEdge(C, S, -1);
	*/
	cout<<"INPUT MATRIX\n";
	graph.displayMatrix();
	
	cout<<"\nAlgorithm Output\n";
	graph.bellmanFord(S);
	
	graph.deallocateMemory();
}

