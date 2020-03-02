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
	
	head->height = (left >= right ? left : right) + 1;
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
	
	first->height = findMaxHeightFromChild(first);
	third->height = findMaxHeightFromChild(third);
	second->height = findMaxHeightFromChild(second);
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
	
	first->height = findMaxHeightFromChild(first);
	second->height = findMaxHeightFromChild(second);
	third->height = findMaxHeightFromChild(third);
	
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
	
	// THIRD UNCHANGED 
	head = second;
	
	first->height = findMaxHeightFromChild(first);
	third->height = findMaxHeightFromChild(third);
	second->height = findMaxHeightFromChild(second);
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
	
	first->height = findMaxHeightFromChild(first);
	second->height = findMaxHeightFromChild(second);
	third->height = findMaxHeightFromChild(third);
}

int addToAVL(nodeS* &head, int data)
{
	int heightLeft, heightRight;
	if (head == NULL)
	{
		head = newNode(data);
		head->height = 1;
		return head->height;
	}
	// MOVING LEFT
	else if (head->data >= data) 
	{
		heightLeft = addToAVL(head->left, data);
		
		if (head->right == NULL)
			heightRight = 0;
		else
			heightRight = head->right->height;		
		
		head->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
		
		if (abs(heightLeft - heightRight) > 1) 
		{
			cout<<"Unbalanced Left at node "<<head->data<<", ";
			cout<<abs(heightLeft - heightRight)<<" "; 
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
					else if (rh > lh)
					{
						cout<<"Processing Left Right Case.. ";	
						lrCase(head);
					}
				}
			}
		}
		return head->height;
	}
	// MOVING RIGHT 
	else if (head->data < data) 
	{
		heightRight = addToAVL(head->right, data);
		
		if (head->left == NULL)
			heightLeft = 0;
		else
			heightLeft = head->left->height;
		
		head->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
			
		if (abs(heightLeft - heightRight) > 1) 
		{
			cout<<abs(heightLeft - heightRight)<<" ";
			cout<<"Unbalanced Right at node "<<head->data<<", ";
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
		}
		return head->height;
	}
}

void insertInAVL(nodeS* &head, int data)
{
	if (head == NULL)
	{
		head = newNode(data);
		head->height = 1;
		return;
	}
	else
	{
		cout<<addToAVL(head, data)<<" ";	
	}
}

void balanceThis (nodeS* &head)
{
	int heightL = 0;
	int heightR = 0;
	
	if (head->left != NULL)	
		heightL = head->left->height;	
	else 
		heightL = 0;
	
	if (head->right != NULL)	
		heightR = head->right->height;	
	else 
		heightR = 0;
		
	if (heightL > heightR)
	{
		cout<<"Left Heavy | "; // SO LL OR LR CASE
		if (head->left->left != NULL && head->left->right == NULL)
		{
			//cout<<"Processing Left Left Case | ";
			llCase(head);
		}
		else if (head->left->left == NULL && head->left->right != NULL)
		{
			//cout<<"Processing Left Right Case | ";	
			lrCase(head);
		}
		else if (head->left->left != NULL && head->left->right != NULL)
		{
			int lh, rh;
			lh = head->left->left->height;
			rh = head->left->right->height;
			if (lh >= rh)
			{
				//cout<<"Processing Left Left Case | ";
				llCase(head);
			}
			else if (rh > lh)
			{
				//cout<<"Processing Left Right Case | ";	
				lrCase(head);
			}
		}
	}
	else if (heightR > heightL)
	{
		cout<<"Right Heavy | "; // SO RR OR RL CASE
		if (head->right->right != NULL && head->right->left == NULL)
		{
			//cout<<"Processing Right Right Case | ";
			rrCase (head);
		}
		else if (head->right->right == NULL && head->right->left != NULL)
		{
			//cout<<"Processing Right Left Case | ";
			rlCase (head);
		}
		else if (head->right->right != NULL && head->right->left != NULL)
		{
			int lh, rh;
			lh = head->right->left->height;
			rh = head->right->right->height;
			if (rh >= lh)
			{
				//cout<<"Processing Right Right Case | ";
				rrCase (head);
			}
			else if (lh > rh)
			{
				//cout<<"Processing Right Left Case | ";
				rlCase (head);
			}
		}
	}
	else if (heightR == heightL)
		cout<<"IMPOSSIBLE.. | ";
}

