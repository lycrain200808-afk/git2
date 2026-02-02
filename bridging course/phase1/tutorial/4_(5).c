#include <stdio.h>

int find_lcm(int a , int b){
	int done=0;
	int lcm=a;
	while (!done)
	{
		lcm%b==0? done=1:lcm+=a;
	}
	return lcm;
}

int find_hcf(int a , int b){
	int done=0;
	int hcf,i;
	for (i=a ; i>=1 ; i--)
	{	
		hcf=i;
		if (a%i==0 && b%i==0) break;
	}
	return hcf;
}
int main(){
	int num,HCF,LCM;
	int i;
	char answer;
	do
	{
		printf("How many integers? ");
		scanf("%d%*c",&num);
		printf("Enter them: ");
		int x[num];
		for (i=0 ; i<num ; i++)
		{
			scanf("%d",&x[i]);
		}
		getchar();
		LCM=x[0];
		HCF=x[0];
		for (i=0 ; i<=num-2 ; i++)
		{
			LCM=find_lcm(LCM,x[i+1]);
			HCF=find_hcf(HCF,x[i+1]);
		}
		printf("Least Common Multiple: %d\n",LCM);
		printf("Highest Common Factor: %d\n\n\n",HCF);
		printf("Do you have another ser of integars <y/n>: ");
		scanf("%c",&answer);
		}while (answer=='y' || answer=='Y');
}