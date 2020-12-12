#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

// B, Beautified Display
void display2DArray(int **arr, int r, int c, int *a)
{
	int i,j;
	
	cout<<"   | 0  ";
	for (i=0; i<c-1; i++)
		if (a[i+1] < 10)
			cout<<a[i]<<"  ";
		else
			cout<<a[i]<<" ";
	cout<<endl;
	
	for (i=0; i<r; i++)
	{
		if (i<10)
			cout<<i<<"  | "; // B
		else
			cout<<i<<" | "; // B
			
		for (j=0; j<c; j++)
			if (arr[i][j] < 10)
				cout<<arr[i][j]<<"  ";
			else
				cout<<arr[i][j]<<" ";
		cout<<"\n";
	}
	cout<<"\n";
}

void set2DArray(int **tab, int r, int c, int set)
{
	int i,j;
	for (i=0; i<r; i++)
		for (j=0; j<c; j++)
			tab[i][j] = set;
}

void solution(int *arr, int n, int tSum)
{
	int i,j;
	int r = tSum+1;
	int c = n+1;
	
	//int ** array = new int*[col];
	//for(int i=0; i<row ; i++)
 	//	array[i] = new int[row];
	
	int **tab = new int* [r];
	for (i=0; i<r; i++)
		tab[i] = new int [c];
	
	set2DArray(tab, r, c, 0);
	if (LOG_LEVEL >= 3) display2DArray(tab, r, c, arr);
	
	// First Row is entirely 0, so True basically
	for (j=0; j<c; j++)
		tab[0][j] = 1;
	// Also presetting the first column with 0 subsets
	for (i=1; i<r; i++)
		tab[i][0] = 0;
		
	if (LOG_LEVEL >= 2) display2DArray(tab, r, c, arr);
	
	for (j=1; j<c; j++)
	{
		for (i=0; i<r; i++)
		{
			if (tab[i][j-1] == 1)
			{
				tab[i][j] = 1;
				if (i+arr[j-1] < r)
					tab[i+ arr[j-1]][j] = 1;
					
			}
		}
	}
	
	if (LOG_LEVEL >= 1) display2DArray(tab, r, c, arr);
	
	// Finding Subset for 11 and 10;
	int toFind;
	toFind = tSum;
	debug (1, "Subset for: ", toFind, "\n");

	while (1)
	{
		for (j=0; j<c; j++)
		{
			if (tab[toFind][j] == 1)
			{
				debug (1, arr[j-1], " ");
				toFind = toFind - arr[j-1];
				break;
			}
		}	
		if (toFind == 0)
			break;
	}
}

int solving(int *arr, int n)
{
	int i;
	int sum=0;
	
	for (i=0; i<n; i++)
		sum += arr[i];
		
	if (sum % 2 == 0)
		solution (arr, n, sum/2);
	else
		debug (1, "No possible solution\n");
}

int main()
{
	// PARTITION PROBLEM 
	// https://en.wikipedia.org/wiki/Partition_problem
	
	// RESOURCE 
	// https://www.educative.io/courses/grokking-dynamic-programming-patterns-for-coding-interviews/3jEPRo5PDvx
	// https://www.geeksforgeeks.org/partition-problem-dp-18/
	// https://www.ideserve.co.in/learn/set-partition-problem-dynamic-programming
	// [YOUTUBE] https://www.youtube.com/watch?v=s6FhG--P7z0
	
	// NP Complete Problem (A famous one at that)
	// Greedy Approach only finds approximate solution
	// Dynamic Solution needs a lot of memory
	
	// Dynamic Solution Complexity 0(sum * n)
	// Dynamic Solution Space Complexity 0(sum * n)
	// Dynamic Programming with Memoization
	
	// NOTE 
	// Has problem with negative numbers
	
	LOG_LEVEL = 3;
	
	int k;

	// Ex 1
    //int arr[] = {1, 5, 11, 5};
    // Ex 2
 	// int arr[] = {1, 5, 3};
 	// Ex 3
 	int arr[] = {-1, -5, -11, -5};
 	// Ex 4
    //int arr[] = {6, 7, 8, 0, 103, 4, 92, 57, 26, 23};
    //int arr[] = {3, 4, 5, -3, 100, 1, 89, 54, 23, 20};
    
	int size = sizeof(arr)/sizeof(arr[0]);
	
	solving(arr, size);
}