bool checkIfBalancingRequired(nodeS* &head)
{
	int heightL = 0;
	int heightR = 0;
	
	if (head->left != NULL)
		heightL = head->left->height;
		
	if (head->right != NULL)
		heightR = head->right->height;
	
	if (abs(heightL - heightR) > 1)
	{
		//cout<<"ITS UNBALANCED.. | ";
		return true;
	}
	return false;		
}

void assignNewHeight(nodeS* &head)
{
	int left = 0, right =0;
	
	if (head->left != NULL)
		left = head->left->height;
	if (head->right != NULL)
		left = head->right->height;
	
	head->height = (left >= right ? left : right ) + 1;
}
void checkBalancingSuccessorsRecur (nodeS* &head)
{
	if (head->left != NULL)
	{
		checkBalancingSuccessorsRecur (head->left);
	}
	assignNewHeight(head);
	cout<<"Checking "<<head->data<<" | ";
	if (checkIfBalancingRequired(head))
		balanceThis(head);
}

int deleteFromBalancedTree(nodeS* &head, nodeS* &prev, int data)
{
	if (head == NULL)
		return 0;
		
	// MOVE LEFT	
	if (head->data > data) 
	{
		int heightL, heightR;
		
		heightL = deleteFromBalancedTree(head->left, head, data);
		
		if (head->right == NULL)
			heightR = 0;
		else
			heightR = head->right->height;
			
		head->height = (heightL >= heightR ? heightL : heightR) + 1;
		
		if (abs (heightL - heightR) > 1)
		{
			cout<<"Unbalanced at "<<head->data<<" | ";
			balanceThis (head);
		}
		return head->height;
	}
	// MOVE RIGHT
	else if (head->data < data) 
	{
		int heightL, heightR;

		heightR = deleteFromBalancedTree(head->right, head, data);
		
		if (head->left == NULL)
			heightL = 0;
		else
			heightL = head->left->height;
		
		head->height = (heightL >= heightR ? heightL : heightR) + 1;
		
		if (abs (heightL - heightR) > 1)
		{
			cout<<"Unbalanced at "<<head->data<<" | ";
			balanceThis (head);
		}
		return head->height;
	}
	// FOUND IT
	else if (head->data == data)
	{
		// NO CHILD
		if (head->left == NULL && head->right == NULL)
		{
			cout<<"No child at "<<head->data<<", prev:"<<prev->data<<" | ";
			if (prev->left == head)
			{
				cout<<"unlinking L | ";
				prev->left = NULL;
				free (head);
			}
			else if (prev->right == head)
			{
				cout<<"unlinking R | ";
				prev->right = NULL;
				free (head);
			}
			return 0;
		}
		// 1 CHILD
		// MADE A TEMP for head, cause can't directly free head 
		// cause prev->direction and head esentially point to the same
		// locations free one and the other also gets free'ed ..
		else if (head->left != NULL && head->right == NULL)
		{
			cout<<"1 child at "<<head->data<<", prev:"<<prev->data<<" | ";
			
			int tempH = head->left->height;
			nodeS *tempN = head;
			
			if (prev->left == head)
			{
				cout<<"unlinking L | ";
				prev->left = head->left;
			}
			else if (prev->right == head)
			{
				cout<<"unlinking R | ";
				prev->right = head->left;
			}
			
			free (tempN);
			return tempH;
		}
		else if (head->left == NULL && head->right != NULL)
		{
			cout<<"1 child at "<<head->data<<", prev:"<<prev->data<<" | ";
			
			int tempH = head->right->height;
			nodeS *tempN = head;
			
			if (prev->left == head)
			{
				cout<<"unlinking L | ";	
				prev->left = head->right;
			}
			else if (prev->right == head)
			{
				cout<<"unlinking R | ";	
				prev->right = head->right;
			}
			
			free (tempN);
			return tempH;
		}
		// 2 Children :O
		else
		{
			cout<<"2 child at "<<head->data<<", prev:"<<prev->data<<" | ";
			
			// IF the next inorder is the successor i.e head->right
			if (head->right->left == NULL)
			{
				cout<<"InOrder Successor: "<<head->right->data<<" | ";
				
				int tempH = head->right->height;
				nodeS *tempN = head;
				
				if (prev->left == head)
				{
					cout<<"unlinking L | ";	
					
					prev->left = head->right;
					prev->left->left = tempN->left;
					// New height
					if (prev->left->left->height >= tempH)
					{
						tempH = prev->left->left->height + 1;
						cout<<"New Height "<<tempH<<" | ";
						prev->left->height = tempH;
					}	
					
					if (checkIfBalancingRequired(prev->left))
						balanceThis(prev->left);
				}
				else if (prev->right == head)
				{
					cout<<"unlinking R | ";	

					prev->right = head->right;
					prev->right->left = tempN->left;
					// New height
					if (prev->right->left->height >= tempH)
					{
						tempH = prev->right->left->height + 1;
						cout<<"New Height "<<tempH<<" | ";
						prev->right->height = tempH;
					}
					
					if (checkIfBalancingRequired(prev->right))
						balanceThis(prev->right);	
				}
				free (tempN);
				return tempH;
			}
			// IF the next inorder is not the successor i.e head->right
			else 
			{
				nodeS *inSuccessorPrev = NULL;
				nodeS *inSuccessor = NULL;
				
				inSuccessorPrev = head->right;
				inSuccessor = head->right->left;
				while (inSuccessor ->left != NULL)
				{
					inSuccessor = inSuccessor ->left;
					inSuccessorPrev = inSuccessorPrev->left;
				}
				cout<<"InOrder Successor: "<<inSuccessor->data<<" with its prev: "<<inSuccessorPrev->data<<" | ";
				int tempH = 0;
				if (prev->left == head)
				{
					nodeS *temp = head;
					inSuccessor->left = head->left;
					inSuccessor->right = head->right;
					prev->left = inSuccessor;
					inSuccessorPrev->left = NULL;
					free (temp);
				}
				else if (prev->right == head)
				{
					nodeS* temp = head;
					inSuccessor->left = head->left;
					inSuccessor->right = head->right;
					prev->right = inSuccessor;
					inSuccessorPrev->left = NULL;
					free (temp);
				}
				// WILL HAVE TO CALCULATE NEW HEIGHTS 
				checkBalancingSuccessorsRecur (inSuccessor->right);
				tempH = (inSuccessor->left->height >= inSuccessor->right->height ? inSuccessor->left->height : inSuccessor->right->height) + 1;
				cout<<"New Height: "<<tempH<<" | ";
				inSuccessor->height = tempH;
				return tempH;
			}
			return head->height;
		}
	}
}

