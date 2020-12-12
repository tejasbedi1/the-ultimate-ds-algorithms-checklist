#include <iostream>
#include <queue>
#include <math.h>
#include <windows.h>

#define SetPos SetConsoleCursorPosition
#define GSH GetStdHandle
#define SOH STD_OUTPUT_HANDLE
// SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

using namespace std;

COORD easy(int x, int line)
{
	COORD coord;
	coord.X = x;
	coord.Y = line;
	return coord;
}

struct node 
{
	int data;
	struct node* left;
	struct node* right;
};

void printTreePrimer (int h, node* head);

void clearLine (int h)
{
	SetPos(GSH(SOH), easy(0,h+2));
	cout<<"                                        \n";
	SetPos(GSH(SOH), easy(0,h+2));
}

void insertLOTrecur (node** temp, node** headPoint, int maxNodes, int processedNodes, queue <node*> nq, int heightTree)
{
	if (nq.empty() == true)
		return;
	
	clearLine(heightTree);
	cout<<"Node Data? ";
	
	node* curr = nq.front();
	cin>>curr->data;
	curr->left = NULL;
	curr->right = NULL;
	nq.pop();
	
	printTreePrimer(heightTree, *headPoint);
	
	if (processedNodes < maxNodes)
	{
		curr->left = new node;
		curr->left->data = 0; // Next 3 lines make sure that printTreePrimer works appropriately and
		curr->left->left = NULL; // not take garbage values
		curr->left->right = NULL;
		nq.push(curr->left);
		
		curr->right = new node;
		curr->right->data = 0; // Next 3 lines make sure that printTreePrimer works appropriately and
		curr->right->left = NULL; // not take garbage values
		curr->right->right = NULL;
		nq.push(curr->right);
		
		processedNodes += 2;
	} 
	insertLOTrecur(&(*temp), &(*headPoint), maxNodes, processedNodes, nq, heightTree);
}

void insertLOT(node** head, int maxNodes, int heightTree)
{
	node* temp = new node;
	queue <node*> nq;
	nq.push(temp);
	
	int processedNodes = 1;
	
	insertLOTrecur (&temp, &temp, maxNodes, processedNodes, nq, heightTree);
	
	*head = temp;
	return;
} 

void printTreeRecur(int h, int clvl, int positionsAvailable, int space, int* arr, node* head)
{
	if (clvl > h)
		return;
		
	int nodes; // No of nodes
	int initialSpace; // space to be left before each line
		
	nodes = pow(2,clvl-1); // nodes in current lvl 
	initialSpace = (positionsAvailable / (nodes*2))-2;
	
	int preDistance; 	// If this is not the first node then a set amount of disance is to be left so that it does not clash with
						// the previous node in the same level
	
	preDistance = arr[clvl-1] * space;
		
	arr[clvl-1] = arr[clvl-1] + 1; // Corresponds to the nth node
	
	SetPos(GSH(SOH), easy(initialSpace+preDistance ,clvl));
	if (head == NULL)
	{
		cout<<"?";
	}
	else
	{
		if (head->data == 0) // MAKES sure garbage values are not printed // Works in conjuntion with the insert function
			cout<<"?";
		else
			cout<<head->data;
	}
	//SetPos(GSH(SOH), easy(0,h+2));
	//system("pause");
	if (head != NULL && head->left != NULL)
		printTreeRecur(h, clvl+1, positionsAvailable, space/2, arr, head->left);
	else
		printTreeRecur(h, clvl+1, positionsAvailable, space/2, arr, NULL);
	if (head != NULL && head->right != NULL)
		printTreeRecur(h, clvl+1, positionsAvailable, space/2, arr, head->right);
	else
		printTreeRecur(h, clvl+1, positionsAvailable, space/2, arr, NULL);
}

void printTreePrimer (int h, node* head)
{
	int* arr = new int[h]; // The array which maintains on which node we currently are at
	for (int i=0;i<h;i++)
	{
		arr[i] = 0;
	}	
	int clvl = 1; // Start with lvl 1
	int nodes, space = 4; // number of nodes & space between the nodes
	
	int positionsAvailable; // How many blocks i.e 1 cursor space is available
	
	nodes = pow(2,h-1); // MAX nodes ie avaialble on last lvl
	positionsAvailable = nodes*space;  
	space = space*(pow(2,h-1)); // Max Space between consecutive nodes
	
	printTreeRecur(h, clvl, positionsAvailable, space, arr, head);
	
	SetPos(GSH(SOH), easy(0,h+2)); // LAST POSITION
}

int main()
{
	int h;
	cout<<"Enter Tree height.. ";
	cin>>h;
	system("CLS");
	
	printTreePrimer(h, NULL);
	
	node* head;
	head = NULL;
	
	int maxNodes = pow(2,h) - 1; 
	insertLOT(&head, maxNodes, h);
	
	clearLine(h);
	cout<<"Done: :)";
}
