#include <stdio.h>
int main(){
	FILE* indata=fopen("F:\\lab\\lab7\\base\\IDENTITY.INF","r");
	int num,check;
	int n[7];
	char a,b;
	char alp(int x)
	{
		if (x==1) return 'A';
		if (x==2) return 'B';
		if (x==3) return 'C';
		if (x==4) return 'D';
		if (x==5) return 'E';
		if (x==6) return 'F';
		if (x==7) return 'G';
		if (x==8) return 'H';
		if (x==9) return 'I';
		if (x==10) return 'Z';
		if (x==11) return 'J';
	}
	
	for (int i=1 ; (fscanf(indata,"%d%c",&num,&a)==2) && i<=20 ; i++)
	{
		printf("%2d.  %d%c   ",i,num,a);
		for(int i=0;i<7;i++) 
		{
			n[6-i]=num%10;
			num=num/10;
		}
		check=11-(2*n[0]+7*n[1]+6*n[2]+5*n[3]+4*n[4]+3*n[5]+2*n[6])%11;
		b=alp(check);
		if (a!=b) printf("==>invalid\n");
		else printf("valid\n");
	}
	return 0;
}