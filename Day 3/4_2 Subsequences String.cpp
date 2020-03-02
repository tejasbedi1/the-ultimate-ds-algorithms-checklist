#include <bits/stdc++.h> 
using namespace std; 

void subsequences(string s)
{
	set <string> st;
	int len = s.length();
	int i,j,k,l,m;
	for (int i=0;i<len;i++)
	{	
		//cout<<i+1<<endl;
		if (i == 0)
		{
			for (j=0;j<len;j++)
				cout<<s[j]<<" ";
			cout<<endl;
		}
		if (i == 1)
		{
			for (j=0;j<len;j++)
				for (k=j+1;k<len;k++)
					cout<<s[j]<<s[k]<<" ";
			cout<<endl;
		}
		if (i == 2)
		{
			for (j=0;j<len;j++)
				for (k=j+1;k<len;k++)
					for (l=k+1;l<len;l++)
						cout<<s[j]<<s[k]<<s[l]<<" ";
			cout<<endl;
		}
		if (i == 3)
		{
			for (j=0;j<len;j++)
				for (k=j+1;k<len;k++)
					for (l=k+1;l<len;l++)
						for (m=l+1;m<len;m++)
							cout<<s[j]<<s[k]<<s[l]<<s[m]<<" ";
			cout<<endl;
		}
	}
} 

int main() 
{ 
	//string s = "aabc"; 
	string s = "abcd"; 
	subsequences(s); 
	return 0; 
} 

