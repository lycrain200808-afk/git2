#include <stdio.h>
#include <string.h>
int main(){
	char alpha[27]={'a','b','c','d','e','f','g','h',
					'i','j','k','l','m','n','o','p',
					'q','r','s','t','u','v','w','x',
					'y','z'};
	char s[202];
	char this1;
	int num,i,j;
	int is_alpha,index_1;
	
	printf("Type a sentence and press enter key: ");
	fgets(s,sizeof(s),stdin);
	printf("\n Alphabet    Frequency\n\n");
	printf("=======================");
	for (i=0 ; i<26 ; i++)
	{	
		is_alpha=0;
		for (j=0 ; j<strlen(s) ; j++)
		{
			if (s[j]==alpha[i])
			{
				is_alpha=1;
				this1=s[j];
				index_1=j;
				break;
			}
		}
		if (is_alpha) 
		{
			num=1;
			for (j=index_1+1 ; j<strlen(s) ; j++)
			{
				if (s[j]==this1) num++;
			}
			printf("\n     %c%9d",this1,num);
		}
	}
	return 0;
}