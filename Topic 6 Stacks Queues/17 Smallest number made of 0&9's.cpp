#include <bits/stdc++.h>
#include <iostream>
#include "debug.h"

using namespace std;

template <class T>
void displayVector(T &vec)
{
	cout<<"Vector Output- \n";
	for (vector <int> v: vec)
	{
		for (int x: v)
		{
			cout<<x<<" ";	
		}
		cout<<"\n";
	}
	cout<<"\n";
}

void displayQueue (queue <string> &que)
{
	queue <string> temp = que;
	debug(1, "Queue... ");	
	while (temp.empty() != true)
	{
		debug(1, temp.front(), " ");
		temp.pop();
	}
	debug (1, "\n");
}

void copyToVector(queue <string> temp, vector<vector <int>> &vec)
{
	// brrrrr
	vector <int> v;
	while (temp.empty() != true)
	{
		v.push_back( stoi(temp.front()) );
		temp.pop();
	}
	vec.push_back( v );
}

void binaryGenerator(vector <vector <int>> &vec, int maxDigits)
{
	int i = 1;
	int j;
	string z = "0";
	string o = "9";
	queue <string> que;
	
	while (i < maxDigits)
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
		copyToVector(que, vec);	
		
		i++;
	}
}

void filterVector(vector <vector <int>> &vec)
{
	vector <vector <int>> newV;
	
	int i=0;
	for (vector <int> &v : vec)
	{
		vector <int> nV;
		for (int &x: v)
		{
			if (x >= pow(10,i))
			{
				nV.push_back(x);	
			}
		}
		newV.push_back(nV);
		i++;
	}	
	vec = newV;
}

int minNo(int x, vector <vector<int>> &vec)
{
	bool flag = false;
	int min = INT_MAX;
	
	for (vector <int> &v: vec)
	{
		for (int &no: v)
		{
			if (no % x == 0)
			{
				flag = true;
				if (min > no)
					min = no;
			}
		}	
		if (flag == true)
			break;
	}
	return min;
}

int main ()
{	
	// RESOURCES & QUESTION
	// https://www.geeksforgeeks.org/smallest-multiple-of-a-given-number-made-of-digits-0-and-9-only/
	// Not the most optimal, my solution is tho
	
	// PROCESS 
	// 
	// First we generate all possible conbinations with the help of a queue
	// Then we store all that in a 2D vector array (so that each digit has a 
	//  different vector array)
	// Then we filter the vector array for results that originally had a 0 in front
	//  (Cause those already have a variant)
	// Then we find the minimum element in that vector group (So as to make sure
	//  we really have the most minimum one)
	
	LOG_LEVEL = 3;
	debug (3, "Algorithm Output--\n\n");
	
	vector < vector<int> > vec;
	
	binaryGenerator(vec, 6); // 3 = 100 4 = 1,000 5 = 10,000 6 = 10,00,000
	
	if(LOG_LEVEL >= 1) displayVector(vec);
	filterVector(vec);
	if(LOG_LEVEL >= 1) displayVector(vec);
	
	int x = 7;
	debug (1, "\nTesting against X: ", x, "\n");
	
	debug (1, "\nMinimum No: ", minNo(x, vec), "\n");
}
