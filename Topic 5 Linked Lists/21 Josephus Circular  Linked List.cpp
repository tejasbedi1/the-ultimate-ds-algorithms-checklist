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
		(*head)->next = (*head);
		(*head)->data = data;
	}
	else
	{
		node *newNode = (node*)malloc(sizeof(node));
		newNode->data = data;
		newNode->next = *head;
		
		node *control = *head;
		while (control->next != *head)
		{
			control = control->next;
		}
		control->next = newNode;
	}
}

void josephusCircle(node **head, int k, int n)
{
	int counter = 1;
	node *prev = NULL;
	node *control = *head;
	node *temp;
	
	if (k == 1)
	{
		// Print the last element of the queue
	}
	else
	{
		prev = control;
		counter ++;
		control = control->next;
		//while (control->next != control->next->next)
		while (n != 1)
		{
			if (counter != k)
			{
				counter++;
				prev = control;
				control = control->next;	
			}
			else
			{
				temp = control;
				control = control->next;
				prev->next = control;
				
				free (temp);		
				counter = 1; n--;
			}
		}
		debug (1, "The chosen one: ", control->data);
	}
}

void display(node *head)
{
	debug (1, "Circular Linked List...\n");
	if (head == NULL)
	{
		debug(1, "NO OUTPUT (Head empty)\n");
		return;
	}
	node *control = head;
	do
	{
		debug (1, control->data, " ");
		control = control->next;
	}while (control != head);
	debug (1, "| ");
	do
	{
		debug (1, control->data, " ");
		control = control->next;
	}while (control != head);
}

int main ()
{
	// Resource
	// https://www.geeksforgeeks.org/josephus-circle-using-circular-linked-list/
	// This implementation is O (n * m )
	// Just to practice circular LL's 
	
	// Faster implemenations are as follows
	// https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/
	// https://www.geeksforgeeks.org/josephus-problem-using-bit-magic/
	 
	LOG_LEVEL = 3;
	
	struct node *head = NULL;
	int n = 5;
	int k = 2;
	
	debug (2, "Pushing data...\n");
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	
	display(head);
	
	debug (2, "\nJosephus Circle...\n");
	josephusCircle(&head, k, n);
}
