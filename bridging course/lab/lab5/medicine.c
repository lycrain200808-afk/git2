#include <stdio.h>
#include <stdlib.h>
int price (char label){
	if (label=='A' || label=='B' || label=='C') return 9;
	if (label=='D' || label=='E' || label=='F' || label=='G') return 15;
	if (label=='H' || label=='I' || label=='J' || label=='K') return 5;
	if (label=='L' || label=='M' || label=='N' || label=='O') return 12;
}
void main(){
	int num,sumsort,pay;
	char label;
	int quan;
	FILE*indata=fopen("F:\\lab\\lab5\\MEDICINE.INF","r");
	FILE*outdata=fopen("F:\\lab\\lab5\\MEDICINE.OUF","w");
	if(indata==NULL){
		printf("can't open inf");
		exit (1);
}
	if(outdata==NULL){
		printf("can't open onf");
		exit (1);
}
	fprintf(outdata," Billnum        Charge");
	fprintf(outdata,"\n =================================");
	while(fscanf(indata,"%d%d%*c",&num,&sumsort)==2)
	{
		int sum=0;
		for (int i=0;i<sumsort;i++){
			fscanf(indata,"%c%d",&label,&quan);
			pay=price (label);
			sum+=pay*quan;
		}
		fprintf(outdata,"\n     %d           %.2f",num,sum);
	}
	fclose(indata);
	fclose(outdata);
}