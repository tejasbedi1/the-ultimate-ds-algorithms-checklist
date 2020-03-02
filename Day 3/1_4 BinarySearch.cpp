#include <iostream>
using namespace std;

void output(int arr, int size)
{
	
}

int main ()
{
	int arr[] = {10,20,30,40,50,60,70,80,90,100};
	int start = 0, end = 9,i, mid;
	int search = 10;
	
	for (i=start; i<=end; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	for (i=start; i<=end; i++)
		cout<<i<<"  ";
	cout<<endl;
	
	while (start<=end)
	{
		mid = (start+end)/2;
		if (arr[mid] == search)
			break;
		else if (arr[mid] > search)
			end = mid-1;
		else if (arr[mid] < search)
			start = mid+1;
	}
	cout<<arr[mid]<<" at "<<mid;
}
