#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

template <class T>
void display (T &arr)
{
	int i;
	for (i=0; i<arr.size(); i++)
		debug (1, arr[i], " ");
	debug (1, "\n");
}

template <class T>
int returnSum(T &arr, int a, int b)
{
	int i;
	int sum = 0;
	for (i=a; i<b; i++)
		sum += arr[i];
		
	return sum;
}

int findOpenPosition(bool *chk,int n)
{
	int i;
	for (i=0; i<n; i++)
		if (chk[i] == false)
			return i;
	return -1;
}

template <class T>
bool recursive(T &arr, int n, bool *chk, int target, int sum, int a, stack<int> &stk)
{
	if (chk[a] == true)
		return true;
		
	else if ( (sum + arr[a]) < target )
	{
		sum += arr[a];
		chk[a] = true;
		debug (2, "+", arr[a], " ");
		stk.push(arr[a]);
		
		a++;
		
		while (1)
		{
			if ( recursive(arr, n, chk, target, sum, a, stk) == false )
			{
				chk[a] = false;
				debug (2, "-", arr[a], " ");
			}
				
			a++;
			if (a >= n)
			{
				debug (2, "\n");
				return false;	
			}
		}
	}
	else if ((sum + arr[a]) > target )
	{
		debug (2, "x", arr[a], " ");
		return false;
	}
	else if (sum + arr[a] == target)
	{
		chk[a] = true;
		debug (2, "v", arr[a], " ");
		stk.push(arr[a]);
		
		a = findOpenPosition(chk, n);
		if (a == -1)
		{
			if (LOG_LEVEL >= 2) system("pause");
			return true;
		}
		recursive(arr, n, chk, target, 0, a, stk);
	}
	
	return true;
}

void displayStack(stack <int> stk, int target)
{
	int count = 0;
	while(stk.empty() != true)
	{
		if (count == 0)
			cout<<"[";
		
		count += stk.top();
		
		cout<<stk.top();
		
		if (count == target)
		{
			count = 0;
			cout<<"] ";
		}
		else
			cout<<",";
		stk.pop();
	}
		
}
template <class T>
void solution(T &arr, int n, int k)
{
	int i;
	
	// If no of subsets is greater than number of elements
	if (n < k)
		debug (1, "Not possible\n");
	
	// Only one subset
	else if (k == 1)
	{
		debug (1, "Sum: ", returnSum(arr, 0, n), " | Subset: ");
		display (arr);
	}
	
	// All elements should be same
	else if (n == k)
	{
		for (i=1; i<n; i++)
			if (arr[0] != arr[i])
			{
				debug (1, "Not possible\n");
				return;
			}
		
		debug (1, "Sum: ", arr[0], " | Subsets: ");
		for (i=0; i<n; i++)
			debug (1, "[", arr[i], "]", " ");
		
	}
	else
	{
		if ( returnSum(arr, 0, n) % k != 0)
			debug (1, "Not possible, total sum not divisible by subsets...\n");
			
		else
		{
			int singleSetSum = returnSum(arr, 0, n) / k;
			debug (2, "Single Set Sum: ", singleSetSum, "\n");
			
			// Now we know its possible 
			bool *chk = new bool[n];
			for (i=0; i<n; i++)
				chk[i] = false;
	
			debug (2, "Begining Recur\n");
			stack <int> stk;
			recursive(arr, n, chk, singleSetSum, 0, 0, stk);
			
			displayStack(stk, singleSetSum);
		}
	}
}

int main()
{
	// RESOURCE 
	// https://www.geeksforgeeks.org/partition-set-k-subsets-equal-sum/
	// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
	
	LOG_LEVEL = 1;
	
	int k;
	
	
	// EX 1 
    //array <int, 5> arr = {2, 1, 4, 5, 6};
    //array <int, 5> arr = {1, 2, 4, 5, 6}; // EX 3 
	//k = 3; 
	// k = 4; Ex 4
	
    // EX 2 
    //array <int, 5> arr = {2, 2, 2, 2, 2, 2};
    //k = n;
    
    // Ex 5
	array <int, 7> arr =  {4, 3, 2, 3, 5, 2, 1};
	k = 4;
    
	solution(arr, arr.size(), k);
}
