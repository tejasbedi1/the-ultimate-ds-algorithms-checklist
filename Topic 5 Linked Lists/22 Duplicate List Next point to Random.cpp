#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

struct node
{
	int data;
	struct node *next;
	struct node *random;
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
		node *control = *head;
		while (control->next != NULL)
		{
			control = control->next;
		}
		
		node *newNode = (node*)malloc(sizeof(node));
		newNode->data = data;
		newNode->next = NULL;
		
		control->next = newNode;
	}
}

void random(node **head, int n)
{
	node *control = *head;
	node *temp = *head;
	//debug(2, "*control", *control);
	int i = 0;
	int r;
	while (i < n)
	{
		r = rand() % 5; // Will rand btw 0-4
		debug(2, "Rand() ", r, " | ");
		temp = *head;
		while (r != 0)
		{
			temp = temp->next;
			r--;
		}
		control->random = temp;
		
		control = control->next;
		i++;
	}
	cout<<endl;
}
	
void display(node *head)
{
	while (head != NULL)
	{
		debug (1, head->data, " ");
		head = head->next;
	}
	debug (1, "\n");
}

void displayWR(node *head)
{
	while (head != NULL)
	{
		debug (1, head->data, " (->", head->random->data, ")  ");
		head = head->next;
	}
	debug (1, "\n");
}

void duplicateIT(node **head, node **dupli)
{
	node *control = *head;
	node *newNode;
	
	// Adding new nodes with similar data
	while (control != NULL)
	{
		newNode = (node*)malloc(sizeof(node));
		newNode->data = control->data;
		newNode->next = control->next;
		
		control->next = newNode;
		
		control = newNode->next;	
	}
	
	// Assigning head node for duplicate list
	node *controlD;
	
	control = *head;
	*dupli = control->next;
	controlD = *dupli;
	
	// Assigning randoms for the new nodes
	while (true)
	{
		controlD->random = control->random->next;
		if (control->next->next != NULL)
		{
			control = control->next->next;
			controlD = controlD->next->next;	
		}
		else
			break;
	}
	
	// Seperating the old and new list
	control = *head;
	controlD = control->next;
	
	while (true)
	{
		if (control->next->next != NULL)
		{
			control->next = control->next->next;
			control = control->next;
				
			controlD->next = controlD->next->next;
			controlD = controlD->next;		
		}
		else
			break;
	}
}

int main ()
{
	// Resource
	// https://www.geeksforgeeks.org/clone-linked-list-next-random-pointer-o1-space/

	// Our question says that we have a normal list 
	// but all node have a second pointer which point to any random node
	
	// Our task is to duplicate the current list along with the random pointing
	// In O (n) Time and using only O (1) space
	
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
	
	debug (1, "\nSetting Random...\n");
	random(&head, 5);
	displayWR(head);
	display(head);
	displayWR(head);
	
	debug (1, "\nDuplicate List...\n");
	node *dupli;
	duplicateIT(&head, &dupli);
	display(dupli);
	displayWR(dupli);
}
