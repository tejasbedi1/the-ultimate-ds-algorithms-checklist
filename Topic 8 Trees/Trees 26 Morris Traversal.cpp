//Inorder Tree Traversal without recursion and without extra space except the O(1)
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

void morrisTraversal(node* head)
{
	node *pred, *current; // predecessor
	current = head;
		
	while (current)
	{
		if (current->left == NULL)
		{
			//cout<<"Left Null.. ";
			cout<<current->data<<" ";
			current = current->right;
		}
		else
		{ 
			//cout<<"Left not Null.. ";
			// Setting rights
			pred = current->left;
			while (pred->right != NULL && pred->right != current)
				pred = pred->right;
			
			if (pred->right == NULL)
			{
				pred->right = current;
				current = current->left;
			}
			else 
			{
				pred->right = NULL;
				cout<<current->data<<" ";
				current = current->right;
			}
		}		
	}
}

int main()
{
	node* head;
	head = NULL;
	
	/* Constructed binary tree is  
        			1
				  /   \ 
        		2      	3
        	  /   \	
    		4     	5
    	  /	  \   /   \
		6	   7 8		9	 
	  /	  \
	10		11
  	
	*/
	head 				= newNode(1);
	
	head->left 			= newNode(2);
	head->right 		= newNode(3);
	
	head->left->left 	= newNode(4);
	head->left->right 	= newNode(5);
	
	head->left->left->left 	= newNode(6);
	head->left->left->right = newNode(7);
	head->left->right->left = newNode(8);
	head->left->right->right= newNode(9);
	
	head->left->left->left->left 	= newNode(10);
	head->left->left->left->right 	= newNode(11);
	
	printTreePrimer (5,head);
	
	morrisTraversal(head);
	
	system("pause");
	system("cls");
	printTreePrimer (5,head);
}
