#include <iostream> 
#include <algorithm>

//using namespace std; 

// In-built Defination
template <class T> 
struct greater 
{
	bool operator () (const T &x, const T &y) const
	{
		return x > y;
	}
	typedef T first_argument_type;
	typedef T second_argument_type;
	typedef bool result_type;
};

// My created
template <class T> 
struct less 
{
	bool operator () (const T &x, const T &y) const
	{
		return x < y;
	}
};

// Lolzi
template <class T> 
struct lesser
{
	bool operator () (T &x, T &y)
	{
		return x < y;
	}
};

int main() 
{ 
	// operator function
 	// https://www.tutorialspoint.com/cplusplus/function_call_operator_overloading.htm
    
	int numbers[] = {20,40,10,50,30};
    
    int n = 10, m = 20;
    
    lesser<int> l;
    std::cout<<l(n, m);
    std::cout<<"\n";
    
	std::sort (numbers, numbers+5, lesser<int>());
	for (int i=0; i<5; i++)
    	std::cout << numbers[i] << ' ';
  	
	std::cout << '\n';
	
} 
