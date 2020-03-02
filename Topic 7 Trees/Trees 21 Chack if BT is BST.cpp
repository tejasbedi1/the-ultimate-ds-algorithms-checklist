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

// WRONG WRONG WRONG 
// PLUS VERY OVERENGINEERED 
bool checkifBTisBST(node* head, int super, int useless)
{
	if (head == NULL)
		return true;
		
	bool ans = true;
	
	// Moving PRE-ORDERLY
	if (head->left != NULL)
	{
		if (head->left->data < head->data)
			ans = true;
		else 
			ans = false;
	}
	if (ans == true && head->right != NULL) // IF not true no point 
	{
		if (head->right->data > head->data && head->right->data < super)
			ans = true;
		else 
			ans = false;
	}
	
	if (ans == true)
		ans = checkifBTisBST(head->left, head->data, 0);
	if (ans == true)
		ans = checkifBTisBST(head->left, super, 0);
	
	return ans;
}

bool checkifBTisBST(node* head, int &data)
{
	if (head == NULL)
		return true;
	
	if (checkifBTisBST(head->left, data) == false)
		return false;
	
	//cout<<head->data<<" ";
	//cout<<"Checking if "<<head->data<<" is greater than "<<data<<endl;
	if (head->data > data)
		data = head->data;	
	else
		return false;	
	
	if (checkifBTisBST(head->right, data) == false)
		return false;
		
	return true;
}

int main()
{
	node* head;
	head = NULL;
	
	/* Constructed balanced binary search tree is  
        			6
				  /   \ 
        		3      	9
        	  /  \	  /	  \
    		2     5  7     11
    	  /	     /    \    /
		1	   4       8  10
	*/
	head 				= newNode(6);
	
	head->left 			= newNode(3);
	
	head->left->left 	= newNode(2);
	head->left->right 	= newNode(5);
	
	head->left->left->left 	= newNode(1);
	head->left->right->left = newNode(4);
	
	head->right 		= newNode(9);
	
	head->right->left 	= newNode(7);
	head->right->right 	= newNode(11);
	
	head->right->left->right = newNode(8);
	head->right->right->left = newNode(10);
	
	printTreePrimer (4,head);
	
	traverseInorderly(head);
	
	cout<<endl<<endl;
	//int super = INT_MAX;
	
	int a = INT_MIN;
	if (checkifBTisBST(head, a) == true)
		cout<<"BT is also a BST";
	else
		cout<<"BT is not a BST";
}
