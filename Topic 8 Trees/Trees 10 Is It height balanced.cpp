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

int getHeight(node* head, int &diff)
{
	int heightL;
	if (head->left != NULL)
		heightL = getHeight(head->left, diff);
	else 
		heightL = 0;
	
	int heightR;
	if (head->right != NULL)
		heightR = getHeight(head->right, diff);
	else 
		heightR = 0;
	
	int ans = 0;
	heightL > heightR ? ans = heightL-heightR : ans = heightR-heightL;
	if (ans > diff)
		diff = ans;
		
	int height = heightL > heightR ? heightL : heightR;
	return 	1 + height;
}

bool isBalanced(node* head)
{
	int diff = 0;
	getHeight(head, diff);	
	cout<<diff<<endl;
	if (diff > 1)
		return false;
	else 
		return true;
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
	if (isBalanced(head) == true)
		cout<<"BALANCED\n";
	else
		cout<<"NOT BALANCED\n";
}
