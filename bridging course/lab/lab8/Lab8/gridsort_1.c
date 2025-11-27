// Square Grid Sort
// This is a structured sorting algorithm

# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>
# define n 8

void swap(int* p , int* m){
	int temp=*p;
	*p=*m;
	*m=temp;
}

int *smaller_address(int *r){
	if (*(r+1)<*(r+n+1)) return r+1;
	else return r+n+1;
}

int main ()
{
      int G [n+1][n+1];

      int i,j,this1;
      int nexti, nextj, temp, interchange;
      int thisi, thisj,  min;

      int i1, j1;
      int row, col;
      long checksum, sorted;

	  // add new indentifiers if you need




      srand (17);
      for (j=0; j<n; j++)
	   for (i=0; i<n; i++)
	    G[i][j] = rand()%200;
	for(i=0; i<=n; i++) G[i][n]=200;
	for(j=0; j<n; j++) G[n][j]=200;
		
      printf ("\n\nRaw Data:\n");
      checksum=0;
      for (i1=0; i1<n; i1++)
      {
	    for ( j1=0; j1<n; j1++)
	    {
	      printf ("%5d",G[i1][j1]);
	      checksum += G[i1][j1];
	    }
	    printf ("\n");
      }
      printf ("Checksum = %ld",checksum);

      // pre-processing row sort to be programmed by you
	for (i1=0; i1<n; i1++){
		int exchange=1;
		int height=n-2;
		while(exchange==1){
			exchange=0;
			for (j1=0; j1<=height; j1++){
				if (G[i1][j1]>G[i1][j1+1]) {
					swap(&G[i1][j1], &G[i1][j1+1]);
					exchange=1;
				}
			}
			height--;
		}
	}
	
       printf ("\n\nAfter row sort:\n");
       checksum=0;
       for (i1=0; i1<n; i1++)
       {
	     for (j1=0; j1<n; j1++)
	     {
	       printf ("%5d",G[i1][j1]);
	       checksum += G[i1][j1];
	     }
	     printf ("\n");
      }
      
	  printf ("Checksum = %ld",checksum);

	  // pre-processing column sort to be programmed by you
	for (j1=0; j1<n; j1++){
		int exchange=1;
		int height=n-2;
		while(exchange==1){
			exchange=0;
			for (i1=0; i1<=height; i1++){
				if (G[i1][j1]>G[i1+1][j1]) {
					swap(&G[i1][j1], &G[i1+1][j1]);
					exchange=1;
				}
			}
			height--;
		}
	}

      printf ("\n\nAfter column sort:\n");
      checksum=0;
      for ( i1=0; i1<n; i1++)
      {
	    for (j1=0; j1<n; j1++)
	    {
	      printf ("%5d",G[i1][j1]);
	      checksum += G[i1][j1];
	    }
	    printf ("\n");
      }
      printf ("Checksum = %ld",checksum);

      // exchange and heap restoration to be programmed by you
	for (i=0; i<=n-2; i++){
		for (j=1; j<n; j++){
			if (G[i][j]>G[i+1][0]) {
				swap(&G[i][j], &G[i+1][0]);
				int *this1=&G[i+1][0];
				bool done=false;
				while(!done){
					int *index=smaller_address(this1);
					if (*this1>*index) {
						swap(this1, index);
						this1=index;
					}
					else done=true;
				}
			}
		}
	}

      printf ("\n\nAfter interchange and restoration:\n");
      checksum=0;
      sorted =1;
      for (i1=0; i1<n; i1++)
      {
	     for (j1=0; j1<n; j1++)
	     {
	        printf ("%5d",G[i1][j1]);
	        checksum += G[i1][j1];
	    }
	    printf ("\n");
      }
      printf ("Checksum = %ld",checksum);

	for (i=0; i<n; i++)
      {
	     for (j=0; j<n; j++)
	     {
	        if (G[i][j]>G[i][j+1]) {
	        	sorted=0;
	        	break;
	        }
      	}
      }
      
      if (sorted ==1) printf ("   sorted\n\n");
      else printf ("    not sorted\n\n");

      return 0;
}
