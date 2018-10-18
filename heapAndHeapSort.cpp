#include<bits/stdc++.h>

using namespace std;

void maxHeapify(int A[], int i, int n)
{
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
		maxHeapify(A,largest,n);
	}

}

void minHeapify(int A[], int i, int n)
{
	int l = 2*i;
	int r = 2*i +1;
	int smallest = i;
	if((l<=n)and(A[l] < A[i]))
		smallest = l;
	if((r<=n)and(A[r] < A[smallest]))
		smallest = r;

	if(smallest != i)
	{
		int swap = A[i];
		A[i] = A[smallest];
		A[smallest] = swap;
		minHeapify(A,smallest,n);
	}

}

void heapSort(int A[],int n)
{
	int j;
	for(j=n;j>1;--j)
	{
		int swap = A[j];
		A[j] = A[1];
		A[1] = swap;
		maxHeapify(A,1,j-1);
	}
}

int main()
{

	int n;
	cin>>n;

	int A[n+1],i,j;

	for(i=1;i<=n;++i)
		cin>>A[i];

	for(i=floor(n/2);i>=1;--i)
		maxHeapify(A,i,n);

	heapSort(A,n);

	for(i=1;i<=n;++i)
		cout<<A[i]<<endl;
}