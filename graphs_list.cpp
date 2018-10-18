#include<bits/stdc++.h>
using namespace std;

typedef struct L{
	int key;
	struct L* next;
}List;

typedef struct{
	int key;
}element;

typedef struct 
{
	element list[100];
	int front,rear;
}quue;

quue initialise()
{
	quue Q;
	Q.rear = 0;
	Q.front = 0;
	return Q;
}

int isEmpty(quue *q)
{
	if(q->front == q->rear)
		return 1;
	return 0;
}

void enQueue(quue *q, int key)
{
	q->list[q->rear].key = key;
	q->rear ++;
}

int  deQueue(quue *q)
{
	return(q->list[q->front++].key);
}

void bfs(List **l,int startIndex,int N)
{
	quue Q,*q;
	Q = initialise();
	q = &Q;
	List *traverse;
	int i,j,visited[N+1],d[N+1],pie[N+1],index;

	for(i=1;i<=N;++i)
	{
		d[i] = 10000;
		visited[i] = 0;
		pie[i] = 0;
	}

	d[startIndex] = 0;
	visited[startIndex] = 1;
	cout<<startIndex<<" ";
	enQueue(q,startIndex);

	while(isEmpty(q) != 1)
	{
		//cout<<"kya"<<endl;
		index = deQueue(q);
		//cout<<"index"<<index<<endl;
		traverse = l[index];
			while(traverse != NULL)
			{
				//cout<<"traverse"<<traverse->key<<endl;
				if(visited[traverse->key] == 0)
				{
					cout<<traverse->key<<" ";
					visited[traverse->key] = 1;
					d[traverse->key] = d[index] + 1;
					pie[traverse->key] = index;
					enQueue(q,traverse->key);
					
				}
				traverse = traverse->next;
			}
	}
	cout<<endl;
}

void dfsVisit (List **l,int index,int N,int visited[],int pie[],int d[],int f[],int *time)
{
	int j,i,check;
	List * traverse;
	(*time)++ ;
	d[index] = *time;
	
	//cout<<"time1"<<*time<<endl;
	visited[index] = 1;
	
	//cout<<"d"<<d[index]<<endl;
	cout<<index<<" ";
	traverse = l[index];
	while(traverse != NULL)
		{	
			check = 0;
			if(visited[traverse->key] == 0)
			{
				pie[traverse->key] = index;
				dfsVisit(l,traverse->key,N,visited,pie,d,f,time);
				//check = 1;
				//*time ++;
				//f[traverse->key] = *time;
			}
			
			traverse = traverse->next;
			
		}
		(*time)++;
		f[index] = *time;

}
void dfs(List **l,int N)
{
	int i,j,visited[N+1],d[N+1],pie[N+1],f[N+1],index,time = 0;;

	for(i=1;i<=N;++i)
	{
		visited[i] = 0;
		pie[i] = 0;
		d[i] = 0;
		f[i] = 0;
	}

	for(i=1;i<=N;++i)
	{
		if(visited[i] == 0)
			dfsVisit(l, i, N, visited,pie,d,f,&time);
	}
	cout<<endl;
	for(i=1;i<=N;++i)
	{
		cout<<d[i]<<" "<<f[i]<<endl;
	}
}


int main()
{
	int N,i,n,x,y,startIndex = 1,time = 0;
	cin>>N>>n;
	List** l ,*traverse,*New;

	l = (List **)malloc((N+1)*(sizeof(List*)));

	for(i=1;i<=N;++i)
	{
		l[x] = NULL;
	}

	for(i=0;i<n;++i)
	{
		cin>>x>>y;
		traverse = l[x];

		if(l[x] == NULL)
		{
			l[x] = new List;
			l[x]->next = NULL;
			l[x]->key = y;
		}
		else
		{
			while(traverse->next != NULL)
				traverse = traverse->next;

			New = new List;
			New->next = NULL;
			New->key = y;

			traverse->next = New;
		}

		traverse = l[y];
		if(l[y] == NULL)
		{
			l[y] = new List;
			l[y]->next = NULL;
			l[y]->key = x;
		}
		else
		{
			while(traverse->next != NULL)
				traverse = traverse->next;

			New = new List;
			New->next = NULL;
			New->key = x;

			traverse->next = New;
		}
			

	}

	for(i=1;i<=N;++i)
	{
		traverse = l[i];

		cout<<i<<"->";
		while(traverse != NULL)
		{
			cout<<traverse->key<<"-";
			traverse = traverse->next;

		}
		cout<<endl;
	}

	bfs(l,startIndex,N);
	cout<<"dfs"<<endl;
    dfs(l,N);

}