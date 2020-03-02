#include <iostream>

using namespace std;

void printTo (int a, int b)
{
	if (a % 100 == 0)
		cout << a << endl;
	a = a + 1;
	if (a <= b)
		printTo(a,b);
}

void printFrom (int a)
{
	//cout << a << endl;
	a = a - 1;
	if (a >= 1)
		printFrom(a);
}

int main ()
{
	printTo(1,10000);
	cout<<"Done\n";
	printFrom(10000);
	cout<<"Done\n";
}
