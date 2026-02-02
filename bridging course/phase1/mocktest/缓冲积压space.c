#include <stdio.h>
int main(){
	char pre1='x';
	char this1;
	do{
		scanf("%c",&this1);
		/*if (this1=='\n') return 0;*/
		if(!(pre1==' '&& this1==' '))printf("%c",this1);
		pre1=this1;
	}while(this1!='\n');
	return 0;}