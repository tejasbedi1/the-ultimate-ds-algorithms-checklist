#include <iostream> 
#include <algorithm>	// sort
//#include <functional> 	// greater , less

//using namespace std; 

// C++ Reference
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

// Cleaned Up
template <class T> 
struct lesser
{
	bool operator () (const T &x, const T &y) const
	{
		return x < y;
	}
};

// Custom
struct great
{
	bool operator () (int &x, int &y)
	{
		return x < y;
	}
};

int main() 
{ 
    int numbers[] = {20,40,10,50,30};
    
    int n = 10, m = 20;
    
    std::cout<<"Sort Output: Decending\n";
	std::sort (numbers, numbers+5, greater<int>());
	for (int i=0; i<5; i++)
    	std::cout << numbers[i] << ' ';	
  	std::cout << "\n";
  	
  	std::cout<<"Sort Output: Acending\n";
	std::sort (numbers, numbers+5, lesser<int>());
	for (int i=0; i<5; i++)
    	std::cout << numbers[i] << ' ';	
  	std::cout << "\n";
  	
  	std::cout<<"Sort Output: Decending\n";
	std::sort (numbers, numbers+5, great());
	for (int i=0; i<5; i++)
    	std::cout << numbers[i] << ' ';	
  	std::cout << "\n";
} 
