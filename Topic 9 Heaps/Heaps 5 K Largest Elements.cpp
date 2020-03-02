#include <bits/stdc++.h>
#include <iostream>
#include "PrintHeap.h"

using namespace std;

class heap
{
	private: 
	
	int *a;
	int size;
	int lastElePos;
	public:
		
	heap (int *data, int l, int s)
	{
		a = data;
		lastElePos = l;
		size = s;
	}
	
	void swap(int &a, int &b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	
	void insert(int newInfo)
	{
		lastElePos++;
		a[lastElePos] = newInfo;
		trikkleUp_MaxHeap ();
	}
	
	void trikkleUp_MinHeap()
	{
		int childPos = lastElePos;
		int parentPos = (childPos-1)/2;
		while (a[childPos] < a[parentPos] && childPos != 0)
		{
			//cout<<"Swapping "<<a[childPos]<<" "<<a[parentPos]<<" | ";
			swap(a[childPos], a[parentPos]);
			
			childPos = parentPos;
			parentPos = (childPos-1)/2;
		}
	}
	
	void trikkleUp_MaxHeap()
	{
		int childPos = lastElePos;
		int parentPos = (childPos-1)/2;
		while (a[childPos] > a[parentPos] && childPos != 0)
		{
			//cout<<"Swapping "<<a[childPos]<<" "<<a[parentPos]<<" | ";
			swap(a[childPos], a[parentPos]);
			
			childPos = parentPos;
			parentPos = (childPos-1)/2;
		}
	}
	
	void deleteInHeap()
	{
		// Always Root gets deleted, so that makes things easy LOL
		a[0] = a[lastElePos];
		a[lastElePos] = 0;
		lastElePos--; 
		trikkleDown_MaxHeap();
	}
	
	void trikkleDown_MinHeap()
	{
		int parentPos = 0;
		
		int childPos_1 = parentPos*2 + 1;
		int childPos_2 = parentPos*2 + 2;
		
		if (childPos_1 > lastElePos)
			childPos_1 = -1;
		if (childPos_2 > lastElePos)
			childPos_2 = -1;
			
		while (childPos_1 != -1 || childPos_2 != -1)
		{
			bool noSwapYet = true;
			if (childPos_1 != -1 && childPos_2 != -1)
			{
				if (a[childPos_1] < a[childPos_2])
				{
					if (a[childPos_1] < a[parentPos])
					{
						//cout<<"Swapping "<<a[childPos_1]<<" "<<a[parentPos]<<" | ";
						swap(a[childPos_1],a[parentPos]);
						parentPos = childPos_1;	
						noSwapYet = false;
					}
				}
				else
				{
					if (a[childPos_2] < a[parentPos])
					{
						//cout<<"Swapping "<<a[childPos_2]<<" "<<a[parentPos]<<" | ";
						swap(a[childPos_2],a[parentPos]);
						parentPos = childPos_2;	
						noSwapYet = false;
					}
				}
			}
			else if (childPos_2 == -1)
			{
				if (a[childPos_1] < a[parentPos])
				{
					//cout<<"Swapping "<<a[childPos_1]<<" "<<a[parentPos]<<" | ";
					swap(a[childPos_1],a[parentPos]);
					parentPos = childPos_1;	
					noSwapYet = false;
				}
			}
			
			childPos_1 = parentPos*2 + 1;
			childPos_2 = parentPos*2 + 2;
			
			if (childPos_1 > lastElePos)
				childPos_1 = -1;
			if (childPos_2 > lastElePos)
				childPos_2 = -1;
				
			if (noSwapYet == true)
				break;
		}
	}
	
	void trikkleDown_MaxHeap()
	{
		int parentPos = 0;
		
		int childPos_1 = parentPos*2 + 1;
		int childPos_2 = parentPos*2 + 2;
		
		if (childPos_1 > lastElePos)
			childPos_1 = -1;
		if (childPos_2 > lastElePos)
			childPos_2 = -1;
		
		while (childPos_1 != -1 || childPos_2 != -1)
		{
			bool noSwap = true;
			if (childPos_1 != -1 && childPos_2 != -1)
			{
				if (a[childPos_1] > a[childPos_2])
				{
					if (a[childPos_1] > a[parentPos])
					{
						//cout<<"Swapping1, "<<a[childPos_1]<<" "<<a[parentPos]<<" | ";
						swap(a[childPos_1],a[parentPos]);
						parentPos = childPos_1;	
						noSwap = false;
					}
				}
				else
				{
					if (a[childPos_2] > a[parentPos])
					{
						//cout<<"Swapping2, "<<a[childPos_2]<<" "<<a[parentPos]<<" | ";
						swap(a[childPos_2],a[parentPos]);
						parentPos = childPos_2;	
						noSwap = false;
					}
				}
			}
			else if (childPos_2 == -1)
			{
				if (a[childPos_1] > a[parentPos])
				{
					//cout<<"Swapping3, "<<a[childPos_1]<<" "<<a[parentPos]<<" | ";
					swap(a[childPos_1],a[parentPos]);
					parentPos = childPos_1;	
					noSwap = false;
				}
			}
			
			childPos_1 = parentPos*2 + 1;
			childPos_2 = parentPos*2 + 2;
		
			if (childPos_1 > lastElePos)
				childPos_1 = -1;
			if (childPos_2 > lastElePos)
				childPos_2 = -1;
				
			if (noSwap == true)
				break;
		}
	}
	
	void heapifyStarter()
	{		
		int parentPos = (lastElePos-1)/2;
		heapify_MinHeap(parentPos);
	}
	
	void heapify_MinHeap (int parentPos)
	{	
		//cout<<"ParentPos "<<parentPos<<" | ";
		int childPos_1 = parentPos*2 + 1;
		int childPos_2 = parentPos*2 + 2;
		
		if (parentPos > lastElePos || parentPos < 0)
		{
			//cout<<"Returning 1 | ";
			return;
		}
			
		if (childPos_1 > lastElePos)
			childPos_1 = -1;
		if (childPos_2 > lastElePos)
			childPos_2 = -1;	
		
		if (childPos_1 == -1 && childPos_2 == -1)
		{
			//cout<<"Returning 2 | ";
			return;
		}
				
		//cout<<"Processing "<<a[parentPos]<<" | ";
		if (childPos_2 == -1)
		{
			if (a[parentPos] > a[childPos_1])
			{
				//cout<<"Swapping "<<a[parentPos]<<" "<<a[childPos_1]<<" | ";
				swap(a[parentPos], a[childPos_1]);
				heapify_MinHeap (childPos_1);
			}
		}
		else 
		{
			if (a[childPos_1] > a[childPos_2])
			{
				if (a[parentPos] > a[childPos_2])
				{
					//cout<<"Swapping "<<a[parentPos]<<" "<<a[childPos_2]<<" | ";
					swap(a[parentPos], a[childPos_2]);
					heapify_MinHeap (childPos_2);
				}
			}
			else 
			{
				if (a[parentPos] > a[childPos_1])
				{
					//<<"Swapping "<<a[parentPos]<<" "<<a[childPos_1]<<" | ";
					swap(a[parentPos], a[childPos_1]);
					heapify_MinHeap (childPos_1);
				}
			}
		}
		parentPos = parentPos - 1;
		heapify_MinHeap (parentPos);
	}
	
	void heapify_MaxHeap (int parentPos)
	{	
		//cout<<"ParentPos "<<parentPos<<" | ";
		int childPos_1 = parentPos*2 + 1;
		int childPos_2 = parentPos*2 + 2;
		
		if (parentPos > lastElePos || parentPos < 0)
		{
			//cout<<"Returning 1 | ";
			return;
		}
			
		if (childPos_1 > lastElePos)
			childPos_1 = -1;
		if (childPos_2 > lastElePos)
			childPos_2 = -1;	
		
		if (childPos_1 == -1 && childPos_2 == -1)
		{
			//cout<<"Returning 2 | ";
			return;
		}
				
		//cout<<"Processing "<<a[parentPos]<<" | ";
		if (childPos_2 == -1)
		{
			if (a[parentPos] < a[childPos_1])
			{
				//cout<<"Swapping "<<a[parentPos]<<" "<<a[childPos_1]<<" | ";
				swap(a[parentPos], a[childPos_1]);
				heapify_MaxHeap (childPos_1);
			}
		}
		else 
		{
			if (a[childPos_1] < a[childPos_2])
			{
				if (a[parentPos] < a[childPos_2])
				{
					//cout<<"Swapping "<<a[parentPos]<<" "<<a[childPos_2]<<" | ";
					swap(a[parentPos], a[childPos_2]);
					heapify_MaxHeap (childPos_2);
				}
			}
			else 
			{
				if (a[parentPos] < a[childPos_1])
				{
					//<<"Swapping "<<a[parentPos]<<" "<<a[childPos_1]<<" | ";
					swap(a[parentPos], a[childPos_1]);
					heapify_MaxHeap (childPos_1);
				}
			}
		}
		parentPos = parentPos - 1;
		heapify_MaxHeap (parentPos);
	}
	
	void heapSort ()
	{
		int originalSize = lastElePos;
		while (lastElePos > 0)
		{
			swap (a[0],a[lastElePos]);
			lastElePos-- ;
			trikkleDown_MaxHeap();
		}
		lastElePos = originalSize;
	}
	
	void displayHeap()
	{
		for (int i = 0; i <= lastElePos; i++)
			cout<<a[i]<<" ";
		cout<<"| ";
	}
	
	void displayHeapTree(int offset)
	{
		int finalSize =  lastElePos+1;
		printTreePrimer (4, a, finalSize, offset);
	}
	
	// FOR FINDING K GREATEST ELEMENTS
	
	void setTemporaryEndPoint(int tempLastElePos)
	{
		lastElePos = tempLastElePos;
	}
	
	void exchangeWithFirst(int k)
	{
		if (a[k] > a[0])
		{
			swap(a[k],a[0]);
			trikkleDown_MinHeap();
		}	
	}
	
};


int main ()
{	
	//int data[] ={ 1, 23, 12, 9, 30, 2, 50 };
	int data[] ={ 1, 23, 12, 9, 30, 2, 50, 20, 10, 40, 25, 15, 35, 45};
	int lastElePos = sizeof(data) / sizeof(data[0]) - 1;
	int arrSize = 20;
	
	int *a = new int[arrSize];
	a = data;
	
	// Initializing
	heap heap(a, lastElePos, arrSize);
	
	cout<<"Initial Heap - ";
	heap.displayHeap();
	heap.displayHeapTree(1);
	
	system("pause");
	system("cls");
	
	// NAIVE'LY MAX HEAPING
	// O(n + k(logn))
	/*
	cout<<"After Heapifying | ";
	
	heap.heapifyStarter();
	heap.displayHeap();
	heap.displayHeapTree(1);
	
	int k = 4; 
	cout<<"K Largest Element | ";
	while (k > 0)
	{
		cout<<a[0]<<" ";
		heap.deleteInHeap();
		k--;
	}
	*/
	
	// USING MIN HEAP INSIDE A K SIZED TEMP ARRAY 
	// INITIAL HEAPING O(k) then checks and trikkleDowns (n-k)logk
	// So O( k + (n-k)logk )
	// Trello for more
	int k = 5;
	cout<<"K = "<<k<<" "<<" Hence temp array is "<<endl;
	heap.setTemporaryEndPoint(k-1);
	heap.displayHeap();
	cout<<endl<<endl;
	
	cout<<"Min Heaping this now.. \n";
	heap.heapifyStarter();
	heap.displayHeap();
	cout<<endl<<endl;
	
	cout<<"Exchange Test.. \n";
	
	int i = k;
	while (i <= lastElePos)
	{
		heap.exchangeWithFirst(i);
		cout<<i<<" - ";
		heap.displayHeap();
		cout<<endl;	
		i++;
	}
	
	cout<<"\nHence Greatest K Elements are - ";
	for (i = 0; i < k; i++)
		cout<<a[i]<<" ";
}
