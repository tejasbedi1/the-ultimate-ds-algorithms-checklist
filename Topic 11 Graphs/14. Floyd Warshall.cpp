#include <bits/stdc++.h>
#include <iostream>

#define S 0
#define A 1
#define B 2
#define C 3
#define D 4
#define E 5

#define INF 9000
using namespace std;

class Graph
{
private:
	int V;
	int i;
	int j;
	int k;
	int **arr;
	int **dist;
	
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
		
		dist = new int*[V];
		for (i = 0; i<V; i++)
			dist[i] = new int[V];
 		
		for (i = 0; i<V; i++)
			for (j = 0; j<V; j++)
				dist[i][j] = INF+100;
	}
	
	void addEdge(int a, int b, int c)
	{
		arr[a][b] = c;
	}
	
	void floydWarshall()
	{
		//viewDistances ();
		cout<<"Zeroing Out\n";
		for (i = 0; i < V; i++)
		{
			dist[i][i] = 0;
		}
		//viewDistances ();
		cout<<"Adding avalable info\n";
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{
				if (arr[i][j] != 0)
					dist[i][j] = arr[i][j];
			}
		}
		viewDistances ();
		cout<<endl;
		for (k = 0; k < V; k++)
		{
			//cout<<"\nAT K --- "<<k<<endl;
			for (i = 0; i < V; i++)
			{
				for (j = 0; j < V; j++)
				{
					//cout<<"At "<<i<<" "<<j<<" - ";
					if (dist[i][j] > dist[i][k] + dist[k][j])
					{
						dist[i][j] = dist[i][k] + dist[k][j];
						//cout<<"At "<<i<<" "<<j<<" - ";
						//cout<<"IF RAN\n";
					}
					//cout<<"\n";
				}
			}
		}
		viewDistances();
	}
	
	void viewDistances ()
	{
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{
				if (dist[i][j] >= INF)
					cout<<"I ";
				else
					cout<<dist[i][j]<<" ";
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
		
		for (i = 0; i<V; i++)
			delete [] dist[i];
		delete [] dist;
	}
};



int main()
{
	// THE PROCESS 
	// Essentially compares all pairs
	// The main loop essentially facilitates this transaction
	// 	- During every K
	// 		- During every I
	//			- For Each element of the I'th row
	// 				- If its distance > kth element of that row +
	// 											kth element of that colowmn
	//					- then give distance the smaller summed value
	// 	- Eventually all shortest paths will be calculated
	
	// Resources on trello
	
	int nodes;
	
	nodes = 4;
	
	Graph graph(nodes);
	
	/*
	*			0
	*		  ^   \
	* 	(4)	 /      \   (-2)
	*	  /	   (3)    >	
	*	1	-------->   2
	* 	  ^			  /
	*      \		/
	* (-1)	 \	   <   (2)
	*			3
	*/
	
	graph.addEdge(0, 2, -2);
	graph.addEdge(2, 3,  2);
	graph.addEdge(3, 1, -1);
	graph.addEdge(1, 0,  4);
	graph.addEdge(1, 2,  3);
	
	cout<<"INPUT MATRIX\n";
	graph.displayMatrix();
	
	cout<<"\nAlgorithm Output\n";
	graph.floydWarshall();
	
	graph.deallocateMemory();
}

