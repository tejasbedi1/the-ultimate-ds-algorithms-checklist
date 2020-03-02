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

bool checkNodes(node *head, int prev)
{
	// Inorder
	if (head == NULL)
		return true;
	
	bool temp = true;
	
	temp = checkNodes(head->left, prev);
	if (temp == false)
		return false;
		
	if (head->data > prev)
		prev = head->data;
	else
		return false;
	
	temp = checkNodes(head->right, prev);
	if (temp == false)
		return false;
	
	return temp;
}

int checkHeights(node* head, bool &flag)
{
	// Post Order
	if (head == NULL)
		return 0;
	
	int height , hl, hr;
	
	hl = checkHeights(head->left, flag);
	hr = checkHeights(head->right, flag);
	
	height = (hl >= hr ? hl : hr) + 1;
	//cout<<head->data<<"-"<<height<<" ";
	if (abs(hl-hr) > 1)
	{
		//cout<<"UNbalanced at "<<head->data<<endl;
		flag = false;
	}
	return height;
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
	//head->right->left->right->right = newNode(8);
	head->right->right->left = newNode(10);
	
	printTreePrimer (4,head);
	
	// Check nodes
	if (checkNodes(head, INT_MIN) == true)
		cout<<"Nodes Check out.."<<endl;
	else 
		cout<<"Nodes Incorrectly Aligned"<<endl;
	
	// Check Heights
	bool flag = true;
	checkHeights(head, flag);
	if (flag)
		cout<<"Tree Balanced.."<<endl;
	else 
		cout<<"Tree Unbalanced.."<<endl;
}
