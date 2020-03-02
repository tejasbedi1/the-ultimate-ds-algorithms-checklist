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
	float angle;
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

void displayAngle (int V, vector <data> &nodesVec)
{
	for (data x : nodesVec)
	{
		cout<<mapObject.convert(x.node)<<": "<<x.angle<<endl;
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

int orientation(data &p, data &q, data &r) 
{ 
	// cross product
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) 
		return 0;  // colinear 
		
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 

float returnAngleBetweenPoints(data &ancestralNode, data &originNode, data &nodeToCheck)
{
	// Find direction vector (terminal point - start point)
	// Plug into line 
	
	float dirVec1X = originNode.x - ancestralNode.x;
	float dirVec1Y = originNode.y - ancestralNode.y;
	
	float dirVec2X = nodeToCheck.x - originNode.x;
	float dirVec2Y = nodeToCheck.y - originNode.y;
	
	float angle;
	
	float n1 = sqrt( pow(dirVec1X,2) + pow(dirVec1Y,2) );
	float n2 = sqrt( pow(dirVec2X,2) + pow(dirVec2Y,2) );
	
	angle = acos ( (dirVec1X*dirVec2X + dirVec1Y*dirVec2Y) / (n1*n2) );
	angle = angle * 180/ PI_F;
	
	// Check if the node is on the right or left of our line between the two 
	//  confirmed points
	
	int orient;
	orient = orientation(ancestralNode, originNode, nodeToCheck);
	if (orient == 0)
		debug(2, "Points Collinear...\n");
	else if (orient == 1)
		angle = angle * -1;
	else if (orient == 2) 
	 	angle = angle;
	 	
	return angle;
}

struct comparison
{
	bool operator () (data &x, data &y)
	{
		return x.angle < y.angle;
	}
};

void GrahamScan(int V, vector <data> &nodesVec)
{
	// Find lowermost OR leftmost point
	// I prefer lowermost for the example
	// So lowermost Y 
	
	// Then Find angles with every node and sort it.
	// Store those sorted details in a stack
	// While iterating through the nodes see no outward edge is forming
	
	// ASSIGN INITIAL ANGLES 
	int i;
	
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
	
	// Calculating and storing angle
	debug(3, "Node in focus: ", mapObject.convert(nodeInFocus.node), "\n");
	for (i=0; i<nodesVec.size(); i++)
	{
		angle = returnAngleBetweenPoints(parentNode, nodeInFocus, nodesVec[i]);
		debug (3, "Angle between ", mapObject.convert(nodeInFocus.node), " & ",
			mapObject.convert(nodesVec[i].node), ": ", angle, "\n");
		nodesVec[i].angle = angle;
	}
	nodesVec[nodeInFocus.node].angle = 0;
	
	debug (2, "Showing Set Angles...\n");
	if (LOG_LEVEL >= 2) displayAngle(V, nodesVec);
	
	sort(nodesVec.begin(), nodesVec.end(), comparison());
	debug(2, "After Sorting Vector Array...\n");
	if (LOG_LEVEL >= 2) displayAngle(V, nodesVec);
	
	// Now take the first 3 and start moving acroos the boundry
	// Will use a, parent,
	//  a nodeInFocus ~ the connection between parent and nodeInFocus is confirmed,
	//  q nextNode ~ checking of the next point will be done in comparison to this node
	parentNode = nodesVec[0];
	nodeInFocus = nodesVec[1];
	i = 2;
	data tempNode;
	while (true)
	{
		debug (1, "Path: ", mapObject.convert(parentNode.node), "-",
			mapObject.convert(nodeInFocus.node), "\n");
		
		nextNode = nodesVec[i];
		while (true)
		{
			debug (2, "Next node: ", mapObject.convert(nextNode.node), "\n");
			
			i++;
			tempNode = nodesVec[i];
			debug (2, "Next to next node: ", mapObject.convert(tempNode.node), 
				"\n");
		
			angle = returnAngleBetweenPoints(nodeInFocus, nextNode, tempNode);	
			debug (2, "Angle: ", angle, "\n");
			
			if (angle >= 0)
				break;
			else 
			{
				debug (2, "Angle is negaive ", mapObject.convert(nodeInFocus.node), "-",
					mapObject.convert(nextNode.node), 
						" will not be able to make a boundry\n");
				nextNode = tempNode;
			}
			
			if (nextNode.node == lowermostNode.node)
				break;
		}
		parentNode = nodeInFocus;
		nodeInFocus = nextNode;
		debug (2, "\n");
		if (nextNode.node == lowermostNode.node)
		{
			debug (2, "Reached the starting node...\n");
			debug (1, "Path: ", mapObject.convert(parentNode.node), "-",
				mapObject.convert(nodeInFocus.node), "\n");
			break;
		}
	}
	delete [] accountedFor;
}

int main()
{
 	// LIMITAION (1)
 	// There is a condition which is required to be followed when 
 	// 	sorting nodes by angle.
 	//  If two nodes have the same angle the closer one is kept first then the
 	// 	further one is added to the stack/ vector array. 
 	// I havnn't added this condition
 	// LIMITAION (2)
 	// we dont actually need to calculate the exact angles 
 	//  we just need to see if the next point is inward/left or outward/right 
 	//  to the line being currently formed
 	
	// Resource
	// Revise Jarvis march first
	//
	// https://brilliant.org/wiki/convex-hull/
	// https://www.geeksforgeeks.org/convex-hull-set-2-graham-scan/
	// 
	// Math resources
	// https://stackoverflow.com/questions/1560492/how-to-tell-whether-a-point-is-to-the-right-or-left-side-of-a-line
	// Angle Between two points
	// https://www.gamedev.net/forums/topic/318640-how-to-get-angle-between-two-points/
	// https://stackoverflow.com/questions/4294638/how-to-calculate-angle-between-two-direction-vectors-that-form-a-closed-open-sha
	// https://answers.unity.com/questions/1294512/how-vectorangle-works-internally-in-unity.html
	
	// Process
	// Start from the lower most node in graph. Why ? Its easy to imagine the 
	// 	boundry from there. (Explained more in the actual function)
	// 
	// We will calculate the angle made to all the nodes from the started node
	//  Store this information in a stack or array in a sorted manner. (smallest first)
	// 
	// The starter node and the node with the lowermost angle are fixed they 
	//  will definetly make a boundry. 
	// Analyze the next node. If the next node makes a positive angle with the 
	//  next to next node that would mean that our next node is outward hence will
	//  make a boundry. 
	// IF te next node makes a negative angle with the next to next node that would mean 
	//  the next to next node will make a better boundry as the next node is more inward
	//  than the next to next node 
	// (SUCH EXPLANATION xD)
	// Continue this until we reach the starting node
	
	// Complexity 
	// O (V LogV) (Slowest part is the sorting)
	
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
	
	debug(1, "Convex Hull: Graham Scan...\n");
	GrahamScan(nodes, nodesVec);
}
