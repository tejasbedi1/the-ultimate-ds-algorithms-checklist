#include <stdio.h>

void calc(int a,int* ans, int* size)
{
	int i,s,temp,carry;
	ans[0] = 1;
	*size = 1;

	while (a>1)
	{
		carry = 0;
		s = *size;
		
		for (i=0;i<s;i++)
		{	
			temp = a * ans[i];	
			temp = temp + carry;
			
			carry = temp/10;
			temp = temp%10;
			
			ans[i] = temp;
		}		
		if (carry > 0)
		{	
			while (carry > 0)
			{
				*size = *size+1;
				ans[*size-1] = carry%10;
				carry = carry/10;
			}
		}
		a--;
	}
}

int main ()
{
	int a;
	int ans[40000], size=0;
	
	printf("Number. Please..\n");
	scanf("%d",&a);
	
	calc (a,ans,&size);
	
	printf("\nOUTPUT..\n");
	for (int i=size-1;i>=0;i--)
		printf("%d",ans[i]);
	printf("\nNumber of DIGITS- %d",size);
}
