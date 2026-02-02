#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main (){
	int t,j;
	for (t=0;t<25;t++)
	{
		system ("cls");
		for (j=0;j<=2*t;j++) printf (" ");
		printf ("--->");
		Sleep(5);
	}
	printf ("\n\n");
	return 0;
}