#include <bits/stdc++.h>
#include <iostream>
#include "extrasV3.h"

const float  PI_F = 3.14159265358979;

using namespace std;

struct data
{
	int node;
	float x;
	float y;
};

class hashMapClass
{
	unordered_map <char, int> helperMap;
	unordered_map <int, char> helperMapInv;
	
	unordered_map<char, int>:: iterator itr;
	unordered_map<int, char>:: iterator itrInv;
	
	public :
	hashMapClass()
	{
		populateHashMap();
		populateInvHashMap();
	}
	
	private :
	void populateHashMap()
	{
		helperMap ['A'] = 0;
		helperMap ['B'] = 1;
		helperMap ['C'] = 2;
		helperMap ['D'] = 3;
		helperMap ['E'] = 4;
		helperMap ['F'] = 5;
		helperMap ['G'] = 6;
		helperMap ['H'] = 7;
		helperMap ['I'] = 8;
		helperMap ['J'] = 9;
		helperMap ['K'] = 10;
		helperMap ['L'] = 11;
		helperMap ['M'] = 12;
		helperMap ['N'] = 13;
		helperMap ['O'] = 14;
		helperMap ['P'] = 15;
		helperMap ['Q'] = 16;
		helperMap ['R'] = 17;
		helperMap ['S'] = 18;
		helperMap ['T'] = 19;
		helperMap ['U'] = 20;
		helperMap ['V'] = 21;
		helperMap ['W'] = 22;
		helperMap ['X'] = 23;
		helperMap ['Y'] = 24;
		helperMap ['Z'] = 25;
		
	}		
	
	void populateInvHashMap()
	{
		helperMapInv [0] = 'A';
		helperMapInv [1] = 'B';
		helperMapInv [2] = 'C';
		helperMapInv [3] = 'D';
		helperMapInv [4] = 'E';
		helperMapInv [5] = 'F';
		helperMapInv [6] = 'G';
		helperMapInv [7] = 'H';
		helperMapInv [8] = 'I';
		helperMapInv [9] = 'J';
		helperMapInv [10] = 'K';
		helperMapInv [11] = 'L';
		helperMapInv [12] = 'M';
		helperMapInv [13] = 'N';
		helperMapInv [14] = 'O';
		helperMapInv [15] = 'P';
		helperMapInv [16] = 'Q';
		helperMapInv [17] = 'R';
		helperMapInv [18] = 'S';
		helperMapInv [19] = 'T';
		helperMapInv [20] = 'U';
		helperMapInv [21] = 'V';
		helperMapInv [22] = 'W';
		helperMapInv [23] = 'X';
		helperMapInv [24] = 'Y';
		helperMapInv [25] = 'Z';
	}	
	
	int getIntFromHashMap(char a)
	{
		itr = helperMap.find(a);
		if ( itr == helperMap.end() )
			return -1;
		else 
			return itr->second;
	}
    
	char getCharFromHashMap(int a)
	{
		itrInv = helperMapInv.find(a);
		if ( itrInv == helperMapInv.end() )
			return '0';
		else 
			return itrInv->second;
	}
	
	public: 
	int convert(char a)
	{
		return getIntFromHashMap(a);
	}
	char convert(int a)
	{
		return getCharFromHashMap(a);
	}
};

hashMapClass mapObject;

void addVertex(vector <data> &nodesVec, int a, float x, float y)
{ 
	data d;
	d.node = a;
	d.x = x;
	d.y = y;
	nodesVec.push_back(d);
}

void addVertex(vector <data> &nodesVec, char e, float x, float y)
{
	int a = mapObject.convert(e);
	data d;
	d.node = a;
	d.x = x;
	d.y = y;
	nodesVec.push_back(d);
}

void display (int V, vector <data> &nodesVec)
{
	cout<<"All Nodes...\n";
	for (data x : nodesVec)
	{
		cout<<x.node<<" ";
	}
	cout<<endl;
}

void displayChars (int V, vector <data> &nodesVec)
{
	cout<<"All Nodes...\n";
	for (data x : nodesVec)
	{
		cout<<mapObject.convert(x.node)<<" ";
	}
	cout<<endl;
}

data lowerMostY(vector <data> &nodesVec)
{
	int lowermostY = INT_MAX;
	data lowermostNode;
	
	for (data x: nodesVec)
	{
		if (x.y < lowermostY)
		{
			lowermostY = x.y;
			lowermostNode = x;
		}
	}
	return lowermostNode;
}

