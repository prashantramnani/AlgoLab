#include <bits/stdc++.h>

using namespace std;

void merge(int A[],int start, int end)
{
	int n = end - start + 1;
	cout<<"n"<<n<<endl;
	int re[n];
	int i,mid,j,k;
	mid = (start+end)/2;
	cout<<A[0]<<endl;
	for(i=start;i<=mid;++i)
	{
		re[i] = A[i];
		 cout<<"A[i]"<<A[i]<<endl;
	}

	for(i= (mid +1);i<=end;++i)
	{
		re[i] = A[i];
		cout<< "A[i]" <<A[i]<<endl;
	}
	
	cout<<"/////"<<endl;
	 for(i=start;i<=end;++i)
	 	cout<<re[i]<<endl;
	cout<<"/////"<<endl;
	for(i=start,j=mid+1,k=start;((i<=mid)&&(j<=end));++k)
	{
		if(re[i]<re[j])
		{
			A[k] = re[i];
			i++;
		}
		else
		{
			A[k] = re[j];
			j++;
		}
	}

	if((j> end)&&(i<=mid))
	{
		for(;k<=end;++k)
			A[k] = re[i++];
	}
	else
		for(;k<n;++k)
			A[k] = re[j++];	

	// cout<<"A"<<endl;
	// for(i=0;i<n;++i)
	// 	cout<<A[i]<<endl;
	// cout<<"A"<<endl;		
}

void mergeSort(int A[],int start, int end)
{
	int mid;
	mid = (start + end)/2;
	
	if(start < end)
	{
		mergeSort(A,start,mid);
		mergeSort(A, mid + 1 ,end);
		merge(A,start,end);
	}	
}

int main()
{
	int n,i,j,k;

	cin>>n;

	int A[n];

	for(i=0;i<n;++i)
		cin>>A[i];

	mergeSort(A,0,n-1);

	for(i=0;i<n;++i)
		cout<<A[i]<<endl;
}