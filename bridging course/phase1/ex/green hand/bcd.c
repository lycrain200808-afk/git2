#include <stdio.h>
int main(){
int x;
scanf("%d",&x);
printf("%x %d",x,x/16*10+x%16);//%x is base(16)
}