#include <iostream>
using namespace std;

void permutator(string, int ,int);

int main()
{
	int N = 3;
	string s = "abc";
	
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
	int i;
	i = first;
	char temp;
	while (i < size)
	{
		//cout<<"Swapping first ele "<<s[first]<<" with "<<s[i]<<" i being "<<i<<endl;
		temp = s[first];
		s[first] = s[i];
		s[i] = temp;
		permutator(s, size, first+1);	
		i++;
	}	
}
