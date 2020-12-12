#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

int powIt(int no, int power)
{
	if (power == 1)
		return no;
	else if (power % 2 == 0)
		return powIt(no*no, power/2);
	else
		return powIt(no*no, (power-1)/2) * no;
}

int main()
{
	// Divide and Conquor Example 
	
	LOG_LEVEL = 3;
	
	int no = 10;
	int power = 5;

	int ans = powIt (no, power);
	
	debug (1, ans);
}
