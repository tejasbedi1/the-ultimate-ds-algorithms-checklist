#include <iostream>

using namespace std;

void recur(string s,int);

int main()
{
	int N = 3;
	string s = "abc"; 
	
	cout<<s<<endl;
	cout<<s[0]<<endl;
	cout<<s[2]<<endl;
	s[0] = s[2];
	cout<<s[0]<<endl;
	
	s = "abc";
	recur(s,0);
}

void recur(string s,int i)
{
	if (i >= 2)
		return;
	if (i != 0)
	{
		s[i] = 'z';
	}
	cout<<s<<endl;
	recur (s,++i);
	cout<<s<<endl;
}
