#include <iostream>
using namespace std;

void permutator(string, int ,int);

int main()
{
	int N = 3;
	string s = "aba";
	
	cout<<s<<endl<<endl;
	permutator(s, N, 0);
}

void permutator(string s, int size, int first)
{
	if (first == size-1)
	{
		cout<<s<<endl;
		return;
	}
	int i,flag,j;
	i = first;
	char temp;
	while (i < size)
	{
		flag = 0;
		if (i != first)
		{
			for (j=first;j<size;j++)
			{
				if (first != j)
				{
					//cout<<"Checking "<<s[first]<<" "<<s[j]<<" AT "<<first<<","<<j<<endl;
					if (s[first] == s[j])
						flag = 1;
				}
			}
		}
		//if (s[first] != s[i] || i == first)//s[first] != s[i]
		//if (true)
		if (flag = 0)
		{
			temp = s[first];
			s[first] = s[i];
			s[i] = temp;
			permutator(s, size, first+1);	
		}
		i++;
	}	
}
