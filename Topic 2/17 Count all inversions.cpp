#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

int merge(int *arr, int n, int l, int m, int r, int &count)
{
	int n1 = m-l;
	int n2 = r-m;
	
	int a[n1];
	int b[n2];
	
	for(int i=0;i<n1;i++)
		a[i] = arr[i+l];
	for(int i=0;i<n2;i++) 
		b[i] = arr[i+m];
		
	
	int i, j, k;
	i = 0;
	j = 0;
	k = l;
	
	while (i+l < m && j+m < r)
	{
		if (a[i] <= b[j])
		{
			arr[k] = a[i];
			count += abs(i+l - k);
			i++;
		}
		else
		{
			arr[k] = b[j];
			count += abs(j+m - k);
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = a[i];
		count += abs(i+l - k);
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = b[j];
		count += abs(j+m - k);
		j++;
		k++;
	}
}

void mergeSort(int *arr, int n, int l, int r, int &count)
{
	if (r-l > 1)
	{
		int m = (l + r) / 2;
		mergeSort(arr, n, l, m, count);
		mergeSort(arr, n, m, r, count);
		merge(arr, n, l, m, r, count);	
	}
}


void output(int *arr, int l, int r)
{
	for (int i=l; i<r; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int solve(int *arr, int n)
{
	int count = 0;
	mergeSort(arr, n, 0, n, count);
	if (LOG_LEVEL >= 2) output(arr, 0, n);
	
	// 2 elements chaging position is 1 inversion, logic sees it as 2
	count = count/2;	
	debug (1, "Inversion Count: ", count, "\n");
}

int main()
{
	// INVERSIONS
	// Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
	// eg {8,4,2,1}
	// ANS 6, [ 8 +3, 4 +2, 2 +1 ]
	
	// Resource
	// D&C - https://www.geeksforgeeks.org/counting-inversions/
	// Using Merge Sort to count inversions
	// Disadvatage, Array is ultimatley swapped
	
	// COMPLEXITY - O(n log(n))
	
	LOG_LEVEL = 3;
	
	int arr[] = {8, 4, 2, 1}; // 6
	//int arr[] = {1, 20, 6, 4, 5}; // 5
	
	int size = sizeof(arr)/sizeof(arr[0]);
	
	solve (arr, size);
}
