#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	int i = 0;
	cin>>s;

	// cout<<s[i]<<endl;
	// cout<<(char)(s[i] + 2)<<endl;



	 while(s[i]!='\0')
	{	
		if((int)s[i]<=('z'-2))
			s[i] = s[i] + 2;
		else
			s[i] = s[i] - ('z'-'a') + 2;
		i++;
	}

	cout<<s<<endl;
}