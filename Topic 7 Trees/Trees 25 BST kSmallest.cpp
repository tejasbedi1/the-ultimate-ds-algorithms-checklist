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

int populate(node* head, node* &calc)
{
	if (head == NULL)
		return 0;
		
	int count = 0;
	
	calc = newNode(0);
	
	count += populate (head->left, calc->left);
	count += populate (head->right, calc->right);	
	
	count++;
	calc->data = count;
	//cout<<"Node "<<head->data<<" has "<<count<<endl;
	
	return count;
}

int assignZeros(node* &calc)
{
	if (calc == NULL)
		return 0;
	
	//cout<<calc->data<<endl;
	if (calc->left != NULL && calc->right == NULL)
	{
		calc->right = newNode(0);
		assignZeros(calc->left);
	}
	else if (calc->left == NULL && calc->right != NULL)
	{
		calc->left = newNode(0);
		assignZeros(calc->right);
	}
	else if (calc->left == NULL && calc->right == NULL)
	{
		calc->right = newNode(0);
		calc->left = newNode(0);
	}
	else 
	{
		assignZeros(calc->left);
		assignZeros(calc->right);
	}
}

int findKthSmallest (node* head, node* calc, int kth)
{
	if (kth < calc->left->data + 1)
	{
		//cout<<"LEFTting..\n";
		findKthSmallest (head->left, calc->left, kth);
	}
	else if (kth > calc->left->data + 1)
	{
		//cout<<"RIGHTting..\n";
		kth = kth - (calc->left->data + 1);
		findKthSmallest (head->right, calc->right, kth);
	}
	else if (kth == calc->left->data + 1 )
	{
		//cout<<"Returning..\n";
		return head->data;
	}
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
	
	system("pause");
	system("cls");
	cout<<"Populating And Assigning Zero's ..";
	populate(head, calc);
	assignZeros(calc);
	
	printTreePrimer (5,calc);
		
	int k = 6;
	cout<<k<<"th smallest is "<<findKthSmallest (head, calc, k);
}
