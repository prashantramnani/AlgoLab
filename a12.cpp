#include <iostream>

using namespace std;

int main()
{
	int number;
	cin>>number;

	int A[number];
	int B[number];
	int i,max,jmax,imax;

	for(i=0;i<number;++i)
	{
		cin>>A[i];
	}

	B[0] = A[0];

	for(i=1;i<number;++i)
	{
		B[i] = B[i-1] + A[i];
	}

	max = B[0];

	for(i=1;i<number;++i)
	{
		if(B[i]>max)
		{
			max = B[i];
			jmax = i;
		}
	}

	for(i=0;i<=jmax;++i)
	{
		if(max-B[i]>max)
		{
			max = max - B[i];
			imax = i + 1;
		}
	}

	cout<<imax + 1<<endl;
	cout<<jmax + 1<<endl;

}