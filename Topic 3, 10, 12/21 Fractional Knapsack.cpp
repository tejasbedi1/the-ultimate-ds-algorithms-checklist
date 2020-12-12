#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

struct Ele
{
	int value;
	int weight;
	
	Ele(int v, int w)
	{
		this->value = v;
		this->weight = w;
	}
};

template <class T>
void displayArr(T &vecArr)
{
	int i;
	for (i=0; i<vecArr.size(); i++)
		debug (1, vecArr[i].value, ",", vecArr[i].weight, "\n");
	debug (1, "\n");
}

struct greatestRatioFirst
{
	bool operator () (Ele &x, Ele &y)
	{
		if ( (x.value / x.weight) > (y.value / y.weight) )
			return true;
		else
			return false;
	}
};

void solve(vector <Ele> &vecArr, int n, int maxWeight)
{
	debug (1, "Values & Weights\n");
	displayArr(vecArr);
	sort(vecArr.begin(), vecArr.end(), greatestRatioFirst()); 
	debug (1, "Sorted\n");
	displayArr(vecArr);
	
	debug (1, "Solving for Max Weight: ", maxWeight, "\n");
	
	int i;
	int ans = 0;
	for (i=0; i<n; i++)
	{
		if (vecArr[i].weight < maxWeight)
		{
			ans = ans + vecArr[i].value;
			maxWeight  = maxWeight -  vecArr[i].weight;
		}
		else
		{
			ans += (vecArr[i].value / vecArr[i].weight) * maxWeight;
			break; 
		}
	}
	
	debug (1, "Max possible Value: ", ans, "\n");
}


int main()
{	
	// GREEDY
	
	// Resource
	// https://www.geeksforgeeks.org/fractional-knapsack-problem/
	
	// COMPLEXITY 
	// Sort: On(logn)
	
	// QUESTION
	// FRACTIONAL KNAPSACK
	
	LOG_LEVEL = 3;
	
	vector <Ele> vecArr;
	
	// V, W
	// Ex 1	 // ANS 240
	/*
	vecArr.push_back( Ele( 60, 10) );
	vecArr.push_back( Ele(100, 20) ); 
	vecArr.push_back( Ele(120, 30) );
	*/
	//EX 2 // ANS 270
	///* 
	vecArr.push_back( Ele( 30, 05) );
	vecArr.push_back( Ele( 20, 10) ); 
	vecArr.push_back( Ele(100, 20) );
	vecArr.push_back( Ele( 90, 30) );
	vecArr.push_back( Ele(160, 40) );
	//*/
	
	int n = vecArr.size();
	
	//int maxWeight = 50; // EX 1 
	int maxWeight = 60; // Ex 2
	
	solve(vecArr, n, maxWeight);
}
