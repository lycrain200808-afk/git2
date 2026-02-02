#include <stdio.h>

int recur2_impl(int this1, int sum){
	if (this1==0) return sum;
	return recur2_impl(this1/10, sum*10 + this1%10);
}

int recur2(int this1){
	if (this1<0) return -recur2_impl(-this1, 0);
	return recur2_impl(this1, 0);
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d",recur2(n));
	return 0;
}