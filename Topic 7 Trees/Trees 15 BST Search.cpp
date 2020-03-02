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

void search(node* head, int ele)
{
	if (head == NULL)
	{
		cout<<"Nothing here..";
		return;
	}
	 
	if (head->data > ele)
	{
		cout<<head->data<<" -> ";
		search(head->left, ele);
	}	
	else if ((head->data < ele))
	{
		cout<<head->data<<" -> ";
		search(head->right, ele);
	}
	else
	{
		cout<<ele<<endl;
	}
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
	
	search(head, 10);
}
