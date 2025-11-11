#include <stdio.h>
#define n 10

void rotate_cc(int p[n] , int count)
{	
	int i;
	int next_p[n];
	for(i=0 ; i<n ; i++) next_p[(i-count+100)%10]=p[i];
	for(i=0 ; i<n ; i++) p[i]=next_p[i];
}

int main(){
	int a[n];
	int i,step;
	for (i=0 ; i<n ; i++) a[i]=3*i+3;
	printf("\n");
	for (i=0 ; i<n ; i++) printf("%d ",a[i]);
	printf("\nsteps <0 to stop>: ");
	scanf("%d%*c",&step);
	while(step!=0)
	{
		rotate_cc(a,step);
		for (i=0 ; i<n ; i++) printf("%d ",a[i]);
		printf("\nsteps <0 to stop>: ");
		scanf("%d%*c",&step);
	}
	return 0;
}
		