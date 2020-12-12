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
	debug (1, "Linked List...\n");
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
}

int main ()
{
	LOG_LEVEL = 3;
	
	int len = 0;
	struct node *head = NULL;
	
	
	debug (2, "Pushing data...\n");
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	
	display(head, &len);
	debug (1, "\nLength: ", len);
}
