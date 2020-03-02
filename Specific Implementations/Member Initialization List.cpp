#include <iostream>

using namespace std;

struct data 
{
	int id;
	int power; 
	
	data (int a, int b) : id (a), power (b)
	{
		
	}
};

int main()
{
	// RESOURCE 1
	// https://stackoverflow.com/questions/1711990/what-is-this-weird-colon-member-syntax-in-the-constructor
	
	// RESOURCE 2 WHEN TO USE IT (6th one is important xD)
	// https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/
	
	data d(1,10);
	cout<<d.id<<" "<<d.power<<endl;
}
