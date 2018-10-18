#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int N;
    cin>>N;
    long long int A[N],B[N];
    long long int j,i;
    
    for(j=0;j<N;++j)
        cin>>A[j];
    for(j=0;j<N;++j)
        cin>>B[j];
    sort(A,A+N);
    sort(B,B+N);
    long long int sum = 0;
    
    for( i=0;i<N;++i)
        sum += abs(A[i] - B[i]);
    cout<<sum<<endl;    
}
