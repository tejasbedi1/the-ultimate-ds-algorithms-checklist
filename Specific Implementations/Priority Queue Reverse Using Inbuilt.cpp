#include <iostream> 
#include <algorithm>	// sort
#include <functional> 	// greater , less
#include <queue>		// Obvious

using namespace std; 

// Commented out bacuse already defined in functional with namespace std;
/*	
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
*/

template <class T> 
struct lesser
{
	bool operator () (const T &x, const T &y) const
	{
		return x < y;
	}
};

void display(priority_queue<int, vector<int>, greater<int>> temp)
{
	while(!temp.empty())
	{
		cout<<temp.top()<<" ";
		temp.pop();
	}
	cout<<"\n";
}
int main() 
{ 
    int numbers[] = {20,40,10,50,30};
    
    int n = 10, m = 20;
    
    cout<<"Sort Output\n";
    sort (numbers, numbers+5, greater<int>());
	for (int i=0; i<5; i++)
    	std::cout << numbers[i] << ' ';
  	
  	cout << "\n";
  	priority_queue<int, vector<int>, greater<int>> first;
  	
  	for (int i=0; i<5; i++)
  		first.push(numbers[i]);
  	
  	display(first);
} 
