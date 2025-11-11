#include <stdio.h>
#include <string.h>
int main(){
	char this1[100];
	char search;
	int num_occ=0;
	gets(this1);
	printf("%d\n",strlen(this1));
	printf("enter:");
	scanf("%c",&search);
	for(int i=0;i<strlen(this1);i++)
	{	
		if (this1[i]==search)  num_occ++;
	}
	printf("In \'%s\', %d %c\n", this1, num_occ, search);
}