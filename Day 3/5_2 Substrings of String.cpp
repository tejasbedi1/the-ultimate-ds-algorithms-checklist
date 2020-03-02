#include <bits/stdc++.h> 
using namespace std; 

void subsequences(string s, int len)
{
	set <string> st;
	int i,j;
	for (i=0;i<len;i++)
	{
		for (j=0;j<len-i;j++)
		{
			//cout<<s.substr(j,i+1)<<endl;
			st.insert(s.substr(j,i+1));
		}
	}
	
	set <string> :: iterator it;
	for (it=st.begin();it!=st.end();it++)
	{
		cout<<*it<<endl;
	}
} 

int main() 
{ 
	string s = "abac"; 
	cout<<s<<endl<<endl;
	subsequences(s,s.length()); 
	return 0; 
} 

