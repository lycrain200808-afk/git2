#include <stdio.h>
#include <stdlib.h>
void main(){
	int num,A,B,C;
	float pa,pb,pc,pay,sump=0;
	FILE*indata=fopen("F:\\ex\\BILL.INF","r");
	FILE*outdata=fopen("F:\\ex\\BILL.OUF","w");
	if(indata==NULL){
		printf("can't open inf");
		exit (1);
}
	if(outdata==NULL){
		printf("can't open onf");
		exit (1);
}
	fprintf(outdata," Billnum        Payment");
	fprintf(outdata,"\n =================================");
	while(fscanf(indata,"%d%d%d%d",&num,&A,&B,&C)==4){
		if(A>100) pa=A*4*0.98;
		else pa=A*4;
		if(B>200) pb=B*6*0.95;
		else pb=B*6;
		if(C>150) pc=C*0.9*5;
		else pc=C*5;
		pay=pa+pb+pc;
		fprintf(outdata,"\n     %d       %.2f" ,num,pay);
		fprintf(outdata,"\n__________________________________");
		sump+=pay;
	}
	fprintf(outdata,"\n  Total payment:$%.2f",sump);
	return 0;
}