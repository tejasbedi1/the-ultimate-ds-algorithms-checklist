#include<iostream>

using namespace std;

void changer0(int a)
{
	a = 5;
	cout<< "A inside function is "<<a<<endl;
}
void changer1(char input[])
{
	int i = 0;
    while (input[i] != '\0')
    {
    	input[i] = 'x';
    	i++;
	}
	cout<< "Inside function char is "<<input<<endl;	
}
void changer2(int b[5])
{
	int i = 0;
	cout<<"Our int array inside the func is - \n";
	b[3] = 33;
	for (i=0;i<5;i++)
	{
		cout<< b[i]<<" ";
	}
	cout<<endl;
}
// The confusion here is that, if we pass a array as argument, if the function 
// alters the array in any way, the array chamges for the whole program
// However if we use single integers etc.. the we need to use the concept of 
// pass by value OR reference

int main()
{
	int a = 11;
	cout<< "A is currently "<<a<<endl;
	changer0(a);
	cout<< "A in main after running func is "<<a<<endl;
	
    cout<<"------------------------------------"<<endl;
	
	char input[100] = "xpiypihpip";
    cout<<"Our character inside main is - "<<input<<endl;
    changer1(input);
    cout<<"Our character after rnning func is -"<<input<<endl;

	cout<<"------------------------------------"<<endl;
	
	int b[5] = {1,2,3,4,5};
	cout<<"Our int array inside main is - \n";
	for (int i=0;i<5;i++)
	{
		cout<< b[i]<<" ";
	}
	cout<<endl;
	changer2(b);
	cout<<"Our int array after running func is - \n";
	for (int i=0;i<5;i++)
	{
		cout<< b[i]<<" ";
	}
	cout<<endl;
}
