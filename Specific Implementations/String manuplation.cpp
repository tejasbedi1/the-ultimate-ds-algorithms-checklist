#include <stdio.h>
#include <string.h>


int add(char *c)
{
	char temp[100];
	sprintf(temp,"XX,");
	strcat(c, temp);
}

int end(char *s)
{
	/*
	int d = strlen(c);
	printf("LEN: %d\n",d);
	c[d-1] = '\0';
	d = strlen(c);
	printf("LEN: %d\n",d);
	strcat(c,"}");
	*/
	int len = strlen(s);
	s[len-1] = '}'; for 
}

int main()
{
	char c[100];
	c[0]='\0';
	
	strcat(c, "{");
	printf("<%s>\n",c);
	add(c);
	printf("<%s>\n",c);
	add(c);
	end(c);
	printf("<%s>\n",c);
}
