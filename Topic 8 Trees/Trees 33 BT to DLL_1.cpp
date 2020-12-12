#include <bits/stdc++.h>
#include "PrintTree.h"

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

void insert(Node **root, int a)
{
	*root = new Node;
	
	(*root)->data = a;
	(*root)->left = NULL;
	(*root)->right = NULL;
}

void postOrder(node* head)
{
	if (head->left != NULL)
		postOrder(head->left);
	else 
	{
		cout<<head->data<<" ";
		return;
	}
		
	if (head->right != NULL)
		postOrder(head->right);
	else
	{
		cout<<head->data<<" ";
		return;
	}
	
	cout<<head->data<<" ";
	return;
}

void preOrder (node* head)
{
	cout<<head->data<<" ";
	
	if (head->left != NULL)
		preOrder(head->left);
	else 
		return;
		
	if (head->right != NULL)
		preOrder(head->right);
	else
		return;
}

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

void convertToDLL(node **head, node **prev)
{
	//node *save = (*head);
	cout<<"At 1:"<<(*head)->data<<" : "<<(*head)<<"\n";
	if ( (*head)->left != NULL)
	{
		cout<<"Going LEFT\n";
		convertToDLL ( &(*head)->left, &(*prev));
	}
	
	//(*head)=save;
	cout<<"At 2:"<<(*head)->data<<" : "<<(*head)<<"\n";
	if ( (*prev) == NULL)	
		cout<<"Prev: NULL | ";
	else
		cout<<"Prev: "<<(*prev)->data<<" | ";
	cout<<"Head: "<<(*head)->data<<"\n";
	if ((*head)->left != NULL) cout<<"(*head)->left curr: "<<(*head)->left->data<<"\n";
	if ((*head)->right != NULL) cout<<"(*head)->right curr: "<<(*head)->right->data<<"\n";
	
	(*head)->left = (*prev);
	if ((*head)->left != NULL) cout<<"(*head)->left set as: "<<
		(*head)->data<<"->left="<<(*head)->left->data<<"\n";
	if ((*prev) != NULL)
	{
		//if ((*prev)->data != 1)
		cout<<"!!!!--"<<(*prev)->right<<"\n";
		(*prev)->right = (*head);
		cout<<"!!!!--"<<(*prev)->right<<"\n";
		cout<<"(*prev)->right set as: "<<(*prev)->data<<"->right="<<(*prev)->right->data<<"\n";
	}

	*prev = *head;
	if ( (*head)->right != NULL)
	{
		cout<<"Going RIGHT\n";
		convertToDLL ( &(*head)->right, &(*prev));
	}
		
}


void printDLL(node *head)
{
	cout<<"Printing DLL\n";
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

void mainConvert(node *head)
{
	node *prev = NULL;
	
	convertToDLL(&head, &prev);
	
	printDLL(head);
}

int main()
{	
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
	
	cout<<"Postorder: ";	postOrder(head);	cout<<"\n";
	cout<<"Preorder: ";		preOrder(head);		cout<<"\n";
	cout<<"Inorder: ";		inOrder(head);		cout<<"\n\n";
	
	cout<<"Make DLL:\n";
	mainConvert(head);
	cout<<"\n";
}
