#include <stdio.h>
#include <stdlib.h>
#define n 60
#define seed 29

int main(){
	srand(seed);
	int x[n], search, left=0, right=n-1, location;
	int mid;
	int found=0;
	for (int i=0; i<n; i++) x[i]=rand()%150;
	printf("Enter search: ");
	scanf("%d", &search);
	
	//bubble sort
	int exchange;
	int height=n-2;
	do{
		exchange=0;
		for (int i=0; i<=height; i++){
			if (x[i]>x[i+1]) {
				int temp=x[i];
				x[i]=x[i+1];
				x[i+1]=temp;
				exchange=1;
			}
		}
		height--;
	}while(exchange==1 && height>=0);
	
	while(left<=right && !found){
		mid=(left+right)/2;
		if (x[mid]==search) {
			found=1;
			location=mid;
		}
		else if (x[mid]<search) left=mid+1;
		else right=mid-1;
	}
	
	if(found) printf("found in %d\n", location);
	else printf("not found\n");

	printf("contents: ");
	for (int i=0; i<n; i++) printf("%d ", x[i]);
	return 0;
}