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

int findLCAforBST(node* head, int a, int b)
{
	int ans = 0;
	if (head->data > a && head->data > b)
	{
		//cout<<"Moving Left..\n";
		ans= findLCAforBST(head->left, a, b);
	}	
	else if (head->data < a && head->data < b)
	{
		//cout<<"Moving Right..\n";
		ans = findLCAforBST(head->right, a, b);
	}	
	else if ( (head->data > a && head->data < b) || (head->data < a && head->data > b) )
	{
		//cout<<"1..\n";
		return head->data;
	} 
	else if (head->data == a || head->data == b)
	{
		//cout<<"2..\n";
		return head->data;
	}
	return ans;
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
	
	int a = 9, b = 10;
	cout<<"Least Common Ancestor for "<<a<<" & "<<b<<" is.."<<endl;
	cout<<findLCAforBST(head, a, b);
}
