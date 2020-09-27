#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

void displayVec(vector <int> vec)
{
	int i;
	debug (1, vec.size(), "[");
	
	for (i=0; i<vec.size(); i++)
	{
		if (i == vec.size()-1)
			debug (1, vec[i]);
		else
			debug (1, vec[i], ",");	
	}
	debug(1, "]\n");
}

void display2DVec(vector <vector<bool>> vec,
	vector<int> arr, vector<int> arr2)
{
	int i,j;
		
	debug (1, "     ");
	for (i=0; i<=arr2[arr2.size()-1]; i++)
	{
		if (i <= 9)
			debug (1, i, "  ");
		else
			debug (1, i, " ");
	}
	debug (1, "\n");
	
	for (i=0; i<vec.size(); i++)
	{
		if (arr[i] <= 9)
			debug (1, arr[i], "  | ");
		else 
			debug (1, arr[i], " | ");	
			
		for (j=0; j<vec[i].size(); j++)
		{
			if (vec[i][j] == true)
				debug (1, "T  ");
			else
				debug (1, "F  ");
		}
		debug (1, "\n");
	}
	debug (1, "\n");
}

void display2DVec(vector <vector<pair<bool, vector<int>> >> vec,
	vector<int> arr, vector<int> arr2)
{
	int i,j;
		
	debug (1, "     ");
	for (i=0; i<=arr2[arr2.size()-1]; i++)
	{
		if (i <= 9)
			debug (1, i, "  ");
		else
			debug (1, i, " ");
	}
	debug (1, "\n");
	
	for (i=0; i<vec.size(); i++)
	{
		if (arr[i] <= 9)
			debug (1, arr[i], "  | ");
		else 
			debug (1, arr[i], " | ");	
			
		for (j=0; j<vec[i].size(); j++)
		{
			if (vec[i][j].first == true)
				debug (1, "T  ");
			else
				debug (1, "F  ");
		}
		debug (1, "\n");
	}
	
	i = vec.size()-1;
	for (j=0; j<vec[i].size(); j++)
	{
		debug (1, j, "[");
		for (auto x: vec[i][j].second)
		{
			debug (1, x, " ");
		}
		debug (1,"] ");
	}	
	debug (1, "\n");
}

bool findInDict(string s, unordered_set <string> &uSet)
{	
	if (uSet.find(s) != uSet.end())
		return true;	
	
	return false;
}

bool canItBeSplit2(vector<int> &arr)
{
	if (arr.size() <= 1)
		return false;
		
	arr.insert(arr.begin(), 0);
	int i,j;
	
	int arrSum = 0;
	int arrSize = arr.size();
	float arrAv;
	
	int k,l;
	int count;
	bool flag;

	int maxSum;	
	
	for (i=0; i<arrSize; i++)
		arrSum += arr[i];

	// -1 cause we increased size by 1 artificially by adding 0
	arrAv = arrSum/((arrSize-1)*1.0);
	
	debug (2, arrAv, "\n");
	
	vector <int> possibleSums;
	
	flag = false;
	count = 0;
	k = 0;
	for (i=1; i<=arrSize/2; i++)
	{
		debug (2, "Difference: ", (arrAv*i) - (int)(arrAv*i), "\n");
		if ((arrAv*i) - (int)(arrAv*i) == 0.0 || (arrAv*i) - (int)(arrAv*i) <= 0.001)
		{
			possibleSums.push_back((int)(arrAv*i));
			flag = true;
			k = count;
		}
		else
			possibleSums.push_back(-1);
			
		count++;
	}
	
	//
	//	k = 1;
	//	flag = true;
	//	possibleSums[1] = 176;
	//
	
	maxSum = possibleSums[k];
	if (LOG_LEVEL >= 2) displayVec(possibleSums);	
	if (flag == false)
		return false;

	// Max size of split array can be half
	vector <vector <bool>> vecAns;
	vector <bool> vecBool;

	// FOR ARR[0] 0
	vecBool.push_back(true);
	for (i=1; i<=maxSum; i++)
		vecBool.push_back(false);
		
	vecAns.push_back(vecBool);
	
	for (i=1; i<arrSize; i++)
	{
		vecBool.clear();
		for (j=0; j<=maxSum; j++)
		{
			if (vecAns[i-1][j] == true)
				vecBool.push_back(true);
			else if (j-arr[i] >= 0 && vecAns[i-1][j-arr[i]] == true)
				vecBool.push_back(true);
			else
				vecBool.push_back(false);
		}
		vecAns.push_back(vecBool);
	}
	
	if (LOG_LEVEL >= 2) display2DVec(vecAns, arr, possibleSums);
	
	// HAHA Size checks will also have to be preformed BITCH
	for (j=0; j<possibleSums.size(); j++)
	{
		if (possibleSums[j] == -1)
			continue;
		debug (2, "Suspects at ", possibleSums[j], ":\n");
		for (i=0; i<arr.size(); i++)
		{
			count = 0;
			flag = false;
			if (vecAns[i][possibleSums[j]] == true)
			{
				debug (2, arr[i], " ");
				count++;
				k = i;
				l = possibleSums[j];
				while (l != 0)
				{
					l = l - arr[k];
					if (l < 0)
						break;
					if (l == 0)
					{
						flag = true;
						break;
					}
					k--;
					while (vecAns[k-1][l] == true)
						k--;
					
					count++;
					debug (2, arr[k], " ");
				}
				//return true;
			}
			if (flag == true)
			{
				debug (2, "\n");	
				if (count == j+1)
					return true;		
			}
			
		}
	}
	
	return false;
}

