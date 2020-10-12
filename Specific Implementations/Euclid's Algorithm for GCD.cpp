#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

// FOR 2 
int inbuilt(int a, int b)
{
	return __gcd(a,b);
}

// FOR 2
int self(int a, int b)
{
	// Euclidean Algorithm
	if (b == 0)
		return a;
	return ( self(b, a%b) );
}

// FOR Array 
int forArray(int *arr, int size)
{
	int i;
	int result;
	
	result = __gcd(arr[0],arr[1]);
	for (i=2; i<size; i++)
		result = __gcd(result, arr[i]);
		
	return result;
}

int main()
{	
	// ALGO for finding Greatest Common Factor 
	
	// Resource
	// https://en.cppreference.com/w/cpp/numeric/gcd
	// https://www.geeksforgeeks.org/stdgcd-c-inbuilt-function-finding-gcd/
	
	// Self Calculating using euclidean 
	// https://www.youtube.com/watch?v=VWOUh4w_zVI
	// https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
	// O (LOG min(a,b))
	// O (n * LOG max(arr)) // I THINK
	
	// Process 
	// Eg GCD (10,14)
	// GDC (10, 14) -> GDC (14,10) -> GCD (10,4) -> GCD (4,2) -> GCD (2,0) Ans.2
	// 10%14 		->	14%10 		-> 		10%4	-> 4%2 		->  Done
	
	//int a = 5, b = 4;
	int a = 100, b = 105;
	int ans;
	int size;
	
	//ans = inbuilt (a,b);
	//ans = self (a,b);
	
	//int arr[] = {1,2,3,4};
	//int arr[] = {10,20,30};
	//int arr[] = {10,12,14};
	int arr[] = {700,707,770};

	size = sizeof(arr)/sizeof(arr[0]);
	
	ans = forArray(arr, size);	
	cout<<ans<<endl;
}
