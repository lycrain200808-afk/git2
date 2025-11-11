#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char word[][15] , int i)
{	
	char temp[15];
	strcpy(temp,word[i]);
	strcpy(word[i],word[i+1]);
	strcpy(word[i+1],temp);
}

int main(){
	printf("Sorted in lexicographical order\n");
	for (int i=0 ; i<31 ; i++) printf("=");
	printf("\n");
	FILE* indata=fopen("C:\\Users\\Rain\\Desktop\\lab9\\words.inf","r");
	if (indata==NULL) 
	{
		printf("can't open inf");
		exit(1);
	}
	
	char word[25][15];
	int num_word=0;
	while(fgets(word[num_word],15,indata)!=NULL)
	{
		num_word++;
	}
	int exchange=1;
	while(exchange)
	{	
		exchange=0;
		for (int i=0 ; i<num_word-1 ; i++)
		{
			if (strcmp(word[i],word[i+1])>0) 
			{
				exchange=1;
				swap(word,i);
			}
		}
	}
	fclose(indata);	
	for (int i=0 ; i<num_word ; i++)
	{
		printf("%6d.        %s",i+1,word[i]);
	}
	return 0;
}
	