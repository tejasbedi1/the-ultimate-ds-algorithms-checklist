#include <iostream>
using namespace std;

int main ()
{
	//int a[] = {1, -2, 1, 1, -2, 1};
	//int a[] = {-2, -2, -1, -1, -2, -1};
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int size = 8;
	int i, ml = 0, mh = 0;
	int max = INT_MIN;
	int altmax = 0, l=0;
	
	for (int i=0;i<size;i++)
	{
		altmax += a[i];
		if (altmax > max)
		{
			max = altmax;
			mh = i;
			ml = l;
		}
		if (altmax < 0)
		{
			altmax = 0;
			l = i+1;
		}
	}
	cout<<max<<" ie from position "<<ml<<" to "<<mh<<endl;
} 
