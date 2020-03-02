#include <iostream>

using namespace std;

struct info
{
	int i;
	int j;
	
	info(int i , int j) : i(i), j(j)
	{
	} 
};

int main()
{
	info i(7,9);
	cout<<i.i<<endl;
	cout<<i.j<<endl;
}
