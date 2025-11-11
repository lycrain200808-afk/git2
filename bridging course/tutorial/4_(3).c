#include <stdio.h>
#include <string.h>

int are_anagrams(char s1[] , char s2[])
{
	size_t len1=strlen(s1) , len2=strlen(s2);
	if (len1!=len2) return 0;
	else 
	{
		char alpha[27]={'a','b','c','d','e','f','g','h',
						'i','j','k','l','m','n','o','p',
						'q','r','s','t','u','v','w','x',
						'y','z'};
		char this1;
		int i,j,index1_1=0;
		
		for (i=0 ; i<26 ; i++)
		{
			int num1=0,num2=0;
			for (j=0 ; j<len1 ; j++)
			{
				if (alpha[i]==s1[j])
				{
					this1=s1[j];
					index1_1=j;
					num1++;
					for (j=index1_1+1 ; j<len1 ; j++)
					{
						if (s1[j]==this1) num1++;
					}
					for (j=0 ; j<len1 ; j++)
					{
					if (s2[j]==this1) num2++;
					}	
					if (num1!=num2) return 0;
				}
			}
		}
		return 1;
	}
}

void remove_newline(char* str){
	size_t len=strlen(str);
	if (str[len-1]=='\n') str[len-1]=0;
}

int main(){
	char word1[17],word2[17];
	char answer;
	do
	{
		printf("\nEnter first word: ");
		fgets(word1,sizeof(word1),stdin);
		remove_newline(word1);
		printf("Enter second word: ");
		fgets(word2,sizeof(word2),stdin);
		remove_newline(word2);
		if (are_anagrams(word1,word2)) printf("\"%s\" and \"%s\" are anagrams.",word1,word2);
		else printf("\"%s\" and \"%s\" are not anagrams.",word1,word2);
		printf("\n\nEnter * if you wish to stop: ");
		scanf("%c%*c",&answer);
	}while (answer!='*');
	return 0;
}