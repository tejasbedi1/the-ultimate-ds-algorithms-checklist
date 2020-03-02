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
void findMid(node* head)
{
	node* mid = head;
	while (true)
	{
		if(head->next != NULL)
		{
			head = head->next;
			if (head->next != NULL)
			{
				mid = mid->next;
				head = head->next;
			}
			else
			{
				std::cout<<"Middle Element are: "<<mid->data<<" ";
				std::cout<<"& "<<(mid->next)->data<<"\n";
				return;
			}
		}
		else
		{
			std::cout<<"Middle Element is: "<<mid->data<<"\n";
			return;
		}
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

int main()
{
	struct node* head;
	head = NULL;
	
	
	insertInNode(&head,1);
	output(head);	
	findMid(head);
	
	insertInNode(&head,2);
	output(head);	
	findMid(head);
	
	insertInNode(&head,3);
	output(head);	
	findMid(head);
	
	insertInNode(&head,4);
	output(head);	
	findMid(head);
	
	insertInNode(&head,5);
	output(head);	
	findMid(head);
	//output(head);	
	//findMid(head);
}
