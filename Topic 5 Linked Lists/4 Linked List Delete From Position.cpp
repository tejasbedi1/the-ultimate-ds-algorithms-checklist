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
		(*head) = new node;
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

void deleteFromPos(node** head, int pos)
{
	int count = 1;
	node* control = *head;
	if (pos == 1)
	{
		*head = (*head)->next;
		free(control);
		return;
	}
	control = control->next;
	count++;
	node* prev = *head;
	while (pos != count)
	{
		count++;
		control = control->next;
		prev = prev->next;
	}
	prev->next = control->next;
	free(control);
}

void output(node* head)
{
	if (head != NULL)
	{
		std::cout<<head->data<<"\n";
		while(head->next != NULL)
		{
			head = head->next;
			std::cout<<head->data<<"\n";
		}	
	}
	//std::cout<<std::endl;
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
	deleteFromPos(&head,5);
	output(head);
}
