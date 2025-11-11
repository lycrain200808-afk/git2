#include <stdio.h>

int rev(int this1, int *sum){
	if(this1==0) return *sum;
	*sum=*sum*10+this1%10;
	return rev(this1/10,sum);
}
	
int main(){
	int n;
	int s=0;
	scanf("%d",&n);
	printf("%d",rev(n,&s));
	return 0;
}