#include <iostream>
#include <stdlib.h> 

struct node
{
	int data;
	struct node* next;
};

void insertInNode(struct node** head, int i);

void bubbleSort(node** head);

//void swap(node**, node**, node**, node**, node**);
void swap(node**, node**, node**);

void output(node *head);

int main()
{
	struct node* head;
	head = NULL;
	/*
	insertInNode(&head,5);
	insertInNode(&head,4);
	insertInNode(&head,3);
	insertInNode(&head,2);
	insertInNode(&head,1);
	*/
	insertInNode(&head,5);
	insertInNode(&head,1);
	insertInNode(&head,4);
	insertInNode(&head,2);
	insertInNode(&head,3);
	output(head);	
	bubbleSort(&head);
	output(head);	
}

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

void bubbleSort(node** head)
{
	node* i = *head;
	node* j;
	//node* prev_i = NULL;
	//node* prev_j = NULL;
	
	//int in=0;
	//while (in < 5)
	//{
	i = *head;	
	int count = 0;
	while (i != NULL)
	{
		j = *head;
		while(j->next != NULL)
		{
			std::cout<<"Swapping.. "<<j->data<<" "<<(j->next)->data<<std::endl;
			if (j->data > (j->next)->data)
			{
				std::cout<<"Swapping.. "<<j->data<<" "<<(j->next)->data<<std::endl;
				swap(&(*head),&j,&(j->next));
				output (*head);
			}
			else 
			{
				std::cout<<"Not possible\n";
				j = j->next;
			}
			//std::cout<<"Swapping.. "<<i->data<<" "<<j->data<<std::endl;
			/*if (i->data > j->data)
			{
				std::cout<<"Swapping.. "<<i->data<<" "<<j->data<<std::endl;
				//if (i->data == 3 && j->data == 2)
					swap(&(*head),&i,&j);
					//swap(&(*head),&i,&j,&prev_i,&prev_j);
					output (*head);
			}
			//prev_j = j;
			else 
			{
				std::cout<<"Not possible\n";
			}*/
			//j = j->next;
		}
		//prev_i = i;
		//i = *head;
		
		std::cout<<"LOOP END I = "<<i->data<<" -------------------\n";
		count++;
		i = *head;
		for (int k=0;k<count;k++)
		{
			i = i->next;
		}
		std::cout<<"LOOP RESTART I = "<<i->data<<" -------------------\n";
		i = i->next;
	}
	//in++;
	//std::cout<<"\n\n\n\n";
	//}
}

//void swap(node** head, node** i_, node** j_, node** p_i, node** p_j)
void swap(node** head, node** i_, node** j_)
{
	node* i = *i_;
	node* j = *j_;
	//node* prev_i = *p_i;
	//node* prev_j = *p_j;
	node* next_i = i->next;
	node* next_j = j->next;
	
	node* prev_i = NULL; int set_i = 0;
	node* prev_j = NULL; int set_j = 0;
	node* control = *head;
	while (control  != NULL)
	{
		if (control == i)	set_i = 1;
		if (set_i == 0)		prev_i = control;
		
		if (control == j)	set_j = 1;
		if (set_j == 0)		prev_j = control;	
		
		control= control->next;
	}
	
	//std::cout<<"Swapping.. "<<i->data<<" "<<j->data<<std::endl;
	//std::cout<<(*head)->data<<"\n";
	std::cout<<"Swapping umm.. these .. "<<i->data<<" "<<j->data<<"\n";
	if(prev_i != NULL) std::cout<<"Prev I:"<<prev_i->data<<"\n";
	if(prev_j != NULL) std::cout<<"Prev J:"<<prev_j->data<<"\n";
	int flagAsHead = 0;
	if (*head == i)
	{
		std::cout<<"Head is same as i\n";
		flagAsHead = 1;
	}
	if (*head == j)
	{
		std::cout<<"Head is same as j\n";
		flagAsHead = 2;
	}
	
	if (i == prev_j || j ==prev_i)
	{
		std::cout<<"Back-to-back nodes these are\n";
		if (i == prev_j)
		{
			i->next = next_j;
			j->next = i;
			if(prev_i != NULL) prev_i->next = j;
			
			if (flagAsHead == 1) *head = j;
		}
		else if(j == prev_i)
		{
			j->next = next_i;
			i->next = j;
			if(prev_j != NULL) prev_j->next = i;
			
			if (flagAsHead == 2) *head = i;	
		}
	}
	else 
	{
		std::cout<<"Spaced Apart nodes these are\n";
		i->next = next_j;
		j->next = next_i;
		if (prev_i != NULL)	prev_i->next = j;
		if (prev_j != NULL)	prev_j->next = i;
	
		if (flagAsHead == 1) *head = j;
		if (flagAsHead == 2) *head = i;	
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
		std::cout<<std::endl;
	}
}
