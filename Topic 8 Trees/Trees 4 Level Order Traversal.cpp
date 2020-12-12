#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

void insertLOTrecur (node** temp, node** headPoint, int maxNodes, int processedNodes, queue <node*> nq)
{
	if (nq.empty() == true)
		return;
		
	node* curr = nq.front();
	cin>>curr->data;
	curr->left = NULL;
	curr->right = NULL;
	nq.pop();
	
	if (processedNodes < maxNodes)
	{
		curr->left = new node;
		nq.push(curr->left);
		
		curr->right = new node;
		nq.push(curr->right);
		
		processedNodes += 2;
	} 
	insertLOTrecur(&(*temp), &(*headPoint), maxNodes, processedNodes, nq);
}

void insertLOT(node** head, int maxNodes)
{
	node* temp = new node;
	queue <node*> nq;
	nq.push(temp);
	
	int processedNodes = 1;
	
	insertLOTrecur (&temp, &temp, maxNodes, processedNodes, nq);
	
	*head = temp;
	return;
}

void LOTrecur(queue<node*> nq)
{
	node* curr = nq.front();
	nq.pop();
		
	cout<<curr->data<<" ";
	
	if (curr->left != NULL)		
		nq.push(curr->left);
	if (curr->right != NULL)	
		nq.push(curr->right);
	
	if (nq.empty() == true)
		return;
	else 
		LOTrecur (nq);
}

void levelOrderTraversal(node* head)
{
	queue <node*> nq;
	nq.push(head);
	LOTrecur(nq);
}

int main()
{
	std::cout<<"Initializing..\n";
	
	node* head;
	head = NULL;
	
	int height = 3;
	int maxNodes = pow (2,height) - 1; // Total Nodes With given height
	
	insertLOT(&head, maxNodes);
	
	levelOrderTraversal(head);
}
