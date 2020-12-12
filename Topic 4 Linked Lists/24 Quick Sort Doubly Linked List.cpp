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

void display(node *first, node *last)
{
	node *head = first;
	while (head != last)
	{
		debug (1, head->data, " ");
		head = head->next;
	}
	debug (1, head->data, ", ");
	
	while (head != first)
	{
		debug (1, head->data, " ");
		head = head->prev;
	}
	debug (1, head->data, "\n");
}


node *sortPartition(node **first, node**last)
{
	node *f = *first;
	node *l = *last;
	debug(2, "Sorting Partition: BEGIN first, last: ", f->data, " ", l->data, "\n");
	
	node *p = *last; 	// Partition
	node *cont = *first; // Control
	node *temp;
	
	// This loop moves all nodes bigger than the partition to the back (of the partition)
	while (cont != p)
	{
		debug (3, "Sorting Partition: Analysing cont: ", cont->data, "\n");
		
		if (p->data > cont->data)
		{
			cont = cont->next;
		}
		else
		{
			if (cont == f)
			{
				if (cont->prev != NULL)
				{
					temp = cont->next;
					
					cont->prev->next = cont->next;
					cont->next->prev = cont->prev;
					
					if (l->next != NULL)
					{
						cont->next = l->next;
						l->next->prev = cont;
						
						cont->prev = l;
						l->next = cont;
						l = cont;
					}
					else
					{
						cont->next = NULL;
						cont->prev = l;
						
						l->next = cont;
						l = cont;
					}
					
					cont = temp;
					f = cont;
				}
				else
				{
					temp = cont->next;
					cont->next->prev = NULL;
					
					if (l->next != NULL)
					{
						cont->next = l->next;
						l->next->prev = cont;
						
						cont->prev = l;
						l->next = cont;
						l = cont;
					}
					else
					{
						cont->next = NULL;
						cont->prev = l;
						
						l->next = cont;
						l = cont;
					}
					
					cont = temp;
					f = cont;
				}
			}
			else
			{
				temp = cont->next;
					
				cont->prev->next = cont->next;
				cont->next->prev = cont->prev;
				
				if (l->next != NULL)
				{
					cont->next = l->next;
					l->next->prev = cont;
					
					cont->prev = l;
					l->next = cont;
					l = cont;
				}
				else
				{
					cont->next = NULL;
					cont->prev = l;
					
					l->next = cont;
					l = cont;
				}
				
				cont = temp;
					
			}
		}
		
		debug(3, "Sorting Partition: After loop f, l: ", f->data, " ", l->data, "\n");
	}
	
	*first = f;
	*last = l;
	debug(2, "Sorting Partition: END first, partition, last: ", f->data, " ", p->data, " ", l->data, "\n");
	if (LOG_LEVEL >= 3) display(f, l);
	
	return p;
}


void qSort(node **f, node **l)
{
	debug (2, "\nQSort: First & Last: ", (*f)->data, ",", (*l)->data, "\n");
	node *p;
	
	if ( (*f) != (*l) )
	{
		p = sortPartition( &(*f), &(*l) );
		
		debug(2, "QSort: first, partition, last: ", (*f)->data, " ", (p)->data, " ", (*l)->data, "\n");
		if (p->prev != NULL && *f != p && *f != p->prev)
			qSort( &(*f), &(p->prev) );
		
		debug(2, "QSort: first, partition, last: ", (*f)->data, " ", (p)->data, " ", (*l)->data, "\n");
	
		if (p->next != NULL && *l != p && *l != p->next)
			qSort( &(p->next), &(*l) );
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
	// Okay this one i didnt write very neatly but ..
	// Its fucking 3 on a saturday and I wannaa sleep
	
	// Resource
	// https://www.geeksforgeeks.org/quick-sort/
	
	LOG_LEVEL = 2;

	struct node *head = NULL;
	
	debug (2, "Pushing data...\n");

	push(&head,1);
	push(&head,8);
	push(&head,3);
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
