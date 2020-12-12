#include <iostream>
//#include "PrintTree.h"

using namespace std;

// /*
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
// */
void insert(node** head, int data)
{
	if (*head == NULL)
	{
		*head = new node;
		(*head)->data = data;
		(*head)->right = NULL;
		(*head)->left = NULL;
		return;
	}
	
	node* temp;
	temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	*head = temp;
}

int main()
{
	std::cout<<"Initializing..\n";
	
	node* head;
	head = NULL;
	
	//insert(&head, 1);
	head = new node;
	head->data = 1;
	head->left = new node;
	head->right = new node;
	
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
	
	//printTreePrimer (3,head);
	
	cout<<head->data<<endl;
	
	cout<<head->left->data<<endl;
	cout<<head->right->data<<endl;
	
	cout<<head->left->left->data<<endl;
	cout<<head->left->right->data<<endl;
	
	cout<<head->right->left->data<<endl;
	cout<<head->right->right->data<<endl;
}
