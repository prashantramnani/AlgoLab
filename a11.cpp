#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	int xOR;
};

void traverse_from_front_to_end(struct node *Head)
{
	struct node *a,*b,*c;
	a = Head;
	b = Head;
	//cout<<"Yahan tak bhi"<<endl;
	while(1)
	{
		//cout<<"kyun"<<endl;
		cout<<a->data<<endl;
		if(a == Head)
		{
			a = a->xOR;
		}
		else
		{
			c = a;
			a = ((unsigned int)a->xOR)^((unsigned int)b);
			//cout<<a<<endl;
			b = c;
		}

		if((((unsigned int)a->xOR)^((unsigned int)b))== NULL)
		{
			//cout<<"Q"<<endl;
			cout<<a->data<<endl;
			break;
		}
	}
}

void traverse_from_end_to_front(struct node *Head)
{
		struct node *a,*b,*c;
	a = Head;
	b = NULL;
	//cout<<"Yahan tak bhi"<<endl;
	while(1)
	{
		c = a;
		a = ((unsigned int)a->xOR)^((unsigned int)b);
		//cout<<a<<endl;
		b = c;
		

		if((((unsigned int)a->xOR)^((unsigned int)b))== NULL)
		{
			b = NULL;
			break;
		}
	}

	//cout<<"kyun"<<endl;

	while(1)
	{
		cout<<a->data<<endl;
		if(a == Head)
		{
			break;
		}

		c = a;
		a = ((unsigned int)a->xOR)^((unsigned int)b);
		//cout<<a<<endl;
		b = c;
		

		
	}


}

void reverse(struct node **Head, struct node **Last)
{
	struct node *a;
	a = *Last;
	*Last = *Head;
	*Head = a;

}

void sort(struct node **Head, struct node **Tail)
{
	struct node *a,*b,*c,*a1,*a2,*b1,*b2,*mAX,*sWAP;
	a = *Head;
	b = *Head;
	b1 = NULL;
	int max,n = 0,swap;
	
	while(1)
	{
		
		if((((unsigned int)b->xOR)^((unsigned int)b1))== NULL)
		{
			break;
		}	
			
		a = (((unsigned int)b->xOR)^((unsigned int)b1));
		a1 = b;
		max = b->data;
		
		mAX = b;

		while(1)
		{	
			if(a->data > max)
			{
				max = a->data;	
				mAX = a;
			}

			a2 = a;
			a = ((unsigned int)a->xOR)^((unsigned int)a1);
			a1 = a2;

			if((((unsigned int)a->xOR)^((unsigned int)a1))== NULL)
			{
				n++;
				break;
			}
		}
		cout<<"n:"<<n<<endl;
		
		if(n==1)
		{
			
			*Head = mAX;
			
		}
	
		cout<<mAX->data<<endl;
		sWAP = b;

		b2 = b;
		b = ((unsigned int)a->xOR)^((unsigned int)b1);
		b1 = b2;

		sWAP = sWAP->xOR;
		sWAP->xOR = mAX->xOR;
		mAX->xOR = sWAP->xOR;

		//traverse_from_end_to_front(*Head);
		
		
		
	}

}

int main()
{
	int i,n;
	cin>>n;

	struct node *Head,*Last,*a;

	Head = (struct node *)malloc(sizeof(struct node));
	Head->data = rand()%100;

	Last = Head;


	for(i=0;i<n-1;++i)
	{
		a = (struct node *)malloc(sizeof(struct node));
		a->data = rand()%100;

		if(Last == Head)
		{
			Head->xOR = (NULL)^((unsigned int) a);
			a->xOR = Head;
			Last = a;
		}

		else
		{
			a->xOR = Last;
			Last->xOR = ((unsigned int) Last->xOR)^((unsigned int) a);
			Last = a;
		}
	}
	//cout<<"sahi"<<endl;
	//traverse_from_front_to_end(Head);

	//traverse_from_end_to_front(Head);

	reverse(&Head,&Last);

	sort(&Head, &Last);

}