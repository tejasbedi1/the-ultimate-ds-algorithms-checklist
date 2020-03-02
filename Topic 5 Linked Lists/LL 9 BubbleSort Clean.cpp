#include <iostream>
#include <stdlib.h> 

struct node
{
	int data;
	struct node* next;
};

void insertInNode(struct node** head, int i);

void bubbleSort(node** head);

void swap(node**, node**, node**);

void output(node *head);

int main()
{
	struct node* head;
	head = NULL;
	
	insertInNode(&head,5);
	insertInNode(&head,4);
	insertInNode(&head,3);
	insertInNode(&head,2);
	insertInNode(&head,1);
	
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
	node* i;
	node* j;
	// Essentially a bubble sort alogrithm but for nodes and using a function for swapping
	i = *head;	
	int count = 0;	 // Keeps track of how many times i has run
	while (i != NULL)
	{
		j = *head;
		while(j->next != NULL) // j moves from first to last node, how many times it does that is dependent on i
		{
			if (j->data > (j->next)->data)
			{
				swap(&(*head),&j,&(j->next));
			}
			else 
			{
				j = j->next;
			}
		}
		// This loop essentially makes sure that node i is being iterated over like
		// in a for loop 
		count++;
		i = *head;
		for (int k=0;k<count;k++)	
		{
			i = i->next;
		}
		i = i->next;
	}
}

void swap(node** head, node** i_, node** j_)
{
	// This is a very meticulious sapping function
	// However very wasteful, because in certan cases the entire list has to be gone through multiple times
	// Doubly linked lists wont have the same problem though
	node* i = *i_;
	node* j = *j_;

	node* next_i = i->next;
	node* next_j = j->next;
	
	node* prev_i = NULL; 
	node* prev_j = NULL; 
	
	node* control = *head;
	int set_i = 0, set_j = 0;
	// STEP 1, Find Previous's
	// Whenever swap is called this loop here finds the previous nodes to i and j
	// This loop is wasteful again, because whenever swap is called the whole damn loop goes through the list
	// Doubly linked lists should'nt have this problem
	while (control  != NULL)
	{
		if (control == i)	
			set_i = 1;
		if (set_i == 0)		
			prev_i = control;
		
		if (control == j)	
			set_j = 1;
		if (set_j == 0)		
			prev_j = control;	
		
		control= control->next;
	}
	// STEP 2, Find if any of them are heads 
	// The following statements check and notedown if any of the nodes are at
	// the head position, cause then they may have to be dealt with later
	int flagAsHead = 0;
	if (*head == i)
	{
		//std::cout<<"Head is same as i\n";
		flagAsHead = 1;
	}
	if (*head == j)
	{
		//std::cout<<"Head is same as j\n";
		flagAsHead = 2;
	}
	
	// STEP 3, Find out if they are spaced out or back back
	// In case they are back to back, then good for us, more code less complicated though
	// So, if j's previous is equal to i then
	// j's next will will now come after i 
	// j will come before i 
	// if i's previous is not null then it wil point to j
	// and in case if i was a head then now j will be a head
	if (i == prev_j || j ==prev_i)
	{
		//std::cout<<"Back-to-back nodes these are\n";
		if (i == prev_j)
		{
			i->next = next_j;
			j->next = i;
			if(prev_i != NULL) 
				prev_i->next = j;
			
			if (flagAsHead == 1) *head = j;
		}
		else if(j == prev_i)
		{
			j->next = next_i;
			i->next = j;
			if(prev_j != NULL) 
				prev_j->next = i;
			
			if (flagAsHead == 2) *head = i;	
		}
	}
	else 
	{
		// In case nodes are spaced apart less code and a lille bit less complicated
		// i will point to j's next
		// j will point to i's next 
		// if the previous's of these exist then they will point to the opposite of what they were pointing already
		// also if any of them were heads, well that switches too
		//std::cout<<"Spaced Apart nodes these are\n";
		i->next = next_j;
		j->next = next_i;
		if (prev_i != NULL)	
			prev_i->next = j;
		if (prev_j != NULL)	
			prev_j->next = i;
	
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
