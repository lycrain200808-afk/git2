#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int outcome(){
	int square=rand()%37-1;
	int result=rand()%37-1;
	if (square==-1) {
		if (result%2==1) return -1;
		else  return 1;
	}
	
	if (square==0){
		if (result%2==0) return -1;
		else return 1;
	}
	
	if (square==result) return -34;
	else return 1;
}

int main(){
	int sum=0;
	int this1;
	srand(time(NULL));
	for (int i=0; i<100; i++){
		this1=outcome();
		printf("%d ",this1);
		sum+=this1;
		Sleep(500);
	}
	printf("\n%f",sum/100.0);
	return 0;
}