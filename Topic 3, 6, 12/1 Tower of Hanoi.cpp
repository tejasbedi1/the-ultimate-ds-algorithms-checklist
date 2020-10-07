#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void tower(int n, char from_rod, char aux_rod, char to_rod)
{
	if (n == 1)
		debug(1, "Moving Disk ", n, " from rod ", from_rod, " to rod ", to_rod, "\n");
	else 
	{
		tower (n-1,from_rod, to_rod, aux_rod);
		debug(1, "Moving Disk ", n, " from rod ", from_rod, " to rod ", to_rod, "\n");
		tower (n-1,aux_rod, from_rod, to_rod);
	}
}

int main ()
{
	//Rule 
	// Any disk cannot have a larger disk on top of itS
	
	LOG_LEVEL = 3;
	
	int n = 3;
    tower(n,'A','B','C');
	
	return 0;
}
