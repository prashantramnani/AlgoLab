#include<bits/stdc++.h>
# define ull unsigned long long 
using namespace std;



ull int ways(ull int N)
{
    ull int M[2][2] = {1,1,1,0},f[2][2],i,j;


    
    for(i=2;i<=N;++i)
    {
      f[0][0] = (M[0][0]*M[0][0] + M[0][1]*M[1][0])%(1000000000 + 7);
      f[0][1] = (M[0][0]*M[0][1] + M[0][1]*M[1][1])%(1000000000 + 7);
      f[1][0] = (M[1][0]*M[0][0] + M[1][1]*M[1][0])%(1000000000 + 7);
      f[1][1] = (M[1][0]*M[0][1] + M[1][1]*M[1][1])%(1000000000 + 7);

      for(i=0;i<2;++i)
        for(j=0;j<2;++j)
          f[i][j] = M[i][j];
    }

    return M[1][0];

}

int main()
{
    ull int T,N;
    cin>>T;
    int i;
    for(i=0;i<T;++i)
    {
        cin>>N;
        cout<<ways(N)<<endl;
    }
}