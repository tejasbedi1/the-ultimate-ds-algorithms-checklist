#include <bits/stdc++.h>
#include <iostream>
#include "PrintTree.h"

using namespace std;

node* newNode(int data)
{
	node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;	
}

void traverseInorderly(node* head)
{
	if (head == NULL)
		return;
	
	traverseInorderly(head->left);
	cout<<head->data<<" ";
	traverseInorderly(head->right);
}

void createTree(node* &head, int arr[], int a, int b)
{	
	int pivot = arr[a];
	
	//cout<<"First: "<<pivot<<"\n";
	head = newNode(pivot);
	
	a++;
	int sudoMid = a;
	bool leftExists = false;
	bool rightExists = false;
	
	for (int i=a; i<=b; i++)
	{
		if (pivot > arr[i])
			leftExists = true;
		if (pivot < arr[i])
		{
			rightExists = true;
			break;
		}
		sudoMid = i;
	}	
	
	if (leftExists) 
	{
		//cout<<"Left.. ";	
		//cout<<arr[a]<<" "<<arr[sudoMid]<<endl;
		//cout<<endl;
		//system("pause");
		createTree(head->left, arr, a, sudoMid);
	}
	if (rightExists)
	{
		//cout<<"Right.. ";
		if (leftExists)
		{
			//cout<<arr[sudoMid+1]<<" "<<arr[b]<<endl;
			//cout<<endl;
			//system("pause");
			
			createTree(head->right, arr, sudoMid+1, b);	
		}	
		else
		{
			//cout<<arr[sudoMid]<<" "<<arr[b]<<endl;
			//cout<<endl;
			//system("pause");
			createTree(head->right, arr, sudoMid, b);	
		}	
	}
		
}

int main()
{
	node* head;
	head = NULL;
	
	int arr[] = {6,3,2,1,5,4,9,7,8,11,10}; 		// 0-10
	//int arr[] = {7,3,2,1,5,6,10,8,9,12,11};	// 0-10
	//int arr[] = {7,3,2,1,5,4,6,10,8,9,12,11};	// 0-11
	
	for (int i = 0; i<11; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	createTree (head, arr, 0, 10);
	//system("pause");
	//system("cls");
	printTreePrimer (4,head);
}
