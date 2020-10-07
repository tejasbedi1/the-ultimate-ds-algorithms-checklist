#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

struct Point 
{
	int id;
	int x;
	int y;
	
	Point(int id, int a, int b)
	{
		this->id = id;
		this->x = a;
		this->y = b;
	}
};

struct Distances
{
	int id1;
	int id2;
	float dist;
	
	Distances(int id1, int id2, float dist)
	{
		this->id1 = id1;
		this->id2 = id2;
		this->dist = dist;
	}
};

template <class T> 
struct lesserA
{
	bool operator () (T &a, T &b)
	{
		return a.x < b.x;
	}
};
template <class T> 
struct lesserB
{
	bool operator () (T &a, T &b) 
	{
		return a.y < b.y;
	}
};

void displayAllPoints(vector <Point> &vec)
{
	debug (1, "Points:-\n");
	int i;
	for (i=0; i<vec.size(); i++)
		debug(1, vec[i].id, " (", vec[i].x, ",", vec[i].y, ")\n");
	debug(1, "\n");
}

float calcDistance(Point a, Point b)
{
	return sqrt( (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) );
}

void calculateDistancesAndStoreInHash (vector <Point> &vec, 
	vector < unordered_map<int, float> > &distVecHash)
{
	int i,j,k;
	float temp;
	
	unordered_map <int, float> uMap;
	
	for (i=0; i<vec.size(); i++)
	{
		k = 0;
		uMap.clear();
		for (j=0; j<vec.size(); j++)
		{
			temp = calcDistance(vec[i], vec[j]);
			debug (3, vec[i].id, ",", vec[j].id, " (", temp, ")\n");
			uMap[k] = temp;
			k++;
		}
		distVecHash.push_back(uMap);
	}
}

void findLargestDistanceFromKCenter(vector <Point> &pointVec, 
	vector < unordered_map<int, float> > &distVecHash, 
	unordered_set <int> kcenterHash, vector <int> kcenterVec)
{
	int i, j;
	int s = kcenterVec.size();
	float min;
	vector <float> maxs;
	
	// choose one with highest minimum distance
	for (j=0; j<pointVec.size(); j++)
	{
		if (kcenterHash.find(pointVec[j].id) == kcenterHash.end())
		{
			min = INT_MAX;
			for (i=0; i<s; i++)
			{
				debug (3, "Checking- ", kcenterVec[i], ",", pointVec[j].id, 
					" (", distVecHash[kcenterVec[i]][pointVec[j].id], ")\n");
				if ( min > distVecHash[kcenterVec[i]][pointVec[j].id] )
				{
					min = distVecHash[kcenterVec[i]][pointVec[j].id];
					debug (3, "New Minimum set: ", min, "\n");
				}
			}	
			maxs.push_back(min);
		}
		else
		{
			maxs.push_back(0);
		}
	}
	
	int index = -1;
	float temp = 0;
	debug (3, "All Max's...\n");
	for (i=0; i<maxs.size(); i++)
	{
		debug (3, maxs[i], " ");
		if (temp < maxs[i])
		{
			temp = maxs[i];
			index = i;
		}
	}
	debug (3, "\n");
	
	debug (1, "Max Distance: ", temp, "\n");
	debug (2, "Furthest Point from K centers: ", index, "\n");
}

int findFurthestOne (vector <Point> &pointVec, 
	vector < unordered_map<int, float> > &distVecHash,
	unordered_set <int> kcenterHash, vector <int> kcenterVec)
{
	int i,j;
	int s = kcenterVec.size();
	float  min;
	vector <float> maxs;
	
	// choose one with highest minimum distance
	for (j=0; j<pointVec.size(); j++)
	{
		if (kcenterHash.find(pointVec[j].id) == kcenterHash.end())
		{
			min = INT_MAX;
			for (i=0; i<s; i++)
			{
				debug (3, "Checking- ", kcenterVec[i], ",", pointVec[j].id, 
					" (", distVecHash[kcenterVec[i]][pointVec[j].id], ")\n");
				if ( min > distVecHash[kcenterVec[i]][pointVec[j].id] )
				{
					min = distVecHash[kcenterVec[i]][pointVec[j].id];
					debug (3, "New Minimum set: ", min, "\n");
				}
			}	
			maxs.push_back(min);
		}
		else
		{
			maxs.push_back(0);
		}
	}
	
	int index = -1;
	float temp = 0;
	debug (2, "All Max's...\n");
	for (i=0; i<maxs.size(); i++)
	{
		debug (2, maxs[i], " ");
		if (temp < maxs[i])
		{
			temp = maxs[i];
			index = i;
		}
	}
	debug (2, "\n");
	debug (2, "Returning Index: ", index, "\n");
	return index;
}

