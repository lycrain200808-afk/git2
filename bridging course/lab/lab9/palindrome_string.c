#include <stdio.h>
#include <string.h>
int main(){
	char word[21];
	while(1)
	{
		printf("Enter: ");
		fgets(word,sizeof(word),stdin);
		int len=strlen(word);
		if (word[len-1]='\n') 
		{
			word[len-1]=0;
			len--;
		}
		if (len==0) break;
		else
		{
			int is_pal=1;
			for (int i=0 ; i<=(len-1)/2 ; i++)
			{	
				if (word[i]!=word[len-1-i])
				{
				is_pal=0;
				break;
				}
			}
			if (is_pal) printf("%s is a palindrome.\n",word);
			else printf("%s is not a palindrome.\n",word);
		}
	}
	return 0;
}