#include <iostream>
using namespace std;

void reverse(string* st)
{
	(*st)[0]= 'T';
	cout<<*st<<endl;
}

int main ()
{
	string st = "How the fuck are you today?";
	reverse(&st);
	cout<<st;
}
