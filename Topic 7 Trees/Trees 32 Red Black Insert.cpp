#include <bits/stdc++.h>
#include <iostream>
#include "PrintTreeRB.h"

#define RED 0
#define BLACK 1

using namespace std;

/*
struct nodeRB // node Specialized
{
	int data;
	nodeRB *left;
	nodeRB *right;
	nodeRB *parent;
	int color; // 0(false) RED 1(true) BLACK 
};
*/

nodeRB *newNode(int data)
{
	nodeRB *node = new nodeRB;
	node->data = data;
	
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	
	node->color = RED;
	return node;
}

nodeRB *llCase(nodeRB *head)
{
	
}
nodeRB *lrCase(nodeRB *head)
{
	
}
nodeRB *rrCase(nodeRB* &head, nodeRB *node)
{
	nodeRB *first, *second, *third;
	first = node->parent->parent;
	second = node->parent;
	third = node;
	
	first->left = first->left; // UNCHANGED
	first->right = second->left;
	
	second->left = first;
	second->right = third; // UNCHANGED
	
	// Third Unchanged
	if (first->parent != NULL)
	{
		cout<<"Parent Exists | ";
		second->parent = first->parent;
		first->parent = second;
	}
	else 
	{
		cout<<"First is Head | ";
		second->parent = NULL;
		head = second;
		first->parent = second;
	}
} 
nodeRB *rlCase(nodeRB* &head, nodeRB* &node)
{
	nodeRB *first, *second, *third;
	first = node->parent->parent;
	second = node->parent;
	third = node;
	
	if (first->parent != NULL)
	{
		cout<<"Parent Exists | ";
		if (first->parent->left == first)
			first->parent->left = third;
		else if (first->parent->right == first)
			first->parent->right = third;
			
		third->parent = first->parent;
		first->parent = third;
		second->parent = third;
	}
	else 
	{
		cout<<"First is Head | ";
		third->parent = NULL;
		head = third;
		first->parent = third;
		second->parent = third;
	}
		
	first->left = first->left; // UNCHANGED
	first->right = third->left;
	cout<<"Address Node RL "<<node<<" | ";
	second->left = third->right;
	second->right = second->right; // UNCHANGED
	cout<<"Address Node RL "<<node<<" | ";
	third->left = first;
	third->right = second;
	
	//cout<<"Second->left in RL "<<second->left<<" | ";
	//cout<<"Address Node RL "<<node<<" | ";
	//cout<<"Address Third RL "<<third<<" | ";
	node = third;
	//cout<<"Second->left in RL "<<second->left<<" | ";
	return third;
}
nodeRB *rlCaseUpDn(nodeRB* &head, nodeRB* &node)
{
	nodeRB *first, *second, *third;
	first = node;
	second = node->right;
	third = node->right->left;		
	cout<<"F, S, T: "<<first->data<<" "<<second->data<<" "<<third->data<<" | ";
	
	if (first->parent != NULL)
	{
		cout<<"Parent Exists | ";
		if (first->parent->left == first)
			first->parent->left = third;
		else if (first->parent->right == first)
			first->parent->right = third;
			
		third->parent = first->parent;
		first->parent = third;
		second->parent = third;
	}
	
	first->left = first->left; // UNCHANGED
	first->right = third->left;

	second->left = third->right;
	second->right = second->right; // UNCHANGED
		
	third->left = first;
	third->right = second;
	
	cout<<"Address Node RL "<<third<<" | ";
	//node = third;
	cout<<"Address Node RL "<<third<<" | ";
	cout<<third->left->data<<" "<<third->right->data<<" | ";
	
	return third;
}

void handleViolationHeadRed(nodeRB* &head)
{
	head->color = BLACK;
}

