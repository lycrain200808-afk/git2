#include <stdio.h>
#include <stdbool.h>
int main(){
	int input,num=0;
	scanf("%d",&input);
	for (int j=2;j<=input;j++ )
	{
		bool prime=true;
		for (int i=2;i<=j/i; i++)
		{	
			if (j%i==0) 
			{
				prime=false;
				break;
			}
		}
		if (prime) num++;
	}
	printf("%d",num);
}
	