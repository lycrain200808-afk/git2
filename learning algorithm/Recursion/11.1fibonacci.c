#include <stdio.h>

int f(int x){
	if (x==1) return 1;
	if (x==2) return 2;
	return f(x-1)+f(x-2);
}

int main(){
	int n,ans;
	scanf("%d",&n);
	ans=f(n);
	printf("%d",ans);
}