#include <iostream>
#include <stack>
using namespace std;

void reverse(string* st)
{
	stack <char> sk;
	int i=0,j=0;
	while (i < (*st).length())
	{
		if ((*st)[i] != ' ')
		{
			sk.push((*st)[i]);
		}
		else
		{
			while (j<i)
			{
				//cout<<sk.top()<<" ";
				(*st)[j] = sk.top();
				sk.pop();
				j++;
			}
			j++;
			//cout<<endl;
		}
		i++;
	}
	while(j<i)
	{
		//cout<<sk.top()<<" ";
		(*st)[j] = sk.top();
		sk.pop();
		j++;
	}
	//cout<<endl;
}

int main ()
{
	string st = "How the fuck are you today?";
	cout<<st<<endl;
	reverse(&st);
	cout<<st;
}
