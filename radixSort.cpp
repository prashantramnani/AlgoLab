#include<bits/stdc++.h>

using namespace std;
void countingSort(int A[],int n,int k)
{
	int c[10] = {0};
	int B[n+1] = {0};
	int i,j;
	cout<<"1"<<endl;
	for(i=1;i<n+1;++i)
		c[(A[i]/k)%10]++;

	for(i=1;i<=10;++i)
		c[i] = c[i] + c[i-1];
	
	for(i=n;i>=1;--i)
	{
		B[(A[i]/k)%10] = A[i];
		c[(A[i]/k)%10] --;
	}
	cout<<"2"<<endl;
	for(i=1;i<n+1;++i)
		A[i] = B[i];
}

int getMax(int A[],int n)
{
	int max = A[1];
	int i;
	for(i=2;i<n+1;++i)
		if(A[i]>max)
			max = A[i];

	return max;	

}

void radixSort(int A[], int n)
{
	int m,i;
	m = getMax(A,n);
	cout<<m<<endl;
	for(i=1;m/i > 0;i *= 10)
	{
		countingSort(A,n,i);
	}
}

int main()
{
	int n,i,j,k;
	cin>>n;

	int A[n+1];

	for(i=1;i<n+1;++i)
		cin>>A[i];

	radixSort(A,n);

	for(i=1;i<n+1;++i)
		cout<<A[i]<<endl;
}