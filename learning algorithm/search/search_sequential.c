#include <stdio.h>
#include <stdlib.h>
#define n 60
#define seed 29

int main(){
	srand(seed);
	int x[n], search, found=0, location;
	for (int i=0; i<n; i++) x[i]=rand()%150;
	printf("Enter search: ");
	scanf("%d", &search);
	
	for (int i=0; i<n; i++){
		if (x[i]==search){
			found=1;
			location=i;
			break;
		}
	}
	
	if(found) printf("found in %d\n",location);
	else printf("not found\n");

	printf("contents: ");
	for (int i=0; i<n; i++) printf("%d ", x[i]);
	return 0;
}