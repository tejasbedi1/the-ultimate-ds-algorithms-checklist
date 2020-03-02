#include <iostream>

using namespace std;
/*
int main ()
{
	int a=0, b=0, c=2, d;
	
	a = 1;
	a = b = c;
	
	cout<<a<<" "<<b<<" "<<c<<endl;
	
	a = 0,b = 0;
	c = (a,b = 1,2),3,4;
	cout << a<<" "<<b<<" "<<c<<endl;
	
	a = b = c = d = 0;
	d = (a=1,b=2,c=3,4);
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	
	a = b = c = 0;
	(a =1,b=2,c=3);
	cout<<a<<" "<<b<<" "<<c<<endl;
}
*/

int main ()
{
	static int a=4, b=0, c=0, d=0; 
	/*
	printf ("%d",a--);
	if (a)
		main();
	*/
	char str[100];
	//scanf("%[^\n]s",&str);
	scanf("%[^\t]s",&str);
	printf("%s",str);
	
}
