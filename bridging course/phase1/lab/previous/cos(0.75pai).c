#include <stdio.h>
#include <math.h>
#define p 3.14159265
int main(){
	int n,i=3;
	double sum=0.0,term=0.75*p;
	while (fabs(term) >1e-8){
	sum+=term;
	term*=-0.75*0.75*p*p;
	for (n=i-1;n<=i;n++){
		term/=n;
	}
	i=i+2;
}
	printf ("%.8f",sum);
	return 0;
}