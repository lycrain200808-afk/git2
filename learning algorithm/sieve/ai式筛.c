#include <stdio.h>
#include <stdbool.h>
int main(){
	int num=0,input;
	bool prime[2000000];
	scanf ("%d",&input);
	for (int i=2;i<=input;i++) prime[i]=true;
	for (int i=2;i<=input;i++)
	{
		if ( prime[i] ) 
		{
			num++;
			for ( int j = 2*i ; j<=input ;j+=i) prime[j]=false;
		}
	}
	printf("%d",num);
	return 0;
}
	