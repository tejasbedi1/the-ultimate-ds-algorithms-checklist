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
		
		// Begin - Adding loop
		if (data == 5)
			newNode->next = *head;
		// End - Adding loop
		
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

bool loopPresence(node *head)
{
	node *slowP = head;
	node *fastP = head;
	
	while (fastP != NULL)
	{
		fastP = fastP->next;
		if (fastP == slowP)
			return true;
		
		if (fastP != NULL)
		{
			fastP = fastP->next;
			if (fastP == slowP)
				return true;
			
			slowP = slowP->next;	
		}
		else
			break;
	}
	return false;
}

int main ()
{
	// Resource 
	// https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
	// Hashing (Requires extra space + compute)
	// Mark visited space (Requires extra space)
	// Floyd Cycle Fidning Algorithm (Minimum space + fastest (2N))
	
	LOG_LEVEL = 3;
	
	struct node *head = NULL;
	
	debug (2, "Pushing data...\n");
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	
	debug (2, "Checking loop...\n");
	if ( loopPresence(head) == true)
	{
		debug (1, "Loop detected in Linked List\n");
	}
	else
	{
		debug (1, "No Loop, present in Linked List\n");
	}
	//debug (1, "Current List...\n");
	//display(head);
}