float returnAngleBetweenPoints(data ancestralNode, data originNode, data nodeToCheck)
{
	// Find direction vector (terminal point - start point)
	// Plug into line 
	
	float dirVec1X = originNode.x - ancestralNode.x;
	float dirVec1Y = originNode.y - ancestralNode.y;
	
	float dirVec2X = nodeToCheck.x - originNode.x; 
	float dirVec2Y = nodeToCheck.y - originNode.y;
	
	float n1 = sqrt( pow(dirVec1X,2) + pow(dirVec1Y,2) );
	float n2 = sqrt( pow(dirVec2X,2) + pow(dirVec2Y,2) );
	
	float angle;
	angle = acos ( (dirVec1X*dirVec2X + dirVec1Y*dirVec2Y) / (n1*n2) );
	angle = angle * 180/ PI_F;
	
	if (angle < 0)
		angle = 360 + angle;
	
	return angle;
}

void JarvisMarch(int V, vector <data> &nodesVec)
{
	// Find lowermost OR leftmost point
	// I prefer lowermost for the example
	// So lowermost Y 
	
	// Then Find lowest angle keep iterating for all boudries. 
	// AND BOOM 
	
	bool *accountedFor;
	accountedFor = new bool[V];
	for(int i=0; i<V; i++)
		accountedFor[V] = false;
	
	data lowermostNode = lowerMostY(nodesVec);
	debug(2, "Lowermost Y: ", mapObject.convert(lowermostNode.node), "\n");
	
	data nodeInFocus = lowermostNode;
	data nextNode;
	float angle;
	
	// For the first node we have to emulate the horizontal axis
	data parentNode;
	parentNode.node = -1;
	parentNode.x = nodeInFocus.x - 1;
	parentNode.y = nodeInFocus.y;
	
	while (true)
	{
		angle = 360;
		debug(2, "Node in focus: ", mapObject.convert(nodeInFocus.node), "\n");
		for (data y: nodesVec)
		{
			if (accountedFor[y.node] == false && nodeInFocus.node != y.node && 
				returnAngleBetweenPoints(parentNode, nodeInFocus, y) < angle)
			{
				angle = returnAngleBetweenPoints(parentNode, nodeInFocus, y);
				
				debug(3,"Angle between ", mapObject.convert(nodeInFocus.node),
			 		" & ", mapObject.convert(y.node), " = ", angle, "\n");
				nextNode = y;
			}
		}
		if (LOG_LEVEL == 1)
			debug (1, mapObject.convert(nodeInFocus.node), "-", 
				mapObject.convert(nextNode.node), "\n");
		else
			debug (2, "Lowermost Angle between: ", mapObject.convert(nodeInFocus.node),
				"-", mapObject.convert(nextNode.node), "\n");
		
		accountedFor[nextNode.node] = true;
		parentNode = nodeInFocus;
		nodeInFocus = nextNode;
		
		if (nodeInFocus.node == lowermostNode.node)
			break;
	}
	
	delete [] accountedFor;
}

int main()
{
	// Resource ---
	// Basic Understanding
	// https://medium.com/@pascal.sommer.ch/a-gentle-introduction-to-the-convex-hull-problem-62dfcabee90c
	// https://brilliant.org/wiki/convex-hull/
	// 	
	// Youtube 
	// https://www.youtube.com/watch?v=Vu84lmMzP2o
	// 
	// GFG
	// https://www.geeksforgeeks.org/convex-hull-set-1-jarviss-algorithm-or-wrapping/
	// 
	// Angle Between two points
	// https://www.gamedev.net/forums/topic/318640-how-to-get-angle-between-two-points/
	// https://stackoverflow.com/questions/4294638/how-to-calculate-angle-between-two-direction-vectors-that-form-a-closed-open-sha
	// https://answers.unity.com/questions/1294512/how-vectorangle-works-internally-in-unity.html
	
	
	// Process
	// The process is fairly straight-forward
	// Find the lowermost/leftmost point in the graph (lowermost I chose)
	// Proceed from there
	// to find the next node on the boundry we find the node with the lowermost angle 
	//  when seen from the direction vector of our current node 
	
	// Complexity 
	// O ( nxh ) h being the number of nodes on the boundry
	
	// GRAPHS
	// Image 39 in directory	
	
	LOG_LEVEL = 1;
	
	hashMapClass map;
	
	int nodes = 12;
	
	vector <data> nodesVec; 
	
	addVertex(nodesVec, 'A', 0, -4);
	addVertex(nodesVec, 'H', 2, -3);
	addVertex(nodesVec, 'E', 3, -1);
	addVertex(nodesVec, 'G', 5, 1);
	addVertex(nodesVec, 'I', 4, 4);
	addVertex(nodesVec, 'F', 2, 3);
	addVertex(nodesVec, 'D', 0, 4.5);
	addVertex(nodesVec, 'C', -2, 2);
	addVertex(nodesVec, 'B', -3, 4);
	addVertex(nodesVec, 'J', -4, 1);
	addVertex(nodesVec, 'K', -2, -3);
	addVertex(nodesVec, 'T', 0, 0);
	
	if (LOG_LEVEL >= 1) displayChars(nodes, nodesVec);
	debug (1,"\n");
	
	debug(1, "Convex Hull: Jarvis March...\n");
	JarvisMarch(nodes, nodesVec);
}
