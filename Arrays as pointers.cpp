#include <iostream>
using namespace std;

void show1D(int *arr,int size)
{
	for (int i=0;i<size;i++)
	{
		cout<<arr[i]<<endl;
	}
}

void show2D(int **arr,int col, int row)
{
	for (int i=0;i<col;i++)
	{   
		for (int j=0;j<row;j++)
		{
			cout<<arr[i][j]<<" ";	
		}
		cout<<endl;
	}
}

int main()
{
	int size = 4;
	
	int *arr = new int[size];
	for (int i=0;i<size;i++)
	{
		arr[i]=i;
	}
	show1D(arr,size);
	
	//int array[4][4];
	int row,col;
	row = col = size;
	
	int ** array = new int*[col];
	for(int i=0; i<row ; i++)
	{
 		array[i] = new int[row];
	}
	
	for (int i=0; i<col; i++)
	{
		for (int j=0; j<row; j++)
		{
			array[i][j]=j;
		}
	}
	show2D(array,col,row);
	for(int i=0; i<row; i++)
	{
    	delete array[i];
	}
}
