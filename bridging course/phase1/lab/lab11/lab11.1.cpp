#include <stdio.h>
#include <stdlib.h>
#define tolerance 1e-8
#define pi 3.1415926

double f(double x, double *sum, int round){
	static double term=1;
	term=term*(-1)*x*x/round/(round-1);
	*sum=*sum+term;
	if(term<tolerance && term>-tolerance) return *sum;
	else return f(x,sum,round+2);
}

int main(){
	double *s=(double *)malloc(sizeof(double));
	*s=1;
	printf("%lf", 2*f(pi,s,2));
	free(s);
	return 0;
}