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

int findKthSmallest (node* head, int kth)
{
	node *current, *pred;
	current = head;
	int count = 1;
	
	while (current)
	{
		if (current->left == NULL)
		{
			//cout<<current->data<<" ";
			if (count == kth)
				return current->data;
			else
				count++;
				
			current = current->right;
		}
		else 
		{
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
				//cout<<current->data<<" ";
				if (count == kth)
					return current->data;
				else
					count++;
					
				current = current->right;
			}
		}
	}
	
	return 0;
}

int main()
{
	node* head;
	head = NULL;
	
	node* calc;
	calc = NULL;
	
	
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
	
	//system("pause");
	//system("cls");
	cout<<"Using Inorder Moris Traversal to Iterate over every node, using only O(1) more space..\n\n";
		
	int k = 11;
	cout<<k<<"th smallest is "<<findKthSmallest (head, k);
}
