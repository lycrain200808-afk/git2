#include <stdio.h>
int main(){
	int n=1,remainder,m;
	while (n>0){
	int sum=0;
	scanf("%d",&n);
	remainder=n;
	while (remainder>0)
	{m=remainder%10;
	remainder=remainder/10;
	sum=sum*10+m;	
	}
	if(sum==n) printf("yes\n\n");
	else printf("no\n\n");
}
	return 0;
}
		