#include<iostream> 

using namespace std; 

void fF(const int i)
{
	//i ++; Here , cant modify a const variable
}

void eF(int *i)
{}

void gF(const int *i)
{} 

class hC
{
	const int i;

public :
	// Initialzer List in c++
	// https://www.studytonight.com/cpp/initializer-list-in-cpp.php
	
	// The const int i has to be initialized like this or before during defination
	// "hc(int x):i(x)" will also work
	hC(int i):i(i)
	{
		cout<<"i = "<<i<<endl;
	}
	display()
	{
		cout<<"Display: "<<i<<endl;
	}
};

class kC
{
	int i;
	int j;

public:
	kC(int i, int j)
	{	
		this->i = i;
		this->j = j;
	}
	void change()
	{
		//i ++; 
		//j ++;	
	}	
	void display()
	{
		cout<<"i, j = "<<i<<", "<<j<<endl;
	}
	void displayConst() const
	{
		cout<<"i, j = "<<i<<", "<<j<<endl;
	}
};

class lC
{
	int i = 6;
	int j = 7;

public:	
	void change() const 
	{
		//i++; 	j++;
	}
	void display() const
	{
		cout<<"i: "<<i<<", j: "<<j<<endl;
	}
};

class pC
{
	int i = 3;
	mutable int j = 3; 	// Cam be changed from const functions

public:	
	void change() const 
	{
		//i++; 	
		j++;
	}
	void display() const
	{
		cout<<"i: "<<i<<", j: "<<j<<endl;
	}
};

int main() 
{ 
	// THEORY const
	
	// RESOURCE 1
	// https://www.studytonight.com/cpp/const-keyword.php
	// RESOURCE 2
	// https://www.learncpp.com/cpp-tutorial/810-const-class-objects-and-member-functions/
	// RESOURCE 3
	// https://www.geeksforgeeks.org/const-member-functions-c/
	// RESOURCE 4 Nice Quiz
	// https://www.geeksforgeeks.org/c-plus-plus-gq/const-keyword-gq/
	
	// 1. CONST VARIABLE
	const int a = 3;
	//a++; 			// Cannot change vairable because its a const  variable
	cout<<a<<endl;
	
	// 2. a.POINTER TO CONST VARIABLE
	//int *b = &a; 	// A normal pointer cannot point to a const variable
	const int *b = &a;
	cout<<*b<<endl;
	
	// 2. b.CONST POINTER
	int c = 5;
	int *const d = &c;
	c++;
	// d = &c; 		// d cannot be re-assigned as it is a const pointer
	cout<<*d<<endl;
	
	// 3. a.Const Function Arguments / Return Types
	fF(1);
	
	// 3. b.Cannot send a const argument to function which has a non-const parameter
	const int* e;
	//eF(e);
	
	// 3. c.Can send a non-const argument to a funciton which has a const parameter
	int *g;
	gF(g);
	
	// 4. If a class Data memeber is const, then it has to be defined in a constructor or before
	hC h(10);
	h.display();
	
	// 5. Class object as const
	const kC k(1,2);
	//k.change();	// Cannot call cause it causes change
	//k.display(); 	// Cannot call cause suprise suprise const objects can only call 
					// constructors and display is clearly no a constructor
	k.displayConst() // this will work becuase its constant
					// "This keyord is giving me a constant headache xD"
					
	// 6. Const member functions
	lC l;
	l.display();
	
	// 7. Mutable keyword will allow mutable data members to be changed from const func
	pC p;
	p.change();
	p.display();
} 
