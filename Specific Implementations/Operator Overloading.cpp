#include<iostream> 
using namespace std; 
  
class Complex 
{ 
private: 
    int real, imag; 

public: 
	Complex()
	{
		real = 0;
		imag = 0;
	}
    Complex(int r, int i) 
	{
		real = r;  
		imag = i;
	}
	
    Complex operator + (Complex const &obj) 
	{ 
        Complex temp; 
        temp.real = real + obj.real; 
        temp.imag = imag + obj.imag; 
        return temp; 
    } 
    Complex operator + (int i)
    {
    	Complex temp;
    	temp.real = real + i;
    	temp.imag = imag + i;
    	return temp;
	}
    Complex operator ++ ()
    {
    	Complex temp;
    	temp.real = real + real;
    	temp.imag = imag + imag;
    	return temp;
    	
	}
    void print() 
	{ 
		cout << real << " " << imag << endl; 
	} 
}; 
  
int main() 
{ 
	// Basically, using a example to explain
	
	// c3 = c1 + c2
	// Complex operator + (Complex const &obj) 
	
	// Here the defination states ReturnType operator <actual operator> (Parameters if any)
	// In this example, this means c1 + (c2)
	// works similiarly for everything else
	
	// Geeks For Geeks
	// https://www.geeksforgeeks.org/operator-overloading-c/
	// Helpul Image 
 	//https://cdn.programiz.com/sites/tutorial2program/files/operator-overloading-C%2B%2B.jpg
    Complex c1(10, 5);
	Complex c2(2, 4); 
    Complex c3;
    
	c3 = c1 + c2; 
	c3.print(); 
	
	c3 = c1 + 2;
    c3.print();
    
    c3 = ++ c1;
    c3.print();
    
    c3 = c1 + c1 + c2 + c2; 
	c3.print(); 
	
	c3 = ++(c1 + c2); 
	c3.print(); 
} 
