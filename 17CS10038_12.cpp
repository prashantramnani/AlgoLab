// Prashant Ramnani
// 17CS10038

#include<bits/stdc++.h>
using namespace std;

typedef struct _node{
	int vno;
	struct _node *next;
}node;

typedef struct vertex{
	node *adjlist;
	int degree;
	int d,low,f;
	int child[10000];
	int Nchild;
}vertex;	

void printList(vertex *graph,int n)
{
	int i;node *traverse;
	for(i=0;i<n;++i)
	{
		cout<<"Vertex "<<i<<":";
		traverse  = graph[i].adjlist;
		while(traverse != NULL)
		{
			cout<<" ";
			cout<<traverse->vno;
			cout<<" ";
			traverse = traverse->next;
		}
		cout<<endl;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////
void dfsVisit (vertex *graph,int index,int rem,int n,int visited[],int pie[])
{
	int j,i;
	node *traverse;
	visited[index] = 1;
	
	traverse = graph[index].adjlist;
	
	while(traverse != NULL)
		{	
			if(traverse->vno == rem)
			{
				//cout<<"phas gya"<<endl;
				traverse = traverse->next;
			}	
			else if(visited[traverse->vno] == 0)
			{
				//cout<<"vno"<<traverse->vno<<endl;
				pie[traverse->vno] = index;
				dfsVisit(graph,traverse->vno,rem,n,visited,pie);
				traverse = traverse->next;	
			}
			else
				traverse = traverse->next;
			
		}
}
int dfs(vertex *graph,int n,int rem)
{
	int i,j,visited[n],pie[n],index,components = 0;

	for(i=0;i<n;++i)
	{
		visited[i] = 0;
		pie[i] = 0;
	}

	for(i=0;i<n;++i)
	{
		if(i==rem)
			continue;
		if(visited[i] == 0)
		{
			components ++;
			//cout<<"i"<<i<<endl;
			//cout<<"rem"<<rem<<endl;
			dfsVisit(graph, i,rem, n, visited,pie);
		}	
	}
	return components;
}

void findCritical(vertex *graph,int n)
{
	int i,what,component;
	for(i=0;i<n;++i)
	{
		component = dfs(graph,n,i);
		
		if(component > 1)
			cout<<"Vertex "<<i<<":"<<component<<" "<<"components"<<endl;
			
	}
}

/////////////////////////////////////////////////////////////////////////////////

int min(int a, int b)
{
	if(a> b)
		return b;
	else
		return a;
}

void dfsFast_visit(vertex *graph,int n,int index,int visited[],int pie[],int *time)
{
	int i,j,u;
	node *traverse,*previous = NULL;
	
	visited[index] = 1;
	*time = *time + 1;
	graph[index].d = *time;
	graph[index].low = *time;
	traverse = graph[index].adjlist;
	cout<<"sdvkhwdbvk"<<endl;
	while(traverse != NULL)
		{	
			u =traverse->vno;
			if(u == pie[index])
				continue;
			if(visited[u] == 0)
			{
				cout<<"kya"<<endl;
				pie[u] = index; 
				dfsFast_visit(graph,n,u,visited,pie,time);
				graph[index].low = min(graph[index].low,graph[u].low);
			}
			else
			{
				cout<<"kya1"<<endl;
				graph[index].low = min(graph[index].low,graph[u].d);
			}
			cout<<"index"<<index<<endl;
			traverse = traverse->next;
			
		}	
		(*time) ++ ;
		graph[index].f = *time;
}


void dfsFast(vertex *graph,int n)
{
	int i,j,visited[n],time = 0,x,min,pie[n],minIndex;
	node *traverse;
	for(i=0;i<n;++i)
	{
		visited[i] = 0;
		pie[i] = -1;
		graph[i].d = 100000;
		graph[i].low = 100000;
	}
	
	for(i=0;i<n;++i)
	{
		if(visited[i] == 0)
			dfsFast_visit(graph,n,i,visited,pie,&time);
	}
	
	
	
	for(i=0;i<n;++i)
	{
		cout<<"Discovery"<<" "<<i<<" "<<graph[i].d<<endl;
		cout<<"Finish"<<" "<<i<<" "<<graph[i].f<<endl;
	}

}	


void findCriticalFast (vertex *graph,int n)
{
	dfsFast(graph,n);
}
/////////////////////////////////////////////////////////////////////////////////
int main()
{
	int n,e,i,j,x,y,degree;
	cin>>n>>e;
	node *traverse,*New;
	vertex *graph;
	
	graph = new vertex[n];
	
	for(i=0;i<n;++i)
	{
		graph[i].adjlist = NULL;
		graph[i].Nchild = 0; 
	}
	
	for(i=0;i<n;++i)
	{
		cin>>graph[i].degree;
		
		for(j=0;j<graph[i].degree;++j)
		{
			cin>>x;
			
			if(graph[i].adjlist == NULL)
			{
				New = new node;
				New->vno = x;
				New->next = NULL;
				graph[i].adjlist = New;
			}
			
			else
			{
				traverse  = graph[i].adjlist;
			
				while(traverse->next != NULL)
					traverse = traverse->next;
				New = new node;
				New->vno = x;
				New->next = NULL;
				traverse->next = New;	
			}
			
		}		
	}

	printList(graph,n);
	cout<<"Critical Juntions using the simple algorithm"<<endl;
	findCritical (graph,n);
	cout<<"Critical Juntions using the fast algorithm"<<endl;
	findCriticalFast (graph,n);
}
