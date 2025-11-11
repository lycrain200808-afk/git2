#include <stdio.h>
#include <stdlib.h>
#define pi 3.14159265
#define tolerance 1e-8

double f(double x, double *sum, int round, double term);

int main(){
	double s;
	printf("%lf",f(0.75*pi, &s, 0, 0));
	return 0;
}
	
double f(double x, double *sum, int round, double term){
	if(round==0) {
		*sum=x;
		return f(x, sum, 1, x);
	}
	term=term*(-1)*x*x/(2*round+1)/(2*round);
	*sum+=term;
	if(term>tolerance || term<-tolerance) return f(x, sum, round+1, term);
	else return *sum;
}