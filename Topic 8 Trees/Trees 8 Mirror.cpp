#include <bits/stdc++.h>
#include <iostream>
#include "PrintTree.h"

using namespace std;

/*struct node
{
	int data;
	struct node* left;
	struct node* right;
};
*/
node* newNode(int data)
{
	node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void mirrorTree(node* head)
{
	node* temp;
	if (head->left != NULL && head->right != NULL)
	{
		temp = head->left;
		head->left = head->right;
		head->right = temp;
	}
	else if (head->left == NULL)
	{
		head->left = head->right;
		head->right = NULL;	
	}
	else if (head->right == NULL)
	{
		head->right = head->left;
		head->left = NULL;
	}
	
	if (head->left != NULL)
		mirrorTree(head->left);
		
	if (head->right != NULL)
		mirrorTree(head->right);
		
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
	
	cout<<"Resuming..\n";
	system("Pause");
	mirrorTree(head);
	printTreePrimer (5,head);
}
