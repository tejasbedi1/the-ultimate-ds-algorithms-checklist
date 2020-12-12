#include <bits/stdc++.h>
//#include <unordered_map>
#include <iostream>
#include "PrintTree.h"

using namespace std;

node* newNode(int data)
{
	node* node = new struct node;
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void showMap(unordered_map<int, int> umap);
void showSet (unordered_set <int> uset);

void traversingLevelOrderly (queue <node*> nq, unordered_map <int, int> &umap)
{
	if (nq.empty() == true)
		return;
		
	node* temp = nq.front();
	nq.pop();
	//cout<<temp->data<<" ";

	if (temp->left != NULL)
	{
		nq.push(temp->left);
		umap.insert( pair<int, int>(temp->left->data, temp->data));
	}
	if (temp->right != NULL)
	{
		nq.push(temp->right);
		umap.insert( pair<int, int>(temp->right->data, temp->data));
	}
	
	traversingLevelOrderly (nq, umap);
}

unordered_map <int, int> populateMap(node *head)
{
	unordered_map <int, int> umap;
	queue <node*> nq;
	
	nq.push(head);
	traversingLevelOrderly (nq, umap);
	
	return umap;
}

unordered_set <int> populateSet(unordered_map <int, int> umap, int a)
{
	unordered_set <int> uset;
	uset.insert(a);
	
	unordered_map <int, int> :: iterator itr;
	
	itr = umap.find (a);
	while (itr != umap.end())
	{
		uset.insert (itr->second);
		itr = umap.find (itr->second);
	}
	return uset;
}

void findLCAforBT(node* head, int a , int b)
{
	// CREATE Uordered MAP 
	unordered_map <int, int> umap;
	umap = populateMap(head);	
	//showMap (umap);
	
	// CREATE Unordered SET	
	unordered_set <int> uset;
	uset = populateSet(umap, a);
	//showSet (uset);
	
	// CHECK from set
	int toFind = b;
	
	unordered_set <int> :: iterator itr;
	unordered_map <int, int> :: iterator itr2;
	
	while (true)
	{
		itr = uset.find(toFind);
		//if (itr == uset.end()) cout<<toFind<<" not present in Set\n";
		if (itr != uset.end())
			break;	
			
		itr2 = umap.find(toFind);
		toFind = itr2->second;
	}
	
	cout<<toFind<<endl;
}

int main()
{
	node* head;
	head = NULL;
	
	/* Constructed binary tree is  
        			1
				  /   \ 
        		2      	3
        	  /   \	
    		4     	5
    	  /	  \   /   \
		6	   7 8		9	 
	  /	  \
	10		11
  	
	*/
	head 				= newNode(1);
	
	head->left 			= newNode(2);
	head->right 		= newNode(3);
	
	head->left->left 	= newNode(4);
	head->left->right 	= newNode(5);
	
	head->left->left->left 	= newNode(6);
	head->left->left->right = newNode(7);
	head->left->right->left = newNode(8);
	head->left->right->right= newNode(9);
	
	head->left->left->left->left 	= newNode(10);
	head->left->left->left->right 	= newNode(11);
	
	printTreePrimer (5,head);
	
	int a = 10, b = 5;
	cout<<"Least Common Ancestor for "<<a<<" & "<<b<<" is.."<<endl;
	findLCAforBT(head, a ,b);
}

void showMap(unordered_map<int, int> umap)
{
	unordered_map <int, int> :: iterator itr;
	for (itr = umap.begin(); itr != umap.end(); ++itr )
	{
		cout<<itr->first<<" "<<itr->second<<endl;
	}
}

void showSet (unordered_set <int> uset)
{
	/*unordered_set <int> :: iterator itr;
	for (itr = uset.begin(); itr != uset.end(); itr++)
	{
		cout<<*itr<<endl;
	}
	*/
	for  (auto itr : uset)
	{
		cout<<itr<<endl;	
	}
}