void outputHeight(nodeS *head);
void constructBinaryTree1 (nodeS* &head);
void constructBinaryTree2 (nodeS* &head);

int main()
{
	nodeS* head;
	head = NULL;
	
	/* EXAMPLE balanced binary search tree is  
        			6						8
				  /   \ 				 /	   \
        		3      	9			  2			10
        	  /  \	  /	  \			/	\	   /  \
    		2     5  7     11	   1	 5	  9	   11	
    	  /	     /    \    /	  /	   /   \		\
		1	   4       8  10	 0	  4		6		12
									 /		\			
									3		7
	*/
	constructBinaryTree1 (head);
	//constructBinaryTree2 (head);
	
	printTreePrimer (5,head,1);
	outputHeight (head);
	cout<<"\n\n";
	
	system ("pause");
	system ("cls");
	nodeS* prev = NULL;
	deleteFromBalancedTree(head, prev, 3);
	//CANT DELETE HEADS CAUSE I WAS TOO LAZY
	printTreePrimer (5,head,2);
	cout<<"INORDER: ";
	outputHeight (head);
}

void constructBinaryTree1 (nodeS* &head)
{
	insertInAVL(head, 6);
	insertInAVL(head, 3);
	insertInAVL(head, 9);
	
	insertInAVL(head, 2);
	insertInAVL(head, 5);
	insertInAVL(head, 7);
	insertInAVL(head, 11);
	
	insertInAVL(head, 1);
	insertInAVL(head, 4);
	insertInAVL(head, 8);
	insertInAVL(head, 10);	
}
void constructBinaryTree2 (nodeS* &head)
{
	insertInAVL(head, 8);
	insertInAVL(head, 2);
	insertInAVL(head, 9);
	
	insertInAVL(head, 1);
	insertInAVL(head, 5);
	insertInAVL(head, 10);
	insertInAVL(head, 11);
	
	insertInAVL(head, 0);
	insertInAVL(head, 4);
	insertInAVL(head, 6);
	insertInAVL(head, 12);	
	insertInAVL(head, 3);
	insertInAVL(head, 7);	
}

void outputHeight(nodeS *head)
{
	if (head == NULL)
	{
		//cout<<"NULL";
		return;
	}
	
	outputHeight (head->left);
	cout<<head->height<<" ";
	outputHeight (head->right);	
}
