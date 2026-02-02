#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define n 50
int main(){
	srand(31);
	int x[n];
	int checksum=0;
	printf("Bubble sort:\n");
	for (int i=0;i<n;i++) 
	{
		x[i]=rand()%300;
		printf("%d ",x[i]);
		checksum+=x[i];
	}
	printf("\n%d",checksum);
	
	//algorithm
	int exchange;
	int height=n-2;
	do{
		exchange=0;
		for (int i=0;i<=height;i++){
			if (x[i+1]<x[i]){
				int temp;
				temp=x[i+1];
				x[i+1]=x[i];
				x[i]=temp;
				exchange=1;
			}
		}
		height--;
	}while (exchange==1 && height>=0);
	checksum=0;
	for (int i=0;i<n;i++) checksum+=x[i];
	printf("\n%d\n",checksum);
	bool sort=true;
	for (int i=0;i<=n-2;i++) {
		if(x[i]>x[i+1]){
			sort=false;
			break;
		}
	}
	if (sort) printf("sorted");
	else printf("failed.");		
	return 0;
}