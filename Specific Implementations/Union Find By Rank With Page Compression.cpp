#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

struct subset
{
	int parent;
	int rank;
};

void displayStruct(int size, subset *sub)
{
	int i;
	for (i=0; i<size; i++)
	{
		cout<<i<<","<<sub[i].parent<<",r"<<sub[i].rank<<"  ";
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

//Modified for Path Compression
int find(subset *sub, int i)
{
	if (sub[i].parent != i)
		sub[i].parent = find(sub, sub[i].parent);
	return sub[i].parent;
}

void unionFunc(subset *sub, int a, int b)
{
	int aPar = find (sub, a);
	int bPar = find (sub, b);
	
	if (aPar != bPar)
	{
		if (sub[bPar].rank >= sub[aPar].rank)
		{
			sub[aPar].parent = bPar;
			sub[bPar].rank += sub[aPar].rank + 1;
			cout<<a<<"'s parent "<<aPar<<" has been assigned a new parent ";
			cout<<bPar<<endl;
			cout<<"Because "<<bPar<<" has a higher rank\n";
		}
		else
		{
			sub[bPar].parent = a;
			sub[aPar].rank += sub[bPar].rank + 1;
			cout<<b<<"'s parent "<<bPar<<" has been assigned a new parent ";
			cout<<aPar<<endl;
			cout<<"Because "<<aPar<<" has a higher rank\n";
		}
	}
	else
	{
		// If this runs then it would also mean that .. 
	 	// a cycle was just detected
		cout<<" ..Hmmm, seems like both belong to the same subset i.e "<<bPar<<endl;
		cout<<"Nothing to do/see here, carry on.\n";
	}
}

struct comparison 
{
	bool operator () (edge const &A, edge const &B)
	{
		return A.distance < B.distance;
	}	
};

int main()
{
	// This implementation contaions
	// UNION And FIND Operations BY RANK AND PATH COMPRESSION
	
	// Find: Determine which subset a particular element is in. This can be used for 
	//		determining if two elements are in the same subset.
	// Union: Join two subsets into a single subset
	
	// PATH COMPRESSION: Just involves modifying the find function
	// 	Whenever find is called for any node/element it makes that element 
	//		point directly to its parent (Basically no more long traversals)
	// 	The leads to "amortized time complexity" effectively making it a  small constant
	// NOTE: In page compression, A node which does not have a parent is its own parent
	
	// Union and Find are generally used to find -
	// a. If a certain undirected graph contains cycles	
	// b. Combine Disjoint Sets in Graphs
	
	// RESOURCE GFG
	// https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
	// https://stackoverflow.com/questions/29998332/detect-cycle-in-a-graph-using-kruskals-algorithm
	p
	// GRAPH https://www.geeksforgeeks.org/wp-content/uploads/Fig-0-300x139.jpg
	
	int nodes = 9, i;
	vector <edge> edgeList;
	edge e;
		
	// In this implementation distance data is used
	// 		just to create some randomness in the entered data
	
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
	
	sort(edgeList.begin(), edgeList.end(), comparison());
	
	cout<<"Edge Data\n";
	displayVector(edgeList);
	cout<<endl;
	
	subset *sub;
	sub = new subset[nodes];
	for (i=0; i<nodes; i++)
	{
		sub[i].parent = i;
		sub[i].rank = 0;
	}
	
	for (auto x : edgeList)
	{
		cout<<"Evaluating "<<x.nodeA<<","<<x.nodeB<<endl;

		if (sub[x.nodeA].parent == x.nodeA  && sub[x.nodeB].parent == x.nodeB )
		{
			cout<<"Both unassigned\n";
			if (sub[x.nodeB].rank >= sub[x.nodeA].rank)
			{
				cout<<x.nodeB<<" has a higher rank\n";
				sub[x.nodeA].parent = x.nodeB;
				sub[x.nodeB].rank++;	
			}
			else
			{
				cout<<x.nodeA<<" has a higher rank\n";
				sub[x.nodeB].parent = x.nodeA;
				sub[x.nodeA].rank++;
			}
		}
		else if (sub[x.nodeA].parent != x.nodeA && sub[x.nodeB].parent == x.nodeB)
		{
			cout<<"NodeA has a parent\n";
			unionFunc (sub, x.nodeB, x.nodeA); // Sending parentless first
		}
		else if (sub[x.nodeA].parent == x.nodeA  && sub[x.nodeB].parent != x.nodeB)
		{
			cout<<"NodeB has a parent\n";
			unionFunc (sub, x.nodeA, x.nodeB); // Sending parentless first
		}
		else if ( sub[x.nodeA].parent != x.nodeA  && sub[x.nodeB].parent != x.nodeB )
		{
			cout<<"Both have parents\n";
			unionFunc (sub, x.nodeA, x.nodeB); // Any order
		}
		displayStruct(nodes, sub);
		cout<<endl;
	}
	
	delete [] sub;
}

