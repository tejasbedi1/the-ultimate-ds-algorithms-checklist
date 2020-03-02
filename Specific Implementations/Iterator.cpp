#include <iostream>
#include <iterator>
#include <set>
#include <vector>
using namespace std;

void withVector();
void withSet ();

int main ()
{
	//withVector();
	withSet ();	
}

void withSet ()
{
	set<int> s;	
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
}

void withVector()
{
	vector<int> v = {1,2,3,4,5};

	for (int j=0;j<5;j++)
		cout<<v[j]<<" ";
	cout<<endl<<endl;
	
	vector<int> :: iterator i;
	// begin and end
	for (i = v.begin(); i != v.end(); i++)
		cout<<*i<<" ";
	cout<<endl<<endl;
	
	// advance 
	i = v.begin();
	advance(i,3);
	cout<<*i<<" ";
	cout<<endl<<endl;
	
	//next prev
	vector<int> :: iterator f = v.begin();
	vector<int> :: iterator g = v.end();
	
	vector<int> :: iterator it1 = next(f,3);
	vector<int> :: iterator it2 = prev(g,3);
	cout<<"it1 and it2 are: "<<*it1<<" "<<*it2<<endl;
	cout<<endl;
	
	// inserter
	vector <int> ar = {10,20};
	i = v.begin();
	advance(i,2);
	copy (ar.begin(), ar.end(), inserter(v,i));
	for (i = v.begin(); i != v.end(); i++ )
		cout<<*i<<" ";
	cout<<endl<<endl;
}
