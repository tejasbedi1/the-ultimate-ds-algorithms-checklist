#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main ()
{
	multiset <int> ms;
	
	ms.insert(40);
	ms.insert(10);
	ms.insert(20);
	ms.insert(70);
	ms.insert(5);
	ms.insert(40);
	
	multiset <int> :: iterator itr;	
	for (itr = ms.begin(); itr != ms.end(); itr++)
	{
		cout<<*itr<<" ";
	}
	cout<<endl;
	ms.erase(ms.find(40)); // erases one
	//ms.erase(40);
	for (itr = ms.begin(); itr != ms.end(); itr++)
	{
		cout<<*itr<<" ";
	}
	cout<<endl;
	cout<<*--ms.end();
}
