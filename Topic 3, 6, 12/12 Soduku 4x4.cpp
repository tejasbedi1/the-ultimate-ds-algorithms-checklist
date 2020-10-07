#include <iostream>
#include <math.h>
#define N 4
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
	
	int array[4][4] = {
	{3,0,0,0},
	{0,1,0,0},
	{2,0,4,0},
	{0,0,0,2}};
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
	//cout<<row<<" "<<col<<endl;
	if (col >= size)
	{
		//cout<<"ROW MODIFY"<<endl;
		row++;
		col=0;
	}
	if (row >= size)
		return true;
	/*
	int flag = 0;
	for (i=0;i<size;i++)
		for (j=0;j<size;j++)
			if (arr[i][j] == 0)
				flag = 1;
	if (flag == 0)
		return true;
	*/
	i = row;
	j = col;
	if (arr[i][j] == 0)
	{
		for (k=1;k<=4;k++)
		{
			arr[i][j] = k;
			//cout<<"OUT-\n";
			//output (arr,size);
			//cout<<endl;
			if (isSafe(arr, i, j, size) == true)
			{
				//cout<<"IN-\n";
				system("CLS");
				output (arr,size);
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
	/*
	int temp;
	temp = arr[0][3];
	arr[0][3] = 4;
	if (isSafe(arr, 0, 3, size) == true)
		cout<<"Safe To Place\n";
	else
	{
		cout<<"Unsafe to place\n";
		arr[0][3] = temp;
	}
	*/
	//cout<<"BACKTRACKING AT "<<row<<" "<<col<<"\n";
	return false;
}

bool isSafe(int arr[N][N], int row, int col, int size)
{
	// check row
	int i,j;
	//cout<<"--Row\n";
	for (int i=0;i<size;i++)
	{
		if (arr[row][i] == arr[row][col] && i != col)
			return false;
	}
	//check col
	//cout<<"--Col\n";
	for (int i=0;i<size;i++)
	{
		if (arr[i][col] == arr[row][col] && i != row)
			return false;
	}
	// check box 
	// limits please
	//cout<<"--Box\n";
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
			//cout<<i<<" "<<j<<"\n";
			if (arr[i][j] == arr[row][col])
			{
				if (row == i && col == j)
					continue;
		 		return false;
			}
		}
		//cout<<endl;
	}
	return true;
}
/*
bool checkBox(int arr[N][N], int  )
{
	
}
/*/
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
