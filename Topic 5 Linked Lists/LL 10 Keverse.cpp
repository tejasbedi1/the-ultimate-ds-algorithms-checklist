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

void reverse (node** front, node** back, node** prev_f, node** head) // prev f is the one behind front
{
	node* a = *front;
	node* b = *back;
	/*std::cout<<"Affected Nodes ";
	while (a != b)
	{
		std::cout<<a->data<<" ";
		a = a->next;
	}
	std::cout<<a->data<<" ";
	std::cout<<"\n";*/
	//return;
	a = *front;
	node* next = a->next;
	bool allocateHead = false;
	if (*prev_f == a)
	{
		//std::cout<<"Head Detected...\n with data "<<(*prev_f)->data<<"\n";
		allocateHead = true;
	}
	else 
	{
		(*prev_f)->next = b;
	}
	a->next = b->next;
	while (a != b)
	{
		*prev_f = a;
		a = next;
		if (next->next != NULL)
			next = next->next;
		a->next = *prev_f;
	}
	if (allocateHead == true)
		*head = a;
}

void reverseK (node** head, int k)
{
	if (k == 1)
		return;
	node* back = *head;
	node* front = *head;
	node* prev_f = *head;
	node* temp;
	bool isheadAlloc = false;
	int counter = 1, count;
	
	while (true)
	{
		if(counter != k)
		{
			counter++;
		}
		else 
		{
			//std::cout<<"(i  ) Front "<<front->data<<" Back "<<back->data<<" Prev "<<prev_f->data<<"\n";
			if (back->next == NULL) // Because back is essential the last node in this case 
			{
				reverse(&front, &back, &prev_f, &(*head));
				return;
			}
			reverse(&front, &back, &prev_f, &(*head));
			//std::cout<<"(ii ) Front "<<front->data<<" Back "<<back->data<<" Prev "<<prev_f->data<<"\n";
			//output(*head);
			
			front = front->next;
			while (prev_f->next != front)
				prev_f= prev_f->next;
			count = 0;
			while (count != k)
			{
				back = back->next;
				count++;
			}
			counter = 2;
			//std::cout<<"(iii) Front "<<front->data<<" Back "<<back->data<<" Prev "<<prev_f->data<<"\n";
			//output(*head);
		}
		
		if (back->next == NULL)
		{
			if (front == back)
				return;
			else
			{
				//std::cout<<"( L ) Front "<<front->data<<" Back "<<back->data<<" Prev "<<prev_f->data<<"\n";
				reverse(&front, &back, &prev_f, &(*head));
				return;		
			}
		}
		back = back->next;
	}
	return;
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
	insertInNode(&head,6);
	output(head);
	
	reverseK (&head, 5);
	output(head);
}
