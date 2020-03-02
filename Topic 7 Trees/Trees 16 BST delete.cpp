// EVENTUALLY 
// DID 
// THIS
// AFTER 29th 
// CAUSE SEEMED DIFFICULT 
// BEFORE

// FATAL FLAW 
// THE TREE IS NOT BEING TRAVERSED LIKE A BST, but like a normal BT
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

void deleteNode(node* &head, int data, bool &flag)
{
	if (head == NULL)
		return;
	// PRE ORDER
	
	cout<<"Processing.. "<<head->data<<endl;
	
	if (head->left != NULL && head->left->data == data)
	{
		cout<<"Found on Left.. "<<data<<endl;
		node *suspect = head->left;
		// NO Children O_O
		if (suspect->left == NULL && suspect->right == NULL)
		{
			free(suspect);
			head->left = NULL;
		}
		// One Child
		else if (suspect->left != NULL && suspect->right == NULL)
		{
			head->left = suspect->left;
			free (suspect);
		}
		else if (suspect->left == NULL && suspect->right != NULL)
		{
			head->left = suspect->right;
			free (suspect);
		}
		// Two Children
		else 
		{
			// Find the inorder sucessor basically and replace and delete its links 
			node *temp;
			if (suspect->right->left == NULL)
			{
				temp = suspect->right;
				cout<<"Inorder Successor L "<<temp->data<<endl;
				head->left = temp;
				temp->left = suspect->left;
				free(suspect);
			}
			else
			{
				temp = suspect->right->left;
				node *prev = suspect->right;
				while (temp->left != NULL)
				{
					prev = temp;
					temp = temp->left;
				}
				cout<<"Inorder Successor L "<<temp->data<<" & Prev "<<prev->data<<endl;
				prev->left = NULL;
				head->left = temp;
				temp->left = suspect->left;
				temp->right = suspect->right;
				free(suspect);
			}
		}
		flag = false;
	}
	else if (head->right != NULL && head->right->data == data)
	{
		cout<<"Found on Right.. "<<data<<endl;
		node *suspect = head->right;
		// No Children O_O
		if (suspect->left == NULL && suspect->right == NULL)
		{
			free(suspect);
			head->right = NULL;
		}
		// One Child
		else if (suspect->left != NULL && suspect->right == NULL)
		{
			head->right = suspect->left;
			free (suspect);
		}
		else if (suspect->left == NULL && suspect->right != NULL)
		{
			head->right = suspect->right;
			free (suspect);
		}
		// Two Children
		else
		{
			node *temp;
			if (suspect->right->left == NULL)
			{
				temp = suspect->right;
				cout<<"Inorder Successor R"<<temp->data<<endl;
				head->right = temp;
				temp->left = suspect->left;
				free(suspect);
			}
			else
			{
				temp = suspect->right->left;
				node *prev = suspect->right;
				while (temp->left != NULL)
				{
					prev = temp;
					temp = temp->left;
				}
				cout<<"Inorder Successor R "<<temp->data<<" & Prev "<<prev->data<<endl;
				prev->left = NULL;
				head->right = temp;
				temp->left = suspect->left;
				temp->right = suspect->right;
				free(suspect);
			}
		}
		flag = false;
	}
	
	if (flag)
		deleteNode(head->left, data, flag);
	if (flag)
		deleteNode(head->right, data, flag);
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
	
	bool flag = true;
	// NO CONDITIONS TO DELETE HEAD 
	// CAUSE THAT WAS JUST CUUMBERSOME..
	deleteNode(head, 3, flag);
	
	system("pause");
	system("cls");
	printTreePrimer (4,head);
}
