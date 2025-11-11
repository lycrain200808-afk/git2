// Square Grid Sort
// This is a structured sorting algorithm

# include <stdio.h>
# include <stdlib.h>

# define n 8

void swap( int* p , int* m)
{
	int temp=*p;
	*p=*m;
	*m=temp;
}

int* min_2( int* p , int* m)
{
	if (*p<*m) return p;
	else return m;
}
int main ()
{
      int G [n][n];

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
	for (i=0 ; i<n ; i++)
	{ 	int height = n-1;
		int exchange=1;
		while (exchange==1)
		{
		exchange=0;
		for ( j=0 ; j<height ; j++)
		{	
			if (G[i][j]>G[i][j+1]) 
			{
				exchange=1;
				swap(&G[i][j],&G[i][j+1]);
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
	for (j=0 ; j<n ; j++)
	{ 	int height = n-1;
		int exchange=1;
		while (exchange==1)
		{
		exchange=0;
		for ( i=0 ; i<height ; i++)
		{	
			if (G[i][j]>G[i+1][j]) 
			{
				exchange=1;
				swap(&G[i][j],&G[i+1][j]);
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
	for (i1=0 ; i1<n-1 ; i1++)
	{
		for (j1=0 ; j1<=n-1 ; j1++)
		{
		if (G[i1][j1]>G[i1+1][0]) 
		{	swap( &G[i1][j1] , &G[i1+1][0]);
			int thisi1=i1+1,thisj1=0;
			int exchange=1;
			while(exchange==1 && thisi1<n-1 && thisj1<n-1)
			{
			exchange=0;
			int* min=min_2(&G[thisi1+1][thisj1]	, &G[thisi1][thisj1+1]);
			if (G[thisi1][thisj1] > *min ) 
			{exchange=1;
			 swap(&G[thisi1][thisj1] , min);
			 if (min == &G[thisi1+1][thisj1]) thisi1 = thisi1 + 1;
			 else  thisj1 = thisj1 + 1;
			}
			if (thisi1==n-1)
			{
				int exchange=1;
				for ( ; exchange==1 && thisj1+1<n ; thisj1++)
				{
					exchange=0;
					if ( G[thisi1][thisj1] > G[thisi1][thisj1+1] )
					{
						exchange=1;
						swap( &G[thisi1][thisj1] , &G[thisi1][thisj1+1] );	
					}
				}
			}
			if (thisj1==n-1)
			{
				int exchange=1;
				for ( ; exchange==1 && thisi1+1<n ; thisi1++)
				{
					exchange=0;
					if ( G[thisi1][thisj1] > G[thisi1][thisj1+1] )
					{
						exchange=1;
						swap( &G[thisi1][thisj1] , &G[thisi1][thisj1+1] );	
					}
				}
			}
			}
		}
		}
	}
	if (i1==n-1)
	{
	int exchange=1;
	for ( j1=0; exchange==1 && j1+1<n ; j1++)
		{
		exchange=0;
		if ( G[i1][j1] > G[i1][j1+1] )
		{
			exchange=1;
			swap( &G[i1][j1] , &G[i1][j1+1] );	
		}
		}
	}
	for (j1=1 ; j1<=n-1 ; j1++)
	{
		if (G[n-2][j1]>G[n-1][0]) 
		{	swap( &G[n-2][j1] , &G[n-1][0]);
			int thisi1=i1+1,thisj1=0;
			int exchange =1;
			for ( j1=0 ; exchange==1 && j1+1<n ; j1++)
			{
			exchange=0;
			if ( G[n-1][j1] > G[n-1][j1+1] )
			{
			exchange=1;
			swap( &G[n-1][j1] , &G[n-1][j1+1] );	
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
	        if (! ( i1==(n-1) && j1 == (n-1) ) )
	        if ( *(&G[0][0] + i1*n +j1) > *(&G[0][0] + i1*n +j1 + 1) )
		    sorted =0;
	    }
	    printf ("\n");
      }
      printf ("Checksum = %ld",checksum);

      if (sorted ==1) printf ("   sorted\n\n");
      else printf ("    not sorted\n\n");

      return 0;
}

