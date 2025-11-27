#include <stdio.h>
//#include <string.h>
typedef struct this1{
	char name[10];
	struct this1 *next;
}node;

void print_nodes(const node *ptr);

int main(){
	node e1, e2, e3, *start;
	
	strcpy(e1.name, "AA");
	strcpy(e2.name, "BB");
	strcpy(e3.name, "CC");
	
	e1.next=&e2;
	e2.next=&e3;
	e3.next=NULL;
	start=&e1;
	print_nodes(start);
	return 0;
}

void print_nodes(const node *ptr){ //pointer to node
	int count=1;
	while(ptr!=NULL){
		printf("%d is %s\n", count++, ptr->name);
		ptr=ptr->next;
	}
}
	
	