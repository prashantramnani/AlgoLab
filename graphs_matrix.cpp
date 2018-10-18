#include<bits/stdc++.h>
using namespace std;

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

void bfs(int A[][101],int startIndex,int N)
{
	quue Q,*q;
	Q = initialise();
	q = &Q;

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
		index = deQueue(q);
			for(j=1;j<=N;++j)
			{
				if(j == index)
					continue;
				if(A[index][j] == 1)
				{
					if(visited[j] == 0)
					{
						cout<<j<<" ";
						visited[j] = 1;
						d[j] = d[index] + 1;
						pie[j] = index;
						enQueue(q,j);
					}
				}	
			}
	}
cout<<endl;
}

void dfsVisit (int A[][101],int index,int N,int visited[],int pie[])
{
	int j,i;
	visited[index] = 1;
	cout<<index<<" ";
	for(j=1;j<=N;++j)
			{
				if(j == index)
					continue;
				if(A[index][j] == 1)
				{
					if(visited[j] == 0)
					{
						pie[j] = index;
						dfsVisit(A,j,N,visited,pie);	
					}
				}	
			}
}
void dfs(int A[][101],int N)
{
	int i,j,visited[N+1],d[N+1],pie[N+1],f[N+1],index;

	for(i=1;i<=N;++i)
	{
		visited[i] = 0;
		pie[i] = 0;
	}

	for(i=1;i<=N;++i)
	{
		if(visited[i] == 0)
			dfsVisit(A, i, N, visited,pie);
	}
	cout<<endl;
}

int main()
{
	int N,n,x,y,startIndex = 3;
	cin>>N>>n;

	int A[N+1][101],i,j; 

	for(i=1;i<=N;++i)
		for(j=1;j<=N;++j)
			A[i][j] = 0;
	
	for(i=0;i<n;++i)
	{
		cin>>x>>y;
		A[x][y] = 1;
		A[y][x] = 1;
	}

	
	for(i=1;i<=N;++i)
	{
		for(j=1;j<=N;++j)
		{
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;	

	bfs(A,startIndex,N);
	dfs(A,N);

}