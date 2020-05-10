#include <iostream>

using namespace std;

void swapByValue (int a, int b)
{
	a = a + b;
	b = a - b;
	a = a - b;
	cout<<a<<" "<<b<<endl;
}

void swapByReference (int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp; 
	cout<<*a<<" "<<*b<<endl;
}

int main ()
{
	int a = 5, b = 10;
	
	swapByValue(a,b);
	cout<<a<<" "<<b<<endl;
	swapByReference(&a,&b);
	cout<<a<<" "<<b<<endl;
}
