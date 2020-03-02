#include <bits/stdc++.h>
#include <iostream>
#include "PrintTree2.h"

using namespace std;

/*struct nodeS // node Specialized
{
	int data;
	nodeS *left;
	nodeS *right;
	int height;
};
*/
nodeS* newNode(int data)
{
	nodeS* node = new nodeS;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 0; 	
	return node;
}

int findMaxHeightFromChild(nodeS* &head)
{
	int left = 0, right = 0;
	
	if (head->left != NULL)	
		left = head->left->height;
	
	if (head->right != NULL)
		right = head->right->height;
	
	head->height = (left >= right ? left : right);
}

nodeS* rrCase(nodeS* &head)
{
	nodeS *second, *first, *third;
	
	first = head;
	second = head->right;
	third = head->right->right;
	
	first->left = first->left; // UNCHANGED
	first->right = second->left;
	
	second->left = first;
	second->right = third; // UNCHANGED
	
	// Third UNCHANGED
	head = second;
	
	//first->height = first->height-2; 
	first->height = findMaxHeightFromChild(first) + 1;
	//third->height = third->height;	// UNCHANGED
	third->height = findMaxHeightFromChild(third) + 1;
	//second->height = second->height; // UNCHANGED 
	second->height = findMaxHeightFromChild(second) + 1;
}
nodeS* rlCase(nodeS* &head)
{
	nodeS *second, *first, *third;
	
	first = head;
	second = head->right;
	third = head->right->left;
	
	first->left = first->left; // UNCHANGED
	first->right = third->left;

	second->left = third->right;
	second->right = second->right; // UNCHANGED
	
	third->left = first;
	third->right = second;
	
	head = third;
	
	//first->height = first->height-2; 
	first->height = findMaxHeightFromChild(first) + 1;
	//second->height = second->height-1; 
	second->height = findMaxHeightFromChild(second) + 1;
	//third->height = third->height+1;
	third->height = findMaxHeightFromChild(third) + 1;
	
}
nodeS* llCase(nodeS* &head)
{
	nodeS *second, *first, *third;
	
	first = head;
	second = head->left;
	third = head->left->left;
	
	first->left = second->right;
	first->right = first->right;// UNCHANGED
	
	second->left = third;
	second->right = first;
	
	// third unchanged 
	head = second;
	
	//first->height = first->height-2; 
	first->height = findMaxHeightFromChild(first) + 1;
	//third->height = third->height;	// UNCHANGED
	third->height = findMaxHeightFromChild(third) + 1;
	//second->height = second->height; // UNCHANGED 
	second->height = findMaxHeightFromChild(second) + 1;
}
nodeS* lrCase(nodeS* &head)
{
	nodeS *first, *second, *third;
	
	first = head;
	second = head->left;
	third = head->left->right;
	
	first->left = third->right;
	first->right = first->right; // UNCHANGED
	
	second->left = second->left; // UNCHANGED
	second->right = third->left;
	
	third->left = second;
	third->right = first;
	
	head = third;
	
	//first->height = first->height-2; 
	first->height = findMaxHeightFromChild(first) + 1;
	//second->height = second->height-1; 
	second->height = findMaxHeightFromChild(second) + 1;
	//third->height = third->height+1;
	third->height = findMaxHeightFromChild(third) + 1;
}

int addAndCheck(nodeS* &head, int data)
{
	int height, heightOther;
	if (head == NULL)
	{
		head = newNode(data);
		head->height = 1;
		return head->height;
	}
	
	else if (head->data >= data) // MOVING LEFT
	{
		height = addAndCheck(head->left, data);
		//head->height = height + 1;
		//height = head->height;
		// Check if balanced
		if (head->right == NULL)
			heightOther = 0;
		else
			heightOther = head->right->height;		
		
		head->height = (height > heightOther ? height : heightOther) + 1;
		
		if (abs(height - heightOther) > 1) 
		{
			//cout<<"Unbalanced Left at node "<<head->data<<", ";
			cout<<abs(height - heightOther)<<" "; 
			if (head->left != NULL)
			{
				if (head->left->left != NULL && head->left->right == NULL)
				{
					cout<<"Processing Left Left Case.. ";
					llCase(head);
				}
				else if (head->left->left == NULL && head->left->right != NULL)
				{
					cout<<"Processing Left Right Case.. ";	
					lrCase(head);
				}
				else if (head->left->left != NULL && head->left->right != NULL)
				{
					int lh, rh;
					lh = head->left->left->height;
					rh = head->left->right->height;
					if (lh > rh)
					{
						cout<<"Processing Left Left Case.. ";
						llCase(head);
					}
					else if (lh > rh)
					{
						cout<<"Processing Left Right Case.. ";	
						lrCase(head);
					}
				}
			}
			/*
			// If left left case
			if (head->left != NULL  && head->left->left != NULL)
			{
				cout<<"Processing Left Left Case.. ";
				llCase(head);
			}
			// If left right case
			if (head->left != NULL  && head->left->right != NULL)
			{
				cout<<"Processing Left Right Case.. ";	
				lrCase(head);
			}
			*/
		}
		return head->height;
	}
	else if (head->data < data) // MOVING RIGHT 
	{
		height = addAndCheck(head->right, data);
		//head->height = height + 1;
		//height = head->height;
		// Check if balanced
		if (head->left == NULL)
			heightOther = 0;
		else
			heightOther = head->left->height;
		
		head->height = (height > heightOther ? height : heightOther) + 1;
			
		if (abs(height - heightOther) > 1) 
		{
			cout<<abs(height - heightOther)<<" ";
			//cout<<"Unbalanced Right at node "<<head->data<<", ";
			if (head->right != NULL)
			{
				if (head->right->right != NULL && head->right->left == NULL)
				{
					cout<<"Processing Right Right Case.. ";
					rrCase (head);
				}
				else if (head->right->right == NULL && head->right->left != NULL)
				{
					cout<<"Processing Right Left Case.. ";
					rlCase (head);
				}
				else if (head->right->right != NULL && head->right->left != NULL)
				{
					int lh, rh;
					lh = head->right->left->height;
					rh = head->right->right->height;
					if (rh > lh)
					{
						cout<<"Processing Right Right Case.. ";
						rrCase (head);
					}
					else if (lh > rh)
					{
						cout<<"Processing Right Left Case.. ";
						rlCase (head);
					}
				}
			}
			/*
			// If right right case 
			if (head->right != NULL && head->right->right != NULL)
			{
				cout<<"Processing Right Right Case.. ";
				rrCase (head);
			}
			// If right left  case
			if (head->right != NULL && head->right->left != NULL)
			{
				cout<<"Processing Right Left Case.. ";
				rlCase (head);
			}
			*/
		}
		return head->height;
	}
}

void insertInBBST(nodeS* &head, int data)
{
	if (head == NULL)
	{
		head = newNode(data);
		head->height = 1;
		return;
	}
	else
	{
		cout<<addAndCheck(head, data)<<" ";	
	}
}

void outputHeight(nodeS *head);

int main()
{
	nodeS* head;
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
	//insertInBBST(head, 1);
	//insertInBBST(head, 2);
	//insertInBBST(head, 3);
	
	//outputHeight (head);
	//printTreePrimer (4,head);
	
	int a;
	cout<<endl<<endl;
	do
	{
		cin>>a;
		system("cls");
		insertInBBST(head, a);
		printTreePrimer (5,head);
		outputHeight (head);
	} while (a != 0);
	
}

void outputHeight(nodeS *head)
{
	if (head == NULL)
		return;
		
	outputHeight (head->left);
	cout<<head->height<<" ";
	outputHeight (head->right);	
}
