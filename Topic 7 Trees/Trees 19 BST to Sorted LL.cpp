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

struct nodell
{
	int data;
	struct nodell* next;
};

nodell* newLLNode(int data)
{
	nodell* nodell = new struct nodell;
	nodell->data = data;
	nodell->next = NULL;
	return nodell;
}

void traverseInorderly(node* head)
{
	if (head == NULL)
		return;
	
	traverseInorderly(head->left);
	cout<<head->data<<" ";
	traverseInorderly(head->right);
}

void addToLL(nodell* &first, nodell* &last, int data)
{
	if (first == NULL)
	{
		first = newLLNode(data);
		last = first;
		return;
	}
	
	nodell* temp = newLLNode(data);
	last->next = temp;
	last = temp;
	
}

void showLL(nodell* first);

void traverseAndStore(node* head, nodell* &first, nodell* &last)
{
	if (head == NULL)
		return;
		
	traverseAndStore (head->left, first, last);	
	
	cout<<head->data<<" ";
	addToLL(first, last, head->data);
	
	traverseAndStore (head->right, first, last);	
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
	
	//traverseInorderly(head);	
	nodell *first, *last;
	first = NULL;
	last = NULL;
	
	traverseAndStore(head, first, last);
	cout<<endl;
	showLL(first);
}

void showLL(nodell* first)
{
	cout<<"\nContents Of The LL..\n";
	while (first != NULL)
	{
		cout<<first->data<<" ";
		first = first->next;
	}
}
