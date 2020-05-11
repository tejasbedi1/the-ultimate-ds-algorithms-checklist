#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void subsequences(char *str, int size)
{
	int i, j;
	
	// Manual
	//1
	for (i=0; i<size; i++)
	{
		debug(1, str[i], " ");
	}
	//2
	for (i=0; i<size; i++)
	{
		for (j=i+1; j<size; j++)
		{
			debug(1, str[i], str[j], " ");	
		}	
	}
	//3
	for (i=0; i<size; i++)
	{
		for (j=i+2; j<size; j++)
		{
			debug(1, str[i], str[i+1], str[j], " ");	
		}	
	}
	//4
	for (i=0; i<size; i++)
	{
		for (j=i+3; j<size; j++)
		{
			debug(1, str[i], str[i+1], str[i+2], str[j], " ");	
		}	
	}
}

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
