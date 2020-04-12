#include <iostream>
#include <string.h>
using namespace std;
struct data
{
	int no;
};

void dop(char *c)
{
	cout<<c<<endl;
	c = "polo";
	cout<<c<<endl;
}
void dis(char **c)
{
	cout<<*c<<endl;
	cout<<&*c<<endl;	
	
	cout<<*c<<endl;
	*c = "dolo";
	cout<<*c<<endl;
}

void pp(char *c)
{
	//char p[2] = 'Y';
	//stcpy(c, p);
	//char *cp = "Y\0t";
	char cp[] = "N\0";
	//sprintf(c,"%c", cp);
	//&c = cp;
	strcpy(c, cp);
	cout<<c<<endl;
	
	//cout<<*c<<endl;
}
int main()
{
	//char *c = "yolo";
	//cout<<&c<<endl;
	//dis(&c);
	//cout<<c<<endl;
	char cf[2];
	cout<<cf<<endl;
	pp(cf);
	cout<<cf<<endl;
}
