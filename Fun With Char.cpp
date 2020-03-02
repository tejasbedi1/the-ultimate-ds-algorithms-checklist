#include <iostream>

using namespace std;

int main()
{
	int N = 4;
	char c[] = "abc"; 
	
	cout<<c<<endl;
	cout<<c[0]<<endl;
	cout<<c[2]<<endl;
	c[0] = c[2];
	cout<<c[0]<<endl;
}

// IMPLEMENTATON GIVEN BWLOW CAUSES A SEGMENTATION FAULT CAUSE
// C IS A POINTER TO A STRING 
// SO IT CAN POINT TO SOMETHING OR SOMETHING ELSE
// BUI BE CANT CHANGE THE STRING THEN 
/*
int main()
{
	int N = 3;
	char* c = new char[N];
	c = "abc"; 
	char temp;
	
	cout<<c<<endl;
	cout<<c[0]<<endl;
	cout<<c[2]<<endl;
	temp = c[2];
	c[0] = 'z';
	//c[0] = c[2];
	cout<<c[0]<<endl;
}
*/
