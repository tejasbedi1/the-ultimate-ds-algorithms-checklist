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

int sumOfAllNodes(node* head, int sum)
{
	cout<<head->data<<" ";
	sum = sum + head->data;
	
	if (head->left != NULL)
		sum = sumOfAllNodes(head->left, sum);
	
	if (head->right != NULL)
		sum = sumOfAllNodes(head->right, sum);
	
	return sum;
}

int sumOfChildren(node* head)
{
	int left = 0, right = 0;
	if (head->left != NULL)
		left = head->left->data;
	if (head->right != NULL)
		right = head->right->data;
	
	head->data = left + right;
	
	if (head->left != NULL)
		sumOfChildren(head->left);
	
	if (head->right != NULL)
		sumOfChildren(head->right);
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
	//cout<<"\nSum of All: "<<sumOfAllNodes(head, 0);
	sumOfChildren(head);
	printTreePrimer (5,head);
}
