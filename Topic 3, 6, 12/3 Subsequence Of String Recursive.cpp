#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void subsequencesAuto(char *str, int size)
{
	int i, j;
	int k, l;
	// Auto
	for (i=0; i<size; i++)
	{
		debug(1, str[i], " ");
	} 
	for (k=1; k<size; k++)
	{
		for (i=0; i<size; i++)
		{
			for (j=i+k; j<size; j++)
			{
				for (l=0; l<k; l++)
				{
					debug (1, str[i+l]);	
				}
				debug (1, str[j], " ");
			}
		}
	}
}

int main ()
{
	// Iterative
	
	// HAshing can filter out repeating stuff not implementing for now
	
	LOG_LEVEL = 3;
	
	int size;
	
	char c[] = "abcd";
	//char c[] = "aaaa";
    size = sizeof(c)/sizeof(c[1]);
    
    debug (2, "Checking: ", c, " ", size, "\n");
    subsequencesAuto(c, size-1);
}
