#include <bits/stdc++.h>
//#include <iostream>
//#include <set>
//#include <iterator>

using namespace std;

// USING MULTISET I GET 0.05 :O
// SO slow, maybe i didn't write it right
// With FAST I/O 0.04 
int main()
{
	ios_base::sync_with_stdio(false);  // MAKES INPUT ACT LIKE SCANF PRINTF
    cin.tie(NULL);	// HELPS THE CONSOLE
    
	int n, i, k;
	
	cin>>n;
	
	int* arr = new int[n];
	
	for (i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cin>>k;
	
	multiset <int> ms;
	
	for (i=0; i<k; i++)
	{
		ms.insert(arr[i]);
	}
	cout<<*--ms.end()<<" ";
	
	for (i=k; i<n; i++)
	{
		ms.erase(ms.find(arr[i-k]));
		ms.insert(arr[i]);
		cout<<*--ms.end()<<" ";
	}
}

/*
// SECOND ITERATION <not looping if largest stays in array> SPOJ TIME 0.02 ARRAYSUB
// Worst Case is as worse as brute force algo 
// FAST INPUT 0.01
int findLargest(int* arr, int f, int l, int* lp)
{
	int largest = arr[f];
	*lp = f;
	for (int i=f; i<l; i++)
	{
		if (largest < arr[i])
		{
			largest = arr[i];
			*lp = i;
		}
	}
	return largest;
}

int main()
{
	ios_base::sync_with_stdio(false);  // MAKES INPUT ACT LIKE SCANF PRINTF
    cin.tie(NULL);	// HELPS THE CONSOLE
	
	int n, i, k;
	cin>>n;
	
	int* arr = new int[n];
	
	for (i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cin>>k;
	
	int resultSize = n+1-k;
	
	int largest, largestPos = -1;
	
	for (i=0; i<resultSize; i++)
	{
		if (largestPos == -1)
			largest = findLargest(arr, i, i+k, &largestPos);
		else
		{
			if (largestPos >= i)
			{
				if (arr[largestPos] < arr[i+k-1])
				{
					largest = arr[i+k-1];
					largestPos = i+k-1;
				}
			}
			else 
			{
				largest = findLargest(arr, i, i+k, &largestPos);
			}
		}
		//cout<<largest<<" at "<<largestPos<<endl;
		cout<<largest<<" ";
	}
}
*/


/* BRUTE FORCE SPOJ TIME 0.54 ARRAYSUB 	       	-------------------------------------
int findLargest(int* arr, int f, int l)
{
	int largest = arr[f];
	for (int i=f; i<l; i++)
	{
		if (largest < arr[i])
			largest = arr[i];
	}
	return largest;
}

int main()
{
	int n, i, k;
	cin>>n;
	
	int* arr = new int[n];
	
	for (i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cin>>k;
	
	int resultSize = n+1-k;
	
	for (i=0; i<resultSize; i++)
	{
		cout<<findLargest(arr, i, i+k)<<" ";
	}
}
*/
