// SEQUENCES SHOULD BE IN ORDER
#include<iostream>
using namespace std;

void substringRecur (char input[], int start, int end, char out[])
{
	if (start > end)
		return;
		
	int i,j,k;
	for (i=start;i<=end;i++)
	{
		k = 0;
		for (j=start;j<=i;j++)
		{
			out[k] = input[j];
			k++;
		}
		out[k] = '\0';	
		cout<<out<<endl;
	}
	substringRecur (input, ++start, end, out);
}

void substrings(char input[])
{
	int i=0;
	while (input[i] != '\0')	{
		i++;
	}
	char out[100];
	substringRecur(input, 0, i-1,out);
}

int main()
{
    char input[100] = "abcd";
    
    cout<<input<<endl<<endl;
    substrings(input);
    
}
