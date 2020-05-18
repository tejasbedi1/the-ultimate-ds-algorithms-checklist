#include <iostream>
using namespace std;

bool isSafe(int** arr, int row, int col, int size);
bool solvNqueen(int** arr, int col, int size);
void output(int** arr, int size);

int main()
{
	// Resource
	// 
	
	int size = 4;
	int row, col, i;
	row = col = size;
	
	int **arr = new int*[col];
	for (i=0;i<size;i++)
	{
		arr[i] = new int[row];
	}
	// Assign 0 to everything
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			arr[i][j]=0;
		}
	}	
	//arr[0][0] = 1;
	output(arr, size);
	cout<<endl;
	if (solvNqueen(arr, 0, size) == true)
		output(arr, size);
	else
		cout<<"It cant be done, good day;)\n";
		
	for(int i=0; i<size; i++)
	{
    	delete arr[i];
	}
	delete arr;
}

bool solvNqueen(int** arr, int col, int size)
{
	int i;
	if (col == size)
		return true;
	for (i=0;i<size;i++)
	{
		if (isSafe(arr, i, col, size) == true)
		{
			arr[i][col] = 1;	
			if ( solvNqueen(arr, col+1, size) == true)
				return true;
			arr[i][col] = 0;
		}	
	}
	//output(arr, size);
	return false;
}

bool isSafe(int** arr, int row, int col, int size)
{
	int i,j;
	for (i=0;i<size;i++)
	{
		if (arr[row][i] == 1)
			return false;
	}
	// Upper LEFT
	for (i=row, j=col; i>=0 && j>=0; i--,j--)
	{
		if (arr[i][j] == 1)
			return false;
	}
	// lower Left 
	for (i=row, j=col; i<size && j>=0; i++,j--)
	{
		if (arr[i][j] == 1)
			return false;
	}
	return true;
}

void output(int **arr, int size)
{
	for (int i=0; i<size; i++)
	{
		for (int j=0; j<size; j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}	
}
