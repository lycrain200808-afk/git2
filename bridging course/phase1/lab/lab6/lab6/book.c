// book.c

# include <stdio.h>
# include <stdlib.h>

int main(void)
{
  char title [19];
  float price;
  int quantity;

  FILE *indata, *outdata;

  indata  = fopen ("F:\\programming\\bridging course\\lab\\lab6\\lab6\\books.inf","r");
  if (indata==NULL)
  {
	  printf ("books.inf does not exist.");
	  exit (1);
  }

  outdata = fopen ("F:\\programming\\bridging course\\lab\\lab6\\books.ouf","w");
  if (outdata==NULL)
  {
	  printf ("books.ouf cannot be created.");
	  exit (1);
  }

  while ( (fgets (title,19,indata) !=NULL) &&
	  (fscanf (indata,"%f%d%*c",&price,&quantity) ==2) )
  {
     fprintf (outdata, "Book Title : %s \n",title);
     fprintf (outdata, "Price : $ %.2f \n", price);
     fprintf (outdata, "Stock : %d\n\n",quantity);
  }

  fclose (indata);
  fclose (outdata);
  return 0;
}
