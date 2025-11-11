#include <stdio.h>
#include <stdbool.h>
bool check_prime(int n) {
	if (n<=1) return false;
	for (int i=2;i*i<=n;i++) {
		if (n % i == 0) return false;
	}
	return true;
}
 
int main(){
	int n;
	printf("input an integer:");
	scanf("%d",&n);
	FILE *fp = fopen("output.txt","w");
	if (fp ==NULL) {
		printf("err\n");
		return 1;
	}
	
	if (check_prime(n))
		printf("%d is prime",n);
	else printf ("%d isn't prime",n);
	
	if (check_prime(n))
		fprintf(fp,"%d is prime",n);
	else fprintf (fp,"%d isn't prime",n);
	
	fclose(fp);
	return 0;
}
	 
	
		
		