#include <stdio.h>
int main(){
	char this1;
	int answer;
	do 
	{	 
		printf("Enter price: $");
		scanf("%c",&this1);
		printf("Coded price is $");
		while(this1!='\n')
		{
			switch(this1){
				case '0':	this1='X';
							break;
				case '1':   this1='S';
							break;
				case '2':   this1='R';
							break;			
		 		case '3':   this1='E';
							break;
				case '4':   this1='T';
							break;
				case '5':   this1='U';
							break;
				case '6':   this1='P';
							break;
				case '7':   this1='M';
							break;
				case '8':   this1='O';
							break;
				case '9':   this1='C';
							break;
			}
			printf("%c",this1);
			scanf("%c",&this1);
		}
		printf("\n\nAnother price<y/n>: ");
		scanf("%c%*c",&answer);
	}while (answer=='y' || answer=='Y');
}