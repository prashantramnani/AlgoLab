#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef struct rm {
	int hInd;   //x-cordinate for the room data in maze
	int vInd;	//y-cordinate for the room data in maze
} room;// structure for storing room datas

struct node{ //basic node in every linked list created
	room data;
	struct node *next;
};	

typedef struct {  //stores front and rear pointers for queue
	struct node *front, *rear ;
} QUEUE ;

void printmaze(int H[][20], int V[][20], int n)
{
	int i,j,k;
	
	for(i=0;i<n;++i)
	{	
		if(i==0)
		{
			for(k=0;k<n;++k)//printing the required structure using + and -
				cout<<"+---";
			cout<<"+"<<endl;	
		}
		
		cout<<"|   ";  //printing the walls
		
		for(j=1;j<n+1;++j)
		{
			if(V[i][j] == 1)
				cout<<"    ";  //verical walls and opening
			else
				cout<<"|   ";	
		}	
		
		cout<<endl;
		
		for(j=0;j<n;++j)
		{
			if(H[i+1][j] == 1)
				cout<<"+   ";	//horizontal walls and opening
			else
				cout<<"+---";	
		}
		cout<<"+"<<endl;
	}
}

void createmaze(struct node *maze[][20],int n,int H[][20], int V[][20])
{
	int i,j,k;
	struct node *p,*traverse,*chal;
	
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{//checking for open doors from the (i,j) room
			if(H[i][j] == 1)  //checking the door above
			{
				p =(struct node *)malloc(sizeof(struct node));  //creating the linklist on each room
				p->data.hInd = i-1;   //storing the data for linked list
				p->data.vInd = j;
				p->next = NULL;
				
				traverse = maze[i][j];
				
				while(traverse->next!=NULL)  // adding the node to the linked list
					traverse = traverse->next;
				traverse->next = p;	
			}
			
			if(H[i+1][j] == 1) //checking the door down
			{
				p =(struct node *)malloc(sizeof(struct node));
				p->data.hInd = i+1;
				p->data.vInd = j;
				p->next = NULL;
				
				traverse = maze[i][j];

				while(traverse->next!=NULL)
					traverse = traverse->next;

				traverse->next = p;
			}
			
	
				if(V[i][j] == 1)  //checking the left door 
			{
				p =(struct node *)malloc(sizeof(struct node));
				p->data.hInd = i;
				p->data.vInd = j-1;
				p->next = NULL;
				
				traverse = maze[i][j];

				while(traverse->next!=NULL)
					traverse = traverse->next;
				traverse->next = p;	
			}

			if(V[i][j+1] == 1)  //checking the right door 
			{
				p =(struct node *)malloc(sizeof(struct node));
				p->data.hInd = i;
				p->data.vInd = j+1;
				p->next = NULL;
				
				traverse = maze[i][j];
				
				while(traverse->next!=NULL)
					traverse = traverse->next;
				traverse->next = p;
			}
		}
	}
	
	//printing the linked list of each room	
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			chal = maze[i][j];
			
			while(1)
			{
				cout<<"("<<chal->data.hInd<<","<<chal->data.vInd<<")";
				
				if(chal->next == NULL)
				{	
					cout<<endl;
					break;
				}
				
				cout<<"::-->";
		
				chal = chal->next;
			}
		}
	}	
}

//queue functoins
void init(QUEUE *qP)
{
	qP->front = NULL;//initialising the front and rear pointers to NULL
	qP->rear = NULL;
}

int isempty(QUEUE qP) //chechking for empty queue but checking if front pointer id NULL or not
{
	if(qP.front == NULL)
		return 1;
	return 0;
}

void enqueue(QUEUE *qP, room Data) //entering the nodes in rear  queue
{
	struct node *temp;
	
	temp = (struct node *)malloc(sizeof(struct node));

	temp->data.hInd = Data.hInd;
	temp->data.vInd = Data.vInd;

	qP->rear->next = temp;
	qP->rear = qP->rear->next;
}

room dequeue(QUEUE *qP) //deleting the elements from front of queue
{
	room x;
	struct node *temp;
	x.hInd = qP->front->data.hInd;
	x.vInd = qP->front->data.vInd;

	temp = qP->front;

	qP->front = qP->front->next;

	return x;
	free(temp);
}

int strategy2(struct node *maze[][20], int n, room start, room end) //strategy 2  BFS
{
	QUEUE qP,*Qp;
	room x;
	struct node *temp,*traverse;

	int Maze[20][20];  //defining the array to keep check on rooms visited
	int i,j,check = 0;

	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			Maze[i][j] = 0;  //unvisited rooms = 0
		}
	}

	Qp = &qP;
	init(Qp);  //initialising the front and rear pointers

	temp = (struct node*)malloc(sizeof(struct node));
	// temp is the initial node for storing the start room data in the queue as the first node
	temp->next = NULL;
	temp->data.hInd = start.hInd;
	temp->data.vInd = start.vInd;

	qP.front = temp;
	qP.rear = temp;

	Maze[start.hInd][start.vInd] == 1; //marking the staring room as visited

	while(1)
	{
		temp = maze[qP.front->data.hInd][qP.front->data.vInd]; //strating with the room pointed by front pointer
		while(1)
		{	
			traverse = temp->next; //traversing the linked list in the rooms
			temp = temp->next;
						
			if(traverse == NULL)
			{
				break;
			}
			if(Maze[traverse->data.hInd][traverse->data.vInd]==0)
			{	
				enqueue(Qp,traverse->data); //entering the unvisited room in the queue
				Maze[traverse->data.hInd][traverse->data.vInd] = 1;
			}
				
		}

		x = dequeue(Qp);
		if((x.hInd == end.hInd)&&((x.vInd == end.vInd)))
		{
			return 1;//return if end room found in queue
		}

		if(isempty(qP)==1)
		{
			return 0;//returning if front points to NULL implying that queue is empty
		}		
	}
}

int main()
{
	int n,isPath,win;
	room start,end;	
	cin>>n;
	
	int H[21][20];
	int V[20][20];
	int i,j,s,t,u,v;
	
	// scanning H and V values
	for(i=0;i<n+1;++i)
	{
		for(j=0;j<n;++j)
		{
			cin>>H[i][j];
		}
	}
	
	for(i=0;i<n;++i)
	{
		for(j=0;j<n+1;++j)
		{
			cin>>V[i][j];
		}
	}
	 //getting the start and end room datas
	cin>>start.hInd>>start.vInd;
	cin>>end.hInd>>end.vInd;
	

	struct node *maze[20][20];  //an array of pointers of type struct node
	
	for(i=0;i<n;++i) //initialising the forst node on the maze array and storing the room data
	{
		for(j=0;j<n;++j)
		{
			maze[i][j] =(struct node *)malloc(sizeof(struct node));
			maze[i][j]->next = NULL;
			maze[i][j]->data.hInd = i;
			maze[i][j]->data.vInd = j;
		}
	}
	
	printmaze(H,V,n);  //printing the maze
	createmaze(maze,n,H,V); //creating the link list storing the room data which are open form each room

	win = strategy2(maze, n, start, end);

	if(win == 1)
	{
		cout<<"A path is found using strategy 1 from ("<<start.hInd<<","<<start.vInd<<")"<<" to ("<<end.hInd<<","<<end.vInd<<")"<<endl;
	}
	else
		cout<<"NO path is found from ("<<start.hInd<<","<<start.vInd<<")"<<" to ("<<end.hInd<<","<<end.vInd<<")"<<endl;
}
