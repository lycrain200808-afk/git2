#include <stdio.h>
int check_prime(int x)
{
	int f,ans=1;
    for(f=2;f<=x/2;f++){
	if (x%f==0){
	ans=0;break;
}}
return ans;}
int main()
{
int n;
scanf ("%d\n",&n);
printf("%d is ",n);
if (check_prime(n)==0) printf("not");
printf(" prime");
return 0;
}
