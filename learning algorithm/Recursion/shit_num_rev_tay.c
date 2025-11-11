#include <stdio.h>

int recur2(int this1){
	static int sum=0;
	if(this1==0) return 0;
	else
	{
		sum=sum*10+this1%10;
		recur2(this1/10);
	}
	return sum;
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d",recur2(n));
	return 0;
}