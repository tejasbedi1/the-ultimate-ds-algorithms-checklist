#include <bits/stdc++.h>
#include "debug.h"

using namespace std;


int main()
{	
	// https://stackoverflow.com/questions/4084050/can-you-use-arithmetic-operators-to-flip-between-0-and-1
	int i = 0;
	cout<<i<<endl;
	
	i = 1 - i;
	cout<<i<<endl;
	
	i = 1 - i;
	cout<<i<<endl;
	
	// XOR
	i = i^1;
	cout<<i<<endl;
	
	i = i^1;
	cout<<i<<endl;
	
	// NOT
	i = !i;
	cout<<i<<endl;
	
	i = !i;
	cout<<i<<endl;
	
}
