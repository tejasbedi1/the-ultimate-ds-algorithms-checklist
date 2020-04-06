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
	if (head == NULL)
	{
		std::cout<<"ERROR 44 & 202: Cannot print list, List Empty\n";
		return;
	}
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

void deleteFromNode(node** head, int i)
{
	if (*head == NULL)
	{
		std::cout<<"ERROR 202 & 307: List Empty, Cannot Delete\n";
		return;
	}
	node* control = *head;
	if ((*head)->data == i)
	{
		if ((*head)->next != NULL)
		{
			*head = (*head)->next;
			(*head)->prev = NULL;
			free (control);
			return;	
		}
		std::cout<<"All Elements Deleted\n";
		*head = NULL;
		return;
	}
	node* prev = *head;
	
	while (control->next != NULL)
	{
		control = control->next;
		if (control->data == i)
		{
			prev->next = control->next;	
			if (control->next != NULL)
			{
				(control->next)->prev = prev;
			}
			free(control);
			return;
		}
		prev = control;
	}
	std::cout<<"Element NOT Found\n";
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
	deleteFromNode(&head,5);
	deleteFromNode(&head,4);
	deleteFromNode(&head,3);
	deleteFromNode(&head,2);
	deleteFromNode(&head,1);
	deleteFromNode(&head,1);
	output(head);
}
