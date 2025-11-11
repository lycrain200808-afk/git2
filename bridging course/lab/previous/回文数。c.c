#include <stdio.h>
int main(){
	int a[101],m,x,bool,n;
	do{
	int i=0;
	printf("Enter 0 to stop or a positive number:");
	scanf("%d",&n);	
	if(n==0) return 0;
	m=n;
	do {
		m=m/10;			/*判断位数*/
		i++;
	}while (m>0);
	m=n;
	for (x=1;x<=i;x++)
	{a[x]=m%10;
	m=m/10;
	}
	for(m=1;m<=i/2;m++)	{
		if(a[i+1-m]!=a[m]) {
			bool=1;
		}	
		else bool=0;
	}
	if (bool) printf("no\n\n");
	else printf("yes\n\n");
}   while(n>0);
return 0;
}