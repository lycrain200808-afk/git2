#include <stdio.h>
#include <stdlib.h>

void scan_set(int* set , int size) 
{
	// scanf("%d",size);  standard: input in main 
	printf("Input the set: ");
	for (int i=0 ; i < size ; i++)
	{
		scanf("%d",&set[i]);
	}
}

void print_set(int* set , int size)
{ 
	printf("{");
	switch(size)
	{
	case 0:
		break;
	case 1: 
		printf("%d", set[0]);
		break;
	default: 
		for (int i=0; i<=size-2 ; i++)
		{
			printf("%d, ",set[i]);
		}	
		printf("%d",set[size-1]);
	}
	printf("}.");
	printf("\n");
}

int is_member(int item , int* set, int size)
{	int isnot_item=1;
	for (int i=0; i<size ;i++)
	{
		if (set[i]==item) 
		{
			printf("Item %d is a member of the set.",item);
			isnot_item=0;
			return 1;
		}
	}
	if(isnot_item)	
	{	
		printf("Item %d is NOT a member of the set.",item);
		return 0;
	}
}

void intersect(int setA[], int sizeA, int setB[], int sizeB, int* setC)
{	
	int num=0;
	for (int i=0 ; i<sizeA ; i++)
	{
		int member=0;
		for (int j=0 ; j<sizeB ; j++)
		{
			if (setA[i]==setB[j])
			{
			member=1;
			break;
			}   //fall in the same place twice
		}
		if (member==1)    
		{
			setC[num]=setA[i];
			num++;
		}
	}
	printf("%d\n", num);
	print_set(setC , num);
}
	
int main(){
	printf("Enter 1 (membership checking) or 2 (intersection) or 3 (top-k-sum): ");
	int option;
	scanf("%d",&option);
	
	int size;
	printf("Enter size: ");
	scanf("%d",&size);
	
	int *set = (int* ) malloc ( size * sizeof(int) );
	scan_set(set , size);
	print_set(set , size);
	
	switch(option)
	{
		case 1:
			{
			int item;
			scanf("%d",&item);
			is_member(item , set , size);
			break;
			}
		
		case 2:
			{
			int sizeB;
			printf("Enter sizeB: ");
			scanf("%d",&sizeB);
			
			int *setB = (int* ) calloc ( sizeB , sizeof(int) );
			scan_set(setB , sizeB);
			print_set(setB , sizeB);
			
			int bigger_size=size;
			if (size<sizeB) bigger_size=sizeB;
			int* setC = (int*) calloc ( bigger_size , sizeof(int) );
			
			intersect(set, size , setB , sizeB , setC);
			break;
			}
			
		case 3:
			{
			int k;
			scanf("%d", &k);
			if ( k>size ) printf("The set is too small.\n");
			else 
			{
				int height = size-1;
				int exchange=1;
				while ( height>=1 && exchange ==1)
				{	exchange = 0;
					for (int i=1 ; i<=height ; i++)
					{
					if (set[i-1]<set[i])	
					{
						int temp=set[i-1];
						set[i-1]=set[i];
						set[i]=temp;
						exchange = 1;
					}
					}
					height--;
				}
			int sum=0;
			for (int i=0;i<k;i++) sum+=set[i];
			printf("%d",sum);
			}
			}
	}
	return 0;
}