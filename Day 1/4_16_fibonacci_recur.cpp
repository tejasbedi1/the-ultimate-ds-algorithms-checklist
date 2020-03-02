#include <iostream>

using namespace std;

void printFibonacci (int a, int b, int size)
{
	cout << a+b << endl;
	
	if (size > 0)
	{
		size = size - 1;
		printFibonacci (b, a+b, size);
	} 
}

int main ()
{
	cout << "0" << endl;
	cout << "1" << endl;
	
	printFibonacci(0,1,10);
}
