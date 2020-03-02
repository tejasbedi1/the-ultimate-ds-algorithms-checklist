#include <bits/stdc++.h>
#include <iostream>

#define S 0
#define A 1
#define B 2
#define C 3
#define D 4
#define X 4
#define Y 5
#define Z 6
#define INF 9000

using namespace std;

class Graph
{
	
private:
	
	struct info
	{
		int node;
		int edge;
	};
	
	int V;
	int i;
	int j;
	int k;
	int **arr;
	int *distance;
	bool *distAssigned;
	bool *visited;
	
	vector < info > *vArray;
	map <int, char> labelMap;
	map <int, char> :: iterator itr;
	
public:		
	Graph(int V)
	{
		this->V = V;
		
		arr = new int*[V];
		for (i = 0; i<V; i++)
			arr[i] = new int[V];
 		
		for (i = 0; i<V; i++)
			for (j = 0; j<V; j++)
				arr[i][j] = INF;
			
		distance = new int[V]; 
		for (i = 0; i<V; i++)
			distance[i] = 0;
		
		distAssigned = new bool[V];
		for (i = 0; i<V; i++)
			distAssigned[i] = false;
		
		visited = new bool[V];
		for (i = 0; i<V; i++)
			visited[i] = false;
			
		vArray = new vector < info > [V];
	}
	
	void addEdge(int a, int b, int c)
	{
		info info;
		info.node = b;
		info.edge = c;
		vArray[a].push_back( info );
	}
	
	void setMap()
	{
		labelMap.insert( make_pair(0,'S') );
		labelMap.insert( make_pair(1,'A') );
		labelMap.insert( make_pair(2,'B') );
		labelMap.insert( make_pair(3,'C') );
		labelMap.insert( make_pair(4,'X') );
		labelMap.insert( make_pair(5,'Y') );
		labelMap.insert( make_pair(6,'Z') );
	}
	
	void johnsonsAlgorithm()
	{
		// Introduce a variable s to Graph G
		for (i = 1; i < V; i++)
			addEdge(S, i, 0);	
		
		// Display the Graph G'
		cout<<"New Graph: G'\n";
		displayGraph();
		
		// Apply bellman ford to get minimum weights for each node
		bellmanFord(S);
		if (doesANegativeCycleExist(S) == true)
		{
			cout<<"\nNEGATIVE CYCLE EXISTS. ENDING\n";
			return;
		}
		else
			cout<<"\nNo negative cycle.\n\n";
		
		// Final Distances
		viewDistances();
		
		// Calculate new weights for each edge
		cout<<"\nAfter altering edge weights\n";
		calculateNewWeights();
		displayGraph();
		
		// Dijkstra's Algorithm
		cout<<"\nUsing Dijkstra's\n";
		
		dijkstrasAlgorithm();
		cout<<"\nFinal Paths-\n";
		viewShortestPairArray();
		
		// FINAL PATH LENGHTS
		cout<<"\nUsing Dijkstra's Output and The weights we calculated earlier \n";
		calculateFinalWeights();
		viewShortestPairArray();
	}
	
	void calculateFinalWeights()
	{
		for (i = 1; i < V; i++)
		{
			for (j = 1; j < V; j++)
			{
				// final distance(u, v) = dijkstraOutput(u , v) + d(v) - d(u)
				//cout<<arr[i][j]<<" + "<<distance[j]<<" - " <<distance[i]<<endl;
				arr[i][j] = arr[i][j] + distance[j] - distance[i];
			}
		}	
	}
	
	void dijkstrasAlgorithm()
	{ 
		for (i = 1; i < V; i++)
		{
			cout<<"Current Source - "<<i<<endl;
			
			arr[i][i] = 0;
			
			falseAllVisited();
			
			int currentNode = nodeWithMinimumDistance(i);
			
			dijkDistancesRecur( currentNode, currentNode );
		}
	}
	
	void dijkDistancesRecur(int src, int currNode)
	{
		for (info x : vArray[currNode])
		{
			if (arr[src][x.node] > x.edge + arr[src][currNode] && visited[x.node] == false)
			{
				arr[src][x.node] = x.edge + arr[src][currNode];
			}
		}
		visited[currNode] = true;
		
		currNode = nodeWithMinimumDistance(src);
		if (currNode != -1)
			dijkDistancesRecur(src, currNode);
	}
	
	int nodeWithMinimumDistance(int i)
	{
		int least = INT_MAX;
		for (j = 1; j < V; j++)
		{
			if (visited[j] == false)
			{
				if (arr[i][j] < least)
					least = j;
			}	
		}
		if (least == INT_MAX)
			return -1;
		else
			return least;
	}
	
	void falseAllVisited ()
	{
		for (j = 0; j<V; j++)
			visited[j] = false;
	}
	
	void calculateNewWeights()
	{
		for (i = 1; i < V; i++)
		{
			// Cant use the following implementation cause it creates a local copy
			//for (info x : vArray[i])
			for (j = 0; j < vArray[i].size(); j++)
			{
				// New weight = old weight + distance node 1 + distance node 2
				// new w(u, v) = old w(u, v) + d(u) - d(v)
				vArray[i][j].edge = vArray[i][j].edge + distance[i] - 
													distance[vArray[i][j].node];
				//cout<<"New Edge "<<i<<","<<vArray[i][j].node<<" = "
				//									<<vArray[i][j].edge<<endl;
			}	
		}
			
	}
	
