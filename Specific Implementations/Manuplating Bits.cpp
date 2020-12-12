#include <bits/stdc++.h>      
using namespace std; 

int countSetBits(int n) 
{ 
int count = 0; 
while (n) 
{ 
    count += n & 1; 
    n >>= 1; 
} 
return count; 
} 
void test()
{
	int n = 13;
	// 13 0000 1101
	n =  n << 1;
	cout<<n<<endl;
	n = 13;
	n = n >> 1;
	cout<<n<<endl;
	n = 15;
	int count=0;
	while (n > 0)
	{
		count += n & 1;
		n = n >> 1; 
	}
	cout<<count<<endl;
}
int main() 
{ 
    int i = 13; 
    test();
    //cout << countSetBits(i); 
    return 0; 
} 
