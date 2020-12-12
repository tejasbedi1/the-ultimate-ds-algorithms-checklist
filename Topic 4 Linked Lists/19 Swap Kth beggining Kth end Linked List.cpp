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

void display(node *head)
{
	if (head == NULL)
	{
		debug(1, "NO OUTPUT (Head empty)\n");
		return;
	}
	while (head != NULL)
	{
		debug (1, head->data, " ");
		head = head->next;
	}
}

void swap(node **prevA, node **a, node **prevB, node **b)
{
	node *temp1;
	node *temp2;
	
	// If they are same
	if (*a == *b)
	{
		debug (2, "Same node, No need to be swap\n");
	}
	// IF they are next to each other
	else if ( (*a)->next == *b )
	{
		temp1 = (*b)->next;
		(*prevA)->next = (*b);
		(*b)->next = (*a);
		(*a)->next = temp1;
	}
	else if (( *b)->next == *a )
	{
		temp1 = (*a)->next;
		(*prevB)->next = (*a);
		(*a)->next = (*b);
		(*b)->next = temp1;
	}
	else
	{
		temp1 = (*a)->next;
		temp2 = (*b)->next;
		
		(*prevA)->next = (*b);
		(*b)->next = temp1;
		(*prevB)->next = (*a);
		(*a)->next = temp2;
	}
}

void swapK(node **head, int k)
{
	// With kth node from begining with kth node from the end
	node *a = *head;
	node *b = *head;
	node *c = *head;
	node *prevA = NULL;
	node *prevB = NULL;
	
	int i=1;
	while (c->next != NULL)
	{
		if (i <= k)
		{
			if (i < k)
			{
				prevA = a;
				a = a->next;
				c = c->next;
			}
			else
				c = c->next;
			i++;	
		}
		else
		{
			prevB = b;
			b = b->next;
			c = c->next;
		}
	}	
	
	debug (2, "Begin K- ", a->data, " |", " Prev- ", prevA->data, "\n");
	debug (2, "End K- ", b->data, " |", " Prev- ", prevB->data, "\n");
	swap (&prevA, &a, &prevB, &b);
}

int main ()
{
	// Resource 
	// https://www.geeksforgeeks.org/swap-kth-node-from-beginning-with-kth-node-from-end-in-a-linked-list/
	// Asssuming both are elements are present in linked list
	// LOOK OUT FOR
	// 1) Y is next to X
	// 2) X is next to Y
	// 3) X and Y are same 
	
	LOG_LEVEL = 3;
	
	struct node *head = NULL;
	
	debug (2, "Pushing data...\n");
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
	push(&head,7);
	push(&head,8);
	push(&head,9);
	//push(&head,10); //Enable to test same node
	
	debug (2, "Swapping...\n");
	swapK(&head, 3);	// Normal swap
	//swapK(&head, 4); 	// a before b 
	//swapK(&head, 5); 	// b before a  
	//swapK(&head, 5); 	// For same node test
	debug (1, "Current List...\n");
	display(head);
}
