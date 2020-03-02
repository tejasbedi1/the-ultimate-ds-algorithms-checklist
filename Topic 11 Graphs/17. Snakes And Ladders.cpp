#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Graph
{
private:
	
	int V;
	int i;
	struct block
	{
		int pos;
		int nxtPos;
		int dist;
		int diceVal;		
	};	
	block *blockArr;
	queue <block> blockQue;
	
public:
		
	Graph(int V)
	{
		this->V = V;
		blockArr = new block[V+1];
	}
	
	void init()
	{
		for(i = 1; i <= V; i++)
		{
			blockArr[i].pos = i;
			blockArr[i].nxtPos = i+1;
			blockArr[i].dist = -1;
			blockArr[i].diceVal = -1;
		}
		blockArr[1].pos = 1;
		blockArr[1].nxtPos = 2;
		blockArr[1].dist = 0;
		blockArr[1].diceVal = 0;
		
		blockArr[30].nxtPos = 30;
	}
	
	void setSpecific(int a, int b)
	{
		blockArr[a].nxtPos = b;
	}
	
	void snakesAndLaddersBaby()
	{
		int currBlock = 1;
		int dist;
		
		blockQue.push( blockArr[currBlock] );
		while (!blockQue.empty())
		{
			currBlock = blockQue.front().pos;
			dist = blockQue.front().dist;
			cout<<"Analyzing "<<currBlock<<endl;
			for (i = 1; i <= 6 && currBlock+i <= 30; i++)
			{
				// If no snake or ladder
				if ( blockArr[currBlock+i].nxtPos == blockArr[currBlock+i].pos + 1)
				{
					if ( dist+1 < blockArr[currBlock+i].dist || 
							blockArr[currBlock+i].dist == -1 )
					{
						blockArr[currBlock+i].dist = dist + 1;
						blockArr[currBlock+i].diceVal = i;
						blockQue.push(blockArr[currBlock+i]);	
					}
				}
				// Ladder 
				else if (blockArr[currBlock+i].nxtPos > blockArr[currBlock+i].pos + 1)
				{
					if ( dist+1 < blockArr[ blockArr[currBlock+i].nxtPos ].dist || 
							blockArr[ blockArr[currBlock+i].nxtPos ].dist == -1 )
					{
						blockArr[ blockArr[currBlock+i].nxtPos ].dist = dist + 1;
						blockArr[ blockArr[currBlock+i].nxtPos ].diceVal = i;
						blockQue.push(blockArr[ blockArr[currBlock+i].nxtPos ]);	
					}
				}
				// Snake 
				else if (blockArr[currBlock+i].nxtPos < blockArr[currBlock+i].pos + 1)
				{
					if ( dist+1 < blockArr[ blockArr[currBlock+i].nxtPos ].dist || 
							blockArr[ blockArr[currBlock+i].nxtPos ].dist == -1 )
					{
						blockArr[ blockArr[currBlock+i].nxtPos ].dist = dist + 1;
						blockArr[ blockArr[currBlock+i].nxtPos ].diceVal = i;
						blockQue.push(blockArr[ blockArr[currBlock+i].nxtPos ]);	
					}
				}
			}
			blockQue.pop();
			//displayQueue();
			//display();
			//break;
		}
	}
	
	void displayQueue()
	{
		cout<<"Displaying Queue..\n";
		queue <block> que = blockQue;
		while (!que.empty())
		{
			cout<< que.front().pos<<endl;
			que.pop();
		}
	}
	
	void display()
	{
		for (i = 1; i <= V; i++)
		{
			cout<<"Pos: "<<blockArr[i].pos<<", NextPos: "<<blockArr[i].nxtPos
				<<", Dist: "<<blockArr[i].dist<<", DiceValue: "<<blockArr[i].diceVal;
			cout<<endl;
			//if (blockArr[i].dist == -1)
			//	break;
		}
	}
	
	void deallocate()
	{
		delete [] blockArr;
	}
};

int main()
{
	// Resources
	// https://www.google.com/search?rlz=1C1CHZL_enIN739IN739&sxsrf=ACYBGNRjGprtH67UzL8FynYlMily7moQIw%3A1571468772621&ei=5LWqXfy_JYXsvgTc2JuQCQ&q=snakes+and+ladders+algorithm+c%2B%2B&oq=snakes+and+ladders+algorithm+c%2B%2B&gs_l=psy-ab.3..33i22i29i30l10.4114.6689..6948...0.2..1.567.3494.0j5j4j1j2j1......0....1..gws-wiz.......0i71j0i67j0j0i22i30.1ARHi_qmY_I&ved=0ahUKEwj8wd6v4aflAhUFto8KHVzsBpIQ4dUDCAs&uact=5
	// https://www.geeksforgeeks.org/snake-ladder-problem-2/
	// PIC : https://media.geeksforgeeks.org/wp-content/uploads/snake-and-ladders.jpg
	
	// Process
	// Keep adding blocks to a queue 
	// After updating disances of the reachable blocks
	// Add them to queue
	// Eventually everyone of the blocks will get added to queue and processed
	// Leaving us with the min distance on the last block
	
	int nodes = 30;
	
	Graph graph(nodes);
	
	graph.init();
	
	graph.setSpecific(3,22);
	graph.setSpecific(5,8);
	graph.setSpecific(20,29);
	graph.setSpecific(11,26);
	
	graph.setSpecific(27,1);
	graph.setSpecific(21,9);
	graph.setSpecific(17,4);
	graph.setSpecific(19,7);
	
	graph.snakesAndLaddersBaby();
	
	graph.display();
	
	graph.deallocate();
}

