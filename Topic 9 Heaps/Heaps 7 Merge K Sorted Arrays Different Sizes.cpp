#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include "PrintHeap.h"

using namespace std;

class heap
{
	private: 
	
	vector <pair<int, int>> vect;
	int size;
	int lastElePos;
	public:
		
	heap (vector <pair<int, int>> data, int l, int s)
	{
		vect = data;
		lastElePos = l;
		size = s;
	}
	
	
	void swap(pair<int, int> &a, pair<int, int> &b)
	{
		pair <int, int> temp;
		temp = a;
		a = b;
		b = temp;
	}
	
	void insert(pair <int, int> newInfo)
	{
		lastElePos++;
		vect[lastElePos] = newInfo;
		trikkleUp_MinHeap ();
	}
	
	void trikkleUp_MinHeap()
	{
		int childPos = lastElePos;
		int parentPos = (childPos-1)/2;
		while (vect[childPos].first < vect[parentPos].first && childPos != 0)
		{
			//cout<<"Swapping "<<a[childPos]<<" "<<a[parentPos]<<" | ";
			swap(vect[childPos], vect[parentPos]);
			
			childPos = parentPos;
			parentPos = (childPos-1)/2;
		}
	}
	
	void trikkleUp_MaxHeap()
	{
		int childPos = lastElePos;
		int parentPos = (childPos-1)/2;
		while (vect[childPos].first > vect[parentPos].first && childPos != 0)
		{
			//cout<<"Swapping "<<a[childPos]<<" "<<a[parentPos]<<" | ";
			swap(vect[childPos], vect[parentPos]);
			
			childPos = parentPos;
			parentPos = (childPos-1)/2;
		}
	}
	
