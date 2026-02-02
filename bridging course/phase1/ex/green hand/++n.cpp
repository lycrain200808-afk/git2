#include <stdio.h>
int main(){
	int p=0,n=0;
	p=++n;
	printf("%p %p \n",(void*)&n,(void*)&p);
}