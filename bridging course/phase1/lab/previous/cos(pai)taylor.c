#include <stdio.h>
#include <math.h>
#define p 3.14159265
int main(){
	int n,i=0;
	double sum=2.0,term=2.0;
	while (fabs(term)>1e-8)
	{
	term*=(-p)*p;
	i+=2;
	for (n=i;n>=i-1;n--){
		term/=n;
	}
	sum+=term;
}
    printf("%.8f",sum);
    return 0;
}