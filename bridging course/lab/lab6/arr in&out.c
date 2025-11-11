#include <stdio.h>
#include <stdlib.h>
int main(){
	char title[100];
	float price;
	int quantity;
	FILE *indata=fopen("F:\\lab\\lab6\\lab6\\book.inf","r");
	FILE *outdata=fopen("F:/lab/lab6/books.ouf","w");
	if (indata==NULL)
	{
		printf("can't open inf\n");
		exit(1);
	}
	if (outdata==NULL)
	{
		printf("can't open ouf");
		fclose(indata);
		exit(1);
	}
	while((fgets (title,19,indata)!=NULL) && (fscanf(indata,"%f%d%*c",&price,&quantity)) == 2)
	{
		fprintf (outdata,"Book Title: %s\n",title);
		fprintf(outdata,"Price: $ %.2f \n",price);
		fprintf(outdata,"Stock: %d\n\n",quantity);
	}
	/*fclose(indata);
	fclose(outdata);
	*/
	return 0;
}