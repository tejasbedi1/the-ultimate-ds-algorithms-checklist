#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

using namespace std;

template <class T>
void displayVector(T &vec)
{
	for (auto x: vec)
	{
		cout<<x<<"\n";
	}
	cout<<"\n";
}

void displayQueue (queue <string> temp)
{
	debug(1, "Queue... ");	
	while (temp.empty() != true)
	{
		debug(1, temp.front(), " ");
		temp.pop();
	}
	debug (1, "\n");
}

void copyToVector(queue <string> temp, vector<int> &vInt, vector<string> &vString)
{
	// brrrrr
	while (temp.empty() != true)
	{
		vInt.push_back(stoi(temp.front()));
		vString.push_back(temp.front());
		temp.pop();
	}
}

void binaryGenerator(vector <int> &vInt, vector <string> &vString, int maxDigits)
{
	int i = 1;
	int j;
	string z = "0";
	string o = "1";
	queue <string> que;
	
	while (i <= maxDigits)
	{
		if (que.empty() == true)
		{
			que.push(z);
			que.push(o);
		}
		else
		{
			for (j = 0; j < (pow(2,i)/2); j++)
			{
				que.push( z + que.front());
				que.push( o + que.front());
				que.pop();
			}
		}
		if(LOG_LEVEL >= 2) displayQueue(que);
		copyToVector(que, vInt, vString);
		i++;
	}
}

int main ()
{	
	// RESOURCES 
	// Saw this technique while solving this
	// https://www.geeksforgeeks.org/smallest-multiple-of-a-given-number-made-of-digits-0-and-9-only/
	
	LOG_LEVEL = 1;
	debug (3, "Algorithm Output--\n\n");
	
	vector <int> vInt;
	vector <string> vString;
	
	int length = 6;
	
	binaryGenerator(vInt, vString, length); 
	
	debug (1, "String Form...\n");
	if(LOG_LEVEL >= 1) displayVector(vString);
	
	debug (2, "Int Form...\n");
	if(LOG_LEVEL >= 2) displayVector(vInt);
	
}
