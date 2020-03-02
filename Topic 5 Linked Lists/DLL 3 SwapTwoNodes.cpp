// DID TRY AND DO THIS PROBLEM 
// BUT ITS TALKING TOO MUCH TIME ON THE LOGIC SIDE OF THINGS

#include <iostream>

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

void insertInNode(node** head, int i)
{
	if (*head == NULL)
	{
		(*head) = new node;
		(*head)->data = i;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		return;
	}
	node* control = *head;
	while (control->next != NULL)
	{
		control = control->next;
	}
	node* temp = new node;
	temp->data = i;
	temp->next = NULL;
	temp->prev = control;
	
	control->next = temp;
}

// Kth node from begining and Kth from the last

void swapTwoNodes (node** head, int posA, int posB)
{
	if (*head == NULL)
	{
		std::cout<<"Empty List\n";
		return;
	}
	int temp;
	// We want A to always be less, our logic assumes that
	if (posB < posA)
	{
		temp = posA;
		posA = posB;
		posB = temp;
	}
	// Positions 
	//std::cout<<"Pos 1: "<<posA<<"\n";
	//std::cout<<"Pos 2: "<<posB<<"\n";
	
	node* control = *head;
	node* a;
	node* b;
	temp = 1;
	while (control != NULL)
	{
		if (temp == posA)
			a = control;
		if (temp == posB)
			b = control;
		temp++;
		control = control->next;
	}
	//std::cout<<"Node a: "<<a->data<<"\n";
	//std::cout<<"Node b: "<<b->data<<"\n";
	
	bool ishead = false;
	if (a == *head)
	{
		//std::cout<<"A is head\n";
		ishead = true;
	}
	
	node* prev_a;
	node* prev_b;
	node* next_a;
	node* next_b;
	
	next_a = a->next;
	next_b = b->next;
	prev_b = b->prev; 
	
	ishead == true ? prev_a = NULL : prev_a = a->prev; 
	
	if (posA == posB-1)
	{
		//std::cout<<"Positions are back to back\n";
		a->next = next_b;
		a->prev = b;
		b->next = a;
		if (next_b != NULL)
			next_b->prev = a;
		if (prev_a != NULL)
		{
			prev_a->next = b;
			b->prev = prev_a;
		}
		else
		{
			b->prev = NULL;
			*head = b;
		}
	}
	else
	{
		//std::cout<<"Positions are spaced out\n";
		a->next = next_b;
		a->prev = prev_b;
		prev_b->next = a;
		
		b->next = next_a;
		next_a->prev = b;
		
		if (next_b != NULL)
			next_b->prev = a;
		if (prev_a != NULL)
		{
			prev_a->next = b;
			b->prev = prev_a;	
		}
		else 
		{
			b->prev = NULL;
			*head = b;	
		}	
	}
}

void output(node* head) 
{
	std::cout<<head->data<<" ";
	while (head->next != NULL)
	{
		head = head->next;
		std::cout<<head->data<<" ";
	}
	std::cout<<"\n";
	while  (head != NULL)
	{
		std::cout<<head->data<<" ";	
		head = head->prev;
	}
	std::cout<<"\n";
}

int main()
{
	node* head;
	head = NULL;
	
	insertInNode(&head,1);
	insertInNode(&head,2);
	insertInNode(&head,3);
	insertInNode(&head,4);
	insertInNode(&head,5);
	output(head);
	std::cout<<"\n";
	// eg. if List is 1 2 3 4 5
	// and we swap 1,5 
	// then List will become 5 2 3 4 1
	// while inserting swap postions, assume
	// - values are different
	// - given positions are available
	
	swapTwoNodes(&head,1,5);
	//swapTwoNodes(&head,1,2);
	//swapTwoNodes(&head,5,4);
	//swapTwoNodes(&head,2,2);
	
	output(head);
}
