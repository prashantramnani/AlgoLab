# include <bits/stdc++.h>

using namespace std;

int lexo(string a,string b)
{
	int i,j;

	for(i=0;((a[i] != '\0')&&(b[i] != '\0'));++i)
	{
		if(a[i]<b[i])
			return 0;
		else if(a[i]>b[i])
			return 1;
	}

	if(a[i] == '\0')
		return 1;
	else 
		return 0;

}

int main()
{
    long long int n,T,i,j,k,temp;
    
    cin>>n>>T;
    unsigned long long int A[n];
    string B[1001],Temp;
	  

    for(i=0;i<n;++i)
        cin>>B[i]>>A[i];
   
    
	if(n == 1)
	{
	    cout<<B[0]<<endl;
	    return 0;
	}
	    
	for(i=0;i<n-1;++i)
	{
	   for(j=0;j<n-1-i;++j)
	   {
	       if(A[j]>A[j+1])
	       {
	           temp = A[j];
	           A[j] = A[j+1];
	           A[j +1] = temp;
	           
	           
	            Temp = B[j];
	            B[j] = B[j+1];
	            B[j+1] = Temp;
	       }
	   }
	}  

	
	
    for(i=n-1;i>(n-1-T);--i)
    {
   
    	if(i == n-T)
    	{
    	
    		if(A[i] != A[i-1])
    			cout<<B[i]<<endl;
    		else
    		{
    			if(lexo(B[i],B[i-1]) == 0)
    			{
    				
    				cout<<B[i]<<endl;
    			}
    			else
    				cout<<B[i-1]<<endl;
    		}
    	}
    	else if(A[i] != A[i-1])
    		cout<<B[i]<<endl;
    	else
    	{
    		if(lexo(B[i],B[i-1]) == 0)
    		{
    			cout<<B[i]<<endl;
    			cout<<B[i-1]<<endl;
    			i = i-1;
    		}
    		
    		else
    		{
    			cout<<B[i-1]<<endl;
    			cout<<B[i]<<endl;
    			i = i-1;
    		}
    			
    	}

    }
}