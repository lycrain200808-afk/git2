#include <stdio.h>
#include <stdlib.h>
int main(){
	float p;
	int sum_return=0;
	srand(31);
for (int j=0;j<10000;j++){
	for (int i=0;i<50;i++){
		p=(float)rand()/32767;
		if(p>=0.4 && p<0.5) sum_return+=2;
		else if (p>=0.5 && p<0.8) sum_return+=3; 
		else if (p>=0.8 && p<=1) sum_return+=4;
		}
	}
	float exp_return=(float)sum_return/500000;
	float ha=(2-exp_return)/2*100;
	printf("%.2f",ha);
}