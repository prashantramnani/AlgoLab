#include <iostream>
#include <string>
#include <sstream>
#include <bits/stdc++.h>

using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node* newnode(int Data)
{
	struct node *Node;
	Node = new struct node;
	Node->data = Data;
	Node->left = NULL;
	Node->right = NULL;

	return Node;
}

struct node * search(int x, struct node ** root)
{
	struct node * traverse;
	traverse = *root;
	if(traverse == NULL)
		return NULL;
	while(traverse != NULL)
	{
		if((traverse->data == x)||(traverse == NULL))
			return traverse;
		else if((traverse->data < x)&&(traverse->right != NULL))
			traverse = traverse->right;
		else  if((traverse->data > x)&&(traverse->left != NULL))
			traverse = traverse->left;
		else  if((traverse->data > x)&&(traverse->left == NULL))
			return traverse;
		else  if((traverse->data < x)&&(traverse->right == NULL))
			return traverse;
	}
}

void insert(int x,struct node **root)
{
	struct node *insert,*New;
	if(*root == NULL)
	{

		*root = newnode(x);
	}
	else
	{
		insert = search(x,root);

		if(insert->data < x)
		{	
			cout<<"insert"<<insert->data<<endl;
			New = new struct node;
			New->data = x;
			insert->right = New;
		}
		else if(insert->data > x)
		{
			New = (struct node*)malloc(sizeof(struct node));
			New->data = x;
			insert->left = New;
		}
	}
}

int main()
{
	int x;

	struct node *root,**Root;
	
	root = NULL;
	Root = &root;
	while(1)
	{	
		cin>>x;
		if(x == -1)
			break;
		insert(x,Root);
	}

	
}