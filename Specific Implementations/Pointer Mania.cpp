#include <iostream>

using namespace std;

void c(int a)
{
	a = 7;
	cout<<"External CBV: "<<a<<endl;
}
void cRef(int &a)
{
	a = 7;
	cout<<"External CBR: "<<a<<endl;
}

void pointerInt()
{
	int a = 5;
	cout<<"Main: "<<a<<endl;
	c(a);
	cout<<"Main after CBV external: "<<a<<endl;
	cRef(a);
	cout<<"Main after CBR external: "<<a<<endl;
}

struct data
{
	int d;
};

void e(data d)
{
	d.d = 5;
	cout<<"External CBV: "<<d.d<<endl;
}

void eRef (data &d)
{
	d.d = 5;
	cout<<"External CBR: "<<d.d<<endl;
}

void pointerStruct()
{
	data d;
	d.d = 2;
	cout<<"Main: "<<d.d<<endl;
	e(d);
	cout<<"Main after CBV external: "<<d.d<<endl;
	eRef(d);
	cout<<"Main after CBV external: "<<d.d<<endl;
}

void f(int *c)
{
	int a = 5;
	c = &a;
	cout<<"External CBV: Pointer Pointing To Value "<<*c<<endl;
	cout<<"External CBV: Pointer Pointing To Address "<<c<<endl;
	cout<<"External CBV: Pointer's ownAddress "<<&c<<endl<<endl;
}

void fRef(int *(*c))
{
	// HERE we have a pointer to a ponter
	cout<<"External CBR: Pointer To Pointer Pointing To Address "<<(c)<<endl;
	cout<<"External CBR: Pointer To Pointer Pointing To Value "<<*(*c)<<endl;
	cout<<"External CBR: Pointer Pointing To Address "<<*(c)<<endl;
	cout<<"External CBR: Pointer's ownAddress "<<*(&c)<<endl<<endl;
	
	int a = 5;
	*(c) = &a;
	
	cout<<"External CBR: Pointer To Pointer Pointing To Address "<<(c)<<endl;
	cout<<"External CBR: Pointer To Pointer Pointing To Value "<<*(*c)<<endl;
	cout<<"External CBR: Pointer Pointing To Address "<<*(c)<<endl;
	cout<<"External CBR: Pointer's ownAddress "<<*(&c)<<endl<<endl;
}

void pointerIntPointer()
{
	int a = 6;
	int *c;
	// Pointer is given a's Address
	c = &a;
	cout<<"Main: Pointer Pointing To Value "<<*c<<endl;
	cout<<"Main: Pointer Pointing To Address "<<c<<endl;
	cout<<"Main: Pointer's ownAddress "<<&c<<endl<<endl;
	// Passing the pointer by the value(address) it contains 
	f(c);
	
	cout<<"Main After CBV: Pointer Pointing To Value "<<*c<<endl;
	cout<<"Main After CBV: Pointer Pointing To Address "<<c<<endl;
	cout<<"Main AFTER CBV: Pointer's ownAddress "<<&c<<endl<<endl;
	// Passing the address of the pointer itself
	fRef(&c);
	
	cout<<"Main After CBR: Pointer Pointing To Value "<<*c<<endl;
	cout<<"Main After CBR: Pointer Pointing To Address "<<c<<endl;
	cout<<"Main AFTER CBR: Pointer's ownAddress "<<&c<<endl<<endl;
}

int main()
{
	//pointerInt();
	//pointerStruct();
	pointerIntPointer();
}
