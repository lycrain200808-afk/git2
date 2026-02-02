/* april 2012 q19 traversing a maze. 
   
   traverse2.c
   Travsere only two possibilities: down and right
*/

#include <stdio.h>
#include <stdbool.h>
#define N 6

bool pass=false;

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
bool traverse(int maze[N][N], int x, int y){
	if (maze[x][y]!=0 || x>=N || y>=N) return false;
	if (x==N-1&&y==N-1) {
		pass=true;
		return true;
	}
	//maze[x][y]=2;
	if (traverse(maze, x+1, y)) return true;
	if (traverse(maze, x, y+1)) return true;
	//maze[x][y]=0;
	return false;
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

	print (maze2);
    printf ("\n\nTwo directional Traversal:");
	traverse(maze2, 0, 0);
	if(pass) printf("\n\nThere is a path to reach the end of the maze.\n  ** Solved !!");
	else printf("  **Blocked !!");
}