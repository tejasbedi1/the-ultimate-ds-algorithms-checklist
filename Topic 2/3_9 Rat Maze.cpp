#include <iostream>
#include <math.h>
#define N 5
using namespace std;

bool mazeSolve(int arr[N][N],int ans[N][N], int x, int y, int size);
void output(int arr[N][N], int size);

int main()
{
	int i,j,size = N;
	
	int** arr;
	arr = new int*[N];
	for (i=0;i<size;i++)
	{
		arr[i] = new int[N];
	}
	
	/*int array[N][N] = {
	{1,0,1,1,1},
	{1,1,1,0,1},
	{1,0,0,1,1},
	{1,0,0,1,0},
	{1,0,0,1,1},
	};*/
	int array[N][N] = {
	{1,0,1,1,1},
	{1,1,1,0,0},
	{1,0,1,1,1},
	{1,0,0,0,0},
	{1,1,1,1,1},
	};
	int ans[N][N] = {
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	{0,0,0,0,0},
	};
	output (array, size);
	cout<<endl;
	mazeSolve(array, ans, 0, 0, size);
	output (ans, size);
	for (i=0;i<size;i++)
	{
		delete arr[i];
	}
	delete arr;
}

bool mazeSolve(int arr[N][N],int ans[N][N], int x, int y, int size)
{
	//output(arr, size);
	//cout<<endl;
	output(ans, size);
	cout<<endl;
	
	ans[x][y] = 1;
	if ( x== size-1 && y == size-1)
		return true;
	//cout<<"Currently at "<<x<<" "<<y<<endl;
	// Right
	if (y+1 < size && arr[x][y+1] == 1 && ans[x][y+1] == 0)
		if (mazeSolve(arr, ans, x, y+1, size) == true)
			return true;
	// Down
	if (x+1 < size && arr[x+1][y] == 1 && ans[x+1][y] == 0)
		if (mazeSolve(arr, ans, x+1, y, size) == true)
			return true;
	// Left
	if (y-1 >= 0 && arr[x][y-1] == 1 && ans[x][y-1] == 0)
		if (mazeSolve(arr, ans, x, y-1, size) == true)
			return true;
	// Up
	if (x-1 >= 0 && arr[x-1][y] == 1 && ans[x-1][y] == 0)
		if (mazeSolve(arr, ans, x-1, y, size) == true)
			return true;
	
	ans[x][y] = 0;
	cout<<"Backtracking\n";
	return false;
}

void output (int arr[N][N], int size)
{
	int i,j;
	for (i=0;i<size;i++)
	{
		for (j=0;j<size;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}
