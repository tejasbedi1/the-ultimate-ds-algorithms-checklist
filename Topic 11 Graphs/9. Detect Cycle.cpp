#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Graph
{

private:	
	int V;
	vector<int> *vArray;
	bool *visited;
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
	
	bool dfs(int s)
	{
		int parent = 0;
		if(dfsRecur(s, visited, parent))
			return true;
		else 
			return false;
 	}
	
	bool dfsRecur(int s, bool *visited, int parent)
	{
		visited[s] = true;	
		cout<<"Processing "<<s<<"\n";
		
		for (int x : vArray[s])
		{
			if (visited[x] == true && x != parent)
			{
				cout<<"\t"<<x<<" is visited and not equal to parent "<<parent<<endl;
				return true;
			}
			if (visited[x] == false)
				if (dfsRecur(x, visited, s))
					return true;
		}
	}
	
	void detectCycle ()
	{
		if( dfs (1) )
			cout<<"Cycle Detected";
		else
			cout<<"No Cycle Detected";
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
	//graph.addEdge(2, 5);
	//graph.addEdge(3, 5);
	graph.addEdge(4, 6);
	graph.addEdge(4, 5);
	//graph.addEdge(5, 6);
	
	graph.detectCycle();
	
	//cout<<"\nDisplay All\n";
	//graph.display();
}
