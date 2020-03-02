#include <iostream>

using namespace std;

void printFibonacci (int size)
{
	int a, b, c;
	a = 0; b = 1;
	
	cout << a << endl;
	cout << b << endl;
	
	for (int i; i<size; i++)
	{
		c = a + b;
		cout << c <<endl;
		a = b;
		b = c;
	}
}

int main ()
{
	printFibonacci(10);
}
