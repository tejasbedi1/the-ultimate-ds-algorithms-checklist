// Inputs:  1->2->3->4->5->6->7->8->NULL and k = 3 
// Output:  3->2->1->6->5->4->8->7->NULL. 

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
		std::cout<<head->data<<" ";	
		while (head->next != NULL)
		{
			head = head->next;
			std::cout<<head->data<<" ";
		}
		std::cout<<"\n";
	}
}

node* maxNode(node* head)
{
	node* max = head;
	while (head->next != NULL)
	{
		if (head->data < ((head->next)->data))
		{
			max = head->next;
		}
		head = head->next;
	}
	return max;
}

void highest (node* head)
{
	std::cout<<"Highest node is at "<<maxNode(head)<<" with max data of "<<(maxNode(head)->data)<<"\n";
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
	
	highest (head);
	output(head);
}