	void deleteInHeap()
	{
		// Always Root gets deleted, so that makes things easy LOL
		vect[0] = vect[lastElePos];
		vect[lastElePos].first = 0;
		vect[lastElePos].second = 0;
		lastElePos--; 
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
				if (vect[childPos_1].first < vect[childPos_2].first)
				{
					if (vect[childPos_1].first < vect[parentPos].first)
					{
						//cout<<"Swapping "<<a[childPos_1]<<" "<<a[parentPos]<<" | ";
						swap(vect[childPos_1],vect[parentPos]);
						parentPos = childPos_1;	
						noSwapYet = false;
					}
				}
				else
				{
					if (vect[childPos_2].first < vect[parentPos].first)
					{
						//cout<<"Swapping "<<a[childPos_2]<<" "<<a[parentPos]<<" | ";
						swap(vect[childPos_2],vect[parentPos]);
						parentPos = childPos_2;	
						noSwapYet = false;
					}
				}
			}
			else if (childPos_2 == -1)
			{
				if (vect[childPos_1].first < vect[parentPos].first)
				{
					//cout<<"Swapping "<<a[childPos_1]<<" "<<a[parentPos]<<" | ";
					swap(vect[childPos_1],vect[parentPos]);
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
				if (vect[childPos_1].first > vect[childPos_2].first)
				{
					if (vect[childPos_1].first > vect[parentPos].first)
					{
						//cout<<"Swapping1, "<<a[childPos_1]<<" "<<a[parentPos]<<" | ";
						swap(vect[childPos_1],vect[parentPos]);
						parentPos = childPos_1;	
						noSwap = false;
					}
				}
				else
				{
					if (vect[childPos_2].first > vect[parentPos].first)
					{
						//cout<<"Swapping2, "<<a[childPos_2]<<" "<<a[parentPos]<<" | ";
						swap(vect[childPos_2],vect[parentPos]);
						parentPos = childPos_2;	
						noSwap = false;
					}
				}
			}
			else if (childPos_2 == -1)
			{
				if (vect[childPos_1].first > vect[parentPos].first)
				{
					//cout<<"Swapping3, "<<a[childPos_1]<<" "<<a[parentPos]<<" | ";
					swap(vect[childPos_1],vect[parentPos]);
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
			if (vect[parentPos].first > vect[childPos_1].first)
			{
				//cout<<"Swapping "<<a[parentPos]<<" "<<a[childPos_1]<<" | ";
				swap(vect[parentPos], vect[childPos_1]);
				heapify_MinHeap (childPos_1);
			}
		}
		else 
		{
			if (vect[childPos_1].first > vect[childPos_2].first)
			{
				if (vect[parentPos].first > vect[childPos_2].first)
				{
					//cout<<"Swapping "<<a[parentPos]<<" "<<a[childPos_2]<<" | ";
					swap(vect[parentPos],vect[childPos_2]);
					heapify_MinHeap (childPos_2);
				}
			}
			else 
			{
				if (vect[parentPos].first > vect[childPos_1].first)
				{
					//<<"Swapping "<<a[parentPos]<<" "<<a[childPos_1]<<" | ";
					swap(vect[parentPos], vect[childPos_1]);
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
			if (vect[parentPos].first < vect[childPos_1].first)
			{
				//cout<<"Swapping "<<a[parentPos]<<" "<<a[childPos_1]<<" | ";
				swap(vect[parentPos], vect[childPos_1]);
				heapify_MaxHeap (childPos_1);
			}
		}
		else 
		{
			if (vect[childPos_1].first < vect[childPos_2].first)
			{
				if (vect[parentPos].first < vect[childPos_2].first)
				{
					//cout<<"Swapping "<<vect[parentPos]<<" "<<vect[childPos_2]<<" | ";
					swap(vect[parentPos], vect[childPos_2]);
					heapify_MaxHeap (childPos_2);
				}
			}
			else 
			{
				if (vect[parentPos].first < vect[childPos_1].first)
				{
					//<<"Swapping "<<vect[parentPos]<<" "<<vect[childPos_1]<<" | ";
					swap(vect[parentPos], vect[childPos_1]);
					heapify_MaxHeap (childPos_1);
				}
			}
		}
		parentPos = parentPos - 1;
		heapify_MaxHeap (parentPos);
	}
	
	void displayHeap()
	{
		for (int i = 0; i <= lastElePos; i++)
			cout<<vect[i].first<<" ";
		cout<<"| ";
	}

	int getRootFirst()
	{
		return vect[0].first;
	}
	
	int getRootSecond()
	{
		return vect[0].second;
	}
};


int main ()
{	
	int i, j;
	
	vector<vector <int> > arr {
    	{2, 6, 12, 3000},
    	{1, 9},
    	{23, 34, 90, 2000}
	}; 
    
    cout<<"Our Array..\n";
    for (i = 0; i < arr.size(); i++) 
	{ 
        for (j = 0; j < arr[i].size(); j++) 
            cout << arr[i][j] << " "; 
        cout << endl; 
    }	
	cout<<endl;
    
	int k = arr.size();
	
	int finalArrSize = 0;
	for (i = 0; i < arr.size(); i++)
		finalArrSize += arr[i].size();	
	int finalArr[finalArrSize];
	int finalArrPos = 0;
	
	// Value, parent Array
	vector <pair <int, int>> vect;
	
	int arrSize = k;
	int lastElePos = 0;
	
	cout<<"Inserting to Vector.. \n";
	int vectorPositions[k];
	for (int i = 0; i < k; i++)
		vectorPositions[i] = 0;
	
	for (i = 0; i < k; i++)
	{
		vect.push_back( make_pair(arr[i][0],i));
	}
	//vect.push_back( make_pair(arr[0][0],0));
	//vect.push_back( make_pair(arr[1][0],1));
	//vect.push_back( make_pair(arr[2][0],2));
	lastElePos = k - 1; //lastElePos = 2;
	
	for (auto i : vect)
		cout<<i.first<<" | ";
	cout<<endl<<endl;
	
	heap heap(vect, lastElePos, arrSize);

	cout<<"Initial Heap - ";
	heap.displayHeap();
	
	cout<<endl<<endl;
	cout<<"Min Heap Heapify - ";
	heap.heapifyStarter();
	heap.displayHeap();
	
	cout<<endl<<endl;
	
	// MAIN LOOP
	while (finalArrPos < finalArrSize)
	{
		//cout<<"Current Min Ele - ";
		//cout<<heap.getRoot()<<endl;	
		//cout<<"Adding to final array..\n";
		finalArr[finalArrPos] = heap.getRootFirst();
		finalArrPos ++;
		
		//cout<<"Deleting ..\n";
		int temp = heap.getRootSecond();
		vectorPositions[temp] ++;
		heap.deleteInHeap();
		
		//cout<<"Inserting .. ";
		if (vectorPositions[temp] < arr[temp].size())
		{
			//cout<<arr[temp][vectorPositions[temp]]<<" of "<<temp<<endl;
			heap.insert( make_pair(arr[temp][vectorPositions[temp]],temp));
		}
		
		//cout<<"Resulting Heap.. ";
		//heap.displayHeap();	
		//cout<<endl<<endl;
	}
	
	cout<<"Final Array - \n";
	for (int i : finalArr)
		cout<<i<<" ";
}
