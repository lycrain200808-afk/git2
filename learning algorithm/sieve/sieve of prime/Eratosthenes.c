#include <stdio.h>
#include <stdbool.h>
int main(){
	int n;
	scanf("%d",&n);
	bool is_prime[n+1];
	int primes[n+1];
	int i,j;
	int num=0;
	for ( i=2 ; i<=n ; i++) is_prime[i]=1;
	
	for ( i=2 ; i<=n ; i++) 
	{
		if (is_prime[i]==1) 
		{
			for ( j= 2*i ; j<=n ; j=j+i) is_prime[j]=0;
			primes[num]=i;
			num++;
		}
	}
	for (i=0 ; i<num ; i++) printf("%d ",primes[i]);
}