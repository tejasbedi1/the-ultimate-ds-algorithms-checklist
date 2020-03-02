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
	}
	else 
	{
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
}

void deleteNode(node** head, int i)
{
	int count=0;
	if ((*head)->next == NULL)
	{
		std::cout<<"Empty List\n";
		return;
	}
	
	node* control = *head;
	
	if (control->data == i)
	{
		std::cout<<"Found it at "<<count<<std::endl;	
		(*head) = (*head)->next;
		free(control);
		return;
	}
	node* prev = *head;
	
	while (control->next != NULL)
	{
		control = control->next;
		count++;
		if(control->data == i)
		{
			std::cout<<"Found it at "<<count<<std::endl;
			//control = control->next;
			prev->next = control->next;
			free(control);
			return;
		}	
		prev = prev->next;
	}
	std::cout<<"Particular data not found\n";
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
	std::cout<<std::endl;
}

int main()
{
	node* head;
	head = NULL;
	
	insertInNode(&head,1);
	insertInNode(&head,2);
	insertInNode(&head,3);
	insertInNode(&head,4);
	
	output(head);
	deleteNode(&head,1);
	deleteNode(&head,1);
	output(head);
}
