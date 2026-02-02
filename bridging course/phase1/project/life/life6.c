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
	int popu=0,i,j;
	for (i=1 ; i<=m ; i++)
	{
		for (j=1 ; j<=m ; j++)
		{
		if (soc[i][j]==1) popu++;
		}
	}
	return popu;
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

void generate(int m , int soc[][m+2] , int gen)
{
	int exchange;
	int round=0;
	while(round<gen)
	{
		exchange=evolve_soc(m , soc);
		if (exchange==0) 
		{
		print_soc(m , soc);
		printf("\nThe number of inhabitants is %d\n\n",population(m,soc)); 
		printf("The society stabilizes at evolution %d.",round);
		break;
		}
		round++;
	}
	if (exchange!=0)
	{
	print_soc(m , soc);	
	printf("\nThe number of inhabitants is %d\n\n",population(m,soc)); 
	printf("Evolution continues after %d evolutions.",round);
	}
}

void census(int m , int soc[][m+2] , int pop[])
{	
	int i,j;
	for (j=1 ; j<=m ; j++) pop[j]=0;
	for (i=1 ; i<=m ; i++)
	{
		for (j=1 ; j<=m ; j++)
		{
			pop[i]+=soc[i][j];
		}
	}
}

void migrate(int m , int soc[][m+2] , int pop[])
{
	int ROW[m+1];
	int i,j;
	int index[m+1];
	
	for ( i=1 ; i<=m ; i++)
	{
		ROW[i]=pop[i];
		index[i]=i;
	}
	int exchange=1;
	int height=m-1;
	while (exchange==1 && height>=1) 
	{
		exchange=0;
		for ( i=1 ; i<=height ; i++)
		{
			if (ROW[i]<ROW[i+1]) 
			{
				int temp=ROW[i];
				ROW[i]=ROW[i+1];
				ROW[i+1]=temp;
				exchange=1;
				temp=index[i];
				index[i]=index[i+1];
				index[i+1]=temp;
			}
		}
		height--;
	}
	int next_soc[m+2][m+2];
	for ( i=1 ; i<=m ; i++)
	{
		for ( j=1 ; j<=m ; j++)
		{
			next_soc[i][j]=soc[index[i]][j];
		}
	}
	for ( i=1 ; i<=m ; i++)
	{
		for ( j=1 ; j<=m ; j++)
		{
			soc[i][j]=next_soc[i][j];
		}
	}
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
	printf("\nThe number of inhabitants is %d.",population(m,soc)); 
	printf("\n\n\n\nAfter One Evolution:\n");
	printf("\n++++++++++++++++++++\n");
	evolve_soc(m , soc);
	print_soc(m , soc);
	printf("\nThe number of inhabitants is %d.\n\n\n\n",population(m,soc)); 
	int gen;
	scanf("%d",&gen);
	printf("\nEvolution begins:\n\n+++++++++++++++++\n");
	generate(m , soc , gen);
	printf("\n\n\n\nCensus Results:\n\n++++++++++++++\n\n");
	int pop[m];
	census(m , soc , pop);
	printf("[");
	for (int i=1 ; i<=m ; i++) printf(" %d", pop[i]);
	printf(" ]");
	printf("\n\n\n\nAfter migration:\n\n++++++++++++++++\n");
	migrate(m , soc , pop);
	print_soc(m , soc);
	printf("\nThe number of inhabitants is %d.",population(m,soc));
	return 0;
}