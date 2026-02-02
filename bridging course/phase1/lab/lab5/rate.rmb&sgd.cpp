#include<stdio.h>
void print_menu()
{
   printf("  Currency Conversion\n");
   printf("1.   Customer sells Renminbi\n");
   printf("2.   Customer buys Renminbi\n");
   printf("3.   Quit\n\n");
   printf("Enter your choice: ");
}
int main(){
	int buy,sell,option=1,amount;
	FILE* outdata=fopen("C:\\Users\\e1719162\\Desktop\\lab5.zip\\RATE.DAT","r");
	fprintf(outdata,"%d%d",&buy,&sell);
	do{
	print_menu();
	scanf("%d",&option);
	switch(option){
	case 1:
		printf("\nHow much to buy?");
		scanf("%d",&amount);
		printf("\n%.2f",amount*buy*0.001);
	case 2:
		printf("\nHow much to sell?");
		scanf("%d",&amount);
		printf("\n%.2f",amount*sell*0.01);\
	case 3:
		printf("\nHave a nice day!");
	default:
		printf("please try again");	
	}
}while(option!=3);
	return 0;
}