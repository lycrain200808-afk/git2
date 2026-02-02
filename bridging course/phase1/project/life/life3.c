#include <stdio.h>

void read_soc(int m , int soc[][m+2] )
{	int j,i;
	char this1;
	for (i=0 ; i<m+2 ; i++)
	{ 
		for (j=0 ; j<m+2 ; j++)
		{
		soc[i][j]=0;
		}
	}
	for (i=1 ; i<=m ; i++)
	{
		for (j=1 ; j<=m ; j++)
		{
			scanf(" %c", &this1);
			if (this1=='*') soc[i][j]=1;
		}
	}
}

void print_soc(int m , int soc[][m+2])
{	
	int i,j;
	printf("\n/");
	for ( i=0 ; i<2*m+1 ; i++)
	{
		printf("o");
	}
	printf("\\\n");
	for ( i=1 ; i<=m ; i++)
	{
		printf("\n");
		printf("|");
		for ( j=1 ; j<=m ; j++)
		{
			if (soc[i][j]==1) printf(" *");
			else printf(" -");
		}
		printf(" |\n");
	}
	printf("\n\\");
	for (i=0 ; i<2*m+1 ; i++) printf("o");
	printf("/\n");
}

int destiny(int m , int soc[][m+2] , int row , int column)
{	int i;
	int num_neighbor=0;
	for ( i=(row-1) ; i<=(row+1) ; i++)
	{
		if (soc[i][column-1]==1) num_neighbor++;
		if (soc[i][column+1]==1) num_neighbor++;
	}
	if (soc[row-1][column]==1) num_neighbor++;
	if (soc[row+1][column]==1) num_neighbor++;
	 
	if (soc[row][column]==1) 
	{
		if (num_neighbor==2 || num_neighbor==3) 
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	 
	if (soc[row][column]==0)
	{
		if (num_neighbor==3) 
		{
			return 1;
		}
		else return 0;
	}
}

int population(int m , int soc[][m+2])
{
	int pop=0,i,j;
	for (i=1 ; i<=m ; i++)
	{
		for (j=1 ; j<=m ; j++)
		{
		if (soc[i][j]==1) pop++;
		}
	}
	return pop;
}

int evolve_soc(int m , int soc[][m+2])
{	
	int i,j;
	int next_soc[m+2][m+2];
	for (i=0 ; i<m+2 ; i++)
	{ 
		for (j=0 ; j<m+2 ; j++)
		{
		next_soc[i][j]=0;
		}
	}
	int exchange=0;
	for (i=1 ; i<=m ; i++)
	{
		for (j=1 ; j<=m ; j++)
		{	
			next_soc[i][j]=destiny(m , soc , i , j);
			if (next_soc[i][j]!=soc[i][j]) exchange=1;
		}
	}
	for (i=1 ; i<=m ; i++)
	{
		for (j=1 ; j<=m ; j++)
		{	
			soc[i][j]=next_soc[i][j];
		}
	}
	return exchange;
}
	
int main(){
	int m;
	printf("\nRead the boudry size: ");
	scanf("%d",&m);
	int soc[m+2][m+2];
	printf("\nBuild the society.\n\n");
	read_soc(m , soc);
	printf("\nNew Life:\n");
	print_soc(m , soc);
	printf("\nThe number of inhabitants is %d ",population(m,soc)); 
	printf("\n\n\nAfter One Evolution:\n");
	printf("\n++++++++++++++++++++\n");
	evolve_soc(m , soc);
	print_soc(m , soc);
	printf("\nThe number of inhabitants is %d ",population(m,soc)); 
}