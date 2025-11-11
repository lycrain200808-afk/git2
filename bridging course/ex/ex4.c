#include <stdio.h>
int main(){
	int i,j,t;
	t=8;
	for (i=0;i<9;i++) printf ("\n");
	for (i=0;i<4;i++)
	{
		for (j=0;j<23;j++) printf (" ");
		for (j=0;j<3-i;j++) printf (" ");
		printf ("*");
		for (j=0;j<2*i;j++) printf (" ");
		printf ("*");
		printf ("\n");
	}
	return 0;
}