void handleVoilationParentRed(nodeRB* &head, nodeRB* &node)
{
	// WHEN P and C are both Red
	// Check Relative color
	// IF Relative is RED then COLOR FLIP
		// Change gradparent to red 
		// Relative and parent to black 
		// child remains red 
	// IF Relative is NULL OR BLACK then ROTATE AND THEN COLOR SET 
		// Rotate appropriately first then
		// color parent black and both children red
	
	cout<<"Handeling Violation P is R | ";
	nodeRB *relative;
	if (node->parent->parent->left == node->parent)
	{
		relative = node->parent->parent->right;
	}
	else if (node->parent->parent->right == node->parent)
	{
		relative = node->parent->parent->left;	
	}
	
	if (relative == NULL)
		cout<<"Relative: NULL | ";
	else
		cout<<"Relative: "<<relative->data<<" | ";
	
	if (relative == NULL || relative->color == BLACK)
	{
		cout<<"Rotating | ";
		if (node->parent->parent->left == node->parent)
		{
			if (node->parent->left == node)
			{
				cout<<"LL Case | ";	
			}
			else if (node->parent->right == node)
			{
				cout<<"LR Case | ";	
			}
		}
		else if (node->parent->parent->right == node->parent)
		{
			if (node->parent->left == node)
			{
				cout<<"RL Case | ";
				cout<<"Address Before RL "<<node<<" | ";
				//nodeRB *temp = rlCase(head, node);
				nodeRB *temp = rlCaseUpDn(head, node->parent->parent);
				node = temp;
				cout<<"Address After RL "<<temp<<" | ";
				
				cout<<"Color Correcting | ";
				temp->color = BLACK;
				temp->right->color = RED;
				temp->left->color = RED;
				//node->color = BLACK;
				//node->right->color = RED;
				//node->left->color = RED;
				//printTreePrimer (4,head,4);

			}
			else if (node->parent->right == node)
			{
				cout<<"RR Case | ";
			}
		}
	}
	else if (relative->color == RED)
	{
		cout<<"Relative RED, Color Flipping | ";
		node->parent->parent->color = RED;
		relative->color = BLACK;
		node->parent->color = BLACK;
	}
}

bool checkViolations(nodeRB* &head, nodeRB* &node)
{
	// Every node is either RED or BLACK
	// Head Node is always BLACK
	// No two adjacent RED nodes
	// Same number of BLACKS fwhen traversing from any node
	//if (node == NULL)
	//	return false;
	cout<<"V check at "<<node->data<<" | ";
	bool check = false;
	
	if (head->color != BLACK)
	{
		cout<<"V Head Red | ";
		handleViolationHeadRed(head);
		check = true;
	}
		
	if (node->color == RED)
	{
		if (node->parent->color == RED)
		{
			cout<<"V at "<<node->data<<", P is R | ";
			cout<<"Address Before V "<<node<<" | ";
			handleVoilationParentRed(head, node);
			cout<<"Address A-fter V "<<node<<" | ";
			check = true;
		}
	}  
	
	// BLACKS ?
	// not right now
	// CRACKED BLACK :)
	if (check == true)
	{
		cout<<"V Loop | ";
		checkViolations(head, node);
	}
}

void insertIntoRBRTreeRecur(nodeRB* &head, nodeRB* &node, int data)
{
	//cout<<"At "<<head->data<<" | ";
	if (node->data > data)
	{
		if (node->left != NULL)
		{
			//cout<<"Moving Left | ";
			insertIntoRBRTreeRecur(head, node->left, data);
		}
		else
		{
			//cout<<"Adding to left "<<data<<" | ";
			node->left = newNode (data);
			node->left->parent = node;
			checkViolations(head, node->left);
		}
	}
	else if (node->data < data)
	{
		if (node->right != NULL)
		{
			//cout<<"Moving Right | ";
			insertIntoRBRTreeRecur(head, node->right, data);
		}
		else 
		{
			//cout<<"Adding to right "<<data<<" | ";
			node->right = newNode (data);
			node->right->parent = node;
			checkViolations(head, node->right);
		}
	}
}

void insertIntoRBTree(nodeRB* &head, int data)
{
	if (head == NULL)
	{
		head = newNode(data);
		head->color = BLACK;
	}
	else
	{
		nodeRB *node = head;
		insertIntoRBRTreeRecur(head, node, data);
	}
}

void naiveInput (nodeRB* &head);
 
int main ()
{
	nodeRB *head;
	head = NULL;
	
	/* TREE DIAGRAM xD
        			3
				  /   \ 
        		1      	5
        	  /  \	  /	  \
    		?     ?  ?     7
    	  /	     /    \    /
		?	   ?       ?  6
	*/
	
	//naiveInput(head);
	insertIntoRBTree(head, 3);
	insertIntoRBTree(head, 1);
	insertIntoRBTree(head, 5);
	insertIntoRBTree(head, 7);
	insertIntoRBTree(head, 6);
	
	printTreePrimer (4,head,4);
}

void naiveInput (nodeRB* &head)
{
	head 				= newNode(6);
	head->color 		= BLACK;
	
	head->left 			= newNode(3);
	head->left->color 	= RED;
	
	head->left->left 		= newNode(2);
	head->left->left->color	= BLACK;
	head->left->right 		= newNode(5);
	head->left->right->color= BLACK;
	
	//head->left->left->left  = newNode(1);
	//head->left->right->left = newNode(4);
	
	head->right 		= newNode(9);
	head->right->color 	= RED;
	
	head->right->left 		= newNode(7);
	head->right->left->color= BLACK;
	head->right->right 		= newNode(11);
	head->right->right->color= BLACK;
	
	//head->right->left->right = newNode(8);
	//head->right->right->left = newNode(10);
}
