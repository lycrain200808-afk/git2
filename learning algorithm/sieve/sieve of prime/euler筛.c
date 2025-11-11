#include <stdio.h>
#include <stdbool.h>

#define MAXN 1000000  

int primes[MAXN+1];     
bool is_prime[MAXN+1];  
int prime_count = 0;

void euler_sieve(int n) {
    for (int i = 2; i <= n; i++) 
	{
        is_prime[i] = true;
    }

    for (int i = 2 ; i <= n; i++) 
	{
        if (is_prime[i]) 
		{
        	primes[prime_count] = i;
            prime_count++;
        }
        for (int j = 0; j < prime_count && i * primes[j] <= n; j++) 
		{
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0) break;
        }
    }
}

int main() {
    int n;
    printf("n:");
    scanf("%d", &n);

    euler_sieve(n);

    printf("Not bigger than %d, the number of prime is %d\n", n, prime_count);
    for (int i = 0; i < prime_count; i++) 
	{
        printf("%d ", primes[i]);
    }
    printf("\n");
	return 0;
}