// Diameter is basically the max distance beteen two nodes
// EVery node will have a max height and max diameter

// To Get height for current node 
// height current node = Max height from left or right node + 1
// AND Diameter is heights of left and right + 1 	
// diameter = getHeight (head->left) + getHeight (head->right) + 1;
// Recursion will do the rest
	
#include <bits/stdc++.h>
#include <iostream>
#include "PrintTree.h"

using namespace std;

/*struct node
{
	int data;
	struct node* left;
	struct node* right;
};*/

node* newNode(int data)
{
	//node* node = (struct node*) malloc(sizeof(struct node));
	node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void LOTrecur(queue<node*> nq)
{
	node* curr = nq.front();
	nq.pop();
		
	cout<<curr->data<<" ";
	
	if (curr->left != NULL)		
		nq.push(curr->left);
	if (curr->right != NULL)	
		nq.push(curr->right);
	
	if (nq.empty() == true)
		return;
	else 
		LOTrecur (nq);
}

void levelOrderTraversal(node* head)
{
	queue <node*> nq;
	nq.push(head);
	LOTrecur(nq);
}

void output(node* head)
{
	levelOrderTraversal(head);
}

int getHeightAndDiameter(node* head, int& maxDia)
{
	if (head == NULL)
		return 0;	
	
	int heightL = getHeightAndDiameter(head->left, maxDia);
	int heightR = getHeightAndDiameter(head->right,maxDia);
	
	int nodeHeight = (heightL > heightR) ? heightL : heightR;
	int nodeDiameter = heightL+heightR+1;
	
	if (nodeDiameter > maxDia)
		maxDia = nodeDiameter;
		
	//cout<<"NODE: "<<head->data<<" HEIGHT: "<<nodeHeight+1<<" DIAMETER: "<<nodeDiameter<<endl;
	return nodeHeight+1;
}

int getDiameter(node* head)
{
	int maxDia = 0;
	int height = getHeightAndDiameter(head, maxDia);
	//cout<<"Height: "<<height<<endl;
	cout<<"Diameter of Tree is: "<<maxDia<<endl;
}

int main()
{
	// MAKES INPUT AS EFFECIENT AS SCANF PRINTF 
	// AFFECTS CONSOLE MANUPLATION
	//ios_base::sync_with_stdio(false);  
    // HELPS THE CONSOLE in certain senarios
	//cin.tie(NULL);	
    
	cout<<"Initializing..\n";
	
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
	//output(head);
	cout<<endl;
	getDiameter(head);
}
