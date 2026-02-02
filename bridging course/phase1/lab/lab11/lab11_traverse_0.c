/* april 2012 q19 traversing a maze. 
   
   traverse2.c
   Travsere only two possibilities: down and right
*/

#include <stdio.h>
#include <stdbool.h>
#define N 6

int *traveller;
bool pass=false;

bool check_right(int this1[N][N], int *p){
	for (int i=0; i<N; i++){
		if (p==&this1[i][N-1]) {
			return true;
		}
	}
	return false;
}

bool check_bottom(int this1[N][N], int *p){
	for (int i=0; i<N; i++){
		if (p==&this1[N-1][i]) {
			return true;
		}
	}
	return false;
}

bool check_cap(int this1[N][N], int *p){
	for (int i=0; i<N; i++){
		if (p==&this1[0][i]) {
			return true;
		}
	}
	return false;
}

void print (int this1[N][N])
{ 
	int i,j;
	for (i=0;i<N;i++)
	{
		for (j=0;j<N;j++)
		{
			if (this1[i][j]==0) printf (" ");
			else printf ("%c",219);
		}
			printf ("\n");
	}
}

// Your own recursive function for traversing in two directions only
void traverse(int this1[N][N]){
	if (traveller==&this1[N-1][N-1]) {
		pass=true;
		return ;
	}
	
	else if (check_right && *(traveller+N)==0) {
		traveller=traveller+N;
		traverse(this1);
		return ;
	} 
	
	else if (check_bottom && *(traveller+1)==0) {
		traveller=traveller+1;
		traverse(this1);
		return ;
	}

	if (*(traveller+N)==0){
		traveller=traveller+N;
		traverse(this1);
		return ;
	} 	
		
	if (*(traveller+1)==0 ) {
		traveller=traveller+1;
		traverse(this1);
		return ;
	}
}


int main() 
{

	
	int maze1 [N][N]= {0, 0, 1, 0, 0, 1,           
	                   1, 0, 1, 0, 1, 1,
	                   1, 0, 0, 0, 1, 0,
	                   1, 0, 1, 1, 1, 1,
					   1, 0, 0, 0, 0, 0,
	                   1, 1, 1, 1, 1, 0};

	int maze2 [N][N]= {0, 0, 1, 0, 0, 0,           
	                   1, 0, 1, 0, 1, 0,
	                   1, 0, 0, 0, 1, 0,
	                   1, 1, 1, 1, 1, 0,
					   1, 1, 1, 1, 1, 0,
	                   1, 1, 1, 1, 1, 0};
	
	int maze3 [N][N]= {0, 0, 1, 0, 0, 0,           
	                   1, 0, 1, 0, 1, 0,
	                   1, 0, 0, 0, 1, 0,
	                   1, 1, 1, 1, 1, 0,
					   1, 1, 1, 1, 1, 1,
	                   1, 1, 1, 1, 1, 0};

	print (maze1);
    printf ("\n\nTwo directional Traversal:");
	traveller=*maze1;
	traverse(maze1);
	
	if(pass) printf("\n\nThere is a path to reach the end of the maze.\n  ** Solved !!");
	else printf("  **Blocked !!");
	return 0;
}