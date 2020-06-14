#include <bits/stdc++.h>
#include "debug.h"

using namespace std;

struct Point 
{
	int x;
	int y;
	
	Point(int a, int b)
	{
		this->x = a;
		this->y = b;
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
		debug(1, "(", vec[i].x, ",", vec[i].y, ")\n");
	debug(1, "\n");
}

float calcDistance(Point a, Point b)
{
	return sqrt( (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y) );
}

void combine(vector <Point> &px, vector <Point> &py,
	int low, int mid, int high, float &smolestDist, int &compCount)
{
	debug (2, "COMB: Low, Mid, High: ", low, ",", mid, ",", high, "\n");
	int n = high - low;
	if (n == 1)
	{
		compCount++;
		debug (3, "INV: Only 1 point selected\n");
	}
	else if (n == 2)
	{
		compCount++;
		if ( calcDistance(px[low], px[mid]) < smolestDist )
		{
			smolestDist = calcDistance(px[low], px[mid]);
			debug (2, "New smolest Dist: ", smolestDist, "\n");
		}
	}
	else
	{
		int i, j;
		
		// Just BRUTE FORCE for now
		/*
		for (i=low; i<mid; i++)
		{
			for (j=mid; j<high; j++)
			{
				debug (2, "COMP: (", px[i].x, ",", px[i].y, ") (",
					px[j].x, ",", px[j].y, ")\n");
				compCount++;
				if ( calcDistance(px[i], px[j]) < smolestDist )
				{
					smolestDist = calcDistance(px[i], px[j]);
					debug (2, "New smolest Dist: ", smolestDist, "\n");
				}
			}
		}
		*/
		
		for (i=low; i<mid; i++)
		{
			vector <Point> pxC; // Custom
			//Point inFocus = new Point[,px[i].y];	
			for (j=mid; j<high && abs(px[mid].x-px[j].x)<smolestDist; j++)
			{
				if ( abs(px[mid].y-px[j].y) < smolestDist )
				{
					debug (2, "COMP: (", px[i].x, ",", px[i].y, ") (",
					px[j].x, ",", px[j].y, ")\n");
					compCount++;
					if ( calcDistance(px[i], px[j]) < smolestDist )
					{
						smolestDist = calcDistance(px[i], px[j]);
						debug (2, "New smolest Dist: ", smolestDist, "\n");
					}	
				}
			}
		}
		
	}
}

void differentiator(vector <Point> &px, vector <Point> &py, 
	int low, int high, float &smolestDist, int &compCount)
{
	if (low < high)
	{
		debug (2, "DIFF: Low, High: ", low, ",", high, "\n");
		int mid = (low+high)/2;
		
		differentiator(px, py, low, mid, smolestDist, compCount);
		differentiator(px, py, mid+1, high, smolestDist, compCount);
		
		combine(px, py, low, mid, high, smolestDist,compCount);
	}
}

void solve(vector <Point> &vec, int size)
{
	// Sort out the Vecs 
	vector <Point> px = vec;
	vector <Point> py = vec;
	
	sort(px.begin(),px.end(), lesserA<Point>() );
	sort(py.begin(),py.end(), lesserB<Point>() );
	
	if (LOG_LEVEL >= 3) displayAllPoints(px);
	if (LOG_LEVEL >= 3) displayAllPoints(py);
	
	int low = 0;
	int high = size;
	
	float smolestDist = 200;
	int compCount = 0;
	
	differentiator(px, py, low, high, smolestDist, compCount);
	
	debug (2, "Comparson Count: ", compCount, "\n");
	debug (1, "Smallest Distance: ", smolestDist, "\n");
	
}


int main()
{	
	// Resource
	// https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/
	// https://www.geeksforgeeks.org/closest-pair-of-points-onlogn-implementation/
	// Good Proces Explanation
	// https://www.youtube.com/watch?v=_pSl90jq-m0
	
	// COMPLEXITY - O(n x log(n)^2)
	
	// My Solution is not O(n log(n))
	// However spent too much time on this already,
	// for now lets stop at what we have
	
	LOG_LEVEL = 1;
	
	vector <Point> vec;
	
	// EX 1 
	/*
	vec.push_back( Point(2,3) );
	vec.push_back( Point(12,30) );
	vec.push_back( Point(40,50) );
	vec.push_back( Point(5,1) );
	vec.push_back( Point(12,10) );
	vec.push_back( Point(3,4) );
	*/
	
	// EX 2
	// Ans 1.414214
	vec.push_back( Point(31,-68) );
	vec.push_back( Point(-36,38) );
	vec.push_back( Point(-83,-25) );
	vec.push_back( Point(45,25) );
	vec.push_back( Point(-90,-66) );
	vec.push_back( Point(68,-82) );
	vec.push_back( Point(-61,15) );
	vec.push_back( Point(3,-24) );
	vec.push_back( Point(-22,51) );
	vec.push_back( Point(7,0) );
	vec.push_back( Point(30,84) );
	vec.push_back( Point(11,-11) );
	vec.push_back( Point(-25,-66) );
	vec.push_back( Point(-27,-91) );
	vec.push_back( Point(-98,39) );
	vec.push_back( Point(-72,63) );
	vec.push_back( Point(-82,84) );
	vec.push_back( Point(-25,47) );
	vec.push_back( Point(-87,-79) );
	vec.push_back( Point(-85,-63) );
	vec.push_back( Point(65,-25) );
	vec.push_back( Point(-71,-27) );
	vec.push_back( Point(0,11) );
	vec.push_back( Point(18,73) );
	vec.push_back( Point(-21,68) );
	vec.push_back( Point(-86,87) );
	vec.push_back( Point(34,6) );
	vec.push_back( Point(32,14) );
	vec.push_back( Point(70,-32) );
	vec.push_back( Point(-60,76) );
	vec.push_back( Point(100,9) );
	vec.push_back( Point(36,60) );
	vec.push_back( Point(72,-5) );
	vec.push_back( Point(-42,-99) );
	vec.push_back( Point(99,8) );
	vec.push_back( Point(-42,76) );
	vec.push_back( Point(-22,98) );
	vec.push_back( Point(-38,-27) );
	vec.push_back( Point(45,94) );
	vec.push_back( Point(-97,-58) );
	vec.push_back( Point(15,86) );
	vec.push_back( Point(60,49) );
	vec.push_back( Point(-34,-27) );
	vec.push_back( Point(37,-69) );
	vec.push_back( Point(-57,-24) );
	vec.push_back( Point(-79,27) );
	vec.push_back( Point(-89,-72) );
	vec.push_back( Point(-89,-40) );
	
	int size = vec.size();
	
	if (LOG_LEVEL >= 2) displayAllPoints(vec);
	
	solve(vec, size);
}
