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

void findNode(node* head, node* &temp, int data)
{
	// PRE ORDER
	if (head->data == data)
		temp = head;
	
	if (head->left != NULL)
		findNode(head->left, temp, data);
	if (head->right != NULL)
		findNode(head->right, temp, data);
}

void findChildrenInRange(node* head, int range)
{
	if (range == 0)
		cout<<head->data<<" "; 
	
	if (head->left != NULL)
		findChildrenInRange(head->left, range-1);
	if (head->right != NULL)
		findChildrenInRange(head->right, range-1);
}

void findParentAndTheirChildren(node* head, node* nodeInfocus, node* &temp, int range)
{
	// PRE ORDER
	if (head->left != NULL && head->left == nodeInfocus) 
	{
		// If our nodeInfocus is found to be a left child of this head then
		temp = head; 	// Assign it to temp
		if (head->right != NULL)
		{
			// If range is avalable then find children of the parent on the right side only though 
			// cause left has the nodeInFocus node
			if (range == 1)
				cout<<head->data<<" ";
			else 
				findChildrenInRange(head->right, range-1-1);	
		}
	}
	if (head->right != NULL && head->right == nodeInfocus)
	{
		// If our nodeInfocus is found to be a right child of this head then
		temp = head;	// Assign it to temp
		if (head->left != NULL)
		{
			// If range is avalable then find children of the parent on the left side only though 
			// cause left has the nodeInFocus node
			if (range == 1)
				cout<<head->data<<" ";
			else 
				findChildrenInRange(head->left, range-1-1);	
		}
	}
	
	if (head->left != NULL)
		findParentAndTheirChildren(head->left, nodeInfocus, temp, range);
	if (head->right != NULL)
		findParentAndTheirChildren(head->right, nodeInfocus, temp, range);
}

void checkParentsAndTheirChildren(node* head, node* nodeInFocus, int range)
{
	if (range == 0)
		return;
	
	node* temp;
	findParentAndTheirChildren(head, nodeInFocus, temp, range);
	
	range--;
	checkParentsAndTheirChildren(head, temp, range);
}

void findInRange(node* head, int data, int range)
{
	// Find Node
	node* nodeInfocus;
	findNode(head, nodeInfocus, data);
	//cout<<"Node at: "<<nodeInfocus<<" with data: "<<nodeInfocus->data<<endl;
	
	// Check children for any nodes in range
	//cout<<"Children in range.. ";
	findChildrenInRange(nodeInfocus, range);
	//cout<<endl;
	
	// Check Parent, then a parent of a parent and so on
	//cout<<"GrandParents, Parents OR Cousins in range... ";
	checkParentsAndTheirChildren(head, nodeInfocus, range);
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
	
	int range = 2;
	int nodeData = 4;
	cout<<"All nodes that are "<<range<<" units from node "<<nodeData<<"..\n";
	findInRange(head, nodeData, range);
}
