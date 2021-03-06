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

void reverse(node **head)
{
	node *prev = NULL;
	node *control = *head;
	node *controlNext = *head;

	controlNext = controlNext->next;
	
	while (controlNext != NULL)
	{
		control->next = prev;
		
		prev = control;
		control = controlNext;
		controlNext = controlNext->next;
	}
	
	control->next = prev;
	*head = control;
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

int main ()
{
	// Resource 
	// https://www.geeksforgeeks.org/reverse-a-linked-list/
	// MAIN - https://media.geeksforgeeks.org/wp-content/cdn-uploads/RGIF2.gif
	
	LOG_LEVEL = 3;
	
	struct node *head = NULL;
	
	
	debug (2, "Pushing data...\n");
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	
	debug (1, "Current List...\n");
	display(head);
	reverse(&head);
	debug (1, "\nReversing...\n");
	display(head);
}
