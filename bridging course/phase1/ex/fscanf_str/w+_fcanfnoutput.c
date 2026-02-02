#include <stdio.h>
#include <stdlib.h>
void main(){
	char this1;
	FILE*indata=fopen("F:\\programming\\bridging course\\ex\\fscanf_separatelyinputread.inf","w+");
	if (indata==NULL){
		printf("can't open inf");
		exit(1);
}	
	fprintf(indata,"Hello world!\n");
	rewind(indata);
	FILE *outcopy=fopen("F:\\programming\\bridging course\\ex\\fscanf_separatelyinputread.ouf","w");
	if (outcopy==NULL){
		printf("can't open ouf");
		exit(1);
}
	while(fscanf(indata,"%c",&this1)!=EOF)
	fprintf(outcopy,"%c",this1);
	fclose(indata);
	fclose(outcopy);
}