#include <stdio.h>
#include <stdlib.h>
#define N 100
#define BASE_START 63

int x[N];

void swap(int x[] , int a , int b)
{
	int temp=x[a];
	x[a]=x[b];
	x[b]=temp;
}

int index_son(int i , int s[])
{
	if (s[2*i+1]>s[2*i+2]) return 2*i+1;
	else return 2*i+2;
}
int main(){
	int i,checksum=0;
	int done , this1 , parent , index;
	srand(17);
	
	for (i=0 ; i<N ; i++) x[i]=rand()%250;
	for (i=0 ; i<N ; i++) checksum+=x[i];
	printf("checksum before heapify:%ld\n",checksum);
	
	for (i=1 ; i<N ; i++)
	{
		done=0;
		this1=i;
		while(!done)
		{
			if (this1==0) done=1;	
			else 
			{
				parent=(this1-1)/2;
				if (x[parent]<x[this1])
				{
				swap(x,parent,this1);
				this1=parent;
				}
				else done=1;
			}
		}
	}
	
	checksum=0;
	for (i=0 ; i<N ; i++) checksum+=x[i];
	printf("checksum after heapify:%ld\n",checksum);
	
	for (i=N-1 ; i>=1 ; i--)
	{
		swap(x,i,0);
		done = 0;
		this1 = 0;
		while(!done)
		{
			if (this1>=BASE_START) done=1;
			else if (2*this1+1>=i) done=1;
			else if (2*this1+2==i)
				{
					if (x[this1]<x[2*this1+1]) swap (x,this1,2*this1+1);
					done =1;
				}
			else {
					index=index_son(this1 , x);
					if (x[this1]<x[index]) 
					{
						swap(x,this1,index);
						this1=index;
					}
					else done=1;
				 }
		}
	} 
	printf("End:");
	for (i=0 ; i<N ; i++) printf("%d ",x[i]);
	checksum=0;
	for (i=0 ; i<N ; i++) checksum+=x[i];
	printf("\nchecksum after sort:%ld\n",checksum);
	
	int sorted=1;
	for (i=0 ; i<=N-2 ; i++)
	{
		if (x[i]>x[i+1]) 
		{
			sorted=0;
			break;
		}
	}
	if (sorted) printf("\nsorted");
	else printf("\nnot sorted");
	return 0;
}		