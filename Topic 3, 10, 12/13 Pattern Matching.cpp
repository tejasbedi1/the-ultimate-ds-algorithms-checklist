#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void displayDeque(deque<int> dque)
{
	while( dque.empty() != true )
	{
		debug (2, dque.front(), " ");
		dque.pop_front();
	}
	debug (2, "\n");
}

void showSolution(unordered_map <char, string> &uMap)
{
	debug (1, "Solution..\n");
	unordered_map <char, string> :: iterator itr;
	for (itr = uMap.begin(); itr != uMap.end(); itr++)
	{
		debug (1, itr->first, ": ", itr->second, "\n");
	}
}

string returnString(char *mainStr, int a, int b)
{
	string str = "";	
	for (int i=a; i<b; i++)
		str.push_back(mainStr[i]);
	return str;
}

bool checkStringPattern(char *str, char *pa, int strLen, int paLen, 
	deque <int> dque)
{
	unordered_map <char, string> uMap;
	unordered_set <string> uSet;
	string temp;
	int i;
	int posS = 0; // starting
	int posE = 0; // ending
	posE += dque.front();
	
	for (i=0; i<paLen; i++)
	{
		if (uMap.find( pa[i] ) == uMap.end())
		{
			temp = returnString(str, posS, posE);
			if (uSet.find (temp) == uSet.end())
			{
				uMap.insert( make_pair(pa[i], temp ) );
				uSet.insert( returnString(str, posS, posE) );
				debug (3, "Inserting for ", pa[i], ": ", temp, "\n");	
			}
			else
			{
				debug (3, "Inserting for ", pa[i], ", string <", temp,
					"> already assigned\n");
				return false;
			}
		}
		else
		{
			debug (3, "Inserting for ", pa[i], ", already present  ");
			if (uMap[ pa[i] ] != returnString(str, posS, posE) )
			{
				debug (3, uMap[pa[i]], " != ", returnString(str, posS, posE),"\n");
				return false;
			}
			else
			{
				debug (3, uMap[pa[i]], " == ", returnString(str, posS, posE),"\n");
			}
		}
		posS += dque.front();
		dque.pop_front();
		posE += dque.front();
	}
	showSolution(uMap);
	return true;
}

// maxL max Length one string can have
// minL minimum length a string should have 
// currPos on array arr
// remL remaining length
// Flag, stops all recusion when answer found

void recursive( char *str, char *pa, int strLen, int paLen, 
	int maxL, int minL, int *arr, int currPos, int remL,
	deque <int> &dque, bool &flag)
{
	if ( currPos+1 < paLen )
	{
		arr [currPos] = minL;
		while (arr[currPos] <= maxL)
		{
			dque.push_back( arr[currPos] );
			
			recursive(str, pa, strLen, paLen, 
				maxL-arr[currPos]+1, 1, arr, currPos+1, remL-arr[currPos],
				dque, flag);
			
			if (flag == true)
				return;
				
			arr[currPos]++;
			dque.pop_back();
		}	
	}
	else if ( currPos+1 == paLen )
	{
		arr [currPos] = remL;
		
		dque.push_back( arr[currPos] );
		if (LOG_LEVEL >= 2) displayDeque(dque);
		if (checkStringPattern(str, pa, strLen, paLen, dque) == true)
			flag = true;
			
		dque.pop_back();
	}
}

void solve(char *str, char *pa, int strLen, int paLen)
{
	unordered_map <string, int> uMap;
	int *arr = new int[paLen]; 
	deque <int> dque;
	bool flag = false;
	
	debug (2, "String Len: ", strLen, "\n");
	debug (2, "Pattern Len: ", paLen, "\n");
	
	recursive (str, pa, strLen, paLen, 
		strLen-paLen+1, 1, arr, 0, strLen,
		dque, flag);
		
	if (flag == false)
		debug (1, "No solution found\n");
}

int main()
{	
	// RESOURCE 
	
	
	// Solutiion explanation
	// I want to break down the string acccording to the pattern into all possible 
	// 	sub strings
	// Eg (abbbab) pattern ABA
	// Can be broken down to... 
	// (a,b,bbab) (a, bb, bab) (a, bbb, ab) (a, bbba, b)
	// (ab, b, bab) (ab, bb, ab) (ab, bba, ab) .. and so
	// Hopefully u see the pattern
	// In terms of lenghts 
	// (1,1,4) (1,2,3) (1,3,1) (1,4,1)
	// (2,1,3) (2,2,3) (2,3,1)
	// (3,1,2) (3,2,1)
	// (4,1,1)
	
	LOG_LEVEL = 1;
	
	int k;
	
	//Ex 1
	//char str[] = "abccab";
	//char pa[] = "aba";
    //Ex2 
    //char str[] = "abcabcabc";
	//char pa[] = "abc";
	//Ex3
	//char str[] = "abcaabc";
	//char pa[] = "aba";
	//Ex4
	//char str[] = "aaaaaa";
	//char pa[] = "abc";
	//Ex 5
	char str[] = "GraphTrGraph";
	char pa[] = "aba";
	
	int strLen = sizeof(str)/sizeof(str[0]) -1;
	int paLen = sizeof(pa)/sizeof(pa[0]) -1;
	
	solve(str, pa, strLen, paLen);
}
