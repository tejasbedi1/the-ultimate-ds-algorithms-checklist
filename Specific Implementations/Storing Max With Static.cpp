#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int maxxer(int b)
{
	static int a;
	if (b > a)
	{
		a = b;
	}
	return a;
}
int main()
{
	maxxer(1);
	maxxer(3);
	maxxer(2);
	cout<<maxxer(INT_MIN); 
}
