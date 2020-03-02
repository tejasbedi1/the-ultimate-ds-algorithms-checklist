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
	
	bool isConnected(int a, int b)
	{
		for (i = 0; i < V; i++)
			visited[i] = false;
		
		if (modDfsRecur(a, b))
			return true;
		else
			return false;
	}
	
	bool modDfsRecur(int a, int b)
	{
		visited[a] = true;
		for (auto x : vArray[a])
		{
			if (visited[x] == false)
			{
				if (modDfsRecur(x, b) == true)
					return true;
			}
		}
		if (a == b)
			return true;
		else 
			return false;
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
	int nodes = 7;
	
	Graph graph(nodes);
	
	graph.addEdge(0, 1);
	graph.addEdge(1, 2);
	graph.addEdge(3, 4);
	
	graph.viewAll();
	cout<<"\nRunning Is Connected\n";
	cout<<graph.isConnected(0,2)<<endl;
	cout<<graph.isConnected(3,4)<<endl;
	cout<<graph.isConnected(2,3)<<endl;
	cout<<"\nDisplay All\n";
	graph.display();
}
