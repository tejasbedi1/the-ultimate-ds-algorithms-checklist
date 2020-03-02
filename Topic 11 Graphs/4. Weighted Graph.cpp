#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Graph
{

private:	
	int V;
	vector<pair<int, int>> *vArray;
	
public:
	Graph (int V)
	{
		vArray = new vector <pair<int, int>> [V];
		this->V = V;
	}
	
	void addEdge(int a, int b, int c)
	{
		vArray[a].push_back(make_pair(b,c));
		vArray[b].push_back(make_pair(a,c));
	}
	
	void display()
	{
		int i;
		for (i = 0; i < V; i++)
		{
			cout<<"Node "<<i<<"- \n";
			for (auto x : vArray[i])
			{
				cout<<"\t"<<"connects with node "<<x.first<<" weighted at "<<x.second<<endl;
			}
			cout<<endl;
		}
	}
};

int main()
{
	int nodes = 4;
	
	Graph graph(nodes);
	// FIG 
	//https://www.geeksforgeeks.org/graph-implementation-using-stl-for-competitive-programming-set-2-weighted-graph/
	
	graph.addEdge(0, 1, 10);
	graph.addEdge(0, 2, 3);
	graph.addEdge(0, 3, 2);
	graph.addEdge(1, 3, 7);
	graph.addEdge(2, 3, 6);
	
	cout<<"\nDisplay All\n";
	graph.display();
}
