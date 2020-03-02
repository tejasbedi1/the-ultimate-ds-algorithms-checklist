#include <iostream>
using namespace std;

int main()
{
	int n,count;
	cin>>n;
	//n = 7;
	if (n%2 == 0 || n <= 5)
	{
		cout<<"xD, Ghadhe that's incompatible!!\n";
		exit(0);
	}
	int j,i;
	for (i=0;i<n;i++)
	{
		if (i == 0)
		{
			for(j=0;j<n;j++)
			{
				if (j==0 || j>=n/2)
					cout<<"*";
				else
					cout<<" ";
			}
			cout<<endl;
		}
		else if (i == n-1)
		{
			for(j=0;j<n;j++)
			{
				if (j==n-1 || j<=n/2)
					cout<<"*";
				else
					cout<<" ";
			}
			cout<<endl;
		}
		else if (i == n/2)
		{
			for(j=0;j<n;j++)
			{
				cout<<"*";
			}
			cout<<endl;
		}
		else
		{
			for(j=0;j<n;j++)
			{
				
				if (i < n/2)
				{
					if (j == 0 || j == n/2)
						cout<<"*";
					else
						cout<<" ";
				}
				if (i > n/2)
				{
					if (j == n-1 || j == n/2)	
						cout<<"*";	
					else
						cout<<" ";
				}
			}
			cout<<endl;
		}
	}
}

