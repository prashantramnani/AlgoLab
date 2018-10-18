#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

struct node{
    unsigned long long int data;
    struct node *left;
    struct node *right;
};


struct node * search(ull int x, struct node *root)
{
    struct node *find;

    find = root;

    while(1)
    { 
        if(find->data == x)
            return find;
        else if((find->data > x)&&(find->left != NULL))
            find = find->left;
        else if((find->data < x)&&(find->right != NULL))
            find = find->right;
        else if((find->right == NULL)||(find->left == NULL))
            return find;
    }
}

void insert(ull int x, struct node *root)
{
    struct node *traverse,*New;

    traverse = root;

    traverse = search(x, root);

    if(x < traverse->data)
    {
        New = new struct node;
        New->data = x;
        traverse->left = New;
    }

    else if(x > traverse->data)
    {
        New = new struct node;
        New->data = x;
        traverse->right = New;
    }
}

void preorder(struct node *root)
{
    struct node *L,*R;

    cout<<root->data<<endl;
    if(root->left != NULL)
    {
        preorder(root->left);
    }
    if(root->right != NULL)
    {
        preorder(root->right);
    }
        
}

void inorder(struct node *root)
{
    if(root->left != NULL)
    {
        inorder(root->left);
    }
    cout<<root->data<<endl;
    if(root->right != NULL)
    {
        inorder(root->right);
    }      
}

void postorder(struct node *root)
{
    if(root->right != NULL)
    {
        postorder(root->right);
    }
    cout<<root->data<<endl;
    if(root->left != NULL)
    {
        postorder(root->left);
    }      
}

struct node *delSearch(uul int x, struct node *root)

void Delete(uul int x, struct node *root)
{
    strut node *element;
    element = delsearch(x, root);


}

int main()
{
    ull int x,n,i;
    struct node *root;
    
    root = new struct node;
    cin>>n;
    cin>>x;
    root->data = x;
    root->right = NULL;
    root->left = NULL;
    
    for(i=0;i<n-1;++i)
    {
        cin>>x;
        insert(x,root);
    }



    //preorder(root);
    //inorder(root);
    //postorder(root);
    cin>>x;
    Delete(x,root);
}