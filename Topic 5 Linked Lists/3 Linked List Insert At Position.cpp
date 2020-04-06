#include <iostream>

struct node
{
	int data;
	struct node* next;
};

void insertInNode(node** head, int i, int pos)
{
	if (*head == NULL)
	{
		//std::cout<<"No Head present, data will be saved at Position 1.\n";
		(*head) = new node;
		(*head)->data = i;
		(*head)->next = NULL;
		return;
	}
	if (pos == 1)
	{
		//std::cout<<"Pushing it at Position 1..\n";
		node* temp = new node;
		temp->data = i;
		temp->next = (*head);
		*head = temp;
		return;
	}
	if (pos <= 0)
	{
		//std::cout<<"Invalid Postion, Returning..\n";
		return;
	}
	if (pos == 50)
	{
		//std::cout<<"Max position putting it last..\n";
		node* control = *head;
		while (control->next != NULL)
		{
			control = control->next;
		}
		node* temp = new node;
		temp->data = i;
		temp->next = NULL;
		control->next = temp;	
		return;
	}
	{	// For custom position values
		int count = 1;
		node* control = *head;
		node* prev = *head;
		while (control->next != NULL)
		{
			control=control->next;
			count++;
			if (pos == count)
			{
				//std::cout<<"Pushing at Postion "<<count<<std::endl;
				node* temp = new node;
				temp->data = i;
				temp->next = control;
				prev->next = temp;
				return;
			}	
			prev = prev->next;
		}
	}
	//std::cout<<"Position available in the last or too far to be available..\n";
	node* control = *head;
	while (control->next != NULL)
	{
		control = control->next;
	}
	node* temp = new node;
	temp->data = i;
	temp->next = NULL;
	control->next = temp;	
	return;
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
	
	insertInNode(&head,1,10);
	insertInNode(&head,2,1);
	insertInNode(&head,3,50); // 50 for no particular position, just put it in the last for mow
	insertInNode(&head,4,2);
	insertInNode(&head,5,5);
	output(head);
}
