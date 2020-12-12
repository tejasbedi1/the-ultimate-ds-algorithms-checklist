#include<iostream> 

using namespace std; 

// Function TEMPLATE
template <class T>
T add (const T a, const T b)
{
	T result = a + b;
	return result;
}

// Multiple parameters FUNCTION TEMPLATE 
template <class X, class Y, class Z>
void display(X a, Y b, Z c)
{
	cout<<"a: "<<a<<" "; 
	cout<<"b: "<<b<<endl;
	cout<<"c: "<<c<<endl;
	//cout<<
}

// Class Template
template <class X, class Y>
class aC
{
	X i;
	Y j;

public :
	aC(X i, Y j)
	{
		this->i = i;
		this->j = j;
	}
	Y add ()
	{
		return i + j;
	}
};

// NON Template Type Arguments
template <class T, int size>
class bC
{
	T arr[size];
public :
	bC()
	{
		arr[0] = 100;
		set();
	}
	set()
	{
		arr[1] = 200;
	}
	display()
	{
		cout<<arr[0]<<" "<<arr[1]<<endl;
	}
};

// Thoery check with structs
template <class T>
struct cS
{	
	bool greater (const T &x, const T &y)
	{
		return x > y;
	}
};


int main() 
{ 
	// RESOURCES 1
	// https://www.javatpoint.com/cpp-templates
	// RESOURCES 2
	//https://www.geeksforgeeks.org/templates-cpp/
	
	// THEORY 
	// Function Templates
	// Class Templates
	
	int i = 3, j = 5;
	cout<<add(i, j)<<endl;
	
	display(20, 20.5, "abd");
	
	aC<int, double> d(3,5.0567);
	cout<<d.add()<<endl;
	
	bC<int, 5> b;
	b.display();	
	
	cS<int> c;
	i = 7; j = 8;
	cout<<c.greater(i, j)<<endl;
} 
