#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

int N;

void display(char *a, char *b, char *c, char *carry,
	unordered_map <char, int> &uMap, bool clearAll)
{
	int n = N;
	int i;
	for (i=0; i<n; i++)
		cout<<carry[i]<<" ";
	cout<<endl;
	for (i=0; i<n; i++)
		cout<<"--";
	cout<<endl;
	
	for (i=0; i<n; i++)
	{
		if (uMap.find(a[i]) == uMap.end())
			cout<<a[i]<<" ";
		else
			cout<<uMap[a[i]]<<" ";
	}
	cout<<endl;
	for (i=0; i<n; i++)
	{
		if (uMap.find(b[i]) == uMap.end())
			cout<<b[i]<<" ";
		else
			cout<<uMap[b[i]]<<" ";
	}
	cout<<endl;
	for (i=0; i<n; i++)
		cout<<"--";
	cout<<endl;
	
	for (i=0; i<n; i++)
	{
		if (uMap.find(c[i]) == uMap.end())
			cout<<c[i]<<" ";
		else
			cout<<uMap[c[i]]<<" ";
	}
	cout<<endl;
	if (LOG_LEVEL >=3) system("pause");
	if (clearAll == true) system("cls");
}

void yolo(char *a, char *b, char *c, char *carry, int aS, int bS, int cS,
	unordered_map <char, int> &uMap, unordered_set <int> &uSet, bool &flag)
{
	if (LOG_LEVEL >= 2 ) display(a, b, c, carry, uMap, true);
		
	if (aS == -1 && bS == -1 && cS == -1)
	{
		debug (1, "Answer\n");
		display(a, b, c, carry, uMap, false);
		debug (1,"\n");
		unordered_map <char, int> :: iterator itr;
		for (itr = uMap.begin(); itr != uMap.end(); itr++)
			debug (1, itr->first, ":", itr->second, "  ");
		
		flag = true;
	}
	if (flag == true)
		return;
		
	int i;
	int temp;
	if (aS == bS && bS == cS)
	{
		for (i=0; i<=9; i++)
		{
			if (uMap.find( a[aS] ) == uMap.end())
			{
				if (uSet.find( i ) == uSet.end())
				{
					debug (3, "Assigning: ", a[aS], ":", i, "\n");
					uMap.insert( make_pair(a[aS],i) );
					uSet.insert( i );
					
					yolo(a, b, c, carry, aS-1, bS, cS, uMap, uSet, flag);
					
					uSet.erase( i );
					uMap.erase( a[aS] );
					debug (3, "Backtracking: ", a[aS], "\n");
				}
			}
			else
			{
				debug (3, a[aS], " already has ", uMap[a[aS]], "\n");
				yolo(a, b, c, carry, aS-1, bS, cS, uMap, uSet, flag);
				
				debug (3, "Backtracking: ", a[aS], "\n");
				break;
			}
		}	
	}
	else if (aS == bS-1 && bS-1 == cS-1)
	{
		for (i=0; i<=9; i++)
		{
			if (uMap.find( b[bS] ) == uMap.end())
			{
				if (uSet.find( i ) == uSet.end())
				{
					debug (3, "Assigning: ", b[bS], ":", i, "\n");
					uMap.insert( make_pair(b[bS],i) );
					uSet.insert( i );
					
					yolo(a, b, c, carry, aS, bS-1, cS, uMap, uSet, flag);
					
					uSet.erase( i );
					uMap.erase( b[bS] );
					debug (3, "Backtracking: ", b[bS], "\n");
				}
			}
			else
			{
				debug (3, b[bS], " already has ", uMap[b[bS]], "\n");
				yolo(a, b, c, carry, aS, bS-1, cS, uMap, uSet, flag);
				
				debug (3, "Backtracking: ", b[bS], "\n");
				break;
			}
		}
	}
	else if (aS == bS && bS == cS-1)
	{
		if (uMap.find( c[cS] ) == uMap.end())
		{
			temp = uMap[ a[cS] ] + uMap[ b[cS] ] + (carry[cS]-48);
			debug (3, "Temp: ", temp, "\n");
			if (temp > 9)
			{
				temp = temp - 10;
				if (uSet.find( temp ) == uSet.end())
				{
					if (cS-1 >= 0) // If its -1 then we wont be able to set carry
					{
						debug (3, "Assigning: ", c[cS], ":", temp, "\n");
						uMap.insert( make_pair(c[cS], temp) );
						uSet.insert( temp );
						
						carry[cS-1] = '1';
						yolo(a, b, c, carry, aS, bS, cS-1, uMap, uSet, flag);
						
						carry[cS-1] = '0';
						uSet.erase( temp );
						uMap.erase( c[cS] );
						debug (3, "Backtracking: ", c[cS], "\n");
					}
				}
			}
			else
			{
				if (uSet.find( temp ) == uSet.end())
				{
					debug (3, "Assigning: ", c[cS], ":", temp, "\n");
					uMap.insert( make_pair(c[cS], temp) );
					uSet.insert( temp );
					
					yolo(a, b, c, carry, aS, bS, cS-1, uMap, uSet, flag);
					
					uSet.erase( temp );
					uMap.erase( c[cS] );
					debug (3, "Backtracking: ", c[cS], "\n");
				}
			}
		}
		// If the equaled answer already exists check calculation
		else if (uMap.find( c[cS] ) != uMap.end())
		{
			temp = uMap[ a[cS] ] + uMap[ b[cS] ] + (carry[cS]-48);
			debug (3, "Temp: ", temp, "\n");
			if (temp > 9)
			{
				temp = temp - 10;
				if (uMap[ c[cS] ] == (temp))
				{
					debug (3, c[cS], " already has ", uMap[c[cS]], "\n");
					carry[cS-1] = '1';
					yolo(a, b, c, carry, aS, bS, cS-1, uMap, uSet, flag);
					
					carry[cS-1] = '0';
					debug (3, "Backtracking: ", c[cS], "\n");
				}
			}
			else
			{
				if (uMap[ c[cS] ] == temp)
				{
					debug (3, c[cS], " already has ", uMap[c[cS]], "\n");
					yolo(a, b, c, carry, aS, bS, cS-1, uMap, uSet, flag);
					
					debug (3, "Backtracking: ", c[cS], "\n");
				}
			}
		}
	}
}

int main()
{	
	// RESOURCE 
	// https://www.geeksforgeeks.org/partition-problem-dp-18/
	// All subsets [Find in Directory]
	
	// Recursive Solution Complexity 2^n
	
	LOG_LEVEL = 1;
	
	int k;

	//char a[] = "0SEND";
	//char b[] = "0MORE";
	//char c[] = "MONEY";
    char a[] = "00MAC";
	char b[] = "0MAAR";
	char c[] = "JOCKO";
    
	int aS = sizeof(a)/sizeof(a[0]);
	int bS = sizeof(b)/sizeof(b[0]);
	int cS = sizeof(c)/sizeof(c[0]);
	
	N = cS;
	char carry[] = "00000";
	
	unordered_set <int> uSet;
	unordered_map <char, int> uMap;
	
	uMap.insert ( make_pair('0', 0) );
	bool flag = false;
	
	yolo(a, b, c, carry, aS-2, bS-2, cS-2, uMap, uSet, flag);
}
