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

void output(node* head)
{
	
	std::cout<<head->data<<" ";
	while (head->next != NULL)
	{
		head = head->next;
		std::cout<<head->data<<" ";
	}
	std::cout<<std::endl;
	while  (head != NULL)
	{
		std::cout<<head->data<<" ";	
		head = head->prev;
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
}
