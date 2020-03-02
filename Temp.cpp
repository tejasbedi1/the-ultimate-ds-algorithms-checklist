#include <iostream>

using namespace std;

void any(int* j)
{
	//cout<<j<<endl;
	*j = 2;
	cout<<*j<<endl;
}
int main()
{
	cout<<"Initializing..\n";
	int i = 1;
	//int *j = &i;
	any(&i);
	cout<<i;
}
/*
void iIN(node** head, int i)
{
	if (*head == NULL)
	{
		*head = new node;
		(*head)->data = 5;
		(*head)->next = NULL;
		std::cout<<(*head)->data<<"\n";
	}	
	else 
	{
		std::cout<<"Head I'nt empty\n";
	}
	std::cout<<(*head)->data<<"\n";
}
*/
