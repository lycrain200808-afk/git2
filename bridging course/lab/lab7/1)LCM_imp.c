#include <stdio.h>

int find_lcm(int a, int b){
	if(a<b){
		int temp=a;
		a=b;
		b=temp;
	}
	int CM=a;
	while(!(CM%b==0)){
			CM+=a;
	}
	return CM;
}

int main(){
	int S,L,CM;
	
	do
	{
		printf ("Enter: ");
		scanf("%d%d",&S,&L);
		if (S<=0 || L<=0) break;
		else printf("%d\n",find_lcm(S, L));
} while (S>0 && L>0);
	return 0;
}
