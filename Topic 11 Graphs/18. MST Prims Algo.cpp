#include <bits/stdc++.h>
#include <iostream>

#define INF 9000
using namespace std;

struct data
{
	int node;
	int distance;
};

void init(int V, vector<data> **vArray)
{
	*vArray = new vector <data> [V];
}

void addEdge(vector<data> *vArray, int a, int b, int c)
{
	data d;
	
	d.node = b;
	d.distance = c;
	vArray[a].push_back(d);
	
	d.node = a;
	vArray[b].push_back(d);
}

void display(int V, vector<data> *vArray)
{
	int i;
	for (i = 0; i < V; i++)
	{
		cout<<"Node "<<i<<"- ";
		for (auto x : vArray[i])
		{
			cout<<x.node<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

template <class T>
struct great
{
	bool operator () (const T &x, const T &y) const
	{
		return x > y;
	}
};

void displayQueue(priority_queue <pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > pQueue)
{
	cout<<"P Queue \n";
	priority_queue <pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>> > copy = pQueue;
	while (!copy.empty())
	{
		cout<< copy.top().second <<",";
		cout<< copy.top().first << endl;
		copy.pop();
	}
}

void displayMST(int V, int *mst)
{
	cout<<"Current Prim's MST\n";
	for (int i=0; i<V; i++)
		cout<<i<<","<<mst[i]<<"  ";
	cout<<endl;
}

void primsMinimumSpanningTree(int V, vector <data> *vArray, int *mst)
{	
	int i;
	priority_queue < pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pQueue;
	
	bool *visited;
	for (i=0; i<V; i++)
		visited[i] = false;
	
	int currNode;
	
	pQueue.push( make_pair( 0,0) );
	
	while(pQueue.empty() != true)
	{
		//displayQueue(pQueue);
		
		currNode = pQueue.top().second;
		if (visited[currNode] == true)
		{
			//cout<<currNode<<" already done. Popping it.\n\n";
			pQueue.pop();
			continue;	
		}
		//cout<<"To push children of : "<<currNode<<endl;
		
		//mst[currNode] = -1 * pQueue.top().first;
		mst[currNode] = pQueue.top().first;
		visited[currNode] = true;
		pQueue.pop();
		
		//cout<<"Popped from Queue: "<<currNode<<endl;
		//displayMST(V, mst);
		
		for (auto x: vArray[currNode])
		{
			if (visited[x.node] == false)
				pQueue.push( make_pair(x.distance, x.node));
		}
		//cout<<endl;
	}
}

int main()
{
	// Graph
	// https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
	// PIC : https://www.geeksforgeeks.org/wp-content/uploads/Fig-11.jpg
	
	// Process 
	// Its simple 
	// Choose a starting node 
	// Its a greedy algorithm, so keep choosing the miminum edge
	// Slowly a tree will form automagically
	
	int nodes = 9;
	
	vector <data> *vArray;
	
	int *mst;
	mst = new int[nodes];
	for (int i=0; i<nodes; i++)
		mst[i] = INF;
	
	init(nodes, &vArray);
	
	addEdge(vArray, 0, 1, 4);
	addEdge(vArray, 0, 7, 8);
	addEdge(vArray, 1, 2, 8);
	addEdge(vArray, 1, 7, 11);
	addEdge(vArray, 2, 3, 7);
	addEdge(vArray, 2, 8, 2);
	addEdge(vArray, 2, 5, 4);
	addEdge(vArray, 3, 4, 9);
	addEdge(vArray, 3, 5, 14);
	addEdge(vArray, 4, 5, 10);
	addEdge(vArray, 5, 6, 2);
	addEdge(vArray, 6, 8, 6);
	addEdge(vArray, 6, 7, 1);
	addEdge(vArray, 7, 8, 7);
	
	display(nodes, vArray);
	
	primsMinimumSpanningTree(nodes, vArray, mst);
	
	displayMST(nodes, mst);
	
	delete [] vArray;
	delete [] mst;
}

