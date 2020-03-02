#include <iostream>

using namespace std;

void output(int arr[]);

void bubbleSort(int arr[]);

int main()
{
	int arr[] = {5,4,3,2,1};
	output (arr);
	bubbleSort(arr);
	output (arr);
}

void bubbleSort(int arr[])
{
	int i,j, temp;
	for (i=0; i<5; i++)
	{
		for (j=0; j<5-1; j++)
		{
			//cout<<"Swapping these "<<arr[j]<<" "<<arr[j+1]<<endl;
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
 			}
		}
	}
}

void output(int arr[])
{
	for (int i=0; i<5; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
