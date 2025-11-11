#include <stdio.h>
int main(){
	int S,L,CM;
	do
	{
		printf ("Enter: ");
		scanf("%d%d",&S,&L);
		if (S<=0) break;
		else {
				CM=L;
				while(!(CM%S==0&&CM%L==0))
				{
					CM+=L;
				}
				printf("%d\n",CM);
			}
} while (S>=0);
	return 0;
}