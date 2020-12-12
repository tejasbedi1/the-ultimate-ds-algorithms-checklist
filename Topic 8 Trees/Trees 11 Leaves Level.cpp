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

int getHeight(node* head, bool &flag)
{
	int hL, hR;
	if (head->left != NULL)
		hL = getHeight(head->left, flag);
	else 
		hL = 0;
		
	if (head->right != NULL)
		hR = getHeight(head->right, flag);
	else 
		hR = 0;
	
	if (hL != hR)
		flag = false;
		
	return 1+(hL > hR ? hL : hR);
}

bool sameLevel(node* head)
{
	bool flag = true;
	getHeight(head, flag);
	return flag;	
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
	
	cout<<"Same Level ?\n";
	sameLevel(head) ? cout<<"Leaves at the same level" : cout<<"Leaves on a different level";
}
