#include <stdio.h>
int main(){
	char this1;
	printf("Enter message:");
	scanf("%c",&this1);
	printf("Encrypted message:");
	while(this1!='\n'){
		if (this1=='\n') return 0;
		switch(this1){
			case'a':this1='!';break;
			case'e':this1='$';break;
			case'i':this1='#';break;
			case'o':this1='*';break;
			case'u':this1='&';break;
		}
		printf("%c",this1);
		scanf("%c",&this1);
	}}