#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Graph
{

private:	
	int V;
	vector<string> *vArray;
	unordered_map<string, int> umap;
	int assignedIndex = 0;
	unordered_map<string, int> :: iterator itr;
	
public:
	Graph (int V)
	{
		vArray = new vector <string> [V];
		this->V = V;
	}	
	
	void addEdge(string a, string b)
	{
		if (umap.find(a) == umap.end())
		{
			umap[a] = assignedIndex;
			assignedIndex++ ;
		}
		vArray[ umap.at(a) ].push_back(b);
		if (umap.find(b) == umap.end())
		{
			umap[b] = assignedIndex;
			assignedIndex++ ;
		}
		vArray[ umap.at(b) ].push_back(a);
	}
	
	void display()
	{
		int i;
		cout<<assignedIndex<<endl;
		for (itr = umap.begin(); itr != umap.end(); itr++ )
		{
			cout<<"Node "<<itr->first<<" - ";
			for (auto x : vArray[ itr->second ])
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
	
	graph.addEdge("a","b");
	graph.addEdge("b", "c");
	graph.addEdge("d", "e");
	
	cout<<"\nDisplay All\n";
	graph.display();
}
