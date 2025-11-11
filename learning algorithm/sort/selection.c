#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define n 50
int main(){
	srand(31);
	int x[n];
	int checksum=0;
	printf("Selection sort:\n");
	for (int i=0;i<n;i++) 
	{
		x[i]=rand()%300;
		printf("%d ",x[i]);
		checksum+=x[i];
	}
	printf("\n%d",checksum);
	for (int i=0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (x[j]<x[i])
			{
				int temp;
				temp=x[j];
				x[j]=x[i];
				x[i]=temp;
			}
		}
	}
	checksum=0;
	for (int i=0;i<n;i++) checksum+=x[i];
	printf("\n%d\n",checksum);
	bool sort=true;
	for (int i=0;i<=n-2;i++) 
	{
		if(x[i]>x[i+1]) sort=false;
		break;
	}
	if (sort) printf("sorted");
	else printf("failed.");		
	return 0;
}