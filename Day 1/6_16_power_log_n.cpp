#include <iostream>

using namespace std;

int calcPower (int x, int y)
{
	int temp;	
	if (y == 1)
		return x;
	temp = calcPower (x, y/2);
	if (y%2 == 0)
		return temp * temp;
	else 
		return x*temp*temp;
}

int calcPower2 (int x, int y)
{
	int temp;
	if (y == 1)
		return x;
	temp = calcPower2 (x, y/2);
	if (y%2 == 0)
		return temp * temp;
	else 
		return x * temp * temp;
}

int calcPower3 (int x, int y)
{
	if (y == 1)
		return x;	
	int temp = 0;
	if (y%2 == 0)
	{
		x = x*x;
		y = y/2;
		return calcPower3(x,y);
	}
	else
	{
		temp = x;
		x = x*x;
		y = y/2;
		return calcPower3(x,y) * temp;
	}
}

int main ()
{
	cout << calcPower2(4,13) <<endl;
	cout << calcPower3(4,13);
}
