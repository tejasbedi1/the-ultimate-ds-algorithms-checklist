#include <iostream>
using namespace std;

int main()
{
	int a = 2;
	int temp;
	int count = 0;
	int sum = 0;
	while (count<10)
	{
		temp = 0;
		for (int i=2;i<=a/2;i++)
		{
			if(a%i == 0)
			{
				temp = 1;
				break;
			}
		}
		if (temp != 1)
		{
			count++;
			sum = sum + a;
		}
		a++;
	}
	cout<<sum<<endl;
}

