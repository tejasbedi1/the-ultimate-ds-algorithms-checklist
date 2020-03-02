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

void searchRecur(node* head, int count, int searchFor)
{
	if (head == NULL)
	{
		std::cout<<"Requested Element Unavailable"<<std::endl;
		return;
	}
	if (head->data == searchFor)
	{
		std::cout<<head->data<<" Found At Pos: "<<count<<std::endl;
		return;
	}
	searchRecur(head->next, ++count, searchFor);
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
	
	searchRecur(head, 1, 4);
	searchRecur(head, 1, 5);
	searchRecur(head, 1, 6);
	searchRecur(head, 1, 1);
	//output(head);
}
