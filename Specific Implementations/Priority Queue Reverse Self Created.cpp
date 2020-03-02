#include <iostream> 
#include <algorithm>	// sort
//#include <functional> 	// greater , less
#include <queue>		// Obvious

//using namespace std; 

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

template <class T> 
struct less 
{
	bool operator () (const T &x, const T &y) const
	{
		return x < y;
	}
};

template <class T> 
struct lesser // Same as less
{
	bool operator () (const T &x, const T &y) const
	{
		return x < y;
	}
};

void display(std::priority_queue<int, std::vector<int>, greater<int>> temp)
{
	while(!temp.empty())
	{
		std::cout<<temp.top()<<" ";
		temp.pop();
	}
	std::cout<<"\n";
}

int main() 
{ 
    int numbers[] = {20,40,10,50,30};
    
    int n = 10, m = 20;
    
    std::cout<<"Sort Output\n";
    std::sort (numbers, numbers+5, greater<int>());
	for (int i=0; i<5; i++)
    	std::cout << numbers[i] << ' ';
  	
  	std::cout << "\n";
  	std::priority_queue<int, std::vector<int>, greater<int>> first;
  	
  	for (int i=0; i<5; i++)
  		first.push(numbers[i]);
  	
  	display(first);
} 
