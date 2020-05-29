#include <iostream>
#include <math.h>
#define N 9
using namespace std;

void output(int arr[N][N], int size);
bool soduSolve(int arr[N][N], int row, int col, int size);
bool isSafe(int arr[N][N], int row, int col, int size);

int main()
{
	int size = N;
	int i;
	
	int** arr;
	arr = new int*[size];
	for (i=0;i<size;i++)
	{
		arr[i] = new int[size];
	} 
	/*
	int array[9][9] = {
	{0,0,6, 0,0,2, 1,0,0},
	{0,0,8, 0,0,1, 0,7,0},
	{0,0,0, 3,7,0, 0,9,6},
	
	{0,0,0, 0,0,0, 0,4,8},
	{8,0,3, 0,0,0, 9,0,5},
	{2,4,0, 0,0,0, 0,0,0},
	
	{6,8,0, 0,5,7, 0,0,0},
	{0,3,0, 4,0,0, 6,0,0},
	{0,0,9, 8,0,0, 4,0,0}
	}; */
	int array[9][9] = {
	{0,1,0, 0,4,0, 0,0,8},
	{0,4,0, 0,0,0, 7,0,0},
	{0,0,0, 0,0,9, 0,3,4},
	
	{6,0,0, 2,0,0, 0,5,0},
	{8,0,2, 0,1,0, 3,0,9},
	{0,3,0, 0,0,8, 0,0,6},
	
	{1,2,0, 8,0,0, 0,0,0},
	{0,0,5, 0,0,0, 0,4,0},
	{4,0,0, 0,6,0, 0,8,0}
	};
	output (array, size);
	cout<<endl;
	
	if (soduSolve(array, 0, 0, size) == true)
	{
		system("CLS");
		output (array, size);	
	}
	else
	{
		system("CLS");
		cout<<"Unsolvable Soduku\n";
		output (array, size);
	}
		
	for (i=0;i<size;i++)
	{
		delete arr[i];	
	} 
	delete arr;
}

bool soduSolve(int arr[N][N], int row, int col, int size)
{
	int i,j,k,temp;
	
	if (col >= size)
	{
		//cout<<"ROW MODIFY"<<endl;
		row++;
		col=0;
	}
	if (row >= size)
		return true;
	
	i = row;
	j = col;
	if (arr[i][j] == 0)
	{
		for (k=1;k<=9;k++)
		{
			arr[i][j] = k;
			//cout<<"OUT-\n";
			//output (arr,size);
			//cout<<endl;
			if (isSafe(arr, i, j, size) == true)
			{
				//cout<<"IN-\n";
				//system("CLS");
				//output (arr,size);
				//cout<<endl;
				if (soduSolve(arr, i, j+1, size) == true)
				{
					return true;
				}	
			}
			arr[i][j] = 0;
		}
	}
	else
	{
		if (soduSolve(arr, i, j+1, size) == true)
		{
			return true;
		}	
		return false;
	}
	//cout<<"BACKTRACKING AT "<<row<<" "<<col<<"\n";
	return false;
}

bool isSafe(int arr[N][N], int row, int col, int size)
{
	// check row
	int i,j;
	for (int i=0;i<size;i++)
	{
		if (arr[row][i] == arr[row][col] && i != col)
			return false;
	}
	//check col
	for (int i=0;i<size;i++)
	{
		if (arr[i][col] == arr[row][col] && i != row)
			return false;
	}
	// check box 
	int rowStart, colStart;
	int e = N/sqrt(N);
	rowStart = row/e;
	colStart = col/e;
	//cout<<"----"<<rowStart<<" "<<colStart<<endl;
	//cout<<"---"<<e<<endl;
	for (i=rowStart*e; i<((rowStart*e)+e); i++)
	{
		for (j=colStart*e; j<((colStart*e)+e); j++)
		{
			if (arr[i][j] == arr[row][col])
			{
				if (row == i && col == j)
					continue;
		 		return false;
			}
		}
	}
	return true;
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
