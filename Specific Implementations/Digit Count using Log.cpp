#include <bits/stdc++.h>

using namespace std;

int digitCount(long long no)
{
	return floor(log10(no) + 1);
}

int main()
{	
	cout<<digitCount(123456);
}
