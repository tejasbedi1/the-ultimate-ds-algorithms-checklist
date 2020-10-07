#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void showStr(char *str, int n)
{
	for (int i=0; i<n-1; i++)
		debug(1, str[i]);
	debug (1, "\n");
}

void swap(char *str, int a, int b)
{
	char c;
	c = str[a];
	str[a] = str[b];
	str[b] = c;
}

void recursive(char str[], int n, int pos, int swapA, int swapB)
{
	swap (str, swapA, swapB);
	
	if (pos >= n-1)
	{
		showStr(str, n);
		return;
	}
	
	int i;
	for (i=pos; i<n-1; i++)
	{
		recursive(str, n, pos+1, pos, i);
	}
}

void solve(char str[], int size)
{
	recursive(str, size, 0, 0, 0);
}

int main()
{
	
	// RESOURCE 
	// https://www.geeksforgeeks.org/partition-problem-dp-18/
	// [Visaul explanation of implementation]
	// https://media.geeksforgeeks.org/wp-content/cdn-uploads/NewPermutation.gif
	
	// Solution Complexity n!
	
	LOG_LEVEL = 1;
	
	int k;

	char str[] = "abc";
    
	int size = sizeof(str)/sizeof(str[0]);
	
	debug(1, "size: ", size, "\n");
	
	solve(str, size);
}
