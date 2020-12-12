#include<iostream>
using namespace std;

void replacePi_v2(char input[],int i)
{
	// count number of pi's 
	// go to the end by finding required more space;
	// start moving backard from there
	int count=0, control=0;
	while (input[i+1] != '\0')
    {
    	if (input[i] == 'p' && input[i+1] == 'i')
    	{
    		count ++;
		}
		i++;
	}
	cout<<count<<endl;
	
	cout<<"Required Extra space is 2 more for every count\n";
	control = i;
	cout<<"Current Length: "<<i<<" at "<<input[i]<<endl;
	i = i + 2*count;
	cout<<"Required Length: "<<i<<endl;
	
	input[i+1] = NULL;	// Just in case
	
	while (i >= 0)
	{
		if (i>0 && input[control] == 'i' && input[control-1] == 'p')
		{
			input[i] = '4';
			input[i-1] = '1';
			input[i-2] = '.';
			input[i-3] = '3';
			i = i-4;
			control = control-2;
		}
		else
		{
			input[i] = input[control];
			i = i-1;
			control = control-1;
		}
		//cout<<input[i]<<" ";
		//i--;
	}
	cout<<endl;
	return;
}

int main()
{
    char input[100] = "xpiypihpip";
    //char input[100] = "xpip";
    cout<<input<<endl;
    replacePi_v2(input,0);
    
    cout<<input<<endl;

	return 0;	
}
