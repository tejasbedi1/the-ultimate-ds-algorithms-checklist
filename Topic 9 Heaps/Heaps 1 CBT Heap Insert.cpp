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
	
	void insert(int newInfo)
	{
		lastElePos++;
		a[lastElePos] = newInfo;
		trikkleUp_MaxHeap ();
	}
	
	void swap(int &a, int &b)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
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
		int childPos_1, childPos_2;
		
		if (2*parentPos + 1 <= lastElePos)
			childPos_1 = 2*parentPos + 1;
		else 
			childPos_1 = -1;	
			
		if (2*parentPos + 2 <= lastElePos)
			childPos_2 = 2*parentPos + 2;
		else 
			childPos_2 = -1;
		
		while (childPos_1 != -1 || childPos_2 != -1)
		{
			bool noSwap = true;
			if (childPos_1 != -1 && childPos_2 != -1)
			{
				if (a[childPos_1] < a[childPos_2])
				{
					if (a[childPos_1] < a[parentPos])
					{
						cout<<"Swapping "<<a[childPos_1]<<" "<<a[parentPos]<<" | ";
						swap(a[childPos_1],a[parentPos]);
						parentPos = childPos_1;	
						noSwap = false;
					}
				}
				else
				{
					if (a[childPos_2] < a[parentPos])
					{
						cout<<"Swapping "<<a[childPos_2]<<" "<<a[parentPos]<<" | ";
						swap(a[childPos_2],a[parentPos]);
						parentPos = childPos_2;	
						noSwap = false;
					}
				}
			}
			else if (childPos_2 == -1)
			{
				if (a[childPos_1] < a[parentPos])
				{
					cout<<"Swapping "<<a[childPos_1]<<" "<<a[parentPos]<<" | ";
					swap(a[childPos_1],a[parentPos]);
					parentPos = childPos_1;	
					noSwap = false;
				}
			}
			
			if (2*parentPos + 1 <= lastElePos)
			childPos_1 = 2*parentPos + 1;
			else 
				childPos_1 = -1;	
				
			if (2*parentPos + 2 <= lastElePos)
				childPos_2 = 2*parentPos + 2;
			else 
				childPos_2 = -1;
				
			if (noSwap == true)
				break;
		}
	}
	
	void trikkleDown_MaxHeap()
	{
		int parentPos = 0;
		int childPos_1, childPos_2;
		
		if (2*parentPos + 1 <= lastElePos)
			childPos_1 = 2*parentPos + 1;
		else 
			childPos_1 = -1;	
			
		if (2*parentPos + 2 <= lastElePos)
			childPos_2 = 2*parentPos + 2;
		else 
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
						cout<<"Swapping "<<a[childPos_1]<<" "<<a[parentPos]<<" | ";
						swap(a[childPos_1],a[parentPos]);
						parentPos = childPos_1;	
						noSwap = false;
					}
				}
				else
				{
					if (a[childPos_2] > a[parentPos])
					{
						cout<<"Swapping "<<a[childPos_2]<<" "<<a[parentPos]<<" | ";
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
					cout<<"Swapping "<<a[childPos_1]<<" "<<a[parentPos]<<" | ";
					swap(a[childPos_1],a[parentPos]);
					parentPos = childPos_1;	
					noSwap = false;
				}
			}
			
			if (2*parentPos + 1 <= lastElePos)
			childPos_1 = 2*parentPos + 1;
			else 
				childPos_1 = -1;	
				
			if (2*parentPos + 2 <= lastElePos)
				childPos_2 = 2*parentPos + 2;
			else 
				childPos_2 = -1;
				
			if (noSwap == true)
				break;
		}
	}
	
	void displayHeap()
	{
		for (int i = 0; i <= lastElePos; i++)
			cout<<a[i]<<" ";
		cout<<"| ";
	}
	
	void displayHeapTree()
	{
		int finalSize =  lastElePos+1;
		printTreePrimer (3, a, finalSize, 1);	
	}
};


int main ()
{	
	int data[] = {17};
	int lastElePos = 0;
	int arrSize = 20;
	
	int *a = new int[arrSize];
	a = data;
	
	// Initializing
	heap heap(a, lastElePos, arrSize);
	
	// 17 15 10 12 7 6
	heap.insert(6);
	heap.insert(12);
	heap.insert(15);
	heap.insert(7);
	heap.insert(10);
	
	heap.displayHeap();
	heap.displayHeapTree();
	
	system("pause");
	system("cls");
	
	heap.deleteInHeap(); 
	heap.deleteInHeap(); 
	heap.displayHeap();
	heap.displayHeapTree();
	
	system("pause");
}
