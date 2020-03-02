// SET Bits are basically the number of 1's in its binary form
#include <iostream>
using namespace std;

int main ()
{
	int n = 13;// 1101
	n = 14; // 1110
	n = 12; // 1100
	int count = 0;
	
	while (n > 0)
	{
		if (n & 1 == 1)
			count ++;
		n = n >> 1;
	}
	cout<<count<<endl;
}
