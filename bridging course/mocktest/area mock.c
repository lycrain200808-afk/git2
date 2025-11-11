#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define f(x) exp(x)
#define g(x) 7-x*x
#define last 10000
int main(){
	int n=0,rounds=0;
	float x,y;
	srand(time(NULL));
	do{
		x=rand()/32767.0*3-2;
		y=rand()/32767.0*7;
		if (y<g(x)&&y>f(x)) n++;
		rounds++;
	}while(rounds<last);
	printf("%.2f",21.0*n/last);
	return 0;
}