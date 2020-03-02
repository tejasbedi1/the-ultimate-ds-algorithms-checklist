#include <iostream>
#include <stdlib.h> 

struct node
{
	int data;
	struct node* next;
};

void insertInNode(struct node** head, int i)
{
	if (*head == NULL)
	{
		*head = new node;
		(*head)->data = i;
		(*head)->next = NULL;	
	}	
	else 
	{
		node* temp = new node;
		temp->data = i;
		temp->next = NULL;
		
		node* control = (*head);
		
		while (control->next != NULL)
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
		std::cout<<head->data<<std::endl;	
		while (head->next != NULL)
		{
			head = head->next;
			std::cout<<head->data<<std::endl;
		}
	}
}

int main()
{
	std::cout<<"Initializing..\n";
	
	struct node* head;
	head = NULL;
	
	
	insertInNode(&head,1);
	insertInNode(&head,2);
	insertInNode(&head,3);
	
	output(head);	
}
