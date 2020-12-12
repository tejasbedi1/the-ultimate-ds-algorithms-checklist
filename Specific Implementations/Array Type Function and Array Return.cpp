#include <iostream>

using namespace std;

int *calc (int* arr)
{
	arr[0] = 100; 
	
	return arr;
}

int main()
{
	int n, i;
	cin>>n;
	
	int* arr = new int[n];
	
	for (i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	arr = calc(arr);
	for (i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

