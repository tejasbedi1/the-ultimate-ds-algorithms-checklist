// ADDING IS SIMPLE 
// JUST CHECK AND ADD
// THe main adding involves balancing the tree as and when we are adding
// That will make it a self balancing tree 
// i.e an AVL tree
// Thats implemented in a diifferent file 

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

void addAppropriately(node* &head, int data)
{
	if (head == NULL)
	{
		head = newNode(data);
		return;
	}
	
	if (head->data <= data)
		addAppropriately(head->right, data);
	else if (head->data > data)
		addAppropriately(head->left, data);
}

int main()
{
	node* head;
	head = NULL;
	
	node* calc;
	calc = NULL;
	
	
	/* Example balanced binary search tree  
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
	
	head->right 		= newNode(9);
	head->right->left 	= newNode(7);
	head->right->right 	= newNode(11);
	
	addAppropriately(head, 1);
	addAppropriately(head, 2);
	addAppropriately(head, 3);
	
	printTreePrimer (5,head);
}
