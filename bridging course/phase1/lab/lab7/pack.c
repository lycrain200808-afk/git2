//pack.c  
// pack string with only alphabets

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void process (char*);

int main()
{
    char string[100];

    printf("Enter a string of not more than 99 characters: ");
    gets(string);
	printf ("The length of string before packing is %d\n", strlen (&string[0]) );
	process (string);
    printf("Packed String: %s\n",string);
	printf ("The length of string after packing is %d\n", strlen (&string[0]) );

    return 0;
}

void process (char s[])
{	
	for (int i=0;i<strlen(s);i++)
	{
		if (!isalpha(s[i]) )
		{	
			int j,index;
			for (j=i+1;j<strlen(s);j++)
			{
				if(isalpha(s[j])) 
				{
					s[i]=s[j];
					index=j;
					break;
				}
			}
			for (int m=i+1;m<strlen(s)-(index-i);m++)
			{
				s[m]=s[++j];
			}
			s[strlen(s)-(index-i)]='\0';
		}
	}	
}