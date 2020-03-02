#include <iostream>
#include <map>
using namespace std;


int main ()
{
	map <string, string> mp;
	
	mp.insert({"a","abc"});
	mp.insert({"b","bac"});
	mp.insert({"c","cab"});
	
	map <string, string> :: iterator it;
	cout<<"KEY\tVALUE\n";
	for(it = mp.begin(); it != mp.end(); it++)
	{
		cout<<it->first<<"\t"<<it->second<<endl;
	}
	
	it = mp.find("c");
	cout<<it->first<<"\t"<<it->second<<endl;
	
}
