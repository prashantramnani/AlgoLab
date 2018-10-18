#include <bits/stdc++.h>

using namespace std;

void partition(int A[],int low,int pivot,int high)
{
	int change;
	if((high == low))
		return ;
	else if(pivot == low)
	{
		if(A[low] > A[low + 1])
		{
			change = A[low];
			A[low] = A[low + 1];
			A[low + 1] = change;
		}
		return;
	}
	int i,j,temp;
	i = low;
	j = high;

	while(i<j)
	{
		if(A[i] > A[pivot])
		{
			if(A[j]<A[pivot])
			{
				temp = A[j];
				A[j] = A[i];
				A[i] = temp;
				i++;
				j--;
			}
			else
				j--;
		}
		else
			i++;

		if(A[j] < A[pivot])
		{
			if(A[i]>A[pivot])
			{
				temp = A[j];
				A[j] = A[i];
				A[i] = temp;
				i++;
				j--;
			}
			else
				i++;
		}
		else
			j--;
	}

	if(A[j] < A[pivot])
	{
		temp = A[j];
		A[j] = A[pivot];
		A[pivot] = temp;
	}

	else if(A[i] < A[pivot] )
	{
		temp = A[i];
		A[i] = A[pivot];
		A[pivot] = temp;
	}
}

void quicksort(int A[],int low,int high)
{
	if(high == low)
		return;
	int pivot = (high + low)/2;

	partition( A, low, pivot,high);
	// for(int i=0;i<(high - low + 1);++i)
	// 	cout<<A[i]<<endl;
	
	quicksort(A,low,pivot);
	quicksort(A,pivot+1,high);

}

int main()
{
	int n,i,j;
	cin>>n;

	int A[n];

	for(i=0;i<n;++i)
		cin>>A[i];

	quicksort(A,0,n-1);

	for(i=0;i<n;++i)
		cout<<A[i]<<endl;
}