	void bellmanFord(int src)
	{
		bool flag;
		distance[src] = 0;
		distAssigned[src] = true;
		
		for (k = 0; k < V-1; k++)
		{
			flag = false;	
			for (i = 0; i < V; i++)
			{
				for (info x : vArray[i])
				{
					if (distance[i] + x.edge < distance[x.node] && 
														distAssigned[src] == true)
					{
						distance[x.node] = distance[i] + x.edge;
						flag = true;
					}
					else if (distAssigned[src] == false)
					{
						distance[x.node] = x.edge;
						distAssigned[src] = true;
					}
				}
			}
			//viewDistances();
			if (flag == false)
				break;
		}
	}
	
	bool doesANegativeCycleExist(int src)
	{
		bool flag;
		flag = false;	
		
		for (i = 0; i < V; i++)
		{
			for (info x : vArray[i])
			{
				if (distance[i] + x.edge < distance[x.node] && 
													distAssigned[src] == true)
				{
					distance[x.node] = distance[i] + x.edge;
					flag = true;
				}
			}
		}
		return flag;
	}
	
	void viewShortestPairArray()
	{
		cout<<"\n    ";
		for (i = 1; i < V; i++)
		{
			itr = labelMap.find(i);
			cout<<itr->second<<"  ";
			//cout<<i<<"  ";
		}
		cout<<endl<<endl;
		for (i = 1; i < V; i++)
		{
			itr = labelMap.find(i);
			cout<<itr->second<<"   ";
			//cout<<i<<"   ";
			for (j = 1; j < V; j++)
			{
				if (arr[i][j] > INF - 1000)
					cout<<"I  ";
				else
					cout<<arr[i][j]<<"  ";	
			}
			cout<<endl;
		}  	
	}
	
	void viewDistances()
	{
		cout<<"Distances - ";
		for (i = 0; i < V; i++)
		{
			cout<<distance[i]<<" ";
		}	
		cout<<endl;
	}
	
	void displayGraph ()
	{
		
		for (i = 0; i < V; i++)
		{
			itr = labelMap.find(i);
			//cout<<i<<" - ";
			cout<<itr->second<<" - ";
			for (info x : vArray[i])
			{
				//cout<<"("<<x.node<<","<<x.distance<<") ";
				itr = labelMap.find(x.node);
				cout<<"("<<itr->second<<","<<x.edge<<") ";
			}	
			cout<<endl;
		}
	}
	
	void deallocateMemory()
	{
		for (i = 0; i<V; i++)
			delete [] arr[i];
		delete [] arr;
		
		delete [] distance;
		delete [] distAssigned;
		delete [] visited;
 		delete [] vArray;
	}
};



int main()
{
	/* 	THE PROCESS 
	* 	Store in appropriate data structure
	* 	1. Add a SOURCE node which is at a distance of 0 from every node
	* 		We'll call the resulting graph G'
	* 	2. Run Bellman ford on G' from S once
	*		The reulting distances, will now be used as reference weights 
	*		to remove negative edges from the graph
	*	3. Run the new edge calculation formula which is
	*	 	new edge e (u, v) = e(u, v) + w(u) - w (v)
	*			e = edge length w = calculated weights / distance whatev
	*	4. Run Dijkstra on the new all positive graph talking very 
	*		node as source once. So basically it will run V times :0
	* 	5. The result will be 2D array detailing distance between each pair
	*		but that's for the dijkstra's version we need to convert this into 
	* 		the orignal Graph G with negative weights and everything else.
	* 		To do this we run e (u, v) = e (u, v) + w (v) - w(u)
	* 									^ Remember v - u ^ 
	* 	Resources on trello
	*/
	
	int nodes;
	
	nodes = 7;				//	1
	//nodes = 5;				//  2
	
	Graph graph(nodes);
	graph.setMap();
	
	/*             -2 			//	1
	*		a	-------->	b	
	*		 <			  /
	*		 4 \	    / -1
	*			 \	c <		
	*			  /   \
	*		 2	/	    \ -3
	*		x <			  > y
	*		 <			   >
	*		 1 \         / -4
	*		     - 	z  -
	*/
	
	graph.addEdge(A, B, -2); 	// 	1
	graph.addEdge(B, C, -1);
	graph.addEdge(C, A,  4);
	graph.addEdge(C, Y, -3);
	graph.addEdge(C, X,  2);
	graph.addEdge(Z, Y, -4);
	graph.addEdge(Z, X,  1);
	
	/*
	graph.addEdge(A, B, -3);   //	2
	graph.addEdge(B, A,  5);
	graph.addEdge(B, C,  3);
	graph.addEdge(C, A,  1);
	graph.addEdge(A, D,  2);
	graph.addEdge(D, A, -1);
	graph.addEdge(D, C,  4);
	*/
	cout<<"INPUT MATRIX\n";
	graph.displayGraph();
	
	cout<<"\nAlgorithm Output\n\n";
	graph.johnsonsAlgorithm();
	
	graph.deallocateMemory();
}

