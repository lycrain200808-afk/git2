#include <stdio.h>
#include <math.h>
#define f(x) (pow(x,7)-279)
int main(){
	double a=2,b=3,m;
	int rounds=1;
	do{
		m=(a+b)/2.0;
		if (f(a)*f(m)>0) a=m;
		else b=m;
	}while(fabs(f(m))>0.000001);
	printf("%.6f",m);
	return 0;
}