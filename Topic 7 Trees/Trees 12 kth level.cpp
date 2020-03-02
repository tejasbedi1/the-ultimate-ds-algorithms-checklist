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

void print(queue <node*> nq, queue <int> iq, int reqlevel)
{
	if (nq.empty() == true)
		return;
	
	node* temp = nq.front();
	int clevel = iq.front();
	
	if (clevel > reqlevel)
		return;
		
	if (reqlevel == clevel)
		cout<<temp->data<<" ";
	
	if (temp->left != NULL)
	{
		nq.push(temp->left);
		iq.push(clevel+1);
	}
	if (temp->right != NULL)
	{
		nq.push(temp->right);
		iq.push(clevel+1);
	}	
	
	nq.pop();
	iq.pop();
	print (nq, iq, reqlevel);
}

void kthLevel(node* head, int level)
{
	// Kth level huh?
	queue <node*> nq;
	queue <int> iq;
	
	nq.push(head);
	iq.push(1);
	
	print(nq, iq, level);
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
	
	cout<<"KthLevel ..\n";
	kthLevel(head, 4);
}