bool canItBeSplit(vector<int> &arr)
{
	if (arr.size() <= 1)
		return false;
		
	arr.insert(arr.begin(), 0);
	int i,j;
	
	int arrSum = 0;
	int arrSize = arr.size();
	float arrAv;
	
	int k,l;
	int count;
	bool flag;

	int maxSum;	
	
	for (i=0; i<arrSize; i++)
		arrSum += arr[i];

	// -1 cause we increased size by 1 artificially by adding 0
	arrAv = arrSum/((arrSize-1)*1.0);
	
	debug (2, arrAv, "\n");
	
	vector <int> possibleSums;
	
	flag = false;
	count = 0;
	k = 0;
	for (i=1; i<=arrSize/2; i++)
	{
		debug (2, "Difference: ", (arrAv*i) - (int)(arrAv*i), "\n");
		if ((arrAv*i) - (int)(arrAv*i) == 0.0 || (arrAv*i) - (int)(arrAv*i) <= 0.001)
		{
			possibleSums.push_back((int)(arrAv*i));
			flag = true;
			k = count;
		}
		else
			possibleSums.push_back(-1);
			
		count++;
	}
	
	maxSum = possibleSums[k];
	if (LOG_LEVEL >= 2) displayVec(possibleSums);	
	if (flag == false)
		return false;

	// Max size of split array can be half
	vector <vector <pair<bool,vector<int>> > > vecAns;
	vector <pair<bool, vector<int>>> vecBoolInt;
	
	vector <int> vecInt;
	vecInt.push_back(0);
	// FOR ARR[0] 0
	vecBoolInt.push_back(make_pair(true, vecInt) );
	
	vecInt.clear();
	for (i=1; i<=maxSum; i++)
		vecBoolInt.push_back(make_pair(false, vecInt));
		
	vecAns.push_back(vecBoolInt);
	
	for (i=1; i<arrSize; i++)
	{
		vecBoolInt.clear();
		for (j=0; j<=maxSum; j++)
		{
			if (arr[i] > j)
			{
				// Copy from above
				vecBoolInt.push_back(vecAns[i-1][j]);
			}
			else
			{
				if (vecAns[i-1][j].first == true && vecAns[i-1][j-arr[i]].first == false)
				{
					vecBoolInt.push_back(vecAns[i-1][j]);
				}
				else if (vecAns[i-1][j].first == false && vecAns[i-1][j-arr[i]].first == true)
				{
					vecInt = vecAns[i-1][j-arr[i]].second;
					for (auto &x: vecInt)
						x = x + 1;
					vecBoolInt.push_back(make_pair(true, vecInt));
				}
				else if (vecAns[i-1][j].first == true && vecAns[i-1][j-arr[i]].first == true)
				{
					vecInt = vecAns[i-1][j-arr[i]].second;
					for (auto &x: vecInt)
						x = x + 1;
					for (auto x: vecAns[i-1][j].second)
					{
						if (find (vecInt.begin(), vecInt.end(), x) == vecInt.end())
							vecInt.push_back(x);
					}
					vecBoolInt.push_back(make_pair(true, vecInt));
				}
				else
				{
					vecBoolInt.push_back(vecAns[i-1][j]);	
				}
			}
		}
		vecAns.push_back(vecBoolInt);
		//if (LOG_LEVEL >= 2) display2DVec(vecAns, arr, possibleSums);
	}
	
	if (LOG_LEVEL >= 2) display2DVec(vecAns, arr, possibleSums);
	
	for (i=0; i<possibleSums.size(); i++)
	{
		if (possibleSums[i] != -1 )
		{
			for (auto x: vecAns[vecAns.size()-1][possibleSums[i]].second)
			{
				if (x == i+1)
					return true;
			}	
		}
	}
	return false;
}

