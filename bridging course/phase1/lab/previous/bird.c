#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main(){
	int i=0,j=0,t=0;
	for (t=0;t<21;t++){
		Sleep(500);
		system("cls");
		for (i=0;i<21-t;i++) printf("\n");
		for (i=0;i<4;i++){
			for (j=0;j<2*t;j++) printf("  ");
			for (j=0;j<3-i;j++) printf(" ");
			printf("/");
			for (j=0;j<2*i;j++) printf(" ");
			printf ("\\");
			for (j=0;j<6-2*i;j++) printf(" ");
			printf("/");
			for (j=0;j<2*i;j++) printf(" ");
			printf ("\\\n");
			}
		Sleep(500);
		system("cls");
		for (;i<21-t;i++) printf("\n");
		printf ("\n\n");
			for (j=0;j<2*t;j++) printf("  ");
			printf ("            ^\n");
			for (j=0;j<2*t;j++) printf("  ");
			printf ("    ______/\\______\n");
			for (j=0;j<2*t;j++) printf("  ");
			printf ("         //");	
}
}
			
			
		
			
		