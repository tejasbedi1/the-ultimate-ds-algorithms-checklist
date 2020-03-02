#include <iostream>

using namespace std;

void output(int[], int, int);

void merge(int arr[], int l, int m, int r)
{
	/*
	for(int i=l;i<m;i++)
		cout<<arr[i]<<" ";
	cout<<"& ";
	for(int i=m;i<r;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	*/
	
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
			i++;
		}
		else
		{
			arr[k] = b[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = a[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = b[j];
		j++;
		k++;
	}
	/*
	for(int i=l;i<m;i++)
		cout<<arr[i]<<" ";
	cout<<"& ";
	for(int i=m;i<r;i++)
		cout<<arr[i]<<" ";	
	cout<<endl; */
}

void mergeSort(int a[], int l, int r)
{
	if (r-l > 1)
	{
		int m = (l+r)/2;
		mergeSort(a, l, m);
		mergeSort(a, m, r);
		merge(a,l,m,r);
	}
}

int main()
{
	int a[] = {8,7,6,5,4,3,2};
	output (a,0,7);
	cout<<endl;
	mergeSort (a,0,7);
	cout<<endl;
	output (a,0,7);
}


void output(int a[], int l, int r)
{
	for (int i=l; i<r; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
