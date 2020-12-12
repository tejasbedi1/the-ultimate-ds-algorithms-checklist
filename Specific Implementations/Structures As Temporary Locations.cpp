#include <iostream>

using namespace std;

struct node 
{
	int data;
};

void access()
{
	node n;
	cout<<n.data<<endl;
}
int main ()
{
	node n;
	n.data = 1;
	access();
	//cout<<n.data<<endl;
	
}
