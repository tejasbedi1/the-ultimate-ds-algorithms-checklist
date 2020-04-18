#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

void push(node **head, int data)
{
	if (*head == NULL)
	{
		(*head) = (node*)malloc(sizeof(node));
		(*head)->next = NULL;
		(*head)->prev = NULL;
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
		newNode->prev = control;
		
		control->next = newNode;
	}
}

void display(node *head)
{
	while (head->next != NULL)
	{
		debug (1, head->data, " ");
		head = head->next;
	}
	debug (1, head->data, " , ");
	
	while (head != NULL)
	{
		debug (1, head->data, " ");
		head = head->prev;
	}
	debug (1, "\n");
}


node *sortPartition(node **first, node**last)
{
	node *f = *first;
	node *l = *last;
	debug(2, "Sorting Partition: first, last: ", f->data, " ", l->data, "\n");
	
	node *p = *last; 	// Partition
	node *cont = *first; // Control
	node *temp;
	
	while (cont != l)
	{
		if (p->data > cont->data)
		{
			cont = cont->next;
		}
		else
		{
			
		}
	}
	
	return p;
}

void qSort(node **f, node **l)
{
	debug (2, "QSort: First & Last: ", f->data, ",", l->data, "\n");
	node *p;
	
	if ( (*f) != (*l) )
	{
		p = sortPartition( &(*f), &(*l) );
		sortPartition( &(*f), &(p->prev) );
		sortPartition( &(p->next), &(*l) );
	}
}

void quickSort(node **head)
{
	node *l = *head;
	while (l->next != NULL)
	{
		l = l->next;
	}
	qSort( &(*head), &l);
}

int main ()
{
	// Resource
	
	LOG_LEVEL = 2;

	struct node *head = NULL;
	
	debug (2, "Pushing data...\n");

	push(&head,3);
	push(&head,8);
	push(&head,1);
	push(&head,9);
	push(&head,5);
	push(&head,7);
	push(&head,4);
	
	debug (1, "Sorting List...\n");
	display(head);
	
	debug (1, "\nSorted List..\n");
	quickSort(&head);
	display(head);
}
