#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	vector<int> v1;
	v1.push_back(1); 
	v1.push_back(2);
	v1.push_back(3);
	
	for (int j=0;j<3;j++)
		cout<<v1[j]<<" ";
	cout<<endl<<endl;
	
	vector< vector<int> > v (3);
	//v.push_back(0);
	v[0].push_back(1); v[0].push_back(1);
	v[1].push_back(2); v[1].push_back(2);
	v[2].push_back(3); v[2].push_back(3);
	for (int i=0;i<3;i++)
	{
		for (int j=0;j<2;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	v.push_back(v1);
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<2;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
