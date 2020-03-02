#include <iostream>
#include <set>
using namespace std;

void eraser(set <int>);

int main ()
{
	set<int> s;	
	s.insert(6);
	s.insert(5);
	s.insert(2);
	s.insert(3);
	s.insert(3);
	s.insert(4);
	s.insert(1);
	
	set<int> :: iterator i;
	for (i = s.begin(); i != s.end(); i++)
		cout<<*i<<" ";
	cout<<endl<<endl;
	
	set<string> st;
	st.insert("abc");
	st.insert("acb");
	st.insert("acb");
	st.insert("bac");
	set<string> :: iterator j;
	for (j = st.begin(); j != st.end(); j++)
		cout<<*j<<" ";
	cout<<endl<<endl;
	
	auto k = st.emplace("abc");
	if (k.second == false)
		cout<<"Already exists\n\n";
	eraser(s);
}

void eraser(set<int> s)
{
	cout<<"Calling Eraser xD\n";
	set<int> :: iterator i;
	// Erase 3
	s.erase(3);
	for (i = s.begin(); i != s.end(); i++)
		cout<<*i<<" ";
	cout<<endl<<endl;
	
	// Erase first ele 
	i = s.begin();
	s.erase(i); 
	
	for (i = s.begin(); i != s.end(); i++)
		cout<<*i<<" ";
	cout<<endl<<endl;
	
	// Erase second to last
	i = s.begin();
	advance(i,2);
	s.erase(i,s.end());
	for (i = s.begin(); i != s.end(); i++)
		cout<<*i<<" ";
	cout<<endl<<endl;
}
