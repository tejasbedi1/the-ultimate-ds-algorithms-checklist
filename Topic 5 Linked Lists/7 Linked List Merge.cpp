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
// Does not have reliance on any other function
struct node* merge(node* a, node* b) {
	node* head = NULL;
	node* tail = NULL;
	
	node* temp = NULL;
	
	while(a != NULL && b != NULL)
	{
		if (a->data <= b->data)
		{
			temp = new node;
			temp->data = a->data;
			temp->next = NULL;	
			a = a->next;
		}	
		else if (a->data > b->data)
		{
			temp = new node;
			temp->data = b->data;
			temp->next = NULL;
			b = b->next;
		}
		if (head == NULL)
		{
			head = new node;
			head = temp;
			tail = head;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
		}
	}
	while (a != NULL)
	{
		temp = new node;
		temp->data = a->data;
		temp->next = NULL;	
		a = a->next;

		tail->next = temp;
		tail = tail->next;
	}
	while (b != NULL)
	{
		temp = new node;
		temp->data = b->data;
		temp->next = NULL;	
		b = b->next;
		
		tail->next = temp;
		tail = tail->next;
	}
	return head;
}

struct node* mergeS(node* a, node* b) // Relies on any insertInNode function, but this makes it sooo damn small
{
	node* head = NULL;
	
	while(a != NULL && b != NULL)
	{
		if (a->data <= b->data)
		{
			insertInNode(&head,a->data);
			a = a->next;
		}	
		else if (a->data > b->data)
		{
			insertInNode(&head,b->data);
			b = b->next;
		}
	}
	while (a != NULL)
	{
		insertInNode(&head,a->data);
		a = a->next;
	}
	while (b != NULL)
	{
		insertInNode(&head,b->data);
		b = b->next;
	}
	return head;
}

void output(node* head)
{
	if (head == NULL)
		return;
	std::cout<<head->data<<" ";
	while(head->next != NULL)
	{
		head = head->next;
		std::cout<<head->data<<" ";
	}
}

int main()
{
	node* head_a = NULL;
	node* head_b = NULL;
	
	
	insertInNode(&head_a,1);
	insertInNode(&head_a,3);
	insertInNode(&head_a,5);
	insertInNode(&head_a,7);
	insertInNode(&head_a,9);
	output(head_a);
	std::cout<<std::endl;
	insertInNode(&head_b,2);
	insertInNode(&head_b,4);
	insertInNode(&head_b,6);
	insertInNode(&head_b,8);
	insertInNode(&head_b,10);
	output(head_b);
	std::cout<<std::endl;
	std::cout<<std::endl;
	node* mergedList = merge(head_a, head_b);
	output(mergedList);
}
