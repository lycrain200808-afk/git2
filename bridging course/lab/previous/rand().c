#include <stdio.h>
#include <stdlib.h>
int main(){
	int i;
	srand(11);
	for (i=0;i<20;i++){
		printf ("%.2f\n",rand()/32767.0*(2.55+3.76)-2.55);
	}
}