#include <bits/stdc++.h>
#include <iostream>
#include "PrintHeap.h"

#define MAXHEAP 2
#define MINHEAP 1

using namespace std;

class heap
{
	private: 
	
	vector <int> a;
	int size;
	int lastElePos;
	int heapType;
	
	public:
		
	heap (int ht)
	{
		size = 0;
		heapType = ht;
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
		a.push_back(newInfo);
		size = a.size();
		lastElePos = size - 1;
			
		if (heapType == MAXHEAP)
			trikkleUp_MaxHeap ();
		else if (heapType == MINHEAP)
			trikkleUp_MinHeap ();
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
		
		a.pop_back();
		lastElePos--;
		size--;
		
		if (heapType == MAXHEAP)
			trikkleDown_MaxHeap();
		else if (heapType == MINHEAP)
			trikkleDown_MinHeap();
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
	
	/*
	void heapifyStarter()
	{		
		int parentPos = (lastElePos-1)/2;
		if (heapType == MAXHEAP)
			heapify_MaxHeap(parentPos);
		else if (heapType == MINHEAP)
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
			if (heapType == MAXHEAP)
				trikkleDown_MaxHeap();
			else if (heapType == MINHEAP)
				trikkleDown_MinHeap();
		}
		lastElePos = originalSize;
	}
	
	*/
	
	void displayHeap()
	{
		for (int i = 0; i <= lastElePos; i++)
			cout<<a[i]<<" ";
		cout<<"| ";
	}
	
	void displayHeapTree(int offset)
	{
		int finalSize =  size;
		int height = 4;
		int *arr = new int[finalSize];
		for (int i = 0; i < size; i++)
		{
			arr[i] = a[i];
		}
		printTreePrimer (height, arr, finalSize, offset);
	}
	
	int getRoot()
	{
		return a[0];
	}
	
	int returnSize()
	{
		int tempS = size;
		return tempS;
	}
	
};


int main ()
{	
	//int data[] = {8,5,7,6,9,4};
	int data[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
	int dataSize = sizeof(data)/ sizeof(data[0]);
	int i = 0;
	
	heap minHeap (MINHEAP);
	heap maxHeap (MAXHEAP); 
	int median = -1;
	int totalElements = 0;
	
	cout<<"Processing "<<data[i]<<"\n";
	median = data[0];
	cout<<"M "<<median<<" "<<i<<endl;
	i ++;
	
	while(i < dataSize)
	{
		cout<<"Processing "<<data[i]<<"\n";
		
		// Size of heap zero
		// ONLY runs once during the second case
		if (minHeap.returnSize() == 0 && maxHeap.returnSize() == 0)
		{
			if (data[i] > median)
			{
				minHeap.insert(data[i]);
				maxHeap.insert(median);			
			}
			else if (data[i] < median)
			{
				minHeap.insert(median);
				maxHeap.insert(data[i]);
			}
			median = -1;
		}
		// Median Empty
		else if (median == -1)
		{
			// Data greater than max heap & Data less than min heap 
			if (data[i] > maxHeap.getRoot() && data[i] < minHeap.getRoot())
			{
				median = data[i];	
			}
			else if (data[i] < maxHeap.getRoot())
			{
				int temp = maxHeap.getRoot();
				maxHeap.deleteInHeap();
				maxHeap.insert(data[i]);
				median = temp;
			}
			else if (data[i] > minHeap.getRoot())
			{
				int temp = minHeap.getRoot();
				minHeap.deleteInHeap();
				minHeap.insert(data[i]);
				median = temp;
			}
		}
		// Median Filled
		else if (median != -1)
		{
			if (data[i] > median)
			{
				minHeap.insert(data[i]);
				maxHeap.insert(median);			
			}
			else if (data[i] < median)
			{
				minHeap.insert(median);
				maxHeap.insert(data[i]);
			}
			median = -1;
		}
		
		if (median == -1)
			cout<<"M "<<(minHeap.getRoot()+maxHeap.getRoot())/2<<" "<<i<<endl;
		else if (median != -1)
			cout<<"M "<<median<<" "<<i<<endl;
		
		i++;
	}
	
	system("pause");
	system("cls");
	cout<<"Median - "<<median<<endl;
	cout<<"MinHeap - \n";
	minHeap.displayHeapTree(1);
	cout<<"MaxHeap - \n";
	maxHeap.displayHeapTree(7);
}
