#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

struct node
{
	int data;
	struct node *next;
};

void push(node **head, int data)
{
	if (*head == NULL)
	{
		(*head) = (node*)malloc(sizeof(node));
		(*head)->next = NULL;
		(*head)->data = data;
	}
	else
	{
		node *newNode = (node*)malloc(sizeof(node));
		newNode->data = data;
		newNode->next = NULL;
		
		node *control = *head;
		while (control->next != NULL)
		{
			control = control->next;
		}
		control->next = newNode;
	}
}

void display(node *head, int *count)
{
	if (head == NULL)
	{
		debug(1, "NO OUTPUT (Head empty)\n");
		return;
	}
	while (head != NULL)
	{
		*count += 1;
		debug (1, head->data, " ");
		head = head->next;
	}
	debug (1, "\n");
}

// v1 Dosen't work for differnt sized LL's
node *resultantNode (node *ll1, node *ll2, int &carry)
{
	struct node* ans = NULL;
	ans = new node;
	
	if (ll1->next != NULL && ll2->next != NULL)
		ans->next = resultantNode (ll1->next, ll2->next, carry );
	else
		ans->next = NULL;
	
	ans->data = ll1->data + ll2->data + carry;
	if (ans->data >= 10)
	{
		ans->data = ans->data - 10;
		carry = 1;
	}
	
	return ans;
}

// v2 Works for differnt sized LL's
node *resultantNode (node *ll1, node *ll2, int &len1, int &len2, int &carry)
{
	struct node* ans = NULL;
	ans = new node;
	
	if (len1 > len2)
	{
		len1--;
		ans->next = resultantNode (ll1->next, ll2, len1, len2, carry);
		
		ans->data = ll1->data + carry;
		if (ans->data >= 10)
		{
			ans->data = ans->data - 10;
			carry = 1;
		}
		else
			carry = 0;
		return ans;	
	}
	else if (len1 < len2)
	{
		len2--;
		ans->next = resultantNode (ll1, ll2->next, len1, len2, carry);
		
		ans->data = ll2->data + carry;
		if (ans->data >= 10)
		{
			ans->data = ans->data - 10;
			carry = 1;
		}
		else
			carry = 0;
			
		return ans;	
	}
	else
	{
		if (ll1->next != NULL && ll2->next != NULL)
			ans->next = resultantNode (ll1->next, ll2->next, len1, len2, carry );
		else
			ans->next = NULL;
			
		ans->data = ll1->data + ll2->data + carry;
		if (ans->data >= 10)
		{
			ans->data = ans->data - 10;
			carry = 1;
		}
		else
			carry = 0;
			
		return ans;	
	}
}

node *addLL(node *ll1, node *ll2, int &len1, int &len2)
{
	int carry = 0;
	struct node *sum = NULL;
	
	sum = resultantNode (ll1, ll2, len1, len2, carry);
	
	if (carry == 1)
	{
		struct node *a;
		a = new node;
		a->data = 1;
		a->next = sum;
		
		sum = a;
	}
	return sum;
}

int main ()
{
	// Resource
	// https://www.geeksforgeeks.org/sum-of-two-linked-lists/
	
	// Question 
	// (1)
	// 5->6->3 = 563 
	// 8->4->2 = 842
	// Ans = 1->4->0->5 = 1405
	// (2)
	// 5->5
	// 4->4->4->5
	// Ans 4->5->0->0
	
	// EXPLANATION 
	// Recursion mostly used
	// We move to the last element using recursion and  
	//  solve from there
	// That would be most performent
	
	LOG_LEVEL = 3;
	
	int len1 = 0;
	int len2 = 0;
	int len3 = 0;
	struct node *ll1 = NULL;
	struct node *ll2 = NULL;
	struct node *ans;
	
	/* 
	//(1)
	push(&ll1,5);
	push(&ll1,6);
	push(&ll1,3);
	//(2)
	push(&ll2,1);
	push(&ll2,1);
	push(&ll2,1);
	*/
	/*
	//(1)
	push(&ll1,5);
	push(&ll1,6);
	push(&ll1,3);
	//(2)
	push(&ll2,8);
	push(&ll2,4);
	push(&ll2,2);
	*/
	
	//(1)
	push(&ll1,5);
	push(&ll1,5);
	//(2)
	push(&ll2,4);
	push(&ll2,5);
	push(&ll2,4);
	push(&ll2,5);
	
	display(ll1, &len1);
	debug (1, "Length: ", len1, "\n");
	display(ll2, &len2);
	debug (1, "Length: ", len2, "\n");
	
	debug (1, "\nAdding \n");
	ans = addLL(ll1, ll2, len1, len2);

	display (ans, &len3);
	debug (1, "Length: ", len3, "\n");
}
