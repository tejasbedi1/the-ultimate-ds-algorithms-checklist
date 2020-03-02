//https://algorithms.tutorialhorizon.com/dynamic-programming-coin-in-a-line-game-problem/
#include <iostream>
using namespace std;

void solve(int* arr, int size);
void outputAGG(int *arr, int first, int last);
void output(int* arr, int size);

int main()
{
	int size = 6;
	int *arr = new int[6];
	
	//int array[] = {6,9,1,16,2,8};
	int array[] = {4,15,7,3,8,9};
	output(array, size);
	solve(array, size);
	delete arr;
}

void solve(int* arr, int size)
{
	int user;
	int first, last;
	int total[] = {0,0};
	first = 0;
	last = size-1;
	user = 0;
	
	int maxF, maxL;
	
	cout<<"\nUsing Optimal Strategy..\n";	
	while (user<size)
	{
		outputAGG(arr,first,last);
		cout<<user%2<<" chooses ";
		// If u first ele
		if (arr[first+1] >= arr[last])
			maxF = arr[first+1];
		else 
			maxF = arr[last];
		// If u last ele
		if (arr[first] >= arr[last-1])
			maxL = arr[first];
		else
			maxL = arr[last-1];
		// If max after choosing first is greatest then choose last
		if (maxF >= maxL)
		{
			cout<<arr[last]<<"\n\n";
			total[user%2] += arr[last];
			last = last-1; 
		}	
		else 
		{
			cout<<arr[first]<<"\n\n";
			total[user%2] += arr[first];
			first = first+1;
		}
		user++;
	}
	cout<<"TOTAL\n";
	cout<<"USER 0: "<<total[0]<<"\nUSER 1: "<<total[1]<<endl;
}

void outputAGG(int *arr, int first, int last)
{
	for (int i=first; i<=last; i++)
	{
		cout<<arr[i]<<" ";
	}	
	cout<<endl;
}

void output(int *arr, int size)
{
	for (int i=0; i<size; i++)
	{
		cout<<arr[i]<<" ";
	}	
	cout<<endl;
}
