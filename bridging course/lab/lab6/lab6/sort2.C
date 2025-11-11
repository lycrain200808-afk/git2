// Lab 6. Sorting Algorithm

# include <stdio.h>
# include <stdlib.h>

# define n 20
# define seed 31

int a[n];

int main ()
{
  int i;
  long checksum;
  int sorted,temp;
  int give,memo;

  srand(seed);  // fix the seed
  for(i=0;i<n;i++) a[i]= rand();
  for (i=0;i<n;i++) printf("%d ",a[i]);

  checksum = 0;
  for(i = 0; i <n; i++ ){ checksum +=a[i];}
  printf("\nChecksum before sorting: %ld\n", checksum);
	for (int i=1;i<n;i++)
	{	int j=i-1;
		while(a[j]>a[i] && j>=0)
		{
			j--;
		}
		temp=a[i];
		for (int m=i;m>j+1;m--)
		{
			a[m]=a[m-1];
		}
		a[j+1]=temp;
}


  // Program the algorithm (without variation) written in the handout

    

  checksum = 0;
  for(i = 0; i <n; i++ ){checksum +=a[i];}
  printf("\nChecksum after sorting: %ld \n", checksum);

  sorted = 1;
  for(i = 0; i < n-1; i++ )
  {
    if (a[i] > a[i+1])
    {
       sorted = 0;
       break;
    }
  }

  if (sorted ==1){
  	printf ("\n====> Sorted! \n");
  	for (i=0;i<n;i++) printf("%d ",a[i]);
 }
  else
     printf ("====> Not sorted \n");

  return 0;
}