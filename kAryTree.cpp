#include<bits/stdc++.h>

using namespace std;

struct btree{
	int *data;
	int n;
	int isLeaf;
	struct btree **childPtr;
};

struct btree* btreeSplitChild(struct btree *New,int index,int t)
{
	int i;
	struct btree* baccha,*temp;
	
	cout<<"normal"<<endl;
	
	cout<<"normal"<<endl;
	temp = new struct btree;
	cout<<"normal"<<endl;
	temp->data = new int[2*t-1];
	cout<<"normal"<<endl;
	temp->childPtr = new struct btree*[t];
	baccha = New->childPtr[index];

	for(i=0;i<2*t;++i)
		temp->childPtr[i] = NULL;
		temp->n = t-1 ;
	temp->isLeaf = baccha->isLeaf;

	for(i=0;i<t-1;++i)
		temp->data[i] = baccha->data[i + t];
	if(baccha->isLeaf == 0)
		for(i=0;i<t-1;++i)
			temp->childPtr[i] = baccha->childPtr[i + t];
	baccha->n = t-1;
	
	for(i=New->n;i>=index+ 1;--i)
		New->childPtr[i+1] = New->childPtr[i];
	New->childPtr[index+1] = temp;
	for(i=New->n;i>=index;--i)
		New->data[i+1] = New->data[i];
	New->data[index] = baccha->data[t-1];

	New->n ++;

	return New;
}

struct btree* btreeInsertNonFull(struct btree *x,int key,int t)
{
	int k = x->n -1;
	cout<<"ki"<<k<<endl; 
	if (x->isLeaf == 1)
			{
				cout<<"Is leaf"<<endl;
 				while((k>=0)&&(key < x->data[k]))
 				{
					x->data[k+1] =  x->data[k];
			    	k = k-1;
			    }	
			    k++;
			    cout<<"k"<<k<<endl;
			    x->data[k] = key;
				x->n++;
			}
	else
	{
		cout<<"is not leaf"<<endl;
		while((k>=0)&&(key < x->data[k]))
 			k = k-1;
 		k++;
 		cout<<"k non leaf"<<k<<endl;
 		cout<<"n"<<x->childPtr[k]->n<<endl;
 		if(x->childPtr[k]->n == (2*t - 1))
 			{
 				
 				x = btreeSplitChild(x,k,t);
 				cout<<"split"<<endl;
 				if(key > x->data[k])
 					k++;
			}
		x->childPtr[k] = btreeInsertNonFull(x->childPtr[k],key,t);	
	}
	return x;		
}

struct btree* btreeInsert(struct btree *root,int t, int key)
{
	int i;
	struct btree *x;
	if(root ==  NULL)
	{
		cout<<"NULL"<<endl;
		root = new struct btree;
		root->data = new int[2*t - 1];
		root->childPtr = new struct btree*[2*t];
		for(i=0;i<2*t;++i)
			root->childPtr[i] = NULL;
		root->n = 0;
		root->isLeaf = 1;
		x = root;
		x->data[x->n] = key;
		x->n ++ ;
	}
	else
	{	
		cout<<"Not NULL"<<endl;
		x = root;
		if(x->n == 2*t-1)
		{
			struct btree *New;
			New = new struct btree;
			New->data = new int[2*t - 1];
			New->childPtr = new struct btree*[2*t];
			for(i=0;i<2*t;++i)
				New->childPtr[i] = NULL;
			New->n = 0;
			New->isLeaf = 0;
			New->childPtr[0] = x;
			root = btreeSplitChild(New,0,t);
			root = btreeInsertNonFull(New,key,t);
		}
		else 
		{
			cout<<"Non Full"<<endl;
			root  = btreeInsertNonFull(x,key,t);
		}
			
	}
	
	return root;	
}
int main()
{
	int n,t;
	int i,x;
	cin>>t>>n;

	struct btree *root;
	root = NULL;

	for(i=0;i<n;++i)
	{
		cin>>x;
		root = btreeInsert(root,t,x);
	}
	cout<<root->data[0]<<endl;
	cout<<root->data[1]<<endl;
	cout<<root->childPtr[0]->data[0]<<endl;
	cout<<root->childPtr[0]->data[1]<<endl;
	cout<<root->childPtr[0]->data[2]<<endl;
	cout<<root->childPtr[1]->data[0]<<endl;
	cout<<root->childPtr[2]->data[0]<<endl;
	cout<<root->childPtr[2]->data[1]<<endl;

}