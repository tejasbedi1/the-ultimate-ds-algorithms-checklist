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

void split(node **first, node **mid, node **last)
{
	*mid = *first;
	*last = *first;
	
	while ( (*last)->next != NULL )
	{
		if ( (*last)->next->next != NULL )
		{
			(*mid) = (*mid)->next;
			(*last) = (*last)->next->next;
		}
		else 
		{
			(*last) = (*last)->next;
		}
	}
}

void merge(node **first, node **mid)
{
	debug (2, "MErge, We have first, last: ", (*first)->data, ",", (*mid)->data, "\n");
	
	node *h;
	node *a = *first;
	node *b = *mid;
	node *p; // prev
	
	if (a->data > b->data)
	{
		h = b;
		p = b;
		b = b->next;
	}
	else
	{
		h = a;
		p = a;
		a = a->next;
	}
	
	debug (2, "Merge, First set as: ", h->data, "\n");
	
	while (a != NULL && b != NULL)
	{
		if (a->data > b->data)
		{
			p->next = b;
			b->prev = p;
			p = b;
			b = b->next;
		}
		else
		{
			p->next = a;
			a->prev = p;
			p = a;
			a = a->next;
		}
	}
	
	while (a != NULL)
	{
		p->next = a;
		a->prev = p;
		p = a;
		a = a->next;	
	}
	
	while (b != NULL)
	{
		p->next = b;
		b->prev = p;
		p = b;
		b = b->next;
	}
	
	*first = h;
	
	if (LOG_LEVEL >= 2) display(*first);
}

void mergeSort(node **head)
{
	node *first;
	node *mid;
	node *last;
	node *temp;
	
	first = *head;
	
	split(&first, &mid, &last);
	
	debug (2, "\nMergeSort, First: ", first->data, "\n");
	debug (2, "MergeSort, Mid: ", mid->data, "\n");
	debug (2, "MergeSort, Last: ", last->data, "\n");
	
	if (first != last)
	{
		// The right side has to start with mid + 1
		temp = mid;
		mid = mid->next;
		temp->next = NULL;
		mid->prev = NULL;
	
		mergeSort( &first );	// LEFT
		mergeSort( &mid ); 		// RIGHT
		merge( &first, &mid);
		
		*head = first;
	}
}

int main ()
{
	// Resource
	// https://www.geeksforgeeks.org/merge-sort/
	// https://www.studytonight.com/post/using-merge-sort-to-sort-a-doubly-linked-list
	//
	
	LOG_LEVEL = 2;

	struct node *head = NULL;
	
	debug (2, "Pushing data...\n");

	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	push(&head,10);
	
	
	debug (1, "Sorting List...\n");
	display(head);
	
	debug (1, "\nSorted List..\n");
	mergeSort(&head);
	display(head);
}
