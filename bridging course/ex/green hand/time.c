#include <stdio.h>
int main(){
int t,hour,min,dt;
scanf("%d %d",&t,&dt);
hour=t/100;
min=t%100;
t=60*hour+min+dt;
printf("%d",t/60*100+t%60);
return 0;
}