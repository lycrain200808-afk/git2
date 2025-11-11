#include <stdio.h>
int main(){
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Output Multiplication Table\n");
	for( int i=0; i<3 ; i++)
	{
		printf("-");
	}
	printf("+");
	for (int i=0 ; i < 3*n-3 ; i++)
	{
		printf("-");
	}
	printf("\n   |");
	for (int i=1 ; i<n ; i++)
	{
		printf("%3d",i);
	}
	printf("\n");
	for( int i=0; i<3 ; i++)
	{
		printf("-");
	}
	printf("+");
	for (int i=0 ; i < 3*n-3 ; i++)
	{
		printf("-");
	}
	
	//print the list
	
	printf("\n");
	for (int i=1 ; i<n ; i++)
	{   
		printf("%3d|",i);
		for (int j=1 ; j<n ; j++)
		{   
			int residue = i*j%n; 
			printf("%3d",residue);
		}
		printf("\n");
	}
	
	for( int i=0; i<3 ; i++)
	{
		printf("-");
	}
	printf("+");
	for (int i=0 ; i < 3*n-3 ; i++)
	{
		printf("-");
	}
	
	//level 3 finished
	
	printf("\n");
	printf("Output Multiplication Table\n");
	for( int i=0; i<3 ; i++)
	{
		printf("-");
	}
	printf("+");
	for (int i=0 ; i < 3*n-3 ; i++)
	{
		printf("-");
	}
	printf("\n   |");
	for (int i=1 ; i<n ; i++)
	{
		printf("%3d",i);
	}
	printf("\n");
	for( int i=0; i<3 ; i++)
	{
		printf("-");
	}
	printf("+");
	for (int i=0 ; i < 3*n-3 ; i++)
	{
		printf("-");
	}
	printf("\n");
	//print a list
	
	for (int i=1 ; i<n ; i++)
	{   
		printf("%3d|",i);
		for (int j=1 ; j<n ; j++)
		{   
			int residue = i*j%n;
			if ( residue == 1 ) printf("  *");
			else printf("   ");
		}
		printf("\n");
	}
	for( int i=0; i<3 ; i++)
	{
		printf("-");
	}
	printf("+");
	for (int i=0 ; i < 3*n-3 ; i++)
	{
		printf("-");
	}
	//level 4
	
	printf("\n");
	printf("Output Quadratic Table\n");
	for( int i=0; i<3 ; i++)
	{
		printf("-");
	}
	printf("+");
	for (int i=0 ; i < 3*n-3 ; i++)
	{
		printf("-");
	}
	printf("\n");
	for (int i=1 ; i<n ; i++)
	{   
		int index;
		int quadratic=0;
		for (int j=1; j<n ;j++)
		{	
			int residue = j*j%n;
			if (residue == i) 
			{
				quadratic=1;
				index=j;
				break;
			}
		}
		if (quadratic == 1) 
		{
			printf("%3d|",i);
			for (int j=index ; j<n ;j++)   //if j>n, j^2=(11t+s)^2, 0<=s<n, it's ok
			{
				int residue = j*j%n;
				if (residue == i) printf("%3d",j);
			}
			printf("\n");
		}
	}
	
	//level 5
	
	for( int i=0; i<3 ; i++)
	{
		printf("-");
	}
	printf("+");
	for (int i=0 ; i < 3*n-3 ; i++)
	{
		printf("-");
	}
	printf("\n");
	printf("Output Quadratic Table\n");
	for( int i=0; i<3 ; i++)
	{
		printf("-");
	}
	printf("+");
	for (int i=0 ; i < 3*n-3 ; i++)
	{
		printf("-");
	}
	printf("\n");
	
	printf("Output Fractal\n");
	printf("   ");
	int digit=n/10;
	for (int i=0; i<=digit ; i++)
	{
		if (i<digit) 
		{
			for (int j=0; j<9 ; j++) printf("%d",i);
		}
		
		else { 
				for (int j=digit*10; j<=n ; j++) printf("%d",digit);
			}
	}
	printf("\n");
	printf("   ");
	for (int i=0; i<=digit ; i++)
	{
		if (i<digit) 
		{
			for (int j=1; j<=9 ; j++) printf("%d",j);
		}
		
		else { 
				for (int j=0; j<=n-digit*10 ; j++) printf("%d",j);
			}
	}
	printf("\n");			
	for (int i=n; i>=1 ; i--)  //row
	{	
		if (i>9) printf("%3d",i);
		else printf(" 0%d",i);
		for (int j= 1; j<=i ;j++) printf(" ");
	    for (int j=i+1; j<=n ;j++) //num of column
	    {	
			int quadra=0;
			for (int k=1 ; k<=j ; k++)
			{
				if ( i == k*k%j ) 
					{
						quadra=1;
						break;
					}
			}
			if (quadra) printf("@");
			
			else printf (".");
		}
		printf("\n");
	}
					
	
	return 0;
}