void solve(vector <Point> &pointVec, vector < unordered_map<int, float> > &distVecHash,
	int k)
{
	debug (2, "\nSolving...\n");
	
	// For k == 1 
	// We can make a special case 
	
	// Choose first arbitarily 
	int size = pointVec.size();
	
	srand((unsigned int)time(NULL));
	int temp = rand() % size;
	debug (1, "First K Center: ", temp, "\n");
	
	unordered_set <int> kcenter;
	vector <int> kcenterVec;
	kcenter.insert(temp);
	kcenterVec.push_back(temp);
	k--;
	
	while (k > 0)
	{
		temp = findFurthestOne (pointVec, distVecHash, kcenter, kcenterVec);
		kcenter.insert(temp);
		kcenterVec.push_back(temp);
		k--;
	}
	
	int i;
	debug (2, "K Centers...\n");
	for (i=0; i<kcenterVec.size(); i++)
	{
		debug (2, kcenterVec[i], " ");
	}
	debug (2, "\n");
	
	findLargestDistanceFromKCenter(pointVec, distVecHash, kcenter, kcenterVec);
}


int main()
{	
	// GREEDY 
	
	// Resource
	
	// COMPLEXITY - k x k x n = ( k^2 x n )
	
	// EXPLANATION
	// The ceoncept is this 
	// Choose the first K center randomly. (If K = 1, then you might want to do it differently)
	// For the next K center choose the one which is furthest from the current K center
	//
	// So what happens when you have multiple K centers ?
	// Here we "choose one with highest minimum distance"
	// I.e for every point measure the distance to all K centers
	//   Save the minimum distance here, in idk a vector ('maxs' (is the one we use))
	//   This basicaly would give you the minimum distance to a k center for every point
	// Now choose the one which is the furthest from all K centers
	//  (basically choose the max from the 'maxs' array)
	// This will be the new K center
	
	LOG_LEVEL = 2;
	
	vector <Point> vec;

	
	// EX 1 
	///* k == 1 OPTIMAL SOL 34.~ | k == 2 OP SOL 20 | k == 3 OP SOL 10.8167
	vec.push_back( Point(0,2,3) );
	vec.push_back( Point(1,12,30) );
	vec.push_back( Point(2,40,50) );
	vec.push_back( Point(3,5,1) );
	vec.push_back( Point(4,12,10) );
	vec.push_back( Point(5,3,4) );
	
	
	// EX 2
	// Ans 1.414214
	/*
	vec.push_back( Point(0,15,27) );
	vec.push_back( Point(1,31,-68) );
	vec.push_back( Point(2,-36,38) );
	vec.push_back( Point(3,-83,-25) );
	vec.push_back( Point(4,45,25) );
	vec.push_back( Point(5,-90,-66) );
	vec.push_back( Point(6,68,-82) );
	vec.push_back( Point(7,-61,15) );
	vec.push_back( Point(8,3,-24) );
	vec.push_back( Point(9,-22,51) );
	vec.push_back( Point(10,7,0) );
	vec.push_back( Point(11,30,84) );
	vec.push_back( Point(12,11,-11) );
	vec.push_back( Point(13,-25,-66) );
	vec.push_back( Point(14,-27,-91) );
	vec.push_back( Point(15,-98,39) );
	vec.push_back( Point(16,-72,63) );
	vec.push_back( Point(17,-82,84) );
	vec.push_back( Point(18,-25,47) );
	vec.push_back( Point(19,-87,-79) );
	vec.push_back( Point(20,-85,-63) );
	vec.push_back( Point(21,65,-25) );
	vec.push_back( Point(22,-71,-27) );
	vec.push_back( Point(23,0,11) );
	vec.push_back( Point(24,18,73) );
	vec.push_back( Point(25,-21,68) );
	vec.push_back( Point(26,-86,87) );
	vec.push_back( Point(27,34,6) );
	vec.push_back( Point(28,32,14) );
	vec.push_back( Point(29,70,-32) );
	vec.push_back( Point(30,-60,76) );
	vec.push_back( Point(31,100,9) );
	vec.push_back( Point(32,36,60) );
	vec.push_back( Point(33,72,-5) );
	vec.push_back( Point(34,-42,-99) );
	vec.push_back( Point(35,99,8) );
	vec.push_back( Point(36,-42,76) );
	vec.push_back( Point(37,-22,98) );
	vec.push_back( Point(38,-38,-27) );
	vec.push_back( Point(39,45,94) );
	vec.push_back( Point(40,-97,-58) );
	vec.push_back( Point(41,15,86) );
	vec.push_back( Point(42,60,49) );
	vec.push_back( Point(43,-34,-27) );
	vec.push_back( Point(44,37,-69) );
	vec.push_back( Point(45,-57,-24) );
	vec.push_back( Point(46,-79,27) );
	vec.push_back( Point(47,-89,-72) );
	vec.push_back( Point(48,-89,-40) );
	*/
	
	int k = 5;
	
	if (LOG_LEVEL >= 2) displayAllPoints(vec);
	
	// As a part of the question we need to know the distance between each point
	// Its a O(n^2) operation but as per the Q this info is already provided
	
	unordered_map <int, float> uMap;
	vector < unordered_map <int, float> > distVecHash;
	
	calculateDistancesAndStoreInHash (vec, distVecHash);
	
	// debug (1, distVecHash[0][3] );
	
	solve(vec, distVecHash, k);
}
