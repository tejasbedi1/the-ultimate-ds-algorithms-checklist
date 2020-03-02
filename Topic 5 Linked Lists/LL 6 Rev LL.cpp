#include <iostream>

struct node
{
	int data;
	struct node* next;	
};

void insertInNode(node** head, int i)
{
	if (*head == NULL)
	{
		*head = new node;
		(*head)->data = i;
		(*head)->next = NULL;
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
	control->next = temp;
}

void revLL(node** head)
{
	// Method 1 
	node* control = *head;
	if (control == NULL || (control->next) == NULL)
	{
		std::cout<<"Insufficient nodes present to perform reversal\n";
		return;
	}
	control = control->next;
	(*head)->next = NULL;
	node* prev = *head;
	while (control->next != NULL)
	{
		prev = control;
		control = control->next;
		prev->next = *head;
		*head = prev;
	}
	prev = control;
	prev->next = *head;
	*head = prev;
}

void output(node* head)
{
	if (head == NULL)
		return;
	std::cout<<head->data<<"\n";
	while(head->next != NULL)
	{
		head = head->next;
		std::cout<<head->data<<"\n";
	}
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
	std::cout<<std::endl;
	revLL(&head);
	output(head);
}
