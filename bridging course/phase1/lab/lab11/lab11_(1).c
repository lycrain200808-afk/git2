#include <stdio.h>
#define pi 3.14159265

float dfs(float x, int n, float term, float sum){
	term= term*(-x)*x/(2*n)/(2*n-1);
	if (term>-1e-8&&term<1e-8) return sum;
	else return dfs(x, n+1, term, sum+term);
}

int main(){
	printf("%f", 2*dfs(pi, 1, 1, 1));
	return 0;
}