#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Graph
{

private:	
	int V;
	vector<int> *vArray;
	
public:
	Graph (int V)
	{
		vArray = new vector <int> [V];
		this->V = V;
	}
	
	void addEdge(int a, int b)
	{
		vArray[a].push_back(b);
		vArray[b].push_back(a);
	}
	
	void dfs(int s)
	{
		int i;
		
		bool *visited = new bool[V];
		for (i = 0; i < V; i++)
			visited[i] = false;
			
		stack <int> processed;
		
		dfsRecur(s, visited, processed);
 	}
	
	void dfsRecur(int s, bool *visited, stack <int> processed)
	{
		processed.push(s);
		visited[s] = true;	
		cout<<s<<" ";
		
		for (int x : vArray[s])
		{
			if (visited[x] == false)
				dfsRecur(x, visited, processed);
		}
		
		processed.pop();
	}
	
	void display()
	{
		int i;
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
};

int main()
{
	int nodes = 6+1;
	
	Graph graph(nodes);
	
	graph.addEdge(1, 2);
	graph.addEdge(1, 3);
	graph.addEdge(2, 4);
	graph.addEdge(2, 5);
	graph.addEdge(3, 5);
	graph.addEdge(4, 6);
	graph.addEdge(4, 5);
	graph.addEdge(5, 6);
	
	graph.dfs(1);
	
	cout<<"\nDisplay All\n";
	graph.display();
}
