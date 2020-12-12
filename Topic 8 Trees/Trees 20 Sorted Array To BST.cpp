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

void sortedArrayBreakdown(int arr[], int a, int b, node* &head)
{
	if (a > b)
		return;
		
	int mid = (a + b) / 2;
	cout<<arr[mid]<<" ";
	head = newNode (arr[mid]);
	
	sortedArrayBreakdown(arr, a, mid-1, head->left);
	sortedArrayBreakdown(arr, mid+1, b, head->right);
}

int main()
{
	node* head;
	head = NULL;
	
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	sortedArrayBreakdown(arr, 0, 9, head);
	printTreePrimer (4,head);
}
