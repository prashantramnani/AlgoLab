#include<bits/stdc++.h>

using namespace std;
void countingSort(int A[],int n,int k)
{
	int c[k+1] = {0};
	int B[n] = {0};
	int i,j;

	for(i=1;i<n+1;++i)
		c[A[i]]++;

	for(i=1;i<=k;++i)
		c[i] = c[i] + c[i-1];
	
	for(i=n;i>=1;--i)
	{
		B[c[A[i]]] = A[i];
		c[A[i]] --;
	}

	for(i=1;i<n+1;++i)
		cout<<B[i]<<endl;
}

int main()
{
	int n,i,j,k;
	cin>>n>>k;

	int A[n+1];

	for(i=1;i<n+1;++i)
		cin>>A[i];

	countingSort(A,n,k);
}