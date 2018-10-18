#include<bits/stdc++.h>

using namespace std;

void maxHeapify(int A[], int i, int *N)
{
	int n = *N;
	//cout<<n<<endl;
	int l = 2*i;
	int r = 2*i +1;
	int largest = i;
	if((l<=n)and(A[l] > A[i]))
		largest = l;
	if((r<=n)and(A[r] > A[largest]))
		largest = r;

	if(largest != i)
	{
		int swap = A[i];
		A[i] = A[largest];
		A[largest] = swap;
		maxHeapify(A,largest,N);
	}

}

int mazimum(int A[])
{
	return A[1];
}

int extractMax(int A[],int *N)
{
	if(N == 0)
	{
		cout<<"fuck off"<<endl;
		return(-1);
	}
	int max = A[1];
	A[1] = A[*N];
	A[*N] = max;
	*N = *N-1;

	maxHeapify(A,1,N);
	return max;

}

void heapIncreaseKey(int A[],int i,int key)
{
	if(A[i] > key)
		return;
	else
	{
		A[i] = key;
		while(i>1)
		{
			if(A[i] > A[i/2])
			{
				int swap = A[i];
				A[i] = A[i/2];
				A[i/2] = swap;
			}
			else
				break;
			i = i/2;
		}
	}
}

int main()
{

	int n,*N;
	cin>>n;
	N = &n;
	int A[n+1],i,j;

	for(i=1;i<=n;++i)
		cin>>A[i];

	for(i=floor(n/2);i>=1;--i)
		maxHeapify(A,i,N);

	//extractMax(A,N);
	for(i=1;i<=n;++i)
		cout<<A[i]<<endl;

	heapIncreaseKey(A,5,6);

	for(i=1;i<=n;++i)
		cout<<A[i]<<endl;	
}