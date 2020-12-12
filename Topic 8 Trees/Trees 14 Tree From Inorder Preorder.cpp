#include <bits/stdc++.h>
#include <iostream>
#include "PrintTree.h"

using namespace std;

node *newNode(int data)
{
	node *node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;	
}

int findPrepointPosition(int inorder[], int toFind, int l, int r)
{
	for (int i=l; i<=r; i++)
	{
		if (inorder[i] == toFind)
			return i;
	}
}

void constructTreeRecur (node* &head, int inorder[], int preorder[], int l, int r, int &prePoint)
{
	head = newNode( preorder[prePoint]);
	
	int pos = findPrepointPosition(inorder, preorder[prePoint], l, r);
	//cout<<"Prepoint "<<preorder[prePoint]<<" l "<<l<<" r "<<r<<" pos "<<pos<<endl;
	//Check if left exists
	if (pos != l && pos > l)
	{
		//cout<<"Going left from "<<head->data<<"\n";
		prePoint++;
		constructTreeRecur(head->left, inorder, preorder, l, pos-1, prePoint);
	}
	else
		return;
		
	// Check if right exists	
	if (pos != r && pos < r)
	{
		//cout<<"Going right from "<<head->data<<"\n";
		prePoint++;
		constructTreeRecur(head->right, inorder, preorder, pos+1, r, prePoint);
	}
	else 
		return;
}

void constructTree(node* &head,int inorder[], int preorder[])
{
	int startingPoint = 0;
	int lowerLimit = 0;
	int upperLimit = 10;
	constructTreeRecur (head, inorder, preorder, lowerLimit, upperLimit, startingPoint);
}

int main()
{
	node *head;
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

	//printTreePrimer (5,head);
	int inorder[] = {10,6,11,4,7,2,8,5,9,1,3};
	int preorder[] = {1,2,4,6,10,11,7,5,8,9,3};
	//int inorder[] = {4,2,5,1,3};
	//int preorder[] = {1,2,4,5,3};
	
	constructTree(head, inorder, preorder);
	//system("pause");
	printTreePrimer (5,head);
}
