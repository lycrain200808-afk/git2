#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  char name[14];
  float hour,hour_rate,wage,total_wage=0;
  int num;
  char gender;

  FILE *indata, *outdata;

  indata  = fopen ("F:\\lab\\lab6\\lab6\\wage.inf","r");
  if (indata==NULL)
  {
	  printf ("books.inf does not exist.");
	  exit (1);
  }

  outdata = fopen ("f:\\lab\\lab6\\wage.ouf","w");
  if (outdata==NULL)
  {
	  printf ("books.ouf cannot be created.");
	  exit (1);
  }
  
  while ( fgets(name,sizeof(name),indata) !=NULL)
  {
  	fscanf (indata,"%d %c%f%f%*c",&num,&gender,&hour_rate,&hour); //or use %*c to eat the \n
  	
  	if(hour>40) wage=40*hour_rate+hour_rate*(hour-40)*1.5;
  	else wage=hour*hour_rate;
  	
  	fprintf(outdata,"    %d          %.2f          %.2f        %.2f\n",num,hour,hour_rate,wage);
  	total_wage+=wage;
  }
  fprintf(outdata,"%.2f",total_wage);
  
  fclose(indata);
  fclose(outdata);
  return 0;
}
  
  	