#include <iostream>
#include <vector>
using namespace std;

struct subset
{
	int data;
	int parent;	
};

struct edge
{
	int nodeA;
	int nodeB;
	int distance;
	
	set(int a, int b, int c)
	{
		nodeA = a;
		nodeB = b;
		distance = c;
	}
};

void displayArray(int size, int *array)
{
	int i;
	for (i=0; i<size; i++)
	{
		cout<<i<<","<<array[i]<<"  ";
	}
	cout<<endl;
}

void displayVector(vector <edge> &edgeList)
{
	for (auto x : edgeList)
	{
		cout<<x.nodeA<<","<<x.nodeB<<" "<<x.distance<<endl;		
	}	
}

int find(int *parent, int i)
{
	if (parent[i] == -1)
		return i;
	find(parent, parent[i]);
}	

void unionFunc(int *parent, int a, int b)
{
	cout<<a<<" assigned parent ";
	a = find (parent, a);
	b = find (parent, b);
	
	if (a != b)
	{
		parent[a] = b;	
		cout<<b<<endl;
	}
	else
	{
		// If this runs then it would also mean that .. 
	 	// a cycle was just detected
		cout<<" ..Hmmm, seems like both belong to the same subset i.e "<<b<<endl;
		cout<<"Nothing to do/see here, carry on.\n";
	}
}

int main()
{
	// This implementation contaions
	// UNION And FIND Operations
	
	// Find: Determine which subset a particular element is in. This can be used for 
	//		determining if two elements are in the same subset.
	// Union: Join two subsets into a single subset
	
	// Union and Find are generally used to find if a certain undirected graph 
	//		contains cycles	
	
	// RESOURCE GFG
	// https://www.geeksforgeeks.org/union-find/
	// https://stackoverflow.com/questions/29998332/detect-cycle-in-a-graph-using-kruskals-algorithm
	
	// GRAPH https://www.geeksforgeeks.org/wp-content/uploads/Fig-0-300x139.jpg
	int nodes = 9, i;
	vector <edge> edgeList;
	edge e;
	
	// In this implementation distance data is useless
	// 		but it was already present in the example
	//		I was reffering,
	// 		So just ignore it..
	
	e.set(0, 1, 4);
	edgeList.push_back( e );
	e.set(0, 7, 8);
	edgeList.push_back( e );
	e.set(1, 2, 8);
	edgeList.push_back( e );
	e.set(1, 7, 11);
	edgeList.push_back( e );
	e.set(2, 3, 7); 
	edgeList.push_back( e );
	e.set(2, 8, 2);
	edgeList.push_back( e );
	e.set(2, 5, 4);
	edgeList.push_back( e );
	e.set(3, 4, 9); 
	edgeList.push_back( e );
	e.set(3, 5, 14);
	edgeList.push_back( e );
	e.set(4, 5, 10);
	edgeList.push_back( e );
	e.set(5, 6, 2); 
	edgeList.push_back( e );
	e.set(6, 8, 6);
	edgeList.push_back( e );
	e.set(6, 7, 1);
	edgeList.push_back( e );
	e.set(7, 8, 7);
	edgeList.push_back( e );
	
	cout<<"Edge Data\n";
	displayVector(edgeList);
	cout<<endl;
	
	int *parent;
	parent = new int[nodes];
	for (i=0; i<nodes; i++)
	{
		parent[i] = -1;
	}
	
	for (auto x : edgeList)
	{
		cout<<"Evaluating "<<x.nodeA<<","<<x.nodeB<<endl;

		if ( parent[x.nodeA] == -1  && parent[x.nodeB] == -1 )
		{
			cout<<"Both unassigned\n";
			parent[x.nodeA] = x.nodeB;
		}
		else if (parent[x.nodeA] != -1  && parent[x.nodeB] == -1)
		{
			cout<<"NodeA has a parent\n";
			unionFunc (parent, x.nodeB, x.nodeA); // Sending parentless first
		}
		else if (parent[x.nodeA] == -1  && parent[x.nodeB] != -1)
		{
			cout<<"NodeB has a parent\n";
			unionFunc (parent, x.nodeA, x.nodeB); // Sending parentless first
		}
		else if ( parent[x.nodeA] != -1  && parent[x.nodeB] != -1 )
		{
			cout<<"Both have parents\n";
			unionFunc (parent, x.nodeA, x.nodeB); // Any order
		}
		displayArray(nodes, parent);
		cout<<endl;
	}
	
	delete [] parent;
}

