#include<stdio.h>
#define last 10000
#include<math.h>
int main(){
	float term=0.5,sum=0;
	for(int i=1;i<last&&(term<-0.000001||term>0.000001);i++){
		sum+=term;
		term=term*(-0.5)*i/(i+1);
	}
	printf("%.4f %.4f",sum,log(1.5));
	return 0;
}