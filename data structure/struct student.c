#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	int id;
	char name[50];
	char gender[2];
}student;

void remove_LF(char *p){
	size_t len=strlen(p);
	if (len>0 && *(p+len-1)=='\n') *(p+len-1)=0;
}

int main(){
	student s;
	s.id=1001;
	strcpy(s.name, "Liu Yucheng");
	
	student *p=malloc(sizeof(student));
	if (p==NULL) {
		printf("memory allocation failed.");
		return 1;
	}
	
	p->id=1002;
	fgets(p->name, sizeof(p->name), stdin);
	remove_LF(p->name);
	printf("%d: %s\n", s.id, s.name);
	printf("%d: %s\n", p->id, p->name);
	printf("%lu",sizeof(student));
	return 0;
}