int main()
{	
	// Iterative O(N*2)
	// This can be made much faster and more memory effecient
	// but fuck it, spent too much time on this queston already
	
	// FASTER - Use Unordered Hash Set instead of vector
	// Speace optimisized - No need of a huge array
	// 		just keep 2 rows
	
	// Resource
	// https://www.interviewbit.com/problems/equal-average-partition/
	// https://leetcode.com/problems/split-array-with-same-average/
	// https://www.geeksforgeeks.org/partition-an-array-of-non-negative-integers-into-two-subsets-such-that-average-of-both-the-subsets-is-equal/
	// https://www.youtube.com/watch?v=VwylCVAVdmo

	// Explanition
	// The important thing to remember is that 
	// (Average of full array) = (Average of sub array)
	//  Sum of Full Array / Size of full Array = Sum of sub array / Size if sub array
	// 	=> S/n = s1/n1
	//  => S/n * n1 = s1
	// 
	// All we need to do is find a smaller array which has the same average 
	//  as that of the bigger array
	// 
	// Now for Eg.0 
	// Average of Array is 4.5
	// Smaller array could be (4,5) or (3,6) or (2,7) or (3,4,5,6) etc
	// 
	// How to find a valid array ? Easy
	// Keeping in mind the average, Try to find
	//
	// Size 1 Array with sum 4.5 OR
	// Size 2 Array with sum 9 OR 
	// Size 3 Array with sum 13.5 OR 
	// Size 4 Array with sum 18
	// The sub array can of size 1 to half of full array
	// We can ignore the decimal places. So I keep them -1
	// 
	// I use a modified  Subset Sum problem to find the solution
	// I keep a tally of number of elements required to make the sum

 	LOG_LEVEL = 3;
	
	// Ex 0 - A YES
	vector <int> arr = {1,2,3,4,5,6,7,8};
	
	// EX 1 - A.YES
	//vector <int> arr = {2,3,4,5};
	
	// Ex 2 - A.YES
	//vector <int> arr = {1,7,15,29,11,9};
	
	// Ex 3 - A.NO
	//vector <int> arr = {1,2,3,5};
	
	// Ex 4 - A.NO
	//vector <int> arr = {0};
	
	// Ex 4 - A.NO
	//vector <int> arr = {18,10,5,3};
	
	// EX 5 - A.No
	//vector <int> arr = {1,6,1};
	
	// EX 6 - A.YES
	//vector <int> arr = {72,56,81,54,15,96,80,90,8};
	
	//EX 7 - A
	//vector <int> arr = {60,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30,30};
	
	debug (1, "Q. ");
	displayVec(arr);
	debug (1, "\n");
	
	bool ans = canItBeSplit (arr);
	debug (1, "Ans: ", ans);
}
