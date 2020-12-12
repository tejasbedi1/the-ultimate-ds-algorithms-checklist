#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void displayVec(vector <int> vec)
{
	int i;
	debug (1, vec.size(), "[");
	
	for (i=0; i<vec.size(); i++)
	{
		if (i == vec.size()-1)
			debug (1, vec[i]);
		else
			debug (1, vec[i], ",");	
	}
	debug(1, "]\n");
}

void display2DVec(vector <vector<bool>> vec,
	vector<int> arr, vector<int> arr2)
{
	int i,j;
		
	debug (1, "     ");
	for (i=0; i<=arr2[arr2.size()-1]; i++)
	{
		if (i <= 9)
			debug (1, i, "  ");
		else
			debug (1, i, " ");
	}
	debug (1, "\n");
	
	for (i=0; i<vec.size(); i++)
	{
		if (arr[i] <= 9)
			debug (1, arr[i], "  | ");
		else 
			debug (1, arr[i], " | ");	
			
		for (j=0; j<vec[i].size(); j++)
		{
			if (vec[i][j] == true)
				debug (1, "T  ");
			else
				debug (1, "F  ");
		}
		debug (1, "\n");
	}
	debug (1, "\n");
}

bool findInDict(string s, unordered_set <string> &uSet)
{	
	if (uSet.find(s) != uSet.end())
		return true;	
	
	return false;
}

void displayStack(stack<int> stk)
{
	//STACK REVERSED
	while (stk.empty() != true)
	{
		debug (1, stk.top(), " ");
		stk.pop();
	}
	debug (1, "\n");
}

struct data
{
	int val;
	int loc;
	
	int units;
	int height;
	
	data(int a, int b, int c, int d)
	{
		val = a;
		loc = b;
		units = c;
		height = d;
	}
};

void displayStack(stack<data> stk)
{
	//STACK REVERSED
	while (stk.empty() != true)
	{
		debug (1, stk.top().val, "(", stk.top().loc, 
								"(", stk.top().units, ",", stk.top().height, "))\n");
		stk.pop();
	}
}

// BASED ON STACK DIDNT WORK OUT
int solve3(vector <int> &arr)
{
	int i;
	
	stack <data> stk;
	
	int top;
	int ans = 0;
	int temp;
	int height;
	
	i = 0;
	while (arr[i] == 0)
		i++;
	
	stk.push(data (arr[i],i,0,0) );
	i++;
	
	displayStack(stk);
		
	for(; i<arr.size(); i++)
	{
		debug (2, "Eval Index:", i, ", Value:", arr[i], "\n");
		
		if (arr[i] == 0)
			continue;
		
		temp = 0;
		
		if (stk.top().val == arr[i])
		{
			ans += stk.top().units;
			temp += (arr[i]-stk.top().height)*(i - stk.top().loc - 1);
			stk.pop();
			stk.push(data(arr[i],i,temp,arr[i]));
		}
		else if (stk.top().val > arr[i])
		{
			if (stk.top().loc - i == -1)
				stk.push(data(arr[i],i,0,0));
			else
			{
				temp += (arr[i]) * (i - stk.top().loc - 1);
				stk.push(data(arr[i],i,temp,arr[i]));
			}
		}
		else if (stk.top().val < arr[i])
		{
			temp += stk.top().units;
			height = stk.top().height;
			stk.pop();
			
			if (stk.top().val == arr[i])
			{
				temp += (arr[i]-height)*(i - stk.top().loc - 1);
				
				stk.pop();
				stk.push(data(arr[i],i,temp,arr[i]));
			}
		}
		if (LOG_LEVEL >= 2) displayStack(stk);
	}
	
	debug (2, "Final --\n");
	if (LOG_LEVEL >= 2) displayStack(stk);
	
	while (stk.empty() != true)
	{
		ans += stk.top().units;
		stk.pop();
	}
	
	return ans;
}

// O(N) Speed 3N
// O(N) Space 3N
int solve(vector <int> &arr)
{
	int ans = 0; 
	int size = arr.size();
	
	vector <int> left, right;
	
	left.resize( size );
  	right.resize( size );
  
    left[0] = arr[0]; 
    for (int i = 1; i < size; i++) 
        left[i] = max(left[i - 1], arr[i]); 
  
    right[size-1] = arr[size-1]; 
    for (int i = size-2; i >= 0; i--) 
        right[i] = max(right[i + 1], arr[i]); 
  
  	displayVec(left);
  	displayVec(right);
  	
    for (int i = 0; i < size; i++) 
       	ans += min(left[i], right[i]) - arr[i]; 
  
    return ans;
}

// O(N) Speed Actual O(N)
// O(1) Space Acutal O(2)
// Silly solution form GFG
// Its effective tho
int solve2(vector <int> &arr)
{
    int ans = 0; 
	int n = arr.size();
    int left_max = 0, right_max = 0;   
    int lo = 0, hi = n - 1; 
  
    while (lo <= hi) 
	{ 
        if (arr[lo] < arr[hi]) 
		{ 
            if (arr[lo] > left_max) 
                left_max = arr[lo]; 
            else
                ans += left_max - arr[lo]; 
            lo++; 
        } 
        else 
		{ 
            if (arr[hi] > right_max) 
                right_max = arr[hi]; 
            else
                ans += right_max - arr[hi]; 
            hi--; 
        } 
    } 
    return ans; 
}

int main()
{	
	// Iterative O(N)
	
	// FASTER - Use Unordered Hash Set instead of vector
	// Speace optimisized - No need of a huge array
	
	// Resource

	// Explanition

 	LOG_LEVEL = 3;
	
	// Ex 0 - A 2
	//vector <int> arr = {3, 0, 2};
	
	// Ex 1 - A 2 
	//vector <int> arr = {2, 0, 2};
	
	// Ex 2 - A 4
	//vector <int> arr = {3, 2, 0, 3};
	
	// Ex 3 - A 4
	//vector <int> arr = {3, 0, 2, 3};
	
	// EX 4 - A.7
	//vector <int> arr = {3, 0, 2, 0, 4};
	
	// Ex 5 - A 2
	//vector <int> arr = {3, 2, 1, 2, 1, 2};
	
	// EX 6 - A 9
	//vector <int> arr = {3, 2, 1, 0, 1, 2, 3};
	
	// Ex 7 - A 6
	vector <int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	
	debug (1, "Q. ");
	displayVec(arr);
	debug (1, "\n");
	
	int ans = solve (arr);
	debug (1, "Ans: ", ans);
}
