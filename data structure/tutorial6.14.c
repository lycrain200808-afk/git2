#include <stdio.h>
typedef struct {
	int a[5];
} rain;
void f(rain);
void g(rain *);
	
int main(){
	rain p1,p2;
	p1.a[0]=p2.a[0]=0;
	f(p1); g(&p2);
	printf("%d %d", p1.a[0], p2.a[0]);
}

void f(rain p){
	p.a[0]=0;
} 
void g(rain *p) {
	p->a[0]=1;
}
	