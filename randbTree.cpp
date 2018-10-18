#include <bits/stdc++.h>

using namespace std;

struct node{
	int data;
	int color;											
	struct node *left;
	struct node *right;
	struct node *parent;
};



struct node * search(int x, struct node *Root,struct node *Null)
{
    struct node *find;

    find = Root;

    while(1)
    { 
        if(find->data == x)
        {
        	cout<<"1"<<endl;
        	cout<<"find"<<find->data<<endl;
            return find;
        }
        else if((find->data > x)&&(find->left != Null))
            find = find->left;
        else if((find->data < x)&&(find->right != Null))
            find = find->right;
        else if((find->right == Null)||(find->left == Null))
        {
        	cout<<"2"<<endl;
        	cout<<"find"<<find->data<<endl;
            return find;
        }
    }
}

void insert(int x,struct node *Root,struct node *Null)
{
	struct node *insert,*New,*z = Null;

	insert = search(x,Root,Null);
	cout<<"insert"<<insert->data<<endl;
	New = new struct node;

	New->color = 1;
	New->data = x;
	New->right = Null;
	New->left = Null;
	//cout<<"-4"<<endl;
	if(insert->data > x)
	{
		insert->left = New;
		New->parent = insert;
		cout<<"insert left"<<insert->left->data<<endl;
	}
	else
	{
		insert->right = New;
		New->parent = insert;
	}

	if(New->parent->color == 1)
		z = New;
	//cout<<"-3"<<endl;
	while(z != Null)
	{
		//cout<<"-2"<<endl;
		if((z->color == 1)&&(z->parent->color == 1))
		{
			if(z->parent == z->parent->parent->left)
			{
				if(z->parent->parent->right->color == 1)
				{
					z->parent->color = 0;
					z->parent->parent->right->color = 0;
					z = z->parent->parent;
				}

				else
				{
					if(z == z->parent->right)
					{
						z->parent->right = z->left;
						z->left->parent = z->parent;
						z->left = z->parent;
						z->parent->parent->left = z;
						z->parent = z->parent->parent;
						z->left->parent = z;
						z = z->left;

						z->parent->color = 0;
						z->parent->parent->color = 1;

						if(z->parent->parent->parent->left == z->parent->parent)
						{
							z->parent->parent->parent->left = z->parent;
							z->parent->parent->left = z->parent->right;
							z->parent->right->parent = z->parent->parent;
							z->parent->right = z->parent->parent;
							z->parent->parent = z->parent->parent->parent;
							z->parent->right->parent = z->parent;
						}
						else
						{
							z->parent->parent->parent->right = z->parent;
							z->parent->parent->left = z->parent->right;
							z->parent->right->parent = z->parent->parent;
							z->parent->right = z->parent->parent;
							z->parent->parent = z->parent->parent->parent;
							z->parent->right->parent = z->parent;
						}
					}

					else
					{

						z->parent->color = 0;
						z->parent->parent->color = 1;
						
						if(z->parent->parent->parent->left == z->parent->parent)
						{
							z->parent->parent->parent->left = z->parent;
							z->parent->parent->left = z->parent->right;
							z->parent->right->parent = z->parent->parent;
							z->parent->right = z->parent->parent;
							z->parent->parent = z->parent->parent->parent;
							z->parent->right->parent = z->parent;
						}
						else
						{
							z->parent->parent->parent->right = z->parent;
							z->parent->parent->left = z->parent->right;
							z->parent->right->parent = z->parent->parent;
							z->parent->right = z->parent->parent;
							z->parent->parent = z->parent->parent->parent;
							z->parent->right->parent = z->parent;
						}
					}	
				}	
			}

			else
			{
				if(z->parent->parent->left->color == 1)
				{
					z->parent->color = 0;
					z->parent->parent->left->color = 0;
					z = z->parent->parent;
				}

				else
				{
					if(z == z->parent->left)
					{
						z->parent->left = z->right;
						z->right->parent = z->parent;
						z->right = z->parent;
						z->parent->parent->right = z;
						z->parent = z->parent->parent;
						z->right->parent = z;
						z = z->right;

						z->parent->color = 0;
						z->parent->parent->color = 1;

						if(z->parent->parent->parent->left == z->parent->parent)
						{
							z->parent->parent->parent->left = z->parent;
							z->parent->parent->right = z->parent->left;
							z->parent->left->parent = z->parent->parent;
							z->parent->left = z->parent->parent;
							z->parent->parent = z->parent->parent->parent;
							z->parent->left->parent = z->parent;
						}
						else
						{
							z->parent->parent->parent->right = z->parent;
							z->parent->parent->right = z->parent->left;
							z->parent->left->parent = z->parent->parent;
							z->parent->left = z->parent->parent;
							z->parent->parent = z->parent->parent->parent;
							z->parent->left->parent = z->parent;
						}
					}

					else
					{
						
						z->parent->color = 0;
						z->parent->parent->color = 1;
						
						if(z->parent->parent->parent->left == z->parent->parent)
						{
							z->parent->parent->parent->left = z->parent;
							z->parent->parent->right = z->parent->left;
							z->parent->left->parent = z->parent->parent;
							z->parent->left = z->parent->parent;
							z->parent->parent = z->parent->parent->parent;
							z->parent->left->parent = z->parent;
						}
						else
						{
							z->parent->parent->parent->right = z->parent;
							z->parent->parent->right = z->parent->left;
							z->parent->left->parent = z->parent->parent;
							z->parent->left = z->parent->parent;
							z->parent->parent = z->parent->parent->parent;
							z->parent->left->parent = z->parent;
						}
					}	
				}
			}
		}

		else
			break;
	}

	Root->color = 0;		
		
}

void inorder(struct node *root,struct node *Null)
{
    if(root->left != Null)
    {
        inorder(root->left,Null);
    }
    cout<<root->data<<endl;
    if(root->right != Null)
    {
        inorder(root->right,Null);
    }      
}

int main()
{
	int x;

	
	struct node *Root,root,null,*Null;
	null.color = 0;
	Null = &null;
	
	Root = &root;
	cin>>x;
	root.data = x;
	root.color = 0;
	root.left = Null;
	root.right = Null;
	root.parent = Null;

	while(1)
	{	
		cin>>x;
		if(x == -1)
			break;
		insert(x,Root,Null);
	}
	
}	