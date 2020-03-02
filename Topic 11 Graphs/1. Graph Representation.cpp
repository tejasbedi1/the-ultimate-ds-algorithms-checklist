#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void addEdgeToList(vector <int> vArray[], int a, int b)
{
	vArray[a].push_back(b);
	vArray[b].push_back(a);
}

void display(vector <int> vArray[], int v)
{
	int i;
	for (i = 0; i < v; i++)
	{
		cout<<"Node "<<i<<" - ";
		for (auto x : vArray[i])
		{
			cout<<x<<" ";
		}
		cout<<endl;
	}
}

void addEdgeToArray(int **arr, int a, int b)
{
	arr[a][b] = 1;
	arr[b][a] = 1;
}

void displayMatrix (int v , int **arr)
{
	int i, j;
	for (i = 0; i < v; i++)
	{
		for (j = 0; j < v; j++)
		{
			cout<<arr[i][j]<<" ";	
		}	
		cout<<endl;
	}
}

int main()
{
	// Adjecency List
	
	int nodes = 3, i,j;
	vector <int> vArray[nodes];
	
	addEdgeToList(vArray, 0, 1);
	addEdgeToList(vArray, 1, 2);
	addEdgeToList(vArray, 2, 0);
	
	cout<<"LIST\n";
	display (vArray, nodes);
	
	// Adjecency Marix
	nodes = 4;
	int **arr = new int*[nodes];
	for(i=0; i<nodes ; i++)
		arr[i] = new int[nodes];
 		
	for (i = 0; i<nodes; i++)
		for (j = 0; j<nodes; j++)
			arr[i][j] = 0;
	
	addEdgeToArray(arr, 0, 1);
	addEdgeToArray(arr, 1, 2);
	addEdgeToArray(arr, 2, 3);	
	addEdgeToArray(arr, 3, 0);	
	
	cout<<"\nMATRIX\n";
	displayMatrix(nodes, arr);
}

