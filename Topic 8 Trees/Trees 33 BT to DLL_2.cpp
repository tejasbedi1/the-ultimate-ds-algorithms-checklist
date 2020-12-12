#include <bits/stdc++.h>
#include "PrintTree.h"
#include "debug.h"

using namespace std;

void inOrder (node* head)
{
	if (head->left != NULL)
		inOrder (head->left);
	else
	{
		cout<<head->data<<" ";
		return;
	}
	cout<<head->data<<" ";
	
	if (head->right != NULL)
		inOrder (head->right);
	else
	{
		cout<<head->data<<" ";
		return;
	}
	return;
}

void convertToDLL(node *head, node **prev)
{
	if (head == NULL)
		return;
	
	convertToDLL(head->left, prev);
	
	debug (2, "Head: ", head->data, "| Prev: ", (*prev)->data, "\n");
	
	head->left = (*prev);
	(*prev)->right = head;
	
	*prev = head;
	
	convertToDLL(head->right, prev);
}

void printDLL(node *head);

void mainConvert(node *head)
{
	node *prev = new node;
	prev->data = -1;
	prev->left = NULL;
	prev->right = NULL;
	
	convertToDLL(head, &prev);
	
	printDLL(head);
}

void printDLL(node *head)
{
	debug (1, "Printing DLL\n");
	while(1)
	{
		cout<<head->data<<" ";
		if (head->left == NULL)
			break;

		head = head->left;
	}
	cout<<"\n";
	while(1)
	{
		cout<<head->data<<" ";
		if (head->right == NULL)
			break;
			
		head = head->right;
	}
	cout<<"\n";
	while(1)
	{
		cout<<head->data<<" ";
		if (head->left == NULL)
			break;
			
		head = head->left;
	}
	cout<<"\n";
}

int main()
{	
	LOG_LEVEL = 3;
	
	struct node *head = NULL;
	
	head = new node;
	head->data = 1;
	head->left = new node;
	head->right = new node;
	
	/*
	head->left->data = 2;
	head->left->left = NULL;
	//head->left->left = new node;
	//head->left->left->data = 4;
	//head->left->left->left = NULL;
	//head->left->left->right = NULL;
	
	head->left->right = NULL;
	//head->left->right = new node;
	//head->left->right->data = 5;
	//head->left->right->left = NULL;
	//head->left->right->right = NULL;
	
	head->right->data = 3;
	head->right->left = NULL;
	//head->right->left = new node;
	//head->right->left->data = 6;
	//head->right->left->left = NULL;
	//head->right->left->right = NULL;
	
	head->right->right = NULL;
	//head->right->right = new node;
	//head->right->right->data = 7;
	//head->right->right->left = NULL;
	//head->right->right->right = NULL;
	
	//*/
	
	///*
	head->left->data = 2;
	head->left->left = new node;
	head->left->left->data = 4;
	head->left->left->left = NULL;
	head->left->left->right = NULL;
	
	head->left->right = new node;
	head->left->right->data = 5;
	head->left->right->left = NULL;
	head->left->right->right = NULL;
	
	head->right->data = 3;
	head->right->left = new node;
	head->right->left->data = 6;
	head->right->left->left = NULL;
	head->right->left->right = NULL;
	
	head->right->right = new node;
	head->right->right->data = 7;
	head->right->right->left = NULL;
	head->right->right->right = NULL;
	//*/
	
	printTreePrimer (4, head);
	
	cout<<"Inorder: ";		inOrder(head);		cout<<"\n\n";
	
	cout<<"Make DLL:\n";
	mainConvert(head);
	cout<<"\n";
}
