#include <stdio.h>
#include <string.h>
int main(){
	char s[100];
	int i,j;
	gets(s);
	printf("%d\n", strlen(s));
	for (i=0; i<strlen(s); i++){
		if (!( (s[i]>='A'&&s[i]<='Z') || (s[i]>='a' && s[i]<='z'))) {
			for (j=i+1; j<strlen(s); j++) s[j-1]=s[j]; //replacement
			s[strlen(s)-1]=0; //tail
			i--;//recover i+1 to i
		}
	}
	printf("%s",s);
	printf("\n%d", strlen(s));
	return 0;
}
