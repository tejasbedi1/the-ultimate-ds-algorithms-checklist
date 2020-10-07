#include <iostream>

using namespace std;

void output(int[], int, int);

int partition (int a[], int l, int r)
{
	int pvtEle = a[l];
	int pvtPos = l;
	for (int i=l;i<=r;i++)
	{
		if (pvtEle > a[i])
		{
			a[pvtPos] = a[i];
			a[i] = pvtEle;
			pvtPos = i;
		}
	}
	return pvtPos;
}

void quickSort(int a[], int l, int r)
{
	if (l<r)
	{
		int p = partition(a,l,r);
		quickSort(a,l,p-1);
		quickSort(a,p+1,r);
	}
}
int main()
{
	//int a[] = {8,7,6,5,4,3,2,1};
	int a[] = {1,8,2,7,3,6,4,5};
	output (a,0,7);
	cout<<endl;
	quickSort (a,0,7);
	cout<<endl;
	output (a,0,7);
}


void output(int a[], int l, int r)
{
	for (int i=l; i<=r; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
