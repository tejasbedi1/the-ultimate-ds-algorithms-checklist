#include<iostream>
using namespace std;

void tower(int n, char from_rod, char aux_rod, char to_rod)
{
	if (n == 1)
		cout<<"Moving Disk "<<n<<" from rod "<<from_rod<<" to rod "<<to_rod<<endl;
	else 
	{
		tower (n-1,from_rod, to_rod, aux_rod);
		cout<<"Moving Disk "<<n<<" from rod "<<from_rod<<" to rod "<<to_rod<<endl;
		tower (n-1,aux_rod, from_rod, to_rod);
	}
}
int main()
{
    int n = 4;
    tower(n,'A','B','C');
	return 0;	
}
