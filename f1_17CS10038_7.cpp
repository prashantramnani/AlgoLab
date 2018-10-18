// Prashant Ramnani
// 17CS10038

#include<bits/stdc++.h>
#define MAX_SIZE 100

using namespace std;

 
typedef struct _job { 
	int jobId; 
	int startTime; 
	int jobLength;
	int remLength; 
} job;

typedef struct _heap { 
	job list[MAX_SIZE]; 
	int numJobs; 
} heap;


typedef struct _jobPair { 
	int jobid_from; 
	int jobid_to; 
} jobpair; 
///////////////////////////////PART-1//////////////////////////////////////////
void printHeap(heap *H)
{
	int i;
	for(i=1;i<=H->numJobs;++i)
	{
		cout<<H->list[i].jobId<<" "<<H->list[i].startTime<<" "<<H->list[i].jobLength<<" "<<H->list[i].remLength<<endl;	
	}
}

void minHeapify(heap * H, int i)
{
	if(i == 0)
		return ;
	int n = H->numJobs;
	
	int l = 2*i;
	int r = 2*i +1;
	int smallest = i;
	
	if((l<=n)and(H->list[l].remLength < H->list[i].remLength))
		smallest = l;
	else if((l<=n)and(H->list[l].remLength == H->list[i].remLength))
	{
		if(H->list[i].jobId > H->list[l].jobId)
			smallest = l;
	}
		
	if((r<=n)and(H->list[r].remLength < H->list[smallest].remLength))
		smallest = r;
	else if((r<=n)and(H->list[r].remLength == H->list[smallest].remLength))
	{
		if(H->list[r].jobId < H->list[smallest].jobId)
			smallest = r;
	}
	if(smallest != i)
	{
		job swap = H->list[i];
		H->list[i] = H->list[smallest];
		H->list[smallest] = swap;
		minHeapify(H,smallest);
	}
}

void insertUp(heap *H)
{
	int i = H->numJobs;
	
	while((i/2>0)&&(H->list[i].remLength <= H->list[i/2].remLength))
	{
		minHeapify(H,i/2);
		i = i/2;
	}
}

void initHeap(heap *H)
{
	H->numJobs = 0;
}

void insertJob(heap *H, job j)
{
	H->numJobs++;
	H->list[H->numJobs] = j;
	
	insertUp(H);
}

int  extractMinJob(heap  *H,  job  *J)
{
	
	if(H->numJobs == 0)
		return -1;
	
	if(H->numJobs == 1)
	{
		H->numJobs = 0;
		H->list[1].remLength--;
		*J = H->list[1];
		return 0;
	}		

	int n = H->numJobs;
	job min = H->list[1];
	H->list[1] = H->list[n];
	H->list[n] = min;
	min.remLength--;
	*J = min;
	H->numJobs--;
	
	minHeapify(H,1);
		
	return 0;	
}

//////////////////////////////////////////////PART-2///////////////////////////////

void Merge(job A[],int p, int q,int r)    
{
	int n1=q-p+1,i,j,k;       
	int n2=r-q;               
	job L[n1],R[n2];

	for(i=0;i<n1;i++)
		L[i] = A[p+i];
	
	for(j=0;j<n2;j++)
		R[j] = A[q+j+1];
	
	i=0,j=0;

	for(k=p;i<n1&&j<n2;k++)
	{
		if(L[i].startTime<R[j].startTime)
		{
			A[k]=L[i++];
		}
		else
		{
			A[k]=R[j++];
		}
	}

	while(i<n1)             
		A[k++]=L[i++];
	
	
	while(j<n2)            
		A[k++]=R[j++];
}

void MergeSort(job A[],int p,int r)   
{
	int q;                                

	if(p<r)
	{
		q=(p+r)/2;                     
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}
}

float turnAroundTime()
{

}

void scheduler(job jobList[], int n)
{
	MergeSort(jobList,0,n-1);
	int i,turnAroundTime[n],T=0,sum=0;
	
	for(i=0;i<n;++i)
		cout<<jobList[i].jobId<<" "<<jobList[i].startTime<<" "<<jobList[i].jobLength<<endl;

	heap h;
	heap *H;
	H = &h;
	initHeap(H);
	
	int timestep=0,nextJob=0;
	job *J;
	job j;
	J = &j;
	cout<<"Jobs scheduled at each timestep are:"<<endl;
	int t = 0; 
	while(1)
	{
		while(nextJob < n)
		{
			//cout<<"-1"<<endl;
			if(timestep == jobList[nextJob].startTime)
				insertJob(H,jobList[nextJob]);
			else
				break;

			nextJob++;
		}
		extractMinJob(H,J);
		
		if(J->remLength + 1 == J->jobLength)
			turnAroundTime[T++] = timestep - J->startTime;
		
		cout<<j.jobId<<" ";
		if(J->remLength != 0)
		 	insertJob(H,j);
		
		 if(H->numJobs == 0)
		 	break;
		timestep ++;
		t++;

	}
	cout<<endl;
	for(i=0;i<n;++i)
		sum +=	turnAroundTime[i];

	cout<<(float)sum/n<<endl;
} 
///////////////////////////////////////////PART-3/////////////////////////////
int main()
{
	job *j,*JobArray;
	heap h,*H;
	H = &h;
	initHeap(H);
	int i,n;
	cin>>n;
	
	JobArray = (job *)malloc(n*sizeof(job));
		
	for(i=0;i<n;++i)
	{
			cin>>JobArray[i].jobId>>JobArray[i].startTime>>JobArray[i].jobLength;
			JobArray[i].remLength = JobArray[i].jobLength; 
	}
	
	scheduler(JobArray,n);
}
