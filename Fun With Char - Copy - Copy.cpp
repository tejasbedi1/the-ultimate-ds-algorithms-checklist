#include <iostream>
#include <string.h>
using namespace std;


struct data
{
	int no;
	char cf[5][2];
};

void poof(char *c)
{
	strcpy (c, "yolo");
	
}
int main()
{
	data *d;
	
	cout<<d->no<<endl;
	//d = new data;
	d = (data*)malloc (sizeof(data));
	
	d->no = 5;
	//strcpy(d->cf, "yolo");
	poof (d->cf[0]);
	
	cout<<d->no<<endl;
	cout<<d->cf[0]<<endl;
}
