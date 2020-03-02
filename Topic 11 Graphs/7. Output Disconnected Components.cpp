#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Graph
{

private:	
	int V;
	vector<int> *vArray;
	bool *visited;
	stack <int> stk;
	int i;
	
public:
	Graph (int V)
	{
		vArray = new vector <int> [V];
		
		visited = new bool[V];
		for (i = 0; i < V; i++)
			visited[i] = false;
		
		this->V = V;
	}
	
	void addEdge(int a, int b)
	{
		vArray[a].push_back(b);
		vArray[b].push_back(a);
	}
	
	void dfs(int a)
	{
		dfsRecur(a);
		cout<<endl;
	}
	
	void dfsRecur(int a)
	{
		cout<<a<<" ";
		visited[a] = true;
		for (auto x : vArray[a])
		{
			if (visited[x] == false)
			{
				dfsRecur(x);
			}
		}
	}
	
	void viewAll()
	{
		for (i = 0; i < V; i++)
		{
			if (visited[i] == false)
				dfs(i);
		}
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
	int nodes = 5;
	
	Graph graph(nodes);
	
	graph.addEdge(0, 1);
	graph.addEdge(1, 2);
	graph.addEdge(3, 4);
	
	graph.viewAll();
	
	cout<<"\nDisplay All\n";
	graph.display();
}
