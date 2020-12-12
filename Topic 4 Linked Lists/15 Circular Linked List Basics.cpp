#include <iostream>
#include <stdlib.h> 

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
		(*head)->next = *head;
	}
	else
	{
		node* temp = new node;
		temp->data = i;
		temp->next = *head;
			
		node* control = *head;
		
		while (control->next != *head)
		{
			control = control->next;
		}
		control->next = temp;
	}
}

void output(node *head)
{
	if (head == NULL)
	{
		std::cout<<"NO OUTPUT (Head is empty))";	
	}
	else 
	{
		node* control = head;
		std::cout<<control->data<<std::endl;	
		while (control->next != head)
		{
			control = control->next;
			std::cout<<control->data<<std::endl;
		}
		std::cout<<"\n";
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
