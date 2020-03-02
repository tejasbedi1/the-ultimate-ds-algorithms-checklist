#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Graph
{
private:
		
	int V;
	vector <int> *vArray;
	
	int *distance;
	bool *visited;
	int *previous;
	
	int i;
	
public:
		
	Graph(int V)
	{
		vArray = new vector <int> [V];
		
		distance = new int[V];
		visited = new bool[V];
		for (i = 0; i < V; i++)
			visited[i] = false;
		previous = new int[V];
		for (i = 0; i < V; i++)
			previous[i] = -1;
		this->V = V;
	}
	
	void addEdge(int a, int b)
	{
		vArray[a].push_back(b);
		vArray[b].push_back(a);	
	}
	
	void shortestDistBFS(int src)
	{
		queue <int> nodeQueue;
		
		nodeQueue.push(src);
		visited[src] = true;
		distance[src] = 0;
		
		while (!nodeQueue.empty())
		{
			src = nodeQueue.front();
			//cout<<src<<endl;
			nodeQueue.pop();
			
			for (int x : vArray[src])
			{
				if (visited[x] == false)
				{
					nodeQueue.push(x);
					visited[x] = true;
					distance[x] = 1 + distance[src];
					previous[x] = src;
					//cout<<"    "<<x<<" visited, distance: "<<distance[x]<<endl;
				}
			}
		}
		//cout<<endl;
	}
	
	void displayPrevious()
	{
		for (i = 0; i < V; i++)
		{
			cout<<"Node "<<i<<"- ";
			cout<<previous[i]<<endl;
		}	
	}
	
	void displayDistances()
	{
		for (i = 0; i < V; i++)
		{
			cout<<"Node: "<<i<<", Dist: ";
			cout<<distance[i]<<", Path - ";
			
			cout<<i<<" ";
			int prev = previous[i];
			while(prev != -1)
			{
				cout<<prev<<" ";
				prev = previous[prev];
			}
			cout<<endl;
		}	
	}
	
	void display()
	{
		for (i = 0; i < V; i++)
		{
			cout<<"Node "<<i<<"- ";
			for (auto x : vArray[i])
			{
				cout<<x<<" ";
			}
			cout<<endl;
		}
	}
	
	void deallocate()
	{
		delete [] distance;
		delete [] visited;
		delete [] previous;
	}
};

int main()
{
	// Graph
	// https://www.geeksforgeeks.org/shortest-path-unweighted-graph/
	// PIC : https://media.geeksforgeeks.org/wp-content/uploads/exampleFigure-1.png
	
	// Process 
	// In our example 
	// We go layer by layer 
	// 0 closest to 1,3
	// 3 closest to 7, 4
	// 4 closest to 7, 6, 5
	// Layer By Layer ;)
	// Adjecency List
	
	int nodes = 8;
	
	Graph graph(nodes);
	
	graph.addEdge(0, 1);
	graph.addEdge(0, 3);
	graph.addEdge(1, 2);
	graph.addEdge(3, 4);
	graph.addEdge(3, 7);
	graph.addEdge(4, 5);
	graph.addEdge(4, 6);
	graph.addEdge(4, 7);
	graph.addEdge(6, 5);
	graph.addEdge(6, 7);
	
	graph.shortestDistBFS(0);
	
	cout<<"\nAll Distances\n";
	graph.displayDistances();
	
	//cout<<"\nAll Previous's\n";
	//graph.displayPrevious();
	
	cout<<"\nDisplay All\n";
	graph.display();
	
	graph.deallocate();
}

